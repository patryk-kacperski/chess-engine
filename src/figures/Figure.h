//
// Created by Patryk Kacperski on 09/07/2018.
//

#ifndef CHESS_ENGINE_FIGURE_H
#define CHESS_ENGINE_FIGURE_H


#include "../util/Side.h"
#include "FigureType.h"
#include "../validators/MoveValidator.h"
#include "../util/MoveResult.h"
#include "../util/Move.h"

namespace pkchessengine {

    class Figure {
    public:
        MoveResult validate(Move move);
        static std::unique_ptr<Figure> create(FigureType type);
    private:
        Side side;
        FigureType type;
        MoveValidator validator;
    };

}


#endif //CHESS_ENGINE_FIGURE_H
