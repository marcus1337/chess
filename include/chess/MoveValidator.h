
#ifndef CHESS_MOVEVALIDATOR_H
#define CHESS_MOVEVALIDATOR_H

#include "Move.h"
#include "Board.h"
#include "KingThreatChecker.h"
#include "BoardUpdater.h"

namespace chess {
    class MoveValidator {
        const BoardUpdater& boardUpdater;
        const Board board;
        const std::vector<Move> moveHistory;
        const PieceColor turnColor;
        const KingThreatChecker kingThreatChecker;

        bool isKingMoved();
        bool isQueenSideRookMoved();
        bool isKingSideRookMoved();

        bool canPassantTake(Move move);
        bool canKingSideCastle(Move move);
        bool canQueenSideCastle(Move move);
        bool canPawnDoublePush(Move move);
        bool isCausingSelfCheck(Move move);

        std::vector<Move> getValidPromoteMoves(Move possibleMove);

    public:
        MoveValidator(const BoardUpdater& _boardUpdater);
        bool isValidMove(const Move& possibleMove);
        std::vector<Move> getValidMoves(const std::vector<Move>& possibleMoves);
    };
}

#endif
