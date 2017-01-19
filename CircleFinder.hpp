/**
 * @file CircleFinder.hpp
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief The file checks whether a given contour is a circle
 */

#ifndef ORANGEBALL_CIRCLEFINDER_HPP
#define ORANGEBALL_CIRCLEFINDER_HPP

using namespace cv;

#define SQ(x) (x*x)

#include "Line.hpp"
#include "CircleFinderResult.hpp"
#include "debug.hpp"

//Östereicher werden restlos erkannt

/**
 * @brief Namespace containing all algorithms to check whether a given set of points describes a circle.
 */
namespace crclfnd{
    int minimumPoints = 10; ///<Minimum Points required for an object detected as circle
    double cos30 = 0.866025403; ///<the cosinus of the minimum angle of any angle in the triangle
    int maxRadius = 200; ///<Maximum radius for a circle. Larger circles will be ignored
    int circleCenterDistanceThreshold = SQ(25); ///<The maximum distance between the calculated potential centers of the circle
    float  triangleLineLengthRatioThreshold = 0.1; ///<The maximum percentual difference between the two shorter edges of the triangle

    /**
     *@brief Calculates the squared distance between two points
     * @param p1 first point
     * @param p2 second point
     * @return the squared distance between p1 and p2 in pixel (integer)
     */
    int sqDistance(Point p1, Point p2){
        return (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y);
    }

    /**
     * @brief Calculates the point located at the middle of the line connecting two points
     * @param p1 first point
     * @param p2 second point
     * @return point located at the middle of the line connecting p1 and p2
     */
    Point getMiddle(Point p1,Point p2){
        return Point((p1.x + p2.x)>>1, (p1.y + p2.y)>>1);
    }

    /**
     * @brief Calculates a point having the same distance to three other points (lying in the middle)
     * @param p1 first point
     * @param p2 second point
     * @param p3 third point
     * @return point where distance to p1, p2, p3 is the same
     */
    Point getMiddle(Point p1, Point p2, Point p3){
        int x=0, y=0;
        x = (p1.x + p2.x + p3.x)/3;
        y = (p1.y + p2.y + p3.y)/3;
        return Point(x, y);
    }

    CircleFinderResult isCircle(std::vector<Point> points){
        CircleFinderResult result(false);

        //To few points for circle
        if(points.size() < minimumPoints)
            return result;

        dbg::printLn("number of points ok");

        //Find triangle corners
        Point triangle[3];
        triangle[0] = points[0];

        //Find point 2 (with largest distance to point 1)
        int maxDist = 0;
        int maxInd = 1;
        for(int c=2; c<points.size(); c++){
            int dist = sqDistance(points[c], triangle[0]);
            if(dist > maxDist){
                maxDist = dist;
                maxInd = c;
            }
        }
        triangle[1] = points[maxInd];

        for(int i = 1; i < points.size(); i++) {
            int sqDistToP1 = sqDistance(points[i], triangle[0]);
            int sqDistToP2 = sqDistance(points[i], triangle[1]);
            if(sqDistToP2 == 0)
                continue;
            float distRatio = sqDistToP1 / sqDistToP2;
            if (abs(1 - distRatio) < triangleLineLengthRatioThreshold) {
                triangle[2] = points[i];
                break;
            }
        }

        dbg::printLn("triangle corners found");

        dbg::printLn(triangle[0]);
        dbg::printLn(triangle[1]);
        dbg::printLn(triangle[2]);

        Point lineCenter[] = {getMiddle(triangle[0], triangle[1]),
                              getMiddle(triangle[0], triangle[2]),
                              getMiddle(triangle[1], triangle[2])};
        Line triangleLines[] = {Line(triangle[0], triangle[1]),
                                Line(triangle[0], triangle[2]),
                                Line(triangle[1], triangle[2])};

        //double check triangle (check angles)
        std::vector<int> lineLengths;
        for(int c=0; c<3; c++){
            lineLengths.push_back(triangleLines[c].getDistPoints());
            if(lineLengths[c] > lineLengths[0]){
                int temp = lineLengths[c];
                lineLengths[c] = lineLengths[0];
                lineLengths[0] = temp;
            }
        }

        double cosAlpha = ((SQ(lineLengths[1]) - SQ(lineLengths[0]) - SQ(lineLengths[2]))
                           / (-2.0*lineLengths[0]*lineLengths[2]));
        double cosBeta = ((SQ(lineLengths[2]) - SQ(lineLengths[1]) - SQ(lineLengths[0]))
                          / (-2.0 * lineLengths[0] * lineLengths[1]));


        if(cosAlpha > cos30|| cosBeta > cos30)
            return result;

        for(int c=0; c<3; c++)
            result.triangle[c] = triangle[c];

        dbg::printLn("angles ok");

        //calculate center candidates
        std::vector<Line> invertedTriangleLines;

        for(int c=0;c<3;c++){
            invertedTriangleLines.push_back(triangleLines[c].getInverted(lineCenter[c]));
            result.midperpendicular.push_back(invertedTriangleLines[c]);
        }



        if(!invertedTriangleLines[0].existsIntersection(invertedTriangleLines[1]) ||
                !invertedTriangleLines[0].existsIntersection(invertedTriangleLines[2]) ||
                !invertedTriangleLines[1].existsIntersection(invertedTriangleLines[2]))
            return result;

        dbg::printLn("intersection between midperpendiculars exist");

        Point circleCenterCandidates[] = {
                invertedTriangleLines[0].getIntersection(invertedTriangleLines[1]),
                invertedTriangleLines[0].getIntersection(invertedTriangleLines[2]),
                invertedTriangleLines[1].getIntersection(invertedTriangleLines[2])};


        Point circleCenter = getMiddle(circleCenterCandidates[0] , circleCenterCandidates[1], circleCenterCandidates[2]);

        dbg::printLn(circleCenter);
        result.centre = circleCenter;
        for(int c=0; c<3; c++){
            dbg::printLn(circleCenterCandidates[c]);
            result.circleCentreCandidates[c] = circleCenterCandidates[c];

            //center candidates not close enough to each other
            if(sqDistance(circleCenter, circleCenterCandidates[c]) > circleCenterDistanceThreshold)
                return result;
        }

        dbg::printLn("center candidates ok");

        //calculate radius out of distance to triangle corners
        int radius = 0;
        for(int c=0; c<3; c++){
            radius += sqDistance(triangle[c], circleCenter);
        }
        radius /= 3;
        radius = (int)sqrt(radius);

        result.radius = radius;

        //too large circle
        if(radius > maxRadius)
            return result;

        double dynamicRadiusRatioThreshold = -0.14473*log(0.010579*radius);
       // double dynamicRadiusRatioThreshold = -0.16715*log(0.0136074*radius); weniger Datenpunkte
        if(dynamicRadiusRatioThreshold < 0.03)
            dynamicRadiusRatioThreshold = 0.03;

        int minRadius = (int)(radius * (1 - dynamicRadiusRatioThreshold));
        int maxRadius = (int)(radius * (1 + dynamicRadiusRatioThreshold));

        //check all points of object
        for(int c=0; c<points.size(); c++){
            int currRadius = (int)sqrt(sqDistance(circleCenter, points[c]));

            if(currRadius < minRadius || currRadius > maxRadius)
                return result;
        }

        dbg::printLn("circle valid!");

        result.isCircle = true;
        return result;
    }
}

#endif //ORANGEBALL_CIRCLEFINDER_HPP
