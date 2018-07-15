//
// Created by Patryk Kacperski on 09/07/2018.
//

#include "Piece.h"

namespace pkchessengine {

    MoveResult Piece::validate(Move move) {
        return MoveResult::kValid;
    }

    Piece::Piece(Side side, PieceType type)
    { }
}