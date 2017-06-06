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
#include "fusion.hpp"
#include "Serial.hpp"

void printHelp(){
    std::cout << "The following arguments are supported:" << std::endl;
    std::cout << "--gui\t Show a graphical output of the images" << std::endl;
    std::cout << "--color\t Run the color based algorithm" << std::endl;
    std::cout << "--canny\t Run the canny based algorithm" << std::endl;
    std::cout << "--device\t Select the video device number" << std::endl;
    std::cout << "--help\t Show this help message" << std::endl;
}

/**
 * Main function
 * @return exit code
 */
int main(int argc, char* argv[]){
    PROF_START(INIT);
    bool guiEnable = false, colorEnable=false, cannyEnable=false;
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
    serial::init();

    PROF_END(INIT);
    while(true){
        if (!cap.read(imgOriginal))
            dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);

        Mat imgCannyResult, imgColourResult;
        std::vector<CircleFinderResult> results;

        if(cannyEnable)
            results = cnny::run(imgOriginal);
        if(colorEnable)
            imgColourResult = clr::run(imgOriginal);

        fusion::BallPosition ballPosition = fusion::getPosition(cannyEnable, colorEnable,
            results, imgColourResult, imgOriginal.size);

        serial::sendChar(37);


        if(guiEnable){
            circle(imgOriginal, ballPosition.center, ballPosition.radius==0?5:ballPosition.radius,
                   Vec3b(0, 255, 0), 3);

            namedWindow("Original", WINDOW_NORMAL);

            imshow("Original", imgOriginal);

            if(cannyEnable)
                cnny::show(fusion::getCanny(results, imgOriginal.size), imgOriginal);
            if(colorEnable)
                clr::show(imgColourResult);
        }

        if (waitKey(30) == 27){
            clr::close();
            cnny::close();
            dbg::close();
            return 0;
        }
    }
}