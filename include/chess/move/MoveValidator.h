
#ifndef CHESS_MOVEVALIDATOR_H
#define CHESS_MOVEVALIDATOR_H

#include "Move.h"
#include "chess/board/Board.h"
#include "chess/KingThreatChecker.h"
#include "chess/board/BoardUpdater.h"

namespace chess {
    class MoveValidator {
        const BoardUpdater& boardUpdater;
        const Board board;
        const std::vector<Move> moveHistory;
        const PieceColor turnColor;
        const KingThreatChecker kingThreatChecker;

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

    public:
        MoveValidator(const BoardUpdater& _boardUpdater);
        bool isValidMove(const Move& possibleMove);
        std::vector<Move> getValidMoves(const std::vector<Move>& possibleMoves);
    };
}

#endif
