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
        if (result == MoveResult::kValid) {
            performMove();
        }
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
        std::vector<Point> moves;
        if (board->containsPoint(point)) {
            auto piece = board->getPiece(point);
            if (piece != nullptr && piece->getSide() == currentSide) {
                fillPossibleMoves(piece, point, moves);
            }
        }
        return moves;
    }

    std::vector<Point> ChessEngine::getPossibleMovesFor(int x, int y) {
        Point point = pointFactory.create(x, y);
        return getPossibleMovesFor(point);
    }

    std::vector<Point> ChessEngine::getPossibleMovesFor(std::pair<int, int> point) {
        Point piecePoint = pointFactory.create(point);
        return getPossibleMovesFor(piecePoint);
    }

    std::vector<Point> ChessEngine::getPossibleMovesFor(const std::string& point) {
        Point piecePoint = pointFactory.create(point);
        return getPossibleMovesFor(piecePoint);
    }

    PromotionResult ChessEngine::attemptToPromote(Point point, PieceType type) {
        if (!board->containsPoint(point)) {
            return PromotionResult::kOutOfBoard;
        } else if (!board->isOnLastRank(point, currentSide)) {
            return PromotionResult::kWrongPosition;
        }
        auto piece = board->getPiece(point);
        if (piece == nullptr) {
            return PromotionResult::kNoPiece;
        } else if (piece->getType() != PieceType::kPawn) {
            return PromotionResult::kPieceIsNotPawn;
        } else if (piece->getSide() != currentSide) {
            return PromotionResult::kWrongSide;
        } else if (type == PieceType::kPawn || type == PieceType::kNone || type == PieceType::kKing) {
            return PromotionResult::kInvalidType;
        }
        performPromotion();
        return PromotionResult::kValid;
    }

    PromotionResult ChessEngine::attemptToPromote(int x, int y, PieceType type) {
        Point point = pointFactory.create(x, y);
        return attemptToPromote(point, type);
    }

    PromotionResult ChessEngine::attemptToPromote(std::pair<int, int> point, PieceType type) {
        Point piecePoint = pointFactory.create(point);
        return attemptToPromote(piecePoint, type);
    }

    PromotionResult ChessEngine::attemptToPromote(const std::string& point, PieceType type) {
        Point piecePoint = pointFactory.create(point);
        return attemptToPromote(piecePoint, type);
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
        int rank {currentSide == Side::kWhite ? 0 : 7};
        for (int file = 0; file < 8; ++file) {
            Point point = pointFactory.create(file, rank);
            auto piece = board->getPiece(point);
            if (piece != nullptr && piece->getType() == PieceType::kPawn && piece->getSide() == currentSide) {
                return {true, point};
            }
        }
        return {false};
    }

    bool ChessEngine::isGameOver() {
        return (currentStatus == GameStatus::kCheckMate || currentStatus == GameStatus::kStaleMate);
    }

    void ChessEngine::fillPossibleMoves(std::shared_ptr<Piece> piece, Point origin, std::vector<Point> &moves) {
        for (int rank = 0; rank < 8; ++rank) {
            for (int file = 0; file < 8; ++file) {
                Point destination = pointFactory.create(file, rank);
                Move move {origin, destination, board, currentSide};
                MoveResult result = piece->validate(move);
                if (result == MoveResult::kValid) {
                    moves.push_back(destination);
                }
            }
        }
    }

    void ChessEngine::performMove() {

    }

    void ChessEngine::performPromotion() {

    }

}