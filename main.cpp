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

    int brightness, width, height, contrast, saturation, hue;

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

    FileStorage cameraConfig("../config/cameraConfig.xml", FileStorage::READ);

    VideoCapture cap(videoNumber);
    /*cap.set(CV_CAP_PROP_FRAME_WIDTH, width = cameraConfig["width"]);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, height = cameraConfig["height"]);
    cap.set(CV_CAP_PROP_BRIGHTNESS, brightness = cameraConfig["brightness"]);
    cap.set(CV_CAP_PROP_CONTRAST, contrast = cameraConfig["contrast"]);
    cap.set(CV_CAP_PROP_SATURATION, saturation = cameraConfig["saturation"]);
    cap.set(CV_CAP_PROP_HUE, hue = cameraConfig["hue"]);*/

    Mat imgOriginal;
    if (!cap.isOpened()){
        dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
        return -1;
    }

    clr::init();
    cnny::init();

    PROF_END(INIT);
    while(true){
        /*cap.set(CV_CAP_PROP_FRAME_WIDTH, width);
        cap.set(CV_CAP_PROP_FRAME_HEIGHT, height);
        cap.set(CV_CAP_PROP_BRIGHTNESS, brightness);
        cap.set(CV_CAP_PROP_CONTRAST, contrast);
        cap.set(CV_CAP_PROP_SATURATION, saturation);
        cap.set(CV_CAP_PROP_HUE, hue);
        cap.set(CV_CAP_PROP_GAIN, gain);
        cap.set(CV_CAP_PROP_EXPOSURE, exposure);*/

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
        if(cannyEnable)
            imgCannyResult = cnny::run(imgUndist);
        if(colorEnable)
            imgColourResult = clr::run(imgUndist);

        if(guiEnable){
            namedWindow("Original", WINDOW_NORMAL);
           /* createTrackbar("Brightness", "Original", &brightness, 10);
            createTrackbar("Width", "Original", &width, 1920);
            createTrackbar("Height", "Original", &height, 1080);
            createTrackbar("Contrast", "Original", &contrast, 20);
            createTrackbar("Saturation", "Original", &saturation, 10);
            createTrackbar("Hue", "Original", &hue, 10);*/

            imshow("Original", imgUndist);

            if(cannyEnable)
                cnny::show(imgCannyResult);
            if(colorEnable)
                clr::show(imgColourResult);
        }
        PROF_END(MAIN);

        if (waitKey(30) == 27){
            /*cameraConfig = FileStorage("../config/cameraConfig.xml", FileStorage::WRITE);
            cameraConfig << "brightness" << brightness;
            cameraConfig << "width" << width;
            cameraConfig << "height" << height;
            cameraConfig << "contrast" << contrast;
            cameraConfig << "saturation" << saturation;
            cameraConfig << "hue" << hue;
            cameraConfig.release();*/


            clr::close();
            cnny::close();
            dbg::close();
            return 0;
        }
    }
}