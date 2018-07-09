//
// Created by Patryk Kacperski on 09/07/2018.
//

#ifndef CHESS_ENGINE_CHESSENGINEFACTORY_H
#define CHESS_ENGINE_CHESSENGINEFACTORY_H


#include <memory>
#include "ChessEngine.h"

namespace pkchessengine {

    class ChessEngineFactory {
    public:
        std::unique_ptr<ChessEngine> create();
        std::unique_ptr<ChessEngine> create(std::vector<std::vector<FigureType>> initialState);
    private:
    };

}


#endif //CHESS_ENGINE_CHESSENGINEFACTORY_H
