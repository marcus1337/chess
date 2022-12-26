
#include "chess/Move.h"

namespace chess {

    bool Move::shouldBePromotion() {
        return fromPiece.getType() == PieceType::PAWN &&
            ((fromPiece.getColor() == PieceColor::WHITE && to.rank == 7) ||
                (fromPiece.getColor() == PieceColor::BLACK && to.rank == 0));
    }

    bool Move::isPromotion() {
        return shouldBePromotion() && promotedTo != PieceType::PAWN && promotedTo != PieceType::KING;
    }
}