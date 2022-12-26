
#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

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
        PieceType type;
        PieceColor color;

    public:
        PieceType getType() const;
        PieceColor getColor() const;
        Piece(PieceType _type, PieceColor _color);
        std::vector<Point> getPossibleEndPoints(Point from); //Includes illegal moves.

        bool operator==(const Piece& other) const {
            return type == other.type && color == other.color;
        }
    };
}

#endif // !PIECE_H
