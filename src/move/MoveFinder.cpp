#include "chess/move/MoveFinder.h"

namespace chess {

    MoveFinder::MoveFinder(const BoardUpdater& _boardUpdater) : moveValidator(_boardUpdater), moveGenerator(_boardUpdater.getBoard())  {

    }

    std::vector<Move> MoveFinder::getMoves(Point from) {
        std::vector<Move> moves;
        moves = moveGenerator.getPossibleMoves(from);
        moves = moveValidator.getValidMoves(moves);
        return moves;
    }

}

