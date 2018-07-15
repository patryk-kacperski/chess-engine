//
// Created by Patryk Kacperski on 09/07/2018.
//

#include "PointFactory.h"

namespace pkchessengine {


    Point PointFactory::create(int x, int y) {
        return {x, y};
    }

    Point PointFactory::create(std::pair<int, int> point) {
        return {point.first, point.second};
    }

    Point PointFactory::create(std::string point) {
        return {0, 0};
    }

    std::pair<Point, Point> PointFactory::createMove(std::string move) {
        return std::make_pair(Point(0, 0), Point(0, 0));
    }
}