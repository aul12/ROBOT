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
    std::cout << "--serial\t Boolean to toggle serial output" << std::endl;
    std::cout << "--help\t Show this help message" << std::endl;
}

/**
 * Main function
 * @return exit code
 */
int main(int argc, char* argv[]){
    PROF_START(INIT);
    bool guiEnable = false, colorEnable=false, cannyEnable=false, serialOutput=false;
    int videoNumber = 0;
    int fusionBias = 50; ///<The weight (in percent) the algorithm uses the contour-based algorithm
    int fusionTreshold = 127; ///<The threshold which is necessary for an object to be recognized as the ball

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
    fusionTreshold = fileStorage["treshold"];

    dbg::init(dbg::STDOUT, dbg::ERROR);

    VideoCapture cap(videoNumber);

    Mat imgOriginal;
    if (!cap.isOpened()){
        dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
        return -1;
    }

    clr::init();
    cnny::init();

    if(serialOutput)
        serial::init();

    PROF_END(INIT);
    while(true){
        PROF_START(Frame)
        PROF_START(Capture)
        if (!cap.read(imgOriginal))
            dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
        PROF_END(Capture)


        Mat imgCannyResult, imgColourResult;
        std::vector<CircleFinderResult> results;
        
        PROF_START(Canny)
        if(cannyEnable)
            results = cnny::run(imgOriginal);
        PROF_END(Canny)

        PROF_START(Color)
        if(colorEnable)
            imgColourResult = clr::run(imgOriginal);
        PROF_END(Color)


        fusion::BallPosition ballPosition;
        PROF_START(Fusion)
        if(cannyEnable && colorEnable){
            ballPosition = fusion::getPosition(cannyEnable, colorEnable,
                results, imgColourResult, imgOriginal.size, fusionBias);
        } else {
            ballPosition.center.x = 0;
            // @TODO
        }
        PROF_END(Fusion)

        if(serialOutput)
            serial::sendChar((uint8_t) (ballPosition.value > fusionTreshold ?ballPosition.center.x / 5 : 0xFF));


        if(guiEnable){
            if(ballPosition.value > fusionTreshold) {
                circle(imgOriginal, ballPosition.center, ballPosition.radius == 0 ? 5 : ballPosition.radius,
                       Vec3b(0, 255, 0), 3);
            }
            namedWindow("Original", WINDOW_NORMAL);

            imshow("Original", imgOriginal);
            createTrackbar("Fusion Bias", "Original", &fusionBias, 100);
            createTrackbar("Fusion Threshold", "Original", &fusionTreshold, 256);

            if(cannyEnable)
                cnny::show(fusion::getCanny(results, imgOriginal.size));
            if(colorEnable)
                clr::show(imgColourResult);
        } else {
            if(ballPosition.value > fusionTreshold)
                std::cout << ballPosition.center.x << std::endl;
        }

        if (waitKey(1) == 27){
            clr::close();
            cnny::close();
            dbg::close();

            fileStorage = FileStorage("../config/fusion.xml", FileStorage::WRITE);

            fileStorage << "treshold" << fusionTreshold;
            fileStorage << "bias" << fusionBias;

            return 0;
        }
        PROF_END(Frame)
    }
}
