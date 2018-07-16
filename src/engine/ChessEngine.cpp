//
// Created by Patryk Kacperski on 08/07/2018.
//

#include "ChessEngine.h"

namespace pkchessengine {

    MoveResult ChessEngine::attemptToMove(Point origin, Point destination) {
        if (isGameOver()) {
            return MoveResult::kGameIsOver;
        } else if (shouldPromote().shouldPromote) {
            return MoveResult::kPromotionShouldBePerformed;
        } else if (!(board->containsPoint(origin) && board->containsPoint(destination))) {
            return MoveResult::kOutOfBoard;
        }
        auto piece = board->getPiece(origin);
        if (piece == nullptr) {
            return MoveResult::kNoPieceAtOrigin;
        } else if (piece->getSide() != currentSide) {
            return MoveResult::kWrongSidePieceAtOrigin;
        }
        Move move {origin, destination, board, currentSide};
        MoveResult result = piece->validate(move);
        return result;
    }

    MoveResult ChessEngine::attemptToMove(int xOrigin, int xDestination, int yOrigin, int yDestination) {
        Point originPoint = pointFactory.create(xOrigin, yOrigin);
        Point destinationPoint = pointFactory.create(xDestination, yDestination);
        return attemptToMove(originPoint, destinationPoint);
    }

    MoveResult ChessEngine::attemptToMove(std::pair<int, int> origin, std::pair<int, int> destination) {
        Point originPoint = pointFactory.create(origin);
        Point destinationPoint = pointFactory.create(destination);
        return attemptToMove(originPoint, destinationPoint);
    }

    MoveResult ChessEngine::attemptToMove(const std::string& origin, const std::string& destination) {
        Point originPoint = pointFactory.create(origin);
        Point destinationPoint = pointFactory.create(destination);
        return attemptToMove(originPoint, destinationPoint);
    }

    MoveResult ChessEngine::attemptToMove(const std::string& move) {
        auto points = pointFactory.createMove(move);
        if (points.first == Point::invalid() || points.second == Point::invalid()) {
            return MoveResult::kInvalidAlgebraicNotation;
        }
        return attemptToMove(points.first, points.second);
    }

    std::vector<Point> ChessEngine::getPossibleMovesFor(Point point) {
        return std::vector<Point>();
    }

    std::vector<Point> ChessEngine::getPossibleMovesFor(int x, int y) {
        return std::vector<Point>();
    }

    std::vector<Point> ChessEngine::getPossibleMovesFor(std::pair<int, int> point) {
        return std::vector<Point>();
    }

    std::vector<Point> ChessEngine::getPossibleMovesFor(const std::string& point) {
        return std::vector<Point>();
    }

    PromotionResult ChessEngine::attemptToPromote(Point point, PieceType type) {
        return PromotionResult::kValid;
    }

    PromotionResult ChessEngine::attemptToPromote(int x, int y, PieceType type) {
        return PromotionResult::kValid;
    }

    PromotionResult ChessEngine::attemptToPromote(std::pair<int, int> point, PieceType type) {
        return PromotionResult::kValid;
    }

    PromotionResult ChessEngine::attemptToPromote(const std::string& point, PieceType type) {
        return PromotionResult::kValid;
    }

    GameStatus ChessEngine::getStatus() {
        return currentStatus;
    }

    Side ChessEngine::getCurrentSide() {
        return currentSide;
    }

    std::vector<std::vector<PieceInfo>> ChessEngine::getBoard() {
        return board->getState();
    }

    PromotionInfo ChessEngine::shouldPromote() {
        return PromotionInfo {false};
    }

    bool ChessEngine::isGameOver() {
        return false;
    }

}