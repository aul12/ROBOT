/**
 * @file main.cpp
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief Main file
 */

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

#include "ColourBased.hpp"
#include "Canny.hpp"

void printHelp(){
    std::cout << "The following arguments are supported:" << std::endl;
    std::cout << "--gui\t Show a graphical output of the images" << std::endl;
    std::cout << "--color\t Run the color based algorithm" << std::endl;
    std::cout << "--canny\t Run the canny based algorithm" << std::endl;
    std::cout << "--help\t Show this help message" << std::endl;
}

/**
 * Main function
 * @return exit code
 */
int main(int argc, char* argv[]){
    bool guiEnable = false, colorEnable=false, cannyEnable=false;

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
        }else if(arg == "--help"){
            printHelp();
            return 0;
        }else{
            std::cout << "Unknown argument: " << arg << std::endl;
            printHelp();
            return 0;
        }
    }

    dbg::init(dbg::STDOUT, dbg::WARN);

    VideoCapture cap(1);
    Mat imgOriginal;

    if (!cap.isOpened()){
        dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
        return -1;
    }

    clr::init();
    cnny::init();

    while(true){
        if (!cap.read(imgOriginal))
            dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);

        Mat imgCannyResult, imgColourResult;
        if(cannyEnable)
            imgCannyResult = cnny::run(imgOriginal);
        if(colorEnable)
            imgColourResult = clr::run(imgOriginal);

        if(guiEnable){
            imshow("Original", imgOriginal);

            if(cannyEnable)
                cnny::show(imgCannyResult);
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