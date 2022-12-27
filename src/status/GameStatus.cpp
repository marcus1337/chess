#include "chess/status/GameStatus.h"
#include "chess/status/KingThreatChecker.h"

namespace chess {

    GameStatus::GameStatus(const BoardUpdater& _boardUpdater, const MoveFinder& _moveFinder) : boardUpdater(_boardUpdater), moveFinder(_moveFinder) {

    }

    void GameStatus::update() {
        setCheck();
        setCheckMate();
        setStaleMate();
    }

    void GameStatus::setCheck() {
        KingThreatChecker kingThreatChecker(boardUpdater.getBoard(), boardUpdater.getTurnColor());
        check = kingThreatChecker.isKingChecked();
    }

    void GameStatus::setCheckMate() {
        checkMate = isCheck() && moveFinder.getMoves().empty();
    }

    void GameStatus::setStaleMate() {
        staleMate = !isCheck() && moveFinder.getMoves().empty();
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
        return boardUpdater.getTurnColor() == PieceColor::WHITE;
    }

}
