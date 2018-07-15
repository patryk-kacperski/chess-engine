
#ifndef CHESS_ENGINE_POINT_H
#define CHESS_ENGINE_POINT_H


namespace pkchessengine {

    struct Point {
        /// x coordinate of a point
        int x;
        /// y coordinate of a point
        int y;

        Point(int x, int y) : x(x), y(y)
        {}
    };

}


#endif //CHESS_ENGINE_POINT_H
