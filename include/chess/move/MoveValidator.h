
#ifndef CHESS_MOVEVALIDATOR_H
#define CHESS_MOVEVALIDATOR_H

#include "Move.h"
#include "chess/board/Board.h"
#include "chess/status/KingThreatChecker.h"
#include "chess/board/BoardUpdater.h"

namespace chess {
    class MoveValidator {
        const BoardUpdater& boardUpdater;
        const Board& board;

        bool isPieceMoved(int startFile, PieceType pieceType);
        bool isKingMoved();
        bool isQueenSideRookMoved();
        bool isKingSideRookMoved();

        bool canPassantTake(Move move);
        bool canKingSideCastle(Move move);
        bool canQueenSideCastle(Move move);
        bool canPawnDoublePush(Move move);
        bool isCausingSelfCheck(Move move);

        std::vector<Move> getValidPromoteMoves(Move possibleMove);
        bool isValidMove(const Move& possibleMove);

    public:
        MoveValidator(const BoardUpdater& _boardUpdater);
        std::vector<Move> getValidMoves(const std::vector<Move>& possibleMoves);
    };
}

#endif
