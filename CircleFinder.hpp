/**
 * @file CircleFinder.hpp
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief The file checks whether a given contour is a circle
 */

#ifndef ORANGEBALL_CIRCLEFINDER_HPP
#define ORANGEBALL_CIRCLEFINDER_HPP

using namespace cv;



#include "Line.hpp"
#include "CircleFinderResult.hpp"
#include "debug.hpp"
#include "preprocessor_math.h"

//Östereicher werden restlos erkannt

/**
 * @brief Namespace containing all algorithms to check whether a given set of points describes a circle.
 */
namespace crclfnd{
    int minimumPoints = 10; ///<Minimum Points required for an object detected as circle
    double minAngle = COS(DEG_TO_RAD(30)); ///<the cosine of the minimum angle of any angle in the triangle
    int maxRadius = 200; ///<Maximum radius for a circle. Larger circles will be ignored
    int minRadius = 6;     ///<Minimum radius for a circle. Smaller circles will be ignored
    int circleCenterDistanceThreshold = SQ(10); ///<The maximum distance between the calculated potential centers of the circle
    float triangleLineLengthRatioThreshold = 0.1; ///<The maximum percentage difference between the two shorter edges of the triangle
    float maxRadiusRatioTolerance = 0.4;///<The maximum tolerance for the ratio between the calculated radius and the actual distance from a point to the center
    float minRadiusRatioTolerance = 0.1; ///<The minimum tolerance for the ratio between the calculated radius and the actual distance from a point to the center
    float radiusRatioToleranceFactor = 0.006;///<The scaling factor of the dynamic radius ratio threshold (lower means more tolerant)

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
        dbg::println("New contour");
        dbg::print("Number of points...");
        CircleFinderResult result(false);

        //To few points for circle
        if(points.size() < minimumPoints){
            dbg::println("To few points", dbg::WARN);
            return result;
        }

        dbg::println("Ok");
        dbg::println("Calculating triangle corners...");

        //Find triangle corners
        Point triangle[3];
        triangle[0] = points[0];
        bool lastPointFound = false;

        //Find point 1 (with largest distance to point[0])
        int maxDist = 0;
        int maxInd = 1;
        for(int c=1; c<points.size(); c++){
            int dist = sqDistance(points[c], points[0]);
            if(dist > maxDist){
                maxDist = dist;
                maxInd = c;
            }
        }
        triangle[0] = points[maxInd];

        //Find point 2 (with largest distance to point 1)
        maxDist = 0;
        maxInd = 1;
        for(int c=0; c<points.size(); c++){
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
                lastPointFound = true;
                break;
            }
        }

        if(!lastPointFound){
            dbg::println("No matching triangle", dbg::WARN);
            return result;
        }


        dbg::println(triangle[0]);
        dbg::println(triangle[1]);
        dbg::println(triangle[2]);

        dbg::println("OK");
        dbg::println("Checking Angles...");

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


        if(cosAlpha > minAngle|| cosBeta > minAngle){
            dbg::println("Angles to small", dbg::WARN);
            return result;
        }


        for(int c=0; c<3; c++)
            result.triangle[c] = triangle[c];

        dbg::println("OK");
        dbg::print("Checking intersections of midperpendiculars...");

        //calculate center candidates
        std::vector<Line> invertedTriangleLines;

        for(int c=0;c<3;c++){
            invertedTriangleLines.push_back(triangleLines[c].getInverted(lineCenter[c]));
            result.midperpendicular.push_back(invertedTriangleLines[c]);
        }



        if(!invertedTriangleLines[0].existsIntersection(invertedTriangleLines[1]) ||
                !invertedTriangleLines[0].existsIntersection(invertedTriangleLines[2]) ||
                !invertedTriangleLines[1].existsIntersection(invertedTriangleLines[2])){
            dbg::println("No intersection", dbg::WARN);
            return result;
        }


        dbg::println("OK");
        dbg::println("Checking center candidates...");

        Point circleCenterCandidates[] = {
                invertedTriangleLines[0].getIntersection(invertedTriangleLines[1]),
                invertedTriangleLines[0].getIntersection(invertedTriangleLines[2]),
                invertedTriangleLines[1].getIntersection(invertedTriangleLines[2])};


        Point circleCenter = getMiddle(circleCenterCandidates[0] , circleCenterCandidates[1], circleCenterCandidates[2]);

        dbg::println(circleCenter);
        result.centre = circleCenter;
        for(int c=0; c<3; c++){
            dbg::println(circleCenterCandidates[c]);
            result.circleCentreCandidates[c] = circleCenterCandidates[c];

            //center candidates not close enough to each other
            if(sqDistance(circleCenter, circleCenterCandidates[c]) > circleCenterDistanceThreshold){
                dbg::println("Center candidates not close enough", dbg::WARN);
                return result;
            }
        }

        dbg::println("OK");
        dbg::print("Checking radius...");

        //calculate radius out of distance to triangle corners
        int radius = 0;
        for(int c=0; c<3; c++){
            radius += sqDistance(triangle[c], circleCenter);
        }
        radius /= 3;
        radius = (int)sqrt(radius);

        result.radius = radius;

        //too large/small circle
        if(radius > maxRadius || radius < minRadius){
            dbg::println("Radius to small/large", dbg::WARN);
            return result;
        }


        double dynamicRadiusRatioThreshold = max(maxRadiusRatioTolerance - radiusRatioToleranceFactor * radius, minRadiusRatioTolerance);

        int minRadius = (int)(radius * (1 - dynamicRadiusRatioThreshold));
        int maxRadius = (int)(radius * (1 + dynamicRadiusRatioThreshold));

        //check all points of object
        for(int c=0; c<points.size(); c++){
            int currRadius = (int)sqrt(sqDistance(circleCenter, points[c]));

            if(currRadius < minRadius || currRadius > maxRadius){
                dbg::println("Radius not fitting for all Points", dbg::WARN);
                return result;
            }

        }

        dbg::println("OK");
        dbg::println("Circle valid!", dbg::WARN);

        result.isCircle = true;
        return result;
    }
}

#endif //ORANGEBALL_CIRCLEFINDER_HPP
