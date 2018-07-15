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
        /**
         * Creates ChessEngine containing board in default position used in chess
         * @return ChessEngine object
         */
        std::unique_ptr<ChessEngine> create();
        /**
         * Creates ChessEngine with user defined initial board state
         * @param initialState std::vector containing user defined piece positions
         * @throw std::invalid_argument if initialState is not of shape 8x8
         * @return ChessEngine object
         */
        std::unique_ptr<ChessEngine> create(const std::vector<std::vector<PieceInfo>>& initialState);
    private:
    };

}


#endif //CHESS_ENGINE_CHESSENGINEFACTORY_H
