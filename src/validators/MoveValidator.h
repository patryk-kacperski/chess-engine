//
// Created by Patryk Kacperski on 09/07/2018.
//

#ifndef CHESS_ENGINE_MOVEVALIDATOR_H
#define CHESS_ENGINE_MOVEVALIDATOR_H


#include "../util/MoveResult.h"
#include "../util/Move.h"

namespace pkchessengine {

    class MoveValidator {
    public:
        MoveResult validate(Move move);
    private:
    };

}


#endif //CHESS_ENGINE_MOVEVALIDATOR_H
