
#ifndef CHESS_H
#define CHESS_H

#include "chess/board/BoardUpdater.h"
#include "chess/move/Move.h"
#include "chess/move/MoveFinder.h"
#include "chess/status/GameStatus.h"

namespace chess {
    class Chess {

        BoardUpdater boardUpdater;
        MoveFinder moveFinder;

    public:

        Chess();
        GameStatus status;

        Board getBoard();
        void reset();
        std::vector<Move> getMoves(Point from);
        std::vector<Move> getMoveHistory();
        void executeMove(Move move);
        void revertLastMove();

    };
}

#endif // !CHESS_H
