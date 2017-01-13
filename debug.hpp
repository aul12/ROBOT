//
// Created by paul on 13.01.17.
//

#ifndef ORANGEBALL_DEBUG_HPP
#define ORANGEBALL_DEBUG_HPP

#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/types.hpp>
#include <iostream>

namespace dbg{
    bool enabled = false;

    void enable(){
        enabled = true;
    }

    void disable(){
        enabled = false;
    }

    void print(cv::String text){
        if(enabled)
            std::cout << text << std::endl;
    }

    void print(cv::Point p){
        if(enabled)
            std::cout << "(" << p.x << "|" << p.y << ")" << std::endl;
    }

    void newLine(){
        if(enabled)
            std::cout << std::endl;
    }
}

#endif //ORANGEBALL_DEBUG_HPP
