/**
 * @file main.cpp
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief Main file
 */

#include <iostream>
#include <thread>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

#include "Profiler.hpp"
#include "ColourBased.hpp"
#include "Canny.hpp"

#define PROF_ENABLED false

void printHelp(){
    std::cout << "The following arguments are supported:" << std::endl;
    std::cout << "--gui\t Show a graphical output of the images" << std::endl;
    std::cout << "--undistort\t Undistort the image of the fisheye camera" << std::endl;
    std::cout << "--color\t Run the color based algorithm" << std::endl;
    std::cout << "--canny\t Run the canny based algorithm" << std::endl;
    std::cout << "--device\t Select the video device number" << std::endl;
    std::cout << "--help\t Show this help message" << std::endl;
}

Matx<float,3,3> cameraMatrix (
        2.7558586477980515e+02, 0, 3.1950000000000000e+02,
        0, 2.7558586477980515e+02, 2.3950000000000000e+02,
        0, 0, 1
);
// 640x480
/*
Matx<float,3,3> cameraMatrixFish (
        2.5053740487237610e+02, 0, 3.4303555211547041e+02,
        0, 2.4982895290354298e+02, 2.3747773177305484e+02,
        0, 0, 1
);*/

// 1920x1080

Matx<float,3,3> cameraMatrixFish (
        5.4608602858857068e+02, 0, 9.9783240705152014e+02,
        0, 5.4372798657356202e+02, 5.3702528456919765e+02,
        0, 0, 1
);

Matx<float,1,5> distCoeffs (
        -2.5803810151961959e-01,
        5.1724264728968586e-02,
        -4.0138190007831046e-03,
        -1.1546095045681297e-03,
        -3.9872469723213665e-03
);

//640x480
/*
Matx<float,1,4> distCoeffsFish (
    -7.1478826652600094e-02,
    0,
    0,
    0
);*/

//1920x1080

Matx<float,1,4> distCoeffsFish (
    5.6287241244863048e-02,
    0,
    0,
    0
);


/**
 * Main function
 * @return exit code
 */
int main(int argc, char* argv[]){
    PROF_START(INIT);
    bool guiEnable = false, colorEnable=false, cannyEnable=false, undistortEnable=false, undistortEnableFish=false;
    int videoNumber = 0;

    if(argc <= 1){
        printHelp();
        return 0;
    }

    for(int c=1; c<argc; c++){
        String arg = argv[c];

        if(arg == "--gui") {
            guiEnable = true;
        }else if(arg == "--canny") {
            cannyEnable = true;
        }else if(arg == "--color") {
            colorEnable = true;
        }else if(arg == "--help") {
            printHelp();
            return 0;
        }else if(arg == "--device") {
            if (c + 1 < argc) {
                videoNumber = atoi(argv[++c]);
            }
        }else if(arg == "--undistort"){
            undistortEnable = true;
            undistortEnableFish = false;
        }else if(arg == "--undistortfish"){
            undistortEnableFish = true;
            undistortEnable = false;
        }else{
            std::cout << "Unknown argument: " << arg << std::endl;
            printHelp();
            return 0;
        }
    }

    dbg::init(dbg::STDOUT, dbg::ERROR);

    VideoCapture cap(videoNumber);

    Mat imgOriginal;
    if (!cap.isOpened()){
        dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
        return -1;
    }

    clr::init();
    cnny::init();

    PROF_END(INIT);
    while(true){
        PROF_START(MAIN);
        PROF_START(CAPTURE)

        if (!cap.read(imgOriginal))
            dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);

        PROF_END(CAPTURE)

        //Mat imgUndist = imgOriginal.clone();
        Mat imgUndist;
        if(undistortEnable) {
            undistort(imgOriginal, imgUndist, cameraMatrix, distCoeffs);
        } else if(undistortEnableFish) {
            fisheye::undistortImage(imgOriginal, imgUndist, cameraMatrixFish,distCoeffsFish,cameraMatrixFish);
        } else {
            imgUndist = imgOriginal.clone();
        }

        Mat imgCannyResult, imgColourResult;
        std::vector<CircleFinderResult> results;
        if(cannyEnable){
            results = cnny::run(imgUndist);

            imgCannyResult = Mat::zeros(imgOriginal.size(), CV_8UC1);

            for(int c=0; c<results.size(); c++){
                if(results[c].isCircle)
                    circle(imgCannyResult, results[c].centre, results[c].radius, results[c].circularity, -1);
            }
        }
        if(colorEnable)
            imgColourResult = clr::run(imgUndist);

        Mat imgFinal = Mat::zeros(imgOriginal.size(), CV_8UC1);
        if(colorEnable && cannyEnable) {
            addWeighted(imgCannyResult, 1, imgColourResult, 1, 0, imgFinal);

            blur(imgFinal, imgFinal, Size(9, 9));

            uchar max = 0;
            bool orangeObject = false;
            int xMax = 0, yMax = 0;
            for (int y = 0; y < imgFinal.rows; y++) {
                for (int x = 0; x < imgFinal.cols; x++) {
                    uchar val = imgFinal.at<uchar>(Point(x, y));

                    if (val > max && val > 80) {
                        orangeObject = true;
                        max = val;
                        xMax = x;
                        yMax = y;
                    }
                }
            }

            bool foundCircle = false;
            if (orangeObject) {
                for (int c = 0; c < results.size(); c++) {
                    Point centre = results[c].centre;
                    if (SQ(xMax - centre.x) + SQ(yMax - centre.y) < SQ(results[c].radius)) {
                        circle(imgFinal, centre, results[c].radius, 255, -1);
                        foundCircle = true;
                        break;
                    }
                }
            }

            if(!foundCircle && orangeObject){
                circle(imgFinal, Point(xMax, yMax), 10, 255, -1);
            }
        }

        if(guiEnable){
            namedWindow("Original", WINDOW_NORMAL);

            imshow("Original", imgUndist);

            if(cannyEnable)
                cnny::show(imgCannyResult, imgOriginal);
            if(colorEnable)
                clr::show(imgColourResult);

            if(cannyEnable && colorEnable)
                imshow("Final", imgFinal);
        }
        PROF_END(MAIN);

        if (waitKey(30) == 27){
            clr::close();
            cnny::close();
            dbg::close();
            return 0;
        }
    }
}