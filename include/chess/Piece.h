
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

        static std::vector<Position> getMoves(PieceType type, PieceColor color);
        static std::vector<Position> getLineMoves();
        static std::vector<Position> getDiagonalMoves();
        static std::vector<Position> getPawnMoves(PieceColor color);

    public:
        const PieceType type;
        const PieceColor color;
        Piece(PieceType _type, PieceColor _color);
        std::vector<Position> getMoves(Position from); //Also returns illegal moves.
    };
}

#endif // !PIECE_H
