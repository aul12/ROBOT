/**
 * @file main.cpp
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief Main file
 */

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

#include "Profiler.hpp"
#include "ColourBased.hpp"
#include "Canny.hpp"

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


Matx<float,1,5> distCoeffs (
        -2.5803810151961959e-01,
        5.1724264728968586e-02,
        -4.0138190007831046e-03,
        -1.1546095045681297e-03,
        -3.9872469723213665e-03
);

/**
 * Main function
 * @return exit code
 */
int main(int argc, char* argv[]){
    bool guiEnable = false, colorEnable=false, cannyEnable=false, undistortEnable=false;
    int videoNumber = 0;

    Profiler profilerParam("PARAM");
    profilerParam.start();

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
        }else{
            std::cout << "Unknown argument: " << arg << std::endl;
            printHelp();
            return 0;
        }
    }

    dbg::init(dbg::STDOUT, dbg::WARN);

    profilerParam.end();
    Profiler videoCaptureCreate("videoCaptureCreate");
    videoCaptureCreate.start();


    VideoCapture cap(videoNumber);
    cap.set(CV_CAP_PROP_BUFFERSIZE, 1);
    Mat imgOriginal;

    videoCaptureCreate.end();

    Profiler capOpen("capOpen");
    capOpen.start();

    if (!cap.isOpened()){
        dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
        return -1;
    }

    capOpen.end();

    Profiler init("INIT");
    init.start();


    clr::init();
    cnny::init();
    init.end();

    Profiler profilerMain("MAIN");
    Profiler profilerCapture("CAPTURE");


    Mat temp;
    for(int c=0; c<100; c++){
        cap.read(temp);
    }
    while(true){
        profilerMain.start();
        profilerCapture.start();

        //@TODO wtf!
        if (!cap.read(imgOriginal))
            dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);

        profilerCapture.end();

        Mat imgUndist = imgOriginal.clone();
        if(undistortEnable)
            undistort(imgOriginal,imgUndist,cameraMatrix,distCoeffs);

        Mat imgCannyResult, imgColourResult;
        if(cannyEnable)
            imgCannyResult = cnny::run(imgUndist);
        if(colorEnable)
            imgColourResult = clr::run(imgUndist);

        if(guiEnable){
            imshow("Original", imgUndist);

            if(cannyEnable)
                cnny::show(imgCannyResult);
            if(colorEnable)
                clr::show(imgColourResult);
        }
        profilerMain.end();

        if (waitKey(30) == 27){
            clr::close();
            cnny::close();
            dbg::close();
            return 0;
        }
    }
}