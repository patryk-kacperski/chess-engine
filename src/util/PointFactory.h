//
// Created by Patryk Kacperski on 09/07/2018.
//

#ifndef CHESS_ENGINE_POINTFACTORY_H
#define CHESS_ENGINE_POINTFACTORY_H


#include <utility>
#include <string>
#include "Point.h"

namespace pkchessengine {

    /**
     * Factory class that creates Point objects
     */
    class PointFactory {
    public:
        /**
         * Creates point out of coordinates
         */
        Point create(int x, int y);
        /**
         * Creates point out of pair of coordinates (x, y)
         */
        Point create(std::pair<int, int> point);
        /**
         * Creates point based on a string describing field (for example "A5")
         * @throw std::invalid_argument if point has length greater than 2, or first sign is not in range
         * ['A'; 'H'] or second sign is not in range ['1'; '8']
         */
        Point create(std::string point);
        /**
         * Creates pair of point based on algebraic notation notation
         * @throw std::invalid_argument if move is not valid algebraic notation of a move
         * @param move std::string describing move in algebraic notation
         * @return std::pair of points (origin, destination)
         */
        std::pair<Point, Point> createMove(std::string move);
    };

}


#endif //CHESS_ENGINE_POINTFACTORY_H
