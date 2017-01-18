/**
 * @file CircleFinderResult.hpp
 * @author Paul Nykiel, Tim Luchterhand
 * @brief Header file for class containing all information of the isCircle-Algorithm
 */

#ifndef ORANGEBALL_CIRCLEFINDERRESULT_HPP
#define ORANGEBALL_CIRCLEFINDERRESULT_HPP

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

#include "Line.hpp"

using namespace cv;

/**
 * Result Type of the isCircle Algorithm, containing all information of the contour the algorithm tested
 * @class CircleFinderResult
 * @brief Class containing all information of the isCircle-Algorithm
 * @see crclfnd::isCircle
 */
class CircleFinderResult {
    public:
        CircleFinderResult(bool isCircle);

        Point centre;                           ///<Centre Point of the circle
        int radius;                             ///<Radius of the circle in Pixels
        bool isCircle;                          ///<A boolean whether the object is a circle

        ///Points of the Triangle which was calculated by the algorithm
        Point triangle[3] = {Point(0,0),Point(0,0),Point(0,0)};
        ///Lines which should intersect in the centre
        std::vector<Line> midperpendicular = {Line(Point(0,0),Point(0,0)), Line(Point(0,0),Point(0,0)), Line(Point(0,0),Point(0,0))};
        ///The three intersections
        Point circleCentreCandidates[3] = {Point(0,0),Point(0,0),Point(0,0)};
};


#endif //ORANGEBALL_CIRCLEFINDERRESULT_HPP
