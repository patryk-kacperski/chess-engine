
#ifndef CHESS_ENGINE_GAMESTATUS_H
#define CHESS_ENGINE_GAMESTATUS_H


namespace pkchessengine {

    enum class GameStatus {
        kInProgress,
        kCheck,
        kCheckMate,
        kStaleMate
    };

}


#endif //CHESS_ENGINE_GAMESTATUS_H
