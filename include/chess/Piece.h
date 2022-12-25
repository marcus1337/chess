
#ifndef PIECE_H
#define PIECE_H

#include "chess/Point.h"
#include <vector>
#include <map>
#include <utility>

namespace chess {
    enum class PieceType {
        PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
    };
    enum class PieceColor {WHITE, BLACK};

    class Piece {

        static std::vector<Point> getPossibleRelativeEndPoints(PieceType type, PieceColor color);
        static std::vector<Point> getLinePoints();
        static std::vector<Point> getDiagonalPoints();
        static std::vector<Point> getPawnPoints(PieceColor color);

    public:
        const PieceType type;
        const PieceColor color;
        Piece(PieceType _type, PieceColor _color);
        std::vector<Point> getPossibleEndPoints(Point from); //Includes illegal moves.
    };
}

#endif // !PIECE_H
