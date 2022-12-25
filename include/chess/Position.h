
#ifndef POSITION_H
#define POSITION_H

#include <string>

namespace chess {
    struct Position {
        int file, rank;

        char getFileChar();
        char getRankChar();
        std::string toString();

        bool operator==(const Position& other) const {
            return file == other.file && rank == other.rank;
        }
        Position operator+(const Position& other) const {
            return { file + other.file, rank + other.rank };
        }

        bool isWithinBounds() const;
    };
}

#endif
