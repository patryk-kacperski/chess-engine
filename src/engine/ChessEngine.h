//
// Created by Patryk Kacperski on 08/07/2018.
//

#ifndef CHESS_ENGINE_CHESSENGINE_H
#define CHESS_ENGINE_CHESSENGINE_H

#include <utility>
#include <string>
#include <vector>

#include "../util/MoveResult.h"
#include "../util/Point.h"
#include "../util/PromotionResult.h"
#include "../util/Side.h"
#include "../util/GameStatus.h"
#include "../util/PointFactory.h"
#include "../board/Board.h"
#include "../util/PromotionInfo.h"
#include "../util/PieceInfo.h"

namespace pkchessengine {

    /**
     * ChessEngine class is responsible for taking in commands and outputting current game state.
     * When sending command a coordinate space can be used.
     * In this space point (0, 0) corresponds to "A8" field and point (7, 7) corresponds to "H1" field.
     */
    class ChessEngine {
    public:

        /**
         * Tries to make a move. If move is valid then it is performed and side changes.
         * Otherwise game status doesn't change.
         * @param origin origin point
         * @param destination destination point
         * @return MoveResult telling if move is valid or not and why
         */
        MoveResult attemptToMove(Point origin, Point destination);
        /**
         * Creates two points and calls attemptToMove(Point origin, Point destination).
         * @sa attemptToMove(Point origin, Point destination)
         * @param xOrigin x coordinate of origin
         * @param xDestination x coordinate of destination
         * @param yOrigin y coordinate of origin
         * @param yDestination y coordinate of destination
         * @return MoveResult telling if move is valid or not and why
         */
        MoveResult attemptToMove(int xOrigin, int xDestination, int yOrigin, int yDestination);
        /**
         * Creates two points and calls attemptToMove(Point origin, Point destination).
         * @sa attemptToMove(Point origin, Point destination)
         * @param origin pair of origin coordinates (x, y)
         * @param destination pair of destination coordinates (x, y)
         * @return MoveResult telling if move is valid or not and why
         */
        MoveResult attemptToMove(std::pair<int, int> origin, std::pair<int, int> destination);
        /**
         * Creates two points and calls attemptToMove(Point origin, Point destination).
         * @sa attemptToMove(Point origin, Point destination)
         * @param origin string describing origin field (for example "B3")
         * @param destination string describing destination field
         * @return MoveResult telling if move is valid or not and why
         */
        MoveResult attemptToMove(const std::string& origin, const std::string& destination);
        /**
         * Creates two points based on algebraic notation description
         * and calls attemptToMove(Point origin, Point destination).
         * @sa attemptToMove(Point origin, Point destination)
         * @param move algebraic notation describing the move
         * @return MoveResult telling if move is valid or not and why
         */
        MoveResult attemptToMove(const std::string& move);

        /**
         * Gets all points a piece on given point can move to
         * @param point position of piece
         * @return std::vector<Point> containing all possible moves.
         * If on given point there is no piece, or there is piece of side that is not current
         * then returns empty std::vector
         */
        std::vector<Point> getPossibleMovesFor(Point point);
        /**
         * Creates a point and calls getPossibleMovesFor(Point point)
         * @sa getPossibleMovesFor(Point point)
         * @param x x coordinate of point
         * @param y y coordinate of point
         * @return std::vector<Point> containing all possible moves.
         * If on given point there is no piece, or there is piece of side that is not current
         * then returns empty std::vector
         */
        std::vector<Point> getPossibleMovesFor(int x, int y);
        /**
         * Creates a point and calls getPossibleMovesFor(Point point)
         * @sa getPossibleMovesFor(Point point)
         * @param point pair of coordinates (x, y)
         * @return std::vector<Point> containing all possible moves.
         * If on given point there is no piece, or there is piece of side that is not current
         * then returns empty std::vector
         */
        std::vector<Point> getPossibleMovesFor(std::pair<int, int> point);
        /**
         * Creates a point and calls getPossibleMovesFor(Point point)
         * @sa getPossibleMovesFor(Point point)
         * @param point string describing field (for example "B3")
         * @return std::vector<Point> containing all possible moves.
         * If on given point there is no piece, or there is piece of side that is not current
         * then returns empty std::vector
         */
        std::vector<Point> getPossibleMovesFor(const std::string& point);

        /**
         * Tries to promote a pawn. If correct (last line) field containing
         * pawn of current side is passed then promotion is valid and performed.
         * Otherwise it's not performed
         * @param point Position of piece
         * @param type Type of piece pawn should be promoted to
         * @return PromotionResult telling if promotion is valid or not and why.
         */
        PromotionResult attemptToPromote(Point point, PieceType type);
        /**
         * Creates a point and calls attemptToPromote(Point point, PieceType type)
         * @sa attemptToPromote(Point point, PieceType type)
         * @param x x coordinate of a point
         * @param y y coordinate of a point
         * @param type type of piece pawn should be promoted to
         * @return PromotionResult telling if promotion is valid or not and why
         */
        PromotionResult attemptToPromote(int x, int y, PieceType type);
        /**
         * Creates a point and calls attemptToPromote(Point point, PieceType type)
         * @sa attemptToPromote(Point point, PieceType type)
         * @param point pair of coordinates (x, y)
         * @param type type of piece pawn should be promoted to
         * @return PromotionResult telling if promotion is valid or not and why
         */
        PromotionResult attemptToPromote(std::pair<int, int> point, PieceType type);
        /**
         * Creates a point and calls attemptToPromote(Point point, PieceType type)
         * @sa attemptToPromote(Point point, PieceType type)
         * @param point string describing field (for example "B3")
         * @param type type of piece pawn should be promoted to
         * @return PromotionResult telling if promotion is valid or not and why
         */
        PromotionResult attemptToPromote(const std::string& point, PieceType type);

        /**
         * Returns current side
         * @return Side containing current side
         */
        Side getCurrentSide();
        /**
         * Checks and returns game status (for example check, check mate etc.)
         * @sa GameStatus
         * @return GameStatus telling the status of the game
         */
        GameStatus getStatus();
        /**
         * Tells if promotion should be performed. If it should, information about position is also returned
         * @sa PromotionProposition
         * @return PromotionProposition with information about possible promotion
         */
        PromotionInfo shouldPromote();
        /**
         * Returns information about current board state. Vector has always size of 8x8. Each value contained in vector
         * corresponds to one piece occupying it. If value in vector is equal to PieceType::none then this field is
         * empty
         * @return std::vector<std::vector<PieceType>> with current board state
         */
        std::vector<std::vector<PieceInfo>> getBoard();

    private:
        /// Current side
        Side currentSide;
        /// Factory object that creates points
        PointFactory pointFactory;
        /// current status of the game
        GameStatus currentStatus;
        /// Board object holding all pieces
        std::shared_ptr<Board> board;

        /// Checks if the game ended
        bool isGameOver();
        /// Fills vector of possible moves for a piece
        void fillPossibleMoves(std::shared_ptr<Piece> piece, Point origin, std::vector<Point> &moves);
        /// Function called after move validation
        void performMove(Point origin, Point destination);
        /// Changes current side
        void changeSide();
        /// Checks and updates game status
        void updateStatus();
    };

}


#endif //CHESS_ENGINE_CHESSENGINE_H