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
    dbg::init(dbg::STDOUT, dbg::WARN);

    VideoCapture cap(1);

    if (!cap.isOpened()){
        dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
        return -1;
    }

    clr::init();
    cnny::init();

    while(true){
        if (!cap.read(imgOriginal))
            dbg::println("Camera not available is a other program already using the camera?", dbg::WARN);

        imshow("Original", imgOriginal);

        //clr::show(clr::run(imgOriginal));
        cnny::show(cnny::run(imgOriginal));

        if (waitKey(30) == 27){
            clr::close();
            cnny::close();
            dbg::close();
            return 0;
        }
    }
}