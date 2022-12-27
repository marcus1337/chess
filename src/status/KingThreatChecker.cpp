#include "chess/status/KingThreatChecker.h"
#include "chess/move/MoveGenerator.h"

namespace chess {

    KingThreatChecker::KingThreatChecker(const Board& _board, PieceColor _kingColor) : board(_board), kingColor(_kingColor), checkedPoints{},
        attackColor(_kingColor == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE){
        setCheckedPoints();
    }

    void KingThreatChecker::setKingColor(PieceColor _kingColor) {
       kingColor = _kingColor;
       attackColor = _kingColor == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
       setCheckedPoints();
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

    bool KingThreatChecker::isKingChecked() const {
        Point kingPoint = board.getKingPoint(kingColor);
        return checkedPoints[kingPoint.file][kingPoint.rank];
    }

    bool KingThreatChecker::isPointChecked(Point point) const {
        return checkedPoints[point.file][point.rank];
    }

}

