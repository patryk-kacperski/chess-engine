//
// Created by Patryk Kacperski on 08/07/2018.
//

#ifndef CHESS_ENGINE_MOVERESULT_H
#define CHESS_ENGINE_MOVERESULT_H

namespace pkchessengine {

    enum class MoveResult {
        kValid,
        kOutOfBoard,
        kIllegal,
        kExposesKing,
        kOwnFigureAtDestination,
        kPathBloceked,
        kNoFigureAtOrigin,
        kWrongSideFigureAtOrigin
    };

}



#endif //CHESS_ENGINE_MOVERESULT_H
