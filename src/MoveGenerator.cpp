#include "chess/MoveGenerator.h"

namespace chess {

    MoveGenerator::MoveGenerator(const Board& _board) : board(_board) {

    }

    bool MoveGenerator::isPathBlocked(Tile fromTile, Tile toTile) {
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

    Move MoveGenerator::getMove(Tile fromTile, Tile toTile) {
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

    std::vector<Move> MoveGenerator::getPossibleMoves(Point from) {
        Tile fromTile = board.getTile(from);
        if (!fromTile.isOccupied())
            return {};

        std::vector<Move> possibleMoves;
        for (Point to : fromTile.getPossibleEndPoints()) {
            Tile toTile = board.getTile(to);
            if (!isPathBlocked(fromTile, toTile)) {
                possibleMoves.push_back(getMove(fromTile, toTile));
            }
        }
        return possibleMoves;
    }

}