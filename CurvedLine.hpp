//
// Created by paul on 01.01.17.
//

#ifndef ORANGEBALL_CURVEDLINE_HPP
#define ORANGEBALL_CURVEDLINE_HPP


#include <vector>
#include "opencv2/opencv.hpp"

class CurvedLine {
    public:
        CurvedLine(std::vector<cv::Point> points);
        double getCurvature();
        double getLength();
    private:
        std::vector<cv::Point> points;
};


#endif //ORANGEBALL_CURVEDLINE_HPP
