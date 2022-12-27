
#ifndef CHESS_MOVEGENERATOR_H
#define CHESS_MOVEGENERATOR_H

#include "chess/board/Board.h"
#include "Move.h"

namespace chess {

    class MoveGenerator {
        const Board& board;
        bool isPathBlocked(Tile fromTile, Tile toTile) const;
        bool isCastlingBlocked(Move castleMove) const;
        Move getMove(Tile fromTile, Tile toTile) const;

    public:
        MoveGenerator(const Board& _board);
        std::vector<Move> getPossibleMoves(Point from) const;
    };
}

#endif
