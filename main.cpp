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
 * Event emitted when clicked on the main window
 * @param event the event type (button...)
 * @param x the x Position of the mouse event
 * @param y the y Position of the mouse event
 */
void onMouseOriginalClick( int event, int x, int y, int, void*){
    if( event != EVENT_LBUTTONDOWN )
        return;

    Mat imgHSV;
    cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);

    cv::Vec3b pixel = imgHSV.at<cv::Vec3b>(0,0); // read pixel (0,0) (make copy)

    std::cout << (int)pixel[0] << " " << (int)pixel[1] << " " << (int)pixel[2] << std::endl;
}

/**
 * Main function
 * @return exit code
 */
int main(){
    VideoCapture cap(0);

    if (!cap.isOpened()){
        std::cout << "Webcam nicht verfügbar, greift ein anderes Programm auf die Webcam zu?" << std::endl;
        return -1;
    }

    clr::init();
    cnny::init();

    dbg::init(dbg::NONE);

    while(true){
        if (!cap.read(imgOriginal))
            std::cout << "Fehler beim Lesen eines neues Frames" << std::endl;

        imshow("Original", imgOriginal);

        setMouseCallback("Original", onMouseOriginalClick, 0);

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