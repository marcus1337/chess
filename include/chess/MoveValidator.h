
#ifndef CHESS_MOVEVALIDATOR_H
#define CHESS_MOVEVALIDATOR_H

#include "Move.h"
#include "Board.h"
#include "KingThreatChecker.h"

namespace chess {
    class MoveValidator {
        const Board& board;
        const std::vector<Move>& moveHistory;
        const PieceColor turnColor;

        bool canPassantTake(int toFile);
        bool canKingSideCastle();
        bool canQueenSideCastle();
        bool isCausingSelfCheck(Move move);

    std::vector<Move> getValidPromoteMoves(Move possibleMove);

    public:
        MoveValidator(const Board& _board, const std::vector<Move>& _moveHistory);
        bool isValidMove(const Move& possibleMove);
        std::vector<Move> getValidMoves(const std::vector<Move>& possibleMoves);
    };
}

#endif
