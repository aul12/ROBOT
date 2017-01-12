/**
 * @file CircleFinderResult.cpp
 * @author Paul Nykiel, Tim Luchterhand
 */

#include "CircleFinderResult.hpp"

/**
 * Constructor to generate a new object with zero radius and a centre at (0,0).
 * This is usually used to generate a non-circle object.
 * @param isCircle
 * @see CircleFinderResult(Point centre, int radius, bool isCircle)
 */
CircleFinderResult::CircleFinderResult(bool isCircle) {
    this->isCircle = isCircle;
    this->radius = 0;
    this->centre = Point(0,0);
}