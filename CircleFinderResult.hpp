//
// Created by paul on 06.01.17.
//

#ifndef ORANGEBALL_CIRCLEFINDERRESULT_HPP
#define ORANGEBALL_CIRCLEFINDERRESULT_HPP

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;

class CircleFinderResult {
    public:
        Point centre;
        int radius;
        bool isCircle;
        CircleFinderResult(bool isCircle);
        CircleFinderResult(Point centre, int radius, bool isCircle);
};


#endif //ORANGEBALL_CIRCLEFINDERRESULT_HPP
