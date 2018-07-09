//
// Created by Patryk Kacperski on 09/07/2018.
//

#include "Figure.h"

namespace pkchessengine {

    MoveResult Figure::validate(Move move) {
        return MoveResult::kValid;
    }

    std::unique_ptr<Figure> Figure::create(FigureType type) {
        return std::unique_ptr<Figure>();
    }
}