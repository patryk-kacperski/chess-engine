
#ifndef CHESS_ENGINE_PROMOTIONRESULT_H
#define CHESS_ENGINE_PROMOTIONRESULT_H


namespace pkchessengine {

    /**
     * Enum telling whether promotion is valid. Conditions are checked in order listed here
     */
    enum class PromotionResult {
        /// promotion is valid and therefore performed
        kValid,
        /// promotion is invalid, because given position is out of board
        kOutOfBoard,
        /// promotion is invalid, because position is not on the last rank
        kWrongPosition,
        /// promotion is invalid, because there is no piece on given position
        kNoPiece,
        /// promotion is invalid, because piece on given position is not a pawn
        kPieceIsNotPawn,
        /// promotion is invalid, because piece on given position is a pawn belonging to enemy
        kWrongSide,
        /// promotion is invalid, because type received is either pawn, king or none
        kInvalidType
    };
}


#endif //CHESS_ENGINE_PROMOTIONRESULT_H
