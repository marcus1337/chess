
#include "chess/Move.h"

namespace chess {


    bool Move::isPromoteMove(Point endPoint, Piece piece) {
        return piece.getType() == PieceType::PAWN &&
            (   (piece.getColor() == PieceColor::WHITE && endPoint.rank == 7) || 
                (piece.getColor() == PieceColor::BLACK && endPoint.rank == 0)   );
    }
}