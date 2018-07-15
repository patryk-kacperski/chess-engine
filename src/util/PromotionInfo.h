
#ifndef CHESS_ENGINE_PROMOTIONPROPOSITION_H
#define CHESS_ENGINE_PROMOTIONPROPOSITION_H


#include "Point.h"

namespace pkchessengine {

    /**
     * struct that hold information about promotion
     */
    struct PromotionInfo {
        /// Tells whether or not promotion should be performed
        bool shouldPromote;
        /**
         * Tells where the promotion should be performed. If shouldPromote is false, then position is (0, 0)
         */
        Point position;

        PromotionInfo(bool shouldPromote) : shouldPromote(shouldPromote), position(Point{0, 0})
        {}

        PromotionInfo(bool shouldPromote, Point position) : shouldPromote(shouldPromote), position(position)
        {}


    };

}


#endif //CHESS_ENGINE_PROMOTIONPROPOSITION_H
