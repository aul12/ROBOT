//
// Created by paul on 29.06.17.
//

#ifndef ORANGEBALL_CAPTURE_HPP
#define ORANGEBALL_CAPTURE_HPP

#include "opencv2/opencv.hpp"

namespace capture{
    cv::Mat imgOriginal;
    bool firstImage = false;

    void captureThread(int videoNumber){
        cv::Mat img;
        cv::VideoCapture cap(videoNumber);
        if (!cap.isOpened()){
            //dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
            return;
        }
        while(1){
            if (cap.read(img)) {
                imgOriginal = img;
                firstImage = true;
            }
               /* dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
            else
                i*/
        }
    }
}

#endif //ORANGEBALL_CAPTURE_HPP
