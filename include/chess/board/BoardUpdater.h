
#ifndef CHESS_BOARDUPDATER_H
#define CHESS_BOARDUPDATER_H

#include "chess/board/Board.h"
#include "chess/move/Move.h"
#include "chess/status/History.h"

namespace chess {
    class BoardUpdater {
        Board board;
        History history;

        static void applyCastlingToBoard(Move move, Board& board);
        static void applyMoveToBoard(Move move, Board& board);
        static void revertMoveFromBoard(Move move, Board& board);
        static void revertCastledRookFromBoard(Move move, Board& board);
    public:        
        Board previewMove(Move move) const;
        void revertMove();
        void executeMove(Move move);
        const History& getHistory() const;
        PieceColor getTurnColor() const;
        const Board& getBoard() const;
    };
}

#endif