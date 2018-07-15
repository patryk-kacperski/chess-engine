
#ifndef CHESS_ENGINE_MOVE_H
#define CHESS_ENGINE_MOVE_H


#include <memory>
#include "Point.h"
#include "Side.h"

namespace pkchessengine {

    class Board; // forward declaration of Board class

    struct Move {
        /// origin point of move
        Point origin;
        /// destination point of move
        Point destination;
        /// pointer to board on which the move should be performed
        std::shared_ptr<Board> board;
        /// side of the moving piece
        Side side;
    };

}


#endif //CHESS_ENGINE_MOVE_H
