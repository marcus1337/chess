
#ifndef CHESS_KINGTHREATCHECKER_H
#define CHESS_KINGTHREATCHECKER_H

#include "chess/board/Board.h"

namespace chess {
    class KingThreatChecker {
        const Board& board;
        const PieceColor kingColor;
        const PieceColor attackColor;

        std::array<std::array<bool, 8>, 8> checkedPoints;
        //std::array<std::array<bool, 8>, 8> checkBlockingPoints;
        void setCheckedPoints();
        //void setBlockingCheckPoints();
        //std::vector<Tile> getLongRangeThreatTiles();

    public:
        KingThreatChecker(const Board& _board, PieceColor _kingColor);
        bool isKingChecked() const;
        bool isPointChecked(Point point) const;
        //bool isPointBlockingCheck(Point point) const;
    };
}

#endif