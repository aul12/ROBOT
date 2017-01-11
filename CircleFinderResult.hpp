/**
 * @file CircleFinderResult.cpp
 * @author Paul Nykiel, Tim Luchterhand
 */

#ifndef ORANGEBALL_CIRCLEFINDERRESULT_HPP
#define ORANGEBALL_CIRCLEFINDERRESULT_HPP

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;

/**
 * Result Type of the isCircle Algorithm, containing all information of the contour the algorithm tested
 * @class CircleFinderResult
 * @brief Class containing all information of the isCircle-Algorithm
 * @see crclfnd::isCircle
 */
class CircleFinderResult {
    public:
        Point centre;                           ///<Centre Point of the circle
        int radius;                             ///<Radius of the circle in Pixels
    bool isCircle;                              ///<A boolean whether the object is a circle
        CircleFinderResult(bool isCircle);
        CircleFinderResult(Point centre, int radius, bool isCircle);
};


#endif //ORANGEBALL_CIRCLEFINDERRESULT_HPP
