
#ifndef CHESS_MOVEGENERATOR_H
#define CHESS_MOVEGENERATOR_H

#include "Board.h"
#include "Move.h"

namespace chess {

    class MoveGenerator {
        const Board& board;

    public:
        MoveGenerator(const Board& _board);

        std::vector<Move> getMoves(Point from);

    };
}

#endif
