#include "chess/Board.h"

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

    int Board::getTileIndex(Point point) {
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

    PieceType Board::getInitialHeavyPieceType(int file) {
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

    Tile Board::getTile(Point point) {
        return tiles[getTileIndex(point)];
    }

    Tile Board::getTile(int file, int rank) {
        return getTile(Point{ file, rank });
    }

    void Board::setPiece(int file, int rank, Piece piece) {
        setPiece(Point{ file, rank }, piece);
    }

}