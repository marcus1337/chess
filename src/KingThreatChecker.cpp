#include "chess/KingThreatChecker.h"
#include "chess/MoveGenerator.h"

namespace chess {
    KingThreatChecker::KingThreatChecker(Board& _board, PieceColor& _kingColor) : board(_board), kingColor(_kingColor), checkedPoints{}, checkBlockingPoints{} {
        setCheckedPoints();
        setBlockingCheckPoints();
    }

    void KingThreatChecker::setCheckedPoints() {
        PieceColor attackColor = kingColor == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
        MoveGenerator moveGenerator(board);
        for (const Tile& tile : board.getOccupiedTiles(attackColor)) {
            for (const Move& move : moveGenerator.getPossibleMoves(tile.getPoint())) {
                if (!move.isPawnPush()) {
                    Point attackPoint = move.getTo();
                    checkedPoints[attackPoint.file][attackPoint.rank] = true;
               }
            }            
        }
    }

    void KingThreatChecker::setBlockingCheckPoints() {

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

