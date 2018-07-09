//
// Created by Patryk Kacperski on 09/07/2018.
//

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H


#include <vector>
#include "../util/Point.h"
#include "../figures/FigureType.h"
#include "../figures/Figure.h"

namespace pkchessengine {

    class Board {
    public:
        void move(Point origin, Point destination);
        void promote(Point point, FigureType type);
        std::vector<std::vector<FigureType>> getState();
        std::unique_ptr<Figure> getFigure(Point point);
    private:
        std::vector<std::vector<std::unique_ptr<Figure>>> board;
    };

}


#endif //CHESS_ENGINE_BOARD_H
