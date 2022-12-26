
#ifndef CHESS_MOVEVALIDATOR_H
#define CHESS_MOVEVALIDATOR_H

#include "Move.h"

namespace chess {
    class MoveValidator {
    public:
        MoveValidator();
        bool isValidMove(const Move& move);
    };
}

#endif
