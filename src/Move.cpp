
#include "chess/Move.h"

namespace chess {

    Move::Move(Point _from, Point _to, Piece _fromPiece) : Move(_from, _to, _fromPiece, PieceType::PAWN) {
    }

    Move::Move(Point _from, Point _to, Piece _fromPiece, Piece _capturedPiece) : Move(_from, _to, _fromPiece, _capturedPiece, _fromPiece.getType()) {
    }

    Move::Move(Point _from, Point _to, Piece _fromPiece, PieceType _promotedTo) : Move(_from, _to, _fromPiece, _fromPiece, _promotedTo) {
    }

    Move::Move(Point _from, Point _to, Piece _fromPiece, Piece _capturedPiece, PieceType _promotedTo) : from(_from), to(_to), fromPiece(_fromPiece), promotedTo(_promotedTo), capturedPiece(_capturedPiece) {
    }

    bool Move::shouldBePromotion() const {
        return fromPiece.getType() == PieceType::PAWN &&
            ((fromPiece.getColor() == PieceColor::WHITE && to.rank == 7) ||
                (fromPiece.getColor() == PieceColor::BLACK && to.rank == 0));
    }

    bool Move::isPromotion() const {
        return shouldBePromotion() && promotedTo != PieceType::PAWN && promotedTo != PieceType::KING;
    }

    std::vector<Move> Move::getPromoteMoves() const {
        return {Move(from, to, fromPiece, capturedPiece, PieceType::KNIGHT),
            Move(from, to, fromPiece, capturedPiece, PieceType::BISHOP),
            Move(from, to, fromPiece, capturedPiece, PieceType::ROOK),
            Move(from, to, fromPiece, capturedPiece, PieceType::QUEEN)};
    }

    bool Move::isCapture() const {
        return fromPiece.getColor() != capturedPiece.getColor() || isEnPassant();
    }

    bool Move::isCastle() const {
        return getFromPiece().getType() == PieceType::KING && std::abs(from.file - to.file) == 2;
    }

    bool Move::isKingSideCastle() const {
        return isCastle() && from.file < to.file;
    }

    bool Move::isQueenSideCastle() const {
        return isCastle() && from.file > to.file;
    }

    Point Move::getFrom() const {
        return from;
    }

    Point Move::getTo() const {
        return to;
    }

    Point Move::getEnPassantCapturePoint() const {
        Point to = getTo();
        if (to.rank == 2)
            return to + Point{ 0, 1 };
        else
            return to + Point{ 0, -1 };
    }

    Point Move::getCapturePoint() const {
        if (isEnPassant())
            return getEnPassantCapturePoint();
        else
            return getTo();
    }

    Piece Move::getFromPiece() const {
        return fromPiece;
    }

    Piece Move::getCapturedPiece() const {
        if (isEnPassant()) {
            PieceColor oppositeColor = fromPiece.getColor() == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
            return Piece{ PieceType::PAWN, oppositeColor };
        }
        return capturedPiece;
    }

    Piece Move::getPromotePiece() const {
        return Piece(promotedTo, fromPiece.getColor());
    }

    bool Move::isEnPassant() const {
        return fromPiece.getType() == PieceType::PAWN && from.file != to.file && !isCapture();
    }

    bool Move::isPawnPush() const {
        return fromPiece.getType() == PieceType::PAWN && from.file == to.file;
    }

    bool Move::isPawnDoublePush() const {
        return isPawnPush() && std::abs(from.rank - to.rank) == 2;
    }

}