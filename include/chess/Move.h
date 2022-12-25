
#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H
#include "Point.h"
#include "Piece.h"

namespace chess {
    class Move {

        Point from, to;

    public:

        void execute();
        void revert();

        bool isPromoting();
        Point getFrom();
        Point getTo(); //returns actual end-position for new pieces -- special to-moves are modified before return.

    };
}

#endif // !CHESS_MOVE_H
