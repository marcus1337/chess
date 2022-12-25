
#ifndef PIECE_H
#define PIECE_H

#include "chess/Position.h"
#include <vector>
#include <map>
#include <utility>

namespace chess {
    enum class PieceType {
        PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
    };
    enum class PieceColor {WHITE, BLACK};

    class Piece {

        static std::vector<Position> getPossibleRelativeEndPositions(PieceType type, PieceColor color);
        static std::vector<Position> getLinePositions();
        static std::vector<Position> getDiagonalPositions();
        static std::vector<Position> getPawnPositions(PieceColor color);

    public:
        const PieceType type;
        const PieceColor color;
        Piece(PieceType _type, PieceColor _color);
        std::vector<Position> getPossibleEndPositions(Position from); //Includes illegal moves.
    };
}

#endif // !PIECE_H
