//
// Created by paul on 29.06.17.
//

#ifndef ORANGEBALL_CAPTURE_HPP
#define ORANGEBALL_CAPTURE_HPP

#include "opencv2/opencv.hpp"

namespace capture{
    cv::Mat imgOriginal;
    bool firstImage = false;
    bool imgWrite = false;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    void captureThread(int videoNumber){
        cv::Mat img;
        cv::VideoCapture cap(videoNumber);
        if (!cap.isOpened()){
            //dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
            return;
        }
        while(1){
            if (cap.read(img)) {
                imgWrite = true;
                imgOriginal = img;
                imgWrite = false;
                firstImage = true;
            }
               /* dbg::println("Camera not available is a other program already using the camera?", dbg::ERROR);
            else
                i*/
        }
    }
#pragma clang diagnostic pop

    cv::Mat getImageOriginal(){
        while(imgWrite);
        return imgOriginal;
    }
}

#endif //ORANGEBALL_CAPTURE_HPP
