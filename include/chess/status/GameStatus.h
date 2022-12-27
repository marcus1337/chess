

#ifndef CHESS_GAMESTATUS_H
#define CHESS_GAMESTATUS_H

#include "chess/move/Move.h"
#include "chess/board/BoardUpdater.h"


//TODO add setThreeFoldRepetition
namespace chess {

    class GameStatus {

        bool staleMate = false;
        bool checkMate = false;
        bool check = false;
        bool whitePlayerTurn = true;
        const BoardUpdater& boardUpdater;

        void setCheck();
        void setCheckMate();
        void setStaleMate();
    
    public:
        GameStatus(const BoardUpdater& _boardUpdater);
        void update();
        bool isGameOver();
        bool isCheckMate();
        bool isCheck();
        bool isStaleMate();
        bool isWhitePlayerTurn();

    };

}


#endif