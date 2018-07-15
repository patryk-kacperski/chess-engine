
#ifndef CHESS_ENGINE_GAMESTATUS_H
#define CHESS_ENGINE_GAMESTATUS_H


namespace pkchessengine {

    enum class GameStatus {
        /// Game is in progress
        kInProgress,
        /// Current side is under check
        kCheck,
        /// Current side is under check mate and lost, game is over
        kCheckMate,
        /// A stalemate has occurred, game is over
        kStaleMate
    };

}


#endif //CHESS_ENGINE_GAMESTATUS_H
