
#ifndef CHESS_MOVEGENERATOR_H
#define CHESS_MOVEGENERATOR_H

#include "Board.h"
#include "Move.h"

namespace chess {

    class MoveGenerator {
        const Board& board;
        bool isPathBlocked(Tile fromTile, Tile toTile);
        Move getMove(Tile fromTile, Tile toTile);

    public:
        MoveGenerator(const Board& _board);
        std::vector<Move> getPossibleMoves(Point from);
    };
}

#endif
