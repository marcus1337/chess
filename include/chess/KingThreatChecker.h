
#ifndef CHESS_KINGTHREATCHECKER_H
#define CHESS_KINGTHREATCHECKER_H

#include "Board.h"

namespace chess {
    class KingThreatChecker {
        const Board& board;
        const PieceColor kingColor;
        const PieceColor attackColor;

        std::array<std::array<bool, 8>, 8> checkedPoints;
        std::array<std::array<bool, 8>, 8> checkBlockingPoints;
        void setCheckedPoints();
        void setBlockingCheckPoints();
        std::vector<Tile> getLongRangeThreatTiles();

    public:
        KingThreatChecker(Board& _board, PieceColor& _kingColor);
        bool isKingChecked();
        bool isPointChecked(Point point);
        bool isPointBlockingCheck(Point point);
    };
}

#endif