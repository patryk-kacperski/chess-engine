//
// Created by Patryk Kacperski on 09/07/2018.
//

#include "ChessEngineFactory.h"

namespace pkchessengine {

    std::unique_ptr<ChessEngine> ChessEngineFactory::create() {
        return nullptr;
    }

    std::unique_ptr<ChessEngine> ChessEngineFactory::create(std::vector<std::vector<FigureType>> initialState) {
        return nullptr;
    }
}