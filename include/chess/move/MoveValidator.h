
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

        bool isPieceMoved(int startFile, PieceType pieceType) const;
        bool isKingMoved() const;
        bool isQueenSideRookMoved() const;
        bool isKingSideRookMoved() const;

        bool canPassantTake(Move move) const;
        bool canKingSideCastle(Move move) const;
        bool canQueenSideCastle(Move move) const;
        bool canPawnDoublePush(Move move) const;
        bool isCausingSelfCheck(Move move) const;

        std::vector<Move> getValidPromoteMoves(Move possibleMove) const;
        bool isValidMove(const Move& possibleMove) const;

    public:
        MoveValidator(const BoardUpdater& _boardUpdater);
        std::vector<Move> getValidMoves(const std::vector<Move>& possibleMoves) const;
    };
}

#endif
