
#ifndef CHESS_ENGINE_FIGUREINFO_H
#define CHESS_ENGINE_FIGUREINFO_H


#include "Side.h"
#include "../pieces/PieceType.h"

namespace pkchessengine {

    /**
     * FigureInfo struct contains basic information about the figure
     */
    struct PieceInfo {
        /// type of figure
        PieceType type;
        /// side of figure
        Side side;
    };

}


#endif //CHESS_ENGINE_FIGUREINFO_H
