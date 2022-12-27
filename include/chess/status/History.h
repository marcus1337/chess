
#ifndef CHESS_HISTORY_H
#define CHESS_HISTORY_H

#include "chess/move/Move.h"
#include "chess/board/Board.h"

namespace chess {
    class History {
        std::vector<Move> moves;
        std::vector<Board> boards;

    public:

        void clear();
        void addState(Move move, Board board);
        void removeLastState();
        const std::vector<Move>& getMoves() const;
        const std::vector<Board>& getBoards() const;
        Move getLastMove() const;

    };
}

#endif
