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

    MoveResult ChessEngine::attemptToMove(std::string origin, std::string destination) {
        return MoveResult::kValid;
    }

    MoveResult ChessEngine::attemptToMove(std::string move) {
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

    std::vector<Point> ChessEngine::getPossibleMovesFor(std::string point) {
        return std::vector<Point>();
    }

    PromotionResult ChessEngine::attemptToPromote(Point point, FigureType type) {
        return PromotionResult::kValid;
    }

    PromotionResult ChessEngine::attemptToPromote(int x, int y, FigureType type) {
        return PromotionResult::kValid;
    }

    PromotionResult ChessEngine::attemptToPromote(std::pair<int, int> point, FigureType type) {
        return PromotionResult::kValid;
    }

    PromotionResult ChessEngine::attemptToPromote(std::string point, FigureType type) {
        return PromotionResult::kValid;
    }

    Side ChessEngine::isCheck() {
        return Side::kNone;
    }

    GameStatus ChessEngine::getStatus() {
        return GameStatus::kInProgress;
    }

    Side ChessEngine::getCurrentSide() {
        return currentSide;
    }

    std::vector<std::vector<FigureType>> ChessEngine::getBoard() {
        return board->getState();
    }

}