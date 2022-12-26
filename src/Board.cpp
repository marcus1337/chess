#include "chess/Board.h"
#include <algorithm>
#include <iterator>

namespace chess {

    Board::Board() : tiles{} {
        setTilePoints();
        reset();
    }

    void Board::setTilePoints() {
        for (int file = 0; file < 8; file++) {
            for (int rank = 0; rank < 8; rank++) {
                Point point{ file, rank };
                int tileIndex = getTileIndex(point);
                tiles[tileIndex] = Tile(point);
            }
        }
    }

    void Board::removePieces() {
        for (Tile& tile : tiles) {
            tile.removePiece();
        }
    }

    int Board::getTileIndex(Point point) const {
        return point.rank * 8 + point.file;
    }

    void Board::setPiece(Point point, Piece piece) {
        tiles[getTileIndex(point)].setPiece(piece);
    }

    void Board::reset() {
        removePieces();
        resetPawns();
        resetHeavyPieces();
    }

    void Board::resetPawns() {
        for (int i = 0; i < 8; i++) {
            setPiece(Point{ i, 1 }, Piece(PieceType::PAWN, PieceColor::WHITE));
            setPiece(Point{ i, 6 }, Piece(PieceType::PAWN, PieceColor::BLACK));
        }
    }

    void Board::resetHeavyPiece(PieceType pieceType) {

    }

    PieceType Board::getInitialHeavyPieceType(int file) const {
        if (file == 0 || file == 7)
            return PieceType::ROOK;
        if (file == 1 || file == 6)
            return PieceType::KNIGHT;
        if (file == 2 || file == 5)
            return PieceType::BISHOP;
        if (file == 3)
            return PieceType::QUEEN;
        return PieceType::KING;
    }

    void Board::resetHeavyPieces() {
        for (int file = 0; file < 8; file++) {
            setPiece(file, 0, Piece(getInitialHeavyPieceType(file), PieceColor::WHITE));
            setPiece(file, 7, Piece(getInitialHeavyPieceType(file), PieceColor::BLACK));
        }
    }

    Tile Board::getTile(Point point) const {
        return tiles[getTileIndex(point)];
    }

    Tile Board::getTile(int file, int rank) const {
        return getTile(Point{ file, rank });
    }

    void Board::setPiece(int file, int rank, Piece piece) {
        setPiece(Point{ file, rank }, piece);
    }

    Point Board::getKingPoint(PieceColor kingColor) const {
        for (const Tile& tile : getOccupiedTiles(kingColor)) {
            if (tile.getPiece().getType() == PieceType::KING)
                return tile.getPoint();
        }
        return Point{-1, -1};
    }

    std::vector<Tile> Board::getOccupiedTiles(PieceColor pieceColor) const {
        std::vector<Tile> occupiedTiles;
        std::copy_if(tiles.begin(), tiles.end(), std::back_inserter(occupiedTiles),
            [pieceColor](const Tile& tile) { return tile.isOccupied() && tile.getPiece().getColor() == pieceColor; });
        return occupiedTiles;
    }

    std::vector<Tile> Board::getOccupiedTiles(Piece piece) const {
        std::vector<Tile> occupiedTiles;
        std::copy_if(tiles.begin(), tiles.end(), std::back_inserter(occupiedTiles),
            [piece](const Tile& tile) { return tile.isOccupied() && tile.getPiece() == piece; });
        return occupiedTiles;
    }

    std::vector<Tile> Board::getIntermediateOccupiedTiles(Point a, Point b) const {
        std::vector<Tile> occupiedTiles;
        for (Point midPoint : a.getIntermediatePoints(b)) {
            Tile tile = getTile(midPoint);
            if (tile.isOccupied())
                occupiedTiles.push_back(tile);
        }
        return occupiedTiles;
    }

}