
#ifndef CHESS_BOARDUPDATER_H
#define CHESS_BOARDUPDATER_H
#include "Move.h"
#include "Board.h"

namespace chess {
    class BoardUpdater {
        Board board;
        std::vector<Move> history;

        static void applyMoveToBoard(Move move, Board& board);
        static void revertMoveFromBoard(Move move, Board& board);
    public:        
        Board previewMove(Move move) const;
        void revertMove();
        void executeMove(Move move);
        std::vector<Move> getHistory() const;
        PieceColor getTurnColor() const;
        Board getBoard() const;
    };
}

#endif