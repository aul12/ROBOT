//
// Created by paul on 05.01.17.
//

#ifndef ORANGEBALL_CIRCLEFINDER_HPP
#define ORANGEBALL_CIRCLEFINDER_HPP

using namespace cv;

#define SQ(x) (x*x)

#include "Line.hpp"

//Östereicher werden restlos erkannt
namespace crclfnd{
    int minimumPoints = 10; // < Empfindlicher
    int distanceThreshold = SQ(50);  // < Empfindlicher
    int circleCenterDistanceThreshold = SQ(250); // > Empfindlicher
    int deltaRadiusThreshold = SQ(200);     // > Empfindlicher

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

    bool isCircle(std::vector<Point> points){
        //Zu wenig Punkte für Kreis
        if(points.size() < minimumPoints)
            return false;

        std::cout << "Anzahl Punkte OK" << std::endl;

        //Drei Punkte suchen
        Point triangle[3];
        triangle[0] = points[0];
        bool p2Found = false, p3Found = false;
        for(int c=1; c<points.size(); c++){
            if(sqDistance(triangle[0], points[c]) > distanceThreshold){
                triangle[1] = points[c];
                p2Found = true;
                break;
            }
        }

        if(!p2Found)
            return false;

        for(int c=1; c<points.size(); c++){
            if(sqDistance(triangle[0], points[c])>distanceThreshold && sqDistance(triangle[1], points[c])>distanceThreshold) {
                triangle[2] = points[c];
                p3Found = true;
                break;
            }
        }

        if(!p3Found)
            return false;

        std::cout << "Drei Punkte gefunden" << std::endl;

        //Mittelpunkte berechnen
        Point lineCenter[] = {getMiddle(triangle[0], triangle[1]),
                              getMiddle(triangle[0], triangle[2]),
                              getMiddle(triangle[1], triangle[2])};
        Line triangleLines[] = {Line(triangle[0], triangle[1]),
                                Line(triangle[0], triangle[2]),
                                Line(triangle[1], triangle[2])};

        std::vector<Line> invertedTriangleLines;

        for(int c=0;c<3;c++){
            invertedTriangleLines.push_back(triangleLines[c].getInverted(lineCenter[c]));
        }

        if(!invertedTriangleLines[0].existsIntersection(invertedTriangleLines[1]) ||
                !invertedTriangleLines[0].existsIntersection(invertedTriangleLines[2]) ||
                !invertedTriangleLines[1].existsIntersection(invertedTriangleLines[2]))
            return false;

        std::cout << "Schnittpunkt der Mittelsenkrechten" << std::endl;

        Point circleCenterCandidates[] = {
                invertedTriangleLines[0].getIntersection(invertedTriangleLines[1]),
                invertedTriangleLines[0].getIntersection(invertedTriangleLines[2]),
                invertedTriangleLines[1].getIntersection(invertedTriangleLines[2])};


        Point circleCenter = getMiddle(circleCenterCandidates[0] , circleCenterCandidates[1], circleCenterCandidates[2]);

        std::cout << circleCenter.x << "|" << circleCenter.y << std::endl;
        for(int c=0; c<3; c++){
            std::cout << circleCenterCandidates[c].x << "|" << circleCenterCandidates[c].y << std::endl;

            //Mittelpunktkandidaten zu weit auseinander
            if(sqDistance(circleCenter, circleCenterCandidates[c]) > circleCenterDistanceThreshold)
                return false;
        }

        std::cout << "Mittelpunkte OK" << std::endl;

        // Radius zu Dreieckseckpunkten
        int radius = 0;
        for(int c=0; c<3; c++){
            radius += sqDistance(triangle[c], circleCenter);
        }
        radius /= 3;

        // Alle Kreispunkte testen
        for(int c=0; c<points.size(); c++){
            if(abs(sqDistance(circleCenter, points[c])-radius) > deltaRadiusThreshold)
                return false;
        }

        std::cout << "Kreis OK" << std::endl;

        return true;
    }
}

#endif //ORANGEBALL_CIRCLEFINDER_HPP
