#include "chess.h"

namespace chess {

    Chess::Chess() : moveFinder(boardUpdater), gameStatus(boardUpdater, moveFinder) {

    }

    Board Chess::getBoard() {
        return boardUpdater.getBoard();
    }

    void Chess::reset() {
        boardUpdater.reset();
        gameStatus.update();
    }

    std::vector<Move> Chess::getMoves(Point from) {
        return moveFinder.getMoves(from);
    }

    std::vector<Move> Chess::getMoveHistory() {
        return boardUpdater.getHistory().getMoves();
    }

    void Chess::executeMove(Move move) {
        boardUpdater.executeMove(move);
        gameStatus.update();
    }

    void Chess::revertLastMove() {
        boardUpdater.revertMove();
        gameStatus.update();
    }

}