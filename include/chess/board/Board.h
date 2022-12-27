
#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Tile.h"
#include <array>

namespace chess {
    class Board {
        std::array<Tile, 64> tiles;
        int getTileIndex(Point point) const;
        void reset();
        void resetPawns();
        void resetHeavyPieces();
        void resetHeavyPiece(PieceType pieceType);
        PieceType getInitialHeavyPieceType(int file) const;
        void setTilePoints();
        void removePieces();
    public:
        Board();
        Tile getTile(Point point) const;
        Tile getTile(int file, int rank) const;
        void removePiece(Point point);
        void setPiece(Point point, Piece piece);
        void setPiece(int file, int rank, Piece piece);
        Point getKingPoint(PieceColor kingColor) const;
        std::vector<Tile> getOccupiedTiles(PieceColor pieceColor) const;
        std::vector<Tile> getOccupiedTiles(Piece piece) const;
        std::vector<Tile> getIntermediateOccupiedTiles(Point a, Point b) const;
    };
}

#endif