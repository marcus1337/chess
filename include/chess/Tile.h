
#ifndef CHESS_TILE_H
#define CHESS_TILE_H

#include "Point.h"
#include "Piece.h"

namespace chess {
    class Tile {
        Point point;
        Piece piece;
        bool occupied = false;

    public:
        Tile();
        Tile(Point _point);
        bool isOccupied() const;
        bool contains(Piece _piece) const;
        void removePiece();
        void setPiece(Piece _piece);
        Piece getPiece() const;
        Point getPoint() const;
        std::vector<Point> getPossibleEndPoints() const;
    };
}

#endif // !TILE_H
