
#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H
#include "Point.h"
#include "Piece.h"

namespace chess {
    class Move {

        Point from, to;
        Piece fromPiece, capturedPiece;
        PieceType promotedTo;

        Move(Point _from, Point _to, Piece _fromPiece, PieceType _promotedTo);
        Move(Point _from, Point _to, Piece _fromPiece, Piece _capturedPiece, PieceType _promotedTo);

    public:

        Move(Point _from, Point _to, Piece _fromPiece);
        Move(Point _from, Point _to, Piece _fromPiece, Piece _capturedPiece);
        
        std::vector<Move> getPromoteMoves();
        bool shouldBePromotion();
        bool isPromotion();
        bool isCapture();
        bool isCastle();
        bool isKingSideCastle();
        bool isQueenSideCastle();     
        bool isEnPassant();
        Point getFrom();
        Point getTo();
        Piece getFromPiece();
        Piece getCapturedPiece();
        Piece getPromotePiece();

    };
}

#endif // !CHESS_MOVE_H
