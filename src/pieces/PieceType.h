
#ifndef CHESS_ENGINE_PIECETYPE_H
#define CHESS_ENGINE_PIECETYPE_H


namespace pkchessengine {

    /**
     * Type of a piece
     */
    enum class PieceType {
        /// Pawn
        kPawn,
        /// Rook
        kRook,
        /// Bishop
        kBishop,
        /// Knight
        kKnight,
        /// King
        kKing,
        /// Queen
        kQueen,
        /// Empty field
        kNone
    };

}


#endif //CHESS_ENGINE_PIECETYPE_H
