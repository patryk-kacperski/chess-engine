//
// Created by Patryk Kacperski on 09/07/2018.
//

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H


#include <vector>
#include "../util/Point.h"
#include "../util/PieceInfo.h"
#include "../pieces/Piece.h"


namespace pkchessengine {

    /**
     * Board class keeps all the pieces and interacts with them
     */
    class Board {
    public:
        /**
         * Perform move from origin to destination
         * @warning this function assumes, that passed points make valid move and doesn't check it
         * @param origin origin point
         * @param destination destination point
         */
        void move(Point origin, Point destination);
        /**
         * Promote pawn
         * @warning this function assumes, that passed point is valid for promotion and doesn't check it
         * @param point point where promotion should be performed
         * @param type type of piece pawn should be promoted to
         */
        void promote(Point point, PieceType type);
        /**
         * Returns state of the board
         * @sa ChessEngine::std::vector<std::vector<PieceInfo>> getState()
         * @return std::vector<std::vector<PieceType>> with current board state
         */
        std::vector<std::vector<PieceInfo>> getState();
        /**
         * Returns piece on given point
         * @throw std::invalid_argument if any of the coordinates is lower than 0 or greater than 7
         * @param point Point where the piece is
         * @return pointer to a piece. nullptr if field is empty
         */
        std::shared_ptr<Piece> getPiece(Point point);
        /**
         * Factory method for creating Board object from initial state. It is the only way to create
         * Board object, since default constructor is private
         * @throw std::invalid_argument if initialState is not of shape 8x8
         * @param initialState std::vector containing initial piece positions
         * @return pointer to newly created Board object
         */
        static std::shared_ptr<Board> create(const std::vector<std::vector<PieceInfo>>& initialState);
    private:
        /// vector of pieces
        std::vector<std::vector<std::shared_ptr<Piece>>> board;
        /// default constructor
        Board();
    };

}


#endif //CHESS_ENGINE_BOARD_H
