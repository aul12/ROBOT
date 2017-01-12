/**
 * @file CircleFinderResult.cpp
 * @author Paul Nykiel, Tim Luchterhand
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
        CircleFinderResult(Point centre, int radius, bool isCircle);
        CircleFinderResult(Point centre, int radius, bool isCircle, Point triangle[]);
        CircleFinderResult(Point centre, int radius, bool isCircle, Point triangle[],
                           std::vector<Line> invertedTriangleLines);
        CircleFinderResult(Point centre, int radius, bool isCircle, Point triangle[],
                           std::vector<Line> invertedTriangleLines, Point circleCentreCandidates[]);

        Point centre;                           ///<Centre Point of the circle
        int radius;                             ///<Radius of the circle in Pixels
        bool isCircle;                          ///<A boolean whether the object is a circle

        ///Debug Information
        Point triangle[3];                      ///<Points of the Triangle which was calculated by the algorithm
        std::vector<Line> invertedTriangleLines;///<Lines which should intersect in the centre
        Point circleCentreCandidates[3];        ///<The three intersections
};


#endif //ORANGEBALL_CIRCLEFINDERRESULT_HPP
