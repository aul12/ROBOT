//
// Created by paul on 01.01.17.
//

#include "CurvedLine.hpp"

CurvedLine::CurvedLine(std::vector<cv::Point> points) {
    this->points = points;
}

double CurvedLine::getCurvature() {
    double gradientLast = (points[1].y-points[0].y)/(points[1].x-points[0].x);
    double curvature = 0;
    for(int c=2; c<points.size(); c++){
        double gradient = (points[c].y-points[c-1].y)/(points[c].x-points[c-1].x);
        curvature += fabs(gradient-gradientLast/(points[c].x-points[c-1].x));
    }

    return curvature/points.size();
}

double CurvedLine::getLength() {
    double len = 0;
    for(int c=1; c<points.size(); c++){
        len += sqrt(pow(points[c].x-points[c-1].x, 2) + pow(points[c].y-points[c-1].y, 2));
    }

    return len;
}
