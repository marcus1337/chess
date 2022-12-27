
#ifndef CHESS_KINGTHREATCHECKER_H
#define CHESS_KINGTHREATCHECKER_H

#include "chess/board/Board.h"

namespace chess {
    class KingThreatChecker {
        const Board& board;
        PieceColor kingColor;
        PieceColor attackColor;

        std::array<std::array<bool, 8>, 8> checkedPoints;
        void setCheckedPoints();

    public:
        KingThreatChecker(const Board& _board, PieceColor _kingColor);
        void setKingColor(PieceColor _kingColor);
        bool isKingChecked() const;
        bool isPointChecked(Point point) const;
    };
}

#endif