
#ifndef CHESS_H
#define CHESS_H

#include "chess/board/BoardUpdater.h"
#include "chess/move/Move.h"

namespace chess {
    class Chess {

        BoardUpdater boardUpdater;

    public:

        Board getBoard();
        void reset();
        bool isGameOver();
        bool isDraw();
        bool isCheckMate();
        bool isCheck();
        bool isWhitePlayerTurn();
        bool canClaimDrawByRepetition();
        void claimDrawByRepetition();

        std::vector<Move> getMoves(Point from);
        std::vector<Move> getMoveHistory();
        void executeMove(Move move);
        void revertLastMove();

    };
}

#endif // !CHESS_H
