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

#include "ColourBased.hpp"
#include "Canny.hpp"

Mat imgOriginal;

/**
 * Main function
 * @return exit code
 */
int main(){
    VideoCapture cap(1);

    if (!cap.isOpened()){
        std::cout << "Camera not available is a other program already using the camera?" << std::endl;
        return -1;
    }

    clr::init();
    cnny::init();

    dbg::init(dbg::STDOUT);

    while(true){
        if (!cap.read(imgOriginal))
            std::cout << "Error getting a new frame" << std::endl;

        imshow("Original", imgOriginal);

        clr::show(clr::run(imgOriginal));
        cnny::show(cnny::run(imgOriginal));

        if (waitKey(30) == 27){
            clr::close();
            cnny::close();
            dbg::close();
            return 0;
        }
    }
}