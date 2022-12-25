
#ifndef POSITION_H
#define POSITION_H

#include <string>

namespace chess {
    struct Position {
        int file, rank;

        char getFileChar();
        char getRankChar();
        std::string toString();
    };
}

#endif
