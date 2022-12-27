
#ifndef CHESS_MOVEFINDER_H
#define CHESS_MOVEFINDER_H

#include "MoveGenerator.h"
#include "MoveValidator.h"
#include "chess/board/BoardUpdater.h"

namespace chess {
    class MoveFinder {

        MoveValidator moveValidator;
        MoveGenerator moveGenerator;

    public:

        MoveFinder(const BoardUpdater& _boardUpdater);
        std::vector<Move> getMoves() const;
        std::vector<Move> getMoves(Point from) const;

    };
}

#endif
