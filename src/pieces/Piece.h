//
// Created by Patryk Kacperski on 09/07/2018.
//

#ifndef CHESS_ENGINE_PIECE_H
#define CHESS_ENGINE_PIECE_H

#include "../validators/MoveValidator.h"
#include "../util/MoveResult.h"
#include "../util/Move.h"
#include "../util/PieceInfo.h"
#include "PieceType.h"

namespace pkchessengine {

    /**
     * Piece class keeps information about piece and validator to check if moves are correct
     */
    class Piece {
    public:
        /**
         * Piece class constructor
         * @param side side of a piece
         * @param type type of a piece
         */
        Piece(Side side, PieceType type);

        /**
         * Validates given move.
         * @param move Move object containing details move details
         * @sa Move
         * @return MoveResult object
         */
        MoveResult validate(Move move);
        /**
         * Changes Piece's type and validator according to given type
         * @warning this function doesn't check if type is correct or if promoted piece is in fact a pawn
         * @param type Type that pawn should be promoted to
         */
        void promote(PieceType type);

        Side getSide();
        PieceType getType();
    private:
        /// information about piece's position and side
        PieceInfo info;
        /// MoveValidator object that is used to check if move is valid
        MoveValidator validator;
    };

}


#endif //CHESS_ENGINE_PIECE_H
