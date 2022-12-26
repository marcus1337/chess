#include "chess/MoveValidator.h"

namespace chess {

    MoveValidator::MoveValidator(const Board& _board, const std::vector<Move>& _moveHistory) : board(_board), moveHistory(_moveHistory), 
        turnColor((moveHistory.size() % 2) == 0 ? PieceColor::WHITE : PieceColor::BLACK) {

    }

    bool MoveValidator::isCausingSelfCheck(Move move) {
        Board boardCopy = board;

        KingThreatChecker kingThreatChecker(boardCopy, turnColor);
        return kingThreatChecker.isKingChecked();
    }

    bool MoveValidator::isValidMove(const Move& move) {
        if (move.getFromPiece().getColor() != turnColor)
            return false;
 
        return false;
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