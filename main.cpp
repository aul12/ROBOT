/**
 * @file main.cpp
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief Main file
 */

#include <iostream>
#include <thread>
#include <future>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

#include "capture.hpp"
#include "Profiler.hpp"
#include "Filter/ColourBased.hpp"
#include "Filter/Canny.hpp"
#include "Filter/fusion.hpp"
#include "Serial.hpp"

void printHelp(){
    std::cout << "The following arguments are supported:" << std::endl;
    std::cout << "--gui\t Show a graphical output of the images" << std::endl;
    std::cout << "--color\t Run the color based algorithm" << std::endl;
    std::cout << "--canny\t Run the canny based algorithm" << std::endl;
    std::cout << "--device\t Select the video device number" << std::endl;
    std::cout << "--serial\t Boolean to toggle serial output" << std::endl;
    std::cout << "--help\t Show this help message" << std::endl;
}

/**
 * Main function
 * @return exit code
 */
int main(int argc, char* argv[]){
    bool guiEnable = false, colorEnable=false, cannyEnable=false, serialOutput=false;
    int videoNumber = 0;
    int fusionBias; ///<The weight (in percent) the algorithm uses the contour-based algorithm
    int fusionThreshold; ///<The threshold which is necessary for an object to be recognized as the ball

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
        }else if(arg == "--serial"){
            serialOutput = true;
        }else if(arg == "--help") {
            printHelp();
            return 0;
        }else if(arg == "--device") {
            if (c + 1 < argc) {
                videoNumber = atoi(argv[++c]);
            } else {
                printHelp();
                return 0;
            }
        }else{
            std::cout << "Unknown argument: " << arg << std::endl;
            printHelp();
            return 0;
        }
    }

    FileStorage fileStorage("../config/fusion.xml", FileStorage::READ);
    fusionBias = fileStorage["bias"];
    fusionThreshold = fileStorage["threshold"];

    dbg::init(dbg::STDOUT, dbg::ERROR);

    std::thread captureThread(capture::captureThread, videoNumber);

    clr::init();
    cnny::init();

    if(serialOutput)
        serial::init();

    while(!capture::firstImage);

    std::future<std::vector<CircleFinderResult> > cannyFutureResult;
    std::future<Mat> imgColourFuture;
    if(cannyEnable) {
        cannyFutureResult = std::async(cnny::run, capture::getImageOriginal());
    }

    if(colorEnable) {
        imgColourFuture = std::async(clr::run, capture::getImageOriginal());
    }

    while(true){
        PROF_START(Frame)
        PROF_START(Frame_NoGui)

        Mat imgCannyResult, imgColourResult;
        std::vector<CircleFinderResult> results;

        if(cannyEnable){
            cannyFutureResult.wait();
            results = cannyFutureResult.get();
            cannyFutureResult = std::async(cnny::run, capture::getImageOriginal());
        }

        if(colorEnable){
            imgColourFuture.wait();
            imgColourResult = imgColourFuture.get();
            imgColourFuture = std::async(clr::run, capture::getImageOriginal());
        }

        fusion::BallPosition ballPosition;
        PROF_START(Fusion)
        ballPosition = fusion::getPosition(cannyEnable, colorEnable,
            results, imgColourResult, capture::getImageOriginal().size, fusionBias, guiEnable);
        PROF_END(Fusion)

        if(serialOutput)
            serial::sendChar((uint8_t) (ballPosition.value > fusionThreshold ?ballPosition.center.x / 5 : 0xFF));


        PROF_END(Frame_NoGui)
        if(guiEnable){
            Mat imageOriginalCopy = capture::getImageOriginal().clone();
            if(ballPosition.value > fusionThreshold) {
                circle(imageOriginalCopy, ballPosition.center, ballPosition.radius == 0 ? 5 : ballPosition.radius,
                       Vec3b(0, 255, 0), 3);
            }
            namedWindow("Original", WINDOW_NORMAL);

            imshow("Original", imageOriginalCopy);
            createTrackbar("Fusion Bias", "Original", &fusionBias, 100);
            createTrackbar("Fusion Threshold", "Original", &fusionThreshold, 256);

            if(cannyEnable)
                cnny::show(fusion::getCanny(results, capture::getImageOriginal().size));
            if(colorEnable)
                clr::show(imgColourResult);
        } else {
            if(ballPosition.value > fusionThreshold)
                std::cout << ballPosition.center.x << std::endl;
        }

        if (waitKey(1) == 27){
            clr::close();
            cnny::close();
            dbg::close();

            fileStorage = FileStorage("../config/fusion.xml", FileStorage::WRITE);

            fileStorage << "threshold" << fusionThreshold;
            fileStorage << "bias" << fusionBias;

            fileStorage.release();

            return 0;
        }
        PROF_END(Frame)
    }
}
