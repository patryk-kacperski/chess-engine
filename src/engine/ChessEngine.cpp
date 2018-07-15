//
// Created by Patryk Kacperski on 08/07/2018.
//

#include "ChessEngine.h"

namespace pkchessengine {

    MoveResult ChessEngine::attemptToMove(Point origin, Point destination) {
        return MoveResult::kValid;
    }

    MoveResult ChessEngine::attemptToMove(int xOrigin, int xDestination, int yOrigin, int yDestination) {
        return MoveResult::kValid;
    }

    MoveResult ChessEngine::attemptToMove(std::pair<int, int> origin, std::pair<int, int> destination) {
        return MoveResult::kValid;
    }

    MoveResult ChessEngine::attemptToMove(const std::string& origin, const std::string& destination) {
        return MoveResult::kValid;
    }

    MoveResult ChessEngine::attemptToMove(const std::string& move) {
        return MoveResult::kValid;
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

}