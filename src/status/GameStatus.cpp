#include "chess/status/GameStatus.h"

namespace chess {

    GameStatus::GameStatus(const BoardUpdater& _boardUpdater) : boardUpdater(_boardUpdater) {

    }

    void GameStatus::update() {
        whitePlayerTurn = boardUpdater.getTurnColor() == PieceColor::WHITE;
        setCheck();
        setCheckMate();
        setStaleMate();
    }

    void GameStatus::setCheck() {
        check = false;
    }

    void GameStatus::setCheckMate() {
        checkMate = false;
    }

    void GameStatus::setStaleMate() {
        staleMate = false;
    }

    bool GameStatus::isGameOver() {
        return isStaleMate() || isCheckMate();
    }

    bool GameStatus::isCheckMate() {
        return checkMate;
    }

    bool GameStatus::isCheck() {
        return check;
    }

    bool GameStatus::isStaleMate() {
        return staleMate;
    }

    bool GameStatus::isWhitePlayerTurn() {
        return whitePlayerTurn;
    }

}
