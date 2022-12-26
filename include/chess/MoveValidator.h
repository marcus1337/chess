
#ifndef CHESS_MOVEVALIDATOR_H
#define CHESS_MOVEVALIDATOR_H

#include "Move.h"
#include "Board.h"

namespace chess {
    class MoveValidator {
        const Board& board;
        const std::vector<Move>& moveHistory;
        const bool whiteToMove;

    std::vector<Move> getValidPromoteMoves(Move possibleMove);

    public:
        MoveValidator(const Board& _board, const std::vector<Move>& _moveHistory);
        bool isValidMove(const Move& possibleMove);
        std::vector<Move> getValidMoves(const std::vector<Move>& possibleMoves);
    };
}

#endif
