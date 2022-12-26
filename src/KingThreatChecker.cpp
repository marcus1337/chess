#include "chess/KingThreatChecker.h"
#include "chess/MoveGenerator.h"

namespace chess {
    KingThreatChecker::KingThreatChecker(Board& _board, PieceColor& _kingColor) : board(_board), kingColor(_kingColor), checkedPoints{}, checkBlockingPoints{}, 
        attackColor(_kingColor == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE) {
        setCheckedPoints();
        setBlockingCheckPoints();
    }

    void KingThreatChecker::setCheckedPoints() {
        MoveGenerator moveGenerator(board);
        for (const Tile& tile : board.getOccupiedTiles(attackColor)) {
            for (const Move& move : moveGenerator.getPossibleMoves(tile.getPoint())) {
                if (!move.isPawnPush() && !move.isCastle()) {
                    Point attackPoint = move.getTo();
                    checkedPoints[attackPoint.file][attackPoint.rank] = true;
               }
            }            
        }
    }

    std::vector<Tile> KingThreatChecker::getLongRangeThreatTiles() {
        std::vector<Tile> tiles;
        Point kingPoint = board.getKingPoint(kingColor);

        for (const Tile& tile : board.getOccupiedTiles(Piece{ PieceType::BISHOP, attackColor })) {
            if (tile.getPoint().isOnSameDiagonal(kingPoint))
                tiles.push_back(tile);
        }
        for (const Tile& tile : board.getOccupiedTiles(Piece{ PieceType::ROOK, attackColor })) {
            if (tile.getPoint().isOnSameLine(kingPoint))
                tiles.push_back(tile);
        }
        for (const Tile& tile : board.getOccupiedTiles(Piece{ PieceType::QUEEN, attackColor })) {
            Point tilePoint = tile.getPoint();
            if (tilePoint.isOnSameLine(kingPoint) || tilePoint.isOnSameDiagonal(kingPoint))
                tiles.push_back(tile);
        }
        return tiles;
    }

    void KingThreatChecker::setBlockingCheckPoints() {
        Point kingPoint = board.getKingPoint(kingColor);

        for (const Tile& tile : getLongRangeThreatTiles()) {
            std::vector<Tile> midTiles = board.getIntermediateOccupiedTiles(kingPoint, tile.getPoint());
            if (midTiles.size() == 1) {
                Point midPoint = midTiles[0].getPoint();
                checkBlockingPoints[midPoint.file][midPoint.rank] = true;
            }
        }
    }

    bool KingThreatChecker::isKingChecked() {
        Point kingPoint = board.getKingPoint(kingColor);
        return checkedPoints[kingPoint.file][kingPoint.rank];
    }

    bool KingThreatChecker::isPointChecked(Point point) {
        return checkedPoints[point.file][point.rank];
    }

    bool KingThreatChecker::isPointBlockingCheck(Point point) {
        return checkBlockingPoints[point.file][point.rank];
    }

}

