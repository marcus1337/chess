
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
        Point getEnPassantCapturePoint() const;

    public:

        Move(Point _from, Point _to, Piece _fromPiece);
        Move(Point _from, Point _to, Piece _fromPiece, Piece _capturedPiece);
        
        std::vector<Move> getPromoteMoves() const;
        bool shouldBePromotion() const;
        bool isPromotion() const;
        bool isCapture() const;
        bool isCastle() const;
        bool isKingSideCastle() const;
        bool isQueenSideCastle() const;     
        bool isEnPassant() const;
        bool isPawnPush() const;
        Point getFrom() const;
        Point getTo() const;
        Point getCapturePoint() const;
        Piece getFromPiece() const;
        Piece getCapturedPiece() const;
        Piece getPromotePiece() const;

    };
}

#endif // !CHESS_MOVE_H
