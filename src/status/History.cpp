#include "chess/status/History.h"

namespace chess {

    void History::clear() {
        moves.clear();
        boards.clear();
    }

    void History::addState(Move move, Board board) {
        moves.push_back(move);
        boards.push_back(board);
    }

    void History::removeLastState() {
        moves.pop_back();
        boards.pop_back();
    }

    Move History::getLastMove() const {
        return moves[moves.size() - 1];
    }

    const std::vector<Move>& History::getMoves() const {
        return moves;
    }

    const std::vector<Board>& History::getBoards() const {
        return boards;
    }

}