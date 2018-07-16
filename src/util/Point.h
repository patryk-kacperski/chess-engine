
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

        /**
         * Invalid point
         */
        static Point invalid() {
            return {-1, -1};
        }

        bool operator==(const Point &other) {
            return x == other.x && y == other.y;
        }
    };

}


#endif //CHESS_ENGINE_POINT_H
