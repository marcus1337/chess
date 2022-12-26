
#ifndef CHESS_POINT_H
#define CHESS_POINT_H
#include <string>

namespace chess {

    struct Point {
        int file, rank;

        char getFileChar();
        char getRankChar();
        std::string toString();

        void stepTowards(Point goalPoint);

        bool operator==(const Point& other) const {
            return file == other.file && rank == other.rank;
        }
        Point operator+(const Point& other) const {
            return { file + other.file, rank + other.rank };
        }

        bool isWithinBounds() const;
    };
}

#endif
