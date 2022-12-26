#include "chess/Point.h"

namespace chess {

    std::string Point::toString() {
        return { getFileChar() , getRankChar() };
    }

    char Point::getFileChar() {
        return 'a' + file;;
    }

    char Point::getRankChar() {
        return '1' + rank;
    }

    bool Point::isWithinBounds() const {
        return file >= 0 && file <= 7 && rank >= 0 && rank <= 7;
    }

    void Point::stepTowards(Point goalPoint) {
        if (file < goalPoint.file)
            file++;
        else if (file > goalPoint.file)
            file--;
        if (rank < goalPoint.rank)
            rank++;
        else if (rank > goalPoint.rank)
            rank--;
    }

    bool Point::isOnSameDiagonal(Point other) const {
        return std::abs(file - other.file) == std::abs(rank - other.rank);
    }

    bool Point::isOnSameLine(Point other) const {
        return file == other.file || rank == other.rank;
    }

    std::vector<Point> Point::getIntermediatePoints(Point other) const {
        if ((!isOnSameDiagonal(other) && !isOnSameLine(other)) || *this == other)
            return {};
        std::vector<Point> midPoints;
        Point midPoint = *this;
        midPoint.stepTowards(other);
        while (midPoint != other) {
            midPoints.push_back(midPoint);
            midPoint.stepTowards(other);
        }
        return midPoints;
    }

}