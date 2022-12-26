
#ifndef CHESS_POINT_H
#define CHESS_POINT_H
#include <string>
#include <vector>

namespace chess {

    struct Point {
        int file, rank;

        char getFileChar();
        char getRankChar();
        std::string toString();

        std::vector<Point> getIntermediatePoints(Point other) const;
        void stepTowards(Point goalPoint);

        bool isOnSameDiagonal(Point other) const;
        bool isOnSameLine(Point other) const;

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
