
#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H
#include "Point.h"
#include "Piece.h"

namespace chess {
    class Move {

        Point from, to;
        Piece movedPiece, capturedPiece;
        
        static bool isPromoteMove(Point endPoint, Piece piece);
        static std::vector<Move> getPromoteMoves(Point from, Point to, Piece piece);

    public:

        Move(Point _from, Point _to);

        bool isLegal(); //board input parameter

        void execute();
        void revert();

        Point getFrom();
        Point getTo();

    };
}

#endif // !CHESS_MOVE_H
