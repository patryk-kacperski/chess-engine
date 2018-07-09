//
// Created by Patryk Kacperski on 09/07/2018.
//

#include "Board.h"

namespace pkchessengine {

    void Board::move(Point origin, Point destination) {

    }

    std::vector<std::vector<FigureType>> Board::getState() {
        return std::vector<std::vector<FigureType>>();
    }

    std::unique_ptr<Figure> Board::getFigure(Point point) {
        return nullptr;
    }

    void Board::promote(Point point, FigureType type) {

    }
}