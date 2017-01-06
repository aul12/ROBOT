//
// Created by paul on 06.01.17.
//

#include "CircleFinderResult.hpp"

CircleFinderResult::CircleFinderResult(bool isCircle) {
    this->isCircle = isCircle;
    this->radius = 0;
    this->centre = Point(0,0);
}

CircleFinderResult::CircleFinderResult(Point centre, int radius, bool isCircle) {
    this->isCircle = isCircle;
    this->centre = centre;
    this->radius = radius;
}
