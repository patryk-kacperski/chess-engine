//
// Created by Patryk Kacperski on 08/07/2018.
//

#ifndef CHESS_ENGINE_MOVERESULT_H
#define CHESS_ENGINE_MOVERESULT_H

namespace pkchessengine {

    /**
     * Enum telling if move is valid. Conditions are checked in order listed here
     */
    enum class MoveResult {
        /// Move is valid and therefore performed
        kValid,
        /// Cannot perform move, because the game is over
        kGameIsOver,
        /// Cannot perform move, because pawn should be promoted first
        kPromotionShouldBePerformed,
        /// Move is invalid, because one of points is out of board
        kOutOfBoard,
        /// Move is invalid, because there is no piece at the origin
        kNoPieceAtOrigin,
        /// Move is invalid, because there is no friendly piece at the origin
        kWrongSidePieceAtOrigin,
        /// Move is invalid, because friendly piece is at the destination
        kFriendlyPieceAtDestination,
        /// Move is invalid, because it is against the rules of chess
        kIllegal,
        /// Move is invalid, because it would expose kind to a check
        kExposesKing,
        /// Move is invalid, because path is blocked by another piece is on the way
        kPathBloceked,
        /// Move is invalid according to algebraic notation
        kInvalidAlgebraicNotation
    };

}



#endif //CHESS_ENGINE_MOVERESULT_H
