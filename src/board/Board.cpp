//
// Created by Patryk Kacperski on 09/07/2018.
//

#include "Board.h"

namespace pkchessengine {

    void Board::move(Point origin, Point destination) {

    }

    std::vector<std::vector<PieceInfo>> Board::getState() {
        return std::vector<std::vector<PieceInfo>>();
    }

    std::shared_ptr<Piece> Board::getPiece(Point point) {
        return nullptr;
    }

    void Board::promote(Point point, PieceType type) {

    }

    Board::Board() { }

    std::shared_ptr<Board> Board::create(const std::vector<std::vector<PieceInfo>>& initialState) {
        return nullptr;
    }

    bool Board::containsPoint(Point point) {
        return false;
    }

    bool Board::isOnLastRank(Point point, Side side) {
        return false;
    }

    bool Board::isCheck(Side side) {
        return false;
    }

    bool Board::isCheckMate(Side side) {
        return false;
    }

    bool Board::isStaleMate() {
        return false;
    }
}