
#ifndef CHESS_ENGINE_SIDE_H
#define CHESS_ENGINE_SIDE_H


namespace pkchessengine {

    /**
     * Enum telling which side should move now or to which side a piece belongs
     */
    enum class Side {
        /// white side
        kWhite,
        /// black side
        kBlack,
    };

}


#endif //CHESS_ENGINE_SIDE_H
