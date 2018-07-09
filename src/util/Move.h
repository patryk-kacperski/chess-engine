
#ifndef CHESS_ENGINE_MOVE_H
#define CHESS_ENGINE_MOVE_H


#include <memory>
#include "Point.h"
#include "../board/Board.h"

namespace pkchessengine {

    struct Move {
        Point origin;
        Point destination;
        std::shared_ptr<Board> board;
        Side side;
    };

}


#endif //CHESS_ENGINE_MOVE_H
