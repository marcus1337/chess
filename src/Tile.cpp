#include "chess/Tile.h"

namespace chess {

    Tile::Tile() : Tile(Point{-1, -1}) {

    }

    Tile::Tile(Point _point) : point(_point), piece(PieceType::PAWN, PieceColor::WHITE) {

    }
    bool Tile::isOccupied() const {
        return occupied;
    }
    void Tile::removePiece() {
        occupied = false;
    }
    void Tile::setPiece(Piece _piece) {
        piece = _piece;
        occupied = true;
    }
    Piece Tile::getPiece() const {
        return piece;
    }
    Point Tile::getPoint() const {
        return point;
    }

    std::vector<Point> Tile::getPossibleEndPoints() const {
        if (!isOccupied())
            return {};
        return getPiece().getPossibleEndPoints(getPoint());
    }

}