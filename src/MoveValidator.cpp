#include "chess/MoveValidator.h"

namespace chess {

    MoveValidator::MoveValidator(const BoardUpdater& _boardUpdater) : board(_boardUpdater.getBoard()), moveHistory(_boardUpdater.getHistory()),
        turnColor(_boardUpdater.getTurnColor()), boardUpdater(_boardUpdater), kingThreatChecker(board, turnColor) {

    }

    bool MoveValidator::isCausingSelfCheck(Move move) {
        Board boardCopy = boardUpdater.previewMove(move);
        KingThreatChecker tempKingThreatChecker(boardCopy, turnColor);
        return tempKingThreatChecker.isKingChecked();
    }

    bool MoveValidator::isKingMoved() {

        return false;
    }
    bool MoveValidator::isQueenSideRookMoved() {

        return false;
    }
    bool MoveValidator::isKingSideRookMoved() {

        return false;
    }

    bool MoveValidator::canPassantTake(Move move) {
        return false;
    }

    bool MoveValidator::canKingSideCastle(Move move) {
        if (isKingMoved() || isKingSideRookMoved())
            return false;
        if (kingThreatChecker.isKingChecked())
            return false;
        if (kingThreatChecker.isPointChecked(move.getTo()))
            return false;
        if (kingThreatChecker.isPointChecked(move.getTo() + Point{ -1,0 }))
            return false;
        return true;
    }

    bool MoveValidator::canQueenSideCastle(Move move) {
        if (isKingMoved() || isQueenSideRookMoved())
            return false;
        if (kingThreatChecker.isKingChecked())
            return false;
        if (kingThreatChecker.isPointChecked(move.getTo()))
            return false;
        if (kingThreatChecker.isPointChecked(move.getTo() + Point{1,0}))
            return false;
        return true;
    }

    bool MoveValidator::canPawnDoublePush(Move move) {
        return (move.getFrom().rank == 1 && move.getFromPiece().getColor() == PieceColor::WHITE) ||
            (move.getFrom().rank == 6 && move.getFromPiece().getColor() == PieceColor::BLACK);
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