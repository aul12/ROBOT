/**
 * @file CircleFinder.hpp
 * @authors Paul Nykiel, Tim Luchterhand
 */

#ifndef ORANGEBALL_CIRCLEFINDER_HPP
#define ORANGEBALL_CIRCLEFINDER_HPP

using namespace cv;

#define SQ(x) (x*x)

#include "Line.hpp"
#include "CircleFinderResult.hpp"

//Östereicher werden restlos erkannt
namespace crclfnd{
    int minimumPoints = 10; ///<Minimum Points required for a form to be allowed as a circle
    double cos45 = 0.707106781186547524400; ///<
    int maxRadius = 500;
    int distanceThreshold = SQ(50);  // < Empfindlicher
    int circleCenterDistanceThreshold = SQ(25); // > Empfindlicher
    float radiusRatioThreshold = 0.1;
    float  trLineLengthRatioThreshold = 0.1; //TriangleLineRatioThreshold

    int sqDistance(Point p1, Point p2){
        return (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y);
    }

    Point getMiddle(Point p1,Point p2){
        return Point((p1.x + p2.x)>>1, (p1.y + p2.y)>>1);
    }

    Point getMiddle(Point p1, Point p2, Point p3){
        int x=0, y=0;
        x = (p1.x + p2.x + p3.x)/3;
        y = (p1.y + p2.y + p3.y)/3;
        return Point(x, y);
    }

    int getPointDistance(Point check, Point p1, Point p2){
        int dist1 = (int)sqrt(sqDistance(check, p1));
        int dist2 = (int)sqrt(sqDistance(check, p2));

        return dist1+dist2;
    }

    CircleFinderResult isCircle(std::vector<Point> points){
        CircleFinderResult result(false);

        //Zu wenig Punkte für Kreis
        if(points.size() < minimumPoints)
            return result;

        std::cout << "Anzahl Punkte OK" << std::endl;

        //Drei Punkte suchen
        Point triangle[3];
        triangle[0] = points[0];
        Point pTemp;

        //Temp Punkt suchen
        //@TODO distanceTH proportional zur Größe
        bool pTempFound = false;
        for(int c=1; c<points.size(); c++){
            if(sqDistance(triangle[0], points[c]) > distanceThreshold ){
                pTemp = points[c];
                pTempFound = true;
                break;
            }
        }

        if(!pTempFound)
            return result;
        std::cout << "TempPunkt gefunden" << std::endl;

        //Punkt 2 berechnen (größter Abstand zu Punkt 1 und TempPunkt)

        int maxDist = 0;
        int maxInd = 1;
        for(int c=2; c<points.size(); c++){
            int dist = getPointDistance(points[c], triangle[0], pTemp);
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
            if (abs(1 - distRatio) < trLineLengthRatioThreshold) {
                triangle[2] = points[i];
                break;
            }
        }

       /* Point triangle[3];
        triangle[0] = points[0];
        bool p2Found = false;
        for(int c=1; c<points.size(); c++){
            if(sqDistance(triangle[0], points[c]) > distanceThreshold ){
                triangle[1] = points[c];
                p2Found = true;
                break;
            }
        }

        if(!p2Found)
            return false;

        int maxDist = 0;
        int maxInd = 1;
        for(int c=2; c<points.size(); c++){
            int dist = getPointDistance(points[c], triangle[0], triangle[1]);
            if(dist > maxDist){
                maxDist = dist;
                maxInd = c;
            }
        }
        if(SQ(maxDist) < distanceThreshold)
            return false;

        triangle[2] = points[maxInd];*/

        std::cout << "Drei Punkte gefunden" << std::endl;

        std::cout <<triangle[0].x << "|" << triangle[0].y<< std::endl;
        std::cout <<triangle[1].x << "|" << triangle[1].y<< std::endl;
        std::cout <<triangle[2].x << "|" << triangle[2].y<< std::endl;

        Point lineCenter[] = {getMiddle(triangle[0], triangle[1]),
                              getMiddle(triangle[0], triangle[2]),
                              getMiddle(triangle[1], triangle[2])};
        Line triangleLines[] = {Line(triangle[0], triangle[1]),
                                Line(triangle[0], triangle[2]),
                                Line(triangle[1], triangle[2])};

        // Dreieck überprüfen
        std::vector<int> lineLengths;
        for(int c=0; c<3; c++){
            lineLengths.push_back(triangleLines[c].getDistPoints());
            if(lineLengths[c] > lineLengths[0]){
                int temp = lineLengths[c];
                lineLengths[c] = lineLengths[0];
                lineLengths[0] = temp;
            }
        }

        int cosAlpha = (int)((SQ(lineLengths[1]) - SQ(lineLengths[0]) - SQ(lineLengths[2]))
                           / (-2.0*lineLengths[0]*lineLengths[2]));
        int cosBeta = (int)((SQ(lineLengths[2]) - SQ(lineLengths[1]) - SQ(lineLengths[0]))
                          / (-2.0 * lineLengths[0] * lineLengths[1]));

        for(int c=0; c<3; c++)
            result.triangle[c] = triangle[c];

        if(cosAlpha > cos45|| cosBeta > cos45)
            return result;

        std::cout << "Winkel ok" << std::endl;

        //Mittelpunkte berechnen
        std::vector<Line> invertedTriangleLines;

        for(int c=0;c<3;c++){
            invertedTriangleLines.push_back(triangleLines[c].getInverted(lineCenter[c]));
            result.invertedTriangleLines.push_back(invertedTriangleLines[c]);
        }



        if(!invertedTriangleLines[0].existsIntersection(invertedTriangleLines[1]) ||
                !invertedTriangleLines[0].existsIntersection(invertedTriangleLines[2]) ||
                !invertedTriangleLines[1].existsIntersection(invertedTriangleLines[2]))
            return result;

        std::cout << "Schnittpunkt der Mittelsenkrechten" << std::endl;

        Point circleCenterCandidates[] = {
                invertedTriangleLines[0].getIntersection(invertedTriangleLines[1]),
                invertedTriangleLines[0].getIntersection(invertedTriangleLines[2]),
                invertedTriangleLines[1].getIntersection(invertedTriangleLines[2])};


        Point circleCenter = getMiddle(circleCenterCandidates[0] , circleCenterCandidates[1], circleCenterCandidates[2]);

        std::cout << circleCenter.x << "|" << circleCenter.y << std::endl;
        result.centre = circleCenter;
        for(int c=0; c<3; c++){
            std::cout << circleCenterCandidates[c].x << "|" << circleCenterCandidates[c].y << std::endl;
            result.circleCentreCandidates[c] = circleCenterCandidates[c];

            //Mittelpunktkandidaten zu weit auseinander
            if(sqDistance(circleCenter, circleCenterCandidates[c]) > circleCenterDistanceThreshold)
                return result;
        }

        std::cout << "Mittelpunkte OK" << std::endl;

        // Radius zu Dreieckseckpunkten
        int radius = 0;
        for(int c=0; c<3; c++){
            radius += sqDistance(triangle[c], circleCenter);
        }
        radius /= 3;
        radius = (int)sqrt(radius);

        result.radius = radius;

        // Zu große Radien testen
        if(radius > maxRadius)
            return result;

        int minRadius = (int)(radius * (1 - radiusRatioThreshold));
        int maxRadius = (int)(radius * (1 + radiusRatioThreshold));

        // Alle Kreispunkte testen
        for(int c=0; c<points.size(); c++){
            /*if(abs(sqrt(sqDistance(circleCenter, points[c]))-radius) > deltaRadiusThreshold)
                return false;*/
            int currRadius = (int)sqrt(sqDistance(circleCenter, points[c]));

            if(currRadius < minRadius || currRadius > maxRadius)
                return result;
        }

        std::cout << "Kreis OK" << std::endl;

        result.isCircle = true;
        return result;
    }
}

#endif //ORANGEBALL_CIRCLEFINDER_HPP
