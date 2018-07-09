
#ifndef CHESS_ENGINE_PROMOTIONRESULT_H
#define CHESS_ENGINE_PROMOTIONRESULT_H


namespace pkchessengine {

    enum class PromotionResult {
        kValid,
        kNoFigure,
        kWrongPosition,
        kFigureIsNotPawn
    };

}


#endif //CHESS_ENGINE_PROMOTIONRESULT_H
