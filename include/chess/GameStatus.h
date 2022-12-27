

#ifndef CHESS_GAMESTATUS_H
#define CHESS_GAMESTATUS_H

#include "move/Move.h"
#include "board/Board.h"

namespace chess {

    class GameStatus {

        bool draw = false;
        bool staleMate = false;
        std::vector<Move> moveHistory;
        Board board;
    
    public:

        void update(std::vector<Move> moveHistory, Board board);
        bool isGameOver();
        bool isDraw();
        bool isCheckMate();
        bool isCheck();
        bool isStaleMate();
        bool isWhitePlayerTurn();
        bool canClaimDrawByRepetition();
        void claimDrawByRepetition();

    };

}


#endif