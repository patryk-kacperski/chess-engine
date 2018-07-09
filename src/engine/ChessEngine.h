//
// Created by Patryk Kacperski on 08/07/2018.
//

#ifndef CHESS_ENGINE_CHESSENGINE_H
#define CHESS_ENGINE_CHESSENGINE_H

#include <utility>
#include <string>
#include <vector>
#include "../util/MoveResult.h"
#include "../util/Point.h"
#include "../util/PromotionResult.h"
#include "../figures/FigureType.h"
#include "../util/Side.h"
#include "../util/GameStatus.h"
#include "../util/PointFactory.h"
#include "../board/Board.h"

namespace pkchessengine {

    class ChessEngine {
    public:
        MoveResult attemptToMove(Point origin, Point destination);
        MoveResult attemptToMove(int xOrigin, int xDestination, int yOrigin, int yDestination);
        MoveResult attemptToMove(std::pair<int, int> origin, std::pair<int, int> destination);
        MoveResult attemptToMove(std::string origin, std::string destination);
        MoveResult attemptToMove(std::string move);

        std::vector<Point> getPossibleMovesFor(Point point);
        std::vector<Point> getPossibleMovesFor(int x, int y);
        std::vector<Point> getPossibleMovesFor(std::pair<int, int> point);
        std::vector<Point> getPossibleMovesFor(std::string point);

        PromotionResult attemptToPromote(Point point, FigureType type);
        PromotionResult attemptToPromote(int x, int y, FigureType type);
        PromotionResult attemptToPromote(std::pair<int, int> point, FigureType type);
        PromotionResult attemptToPromote(std::string point, FigureType type);

        Side isCheck();
        Side getCurrentSide();
        GameStatus getStatus();
        std::vector<std::vector<FigureType>> getBoard();

    private:
        Side currentSide;
        PointFactory pointFactory;
        std::shared_ptr<Board> board;
    };

}


#endif //CHESS_ENGINE_CHESSENGINE_H