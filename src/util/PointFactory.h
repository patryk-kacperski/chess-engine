//
// Created by Patryk Kacperski on 09/07/2018.
//

#ifndef CHESS_ENGINE_POINTFACTORY_H
#define CHESS_ENGINE_POINTFACTORY_H


#include <utility>
#include <string>
#include "Point.h"

namespace pkchessengine {

    class PointFactory {
    public:
        Point create(int x, int y);
        Point create(std::pair<int, int> point);
        Point create(std::string point);
        std::pair<Point, Point> createMove(std::string move);
    };

}


#endif //CHESS_ENGINE_POINTFACTORY_H
