#include "chess/MoveValidator.h"

namespace chess {

    MoveValidator::MoveValidator(const BoardUpdater& _boardUpdater) : board(_boardUpdater.getBoard()), moveHistory(_boardUpdater.getHistory()),
        turnColor(_boardUpdater.getTurnColor()), boardUpdater(_boardUpdater) {

    }

    bool MoveValidator::isCausingSelfCheck(Move move) {
        Board boardCopy = boardUpdater.previewMove(move);
        KingThreatChecker kingThreatChecker(boardCopy, turnColor);
        return kingThreatChecker.isKingChecked();
    }

    bool MoveValidator::isValidMove(const Move& move) {
        if (move.getFromPiece().getColor() != turnColor)
            return false;
        if (move.isKingSideCastle() && !canKingSideCastle(move))
            return false;
        if (move.isQueenSideCastle() && !canQueenSideCastle(move))
            return false;
        if (move.isEnPassant() && !canPassantTake(move))
            return false;
      

        return !isCausingSelfCheck(move);
    }

    std::vector<Move> MoveValidator::getValidPromoteMoves(Move possibleMove) {
        std::vector<Move> validMoves;
        if (!possibleMove.isPromotion() && possibleMove.shouldBePromotion()) {
            for (const Move& promoteMove : possibleMove.getPromoteMoves()) {
                if (isValidMove(promoteMove)) {
                    validMoves.push_back(promoteMove);
                }
            }
        }
        return validMoves;
    }

    std::vector<Move> MoveValidator::getValidMoves(const std::vector<Move>& possibleMoves) {
        std::vector<Move> validMoves;
        for (const Move& possibleMove : possibleMoves) {
            for (const Move& validPromoteMove : getValidPromoteMoves(possibleMove))
                validMoves.push_back(validPromoteMove);
            if (isValidMove(possibleMove))
                validMoves.push_back(possibleMove);
        }
        return validMoves;
    }

}