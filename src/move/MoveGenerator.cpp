#include "chess/move/MoveGenerator.h"

namespace chess {

    MoveGenerator::MoveGenerator(const Board& _board) : board(_board) {

    }

    bool MoveGenerator::isCastlingBlocked(Move castleMove) const {
        int rank = castleMove.getFrom().rank;
        std::vector<Tile> midTiles;
        if (castleMove.isQueenSideCastle())
            midTiles = board.getIntermediateOccupiedTiles(castleMove.getFrom(), Point{ 0, rank });
        if (castleMove.isKingSideCastle())
            midTiles = board.getIntermediateOccupiedTiles(castleMove.getFrom(), Point{ 7, rank });
        return !midTiles.empty();
    }

    bool MoveGenerator::isPathBlocked(Tile fromTile, Tile toTile) const {
        Piece fromPiece = fromTile.getPiece();
        if (toTile.isOccupied() && toTile.getPiece().getColor() == fromPiece.getColor())
            return true;

        Point from = fromTile.getPoint();
        Point to = toTile.getPoint();
        if (fromPiece.getType() == PieceType::PAWN && from.file == to.file && toTile.isOccupied()) {
            return true;
        }

        if (fromPiece.getType() != PieceType::KNIGHT) {
            for (Point midPoint : from.getIntermediatePoints(to)) {
                if (board.getTile(midPoint).isOccupied())
                    return true;
            }
        }
        return false;
    }

    Move MoveGenerator::getMove(Tile fromTile, Tile toTile) const {
        bool capture = toTile.isOccupied();
        Point from = fromTile.getPoint();
        Point to = toTile.getPoint();
        if (capture) {
            return Move(from, to, fromTile.getPiece(), toTile.getPiece());
        }
        else {
            return Move(from, to, fromTile.getPiece());
        }
    }

    std::vector<Move> MoveGenerator::getPossibleMoves(Point from) const {
        Tile fromTile = board.getTile(from);
        if (!fromTile.isOccupied())
            return {};

        std::vector<Move> possibleMoves;
        for (Point to : fromTile.getPossibleEndPoints()) {
            Tile toTile = board.getTile(to);
            if (!isPathBlocked(fromTile, toTile)) {
                Move move = getMove(fromTile, toTile);
                if(!(move.isCastle() && isCastlingBlocked(move)))
                    possibleMoves.push_back(move);
            }
        }
        return possibleMoves;
    }

}