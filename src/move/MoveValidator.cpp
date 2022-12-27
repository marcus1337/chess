#include "chess/move/MoveValidator.h"

namespace chess {

    MoveValidator::MoveValidator(const BoardUpdater& _boardUpdater) : board(_boardUpdater.getBoard()), moveHistory(_boardUpdater.getHistory()),
        turnColor(_boardUpdater.getTurnColor()), boardUpdater(_boardUpdater), kingThreatChecker(board, turnColor) {

    }

    bool MoveValidator::isCausingSelfCheck(Move move) {
        Board boardCopy = boardUpdater.previewMove(move);
        KingThreatChecker tempKingThreatChecker(boardCopy, turnColor);
        return tempKingThreatChecker.isKingChecked();
    }

    bool MoveValidator::isPieceMoved(int startFile, PieceType pieceType) {
        int rank = turnColor == PieceColor::WHITE ? 0 : 7;
        Piece piece = Piece{ pieceType, turnColor };
        Point startPoint = Point{ startFile, rank };
        if (!board.getTile(startPoint).contains(piece))
            return true;
        for (const Move& move : moveHistory) {
            if (move.getFrom() == startPoint)
                return true;
        }
        return false;
    }

    bool MoveValidator::isKingMoved() {
        return isPieceMoved(5, PieceType::KING);
    }
    bool MoveValidator::isQueenSideRookMoved() {
        return isPieceMoved(0, PieceType::ROOK);
    }
    bool MoveValidator::isKingSideRookMoved() {
        return isPieceMoved(7, PieceType::ROOK);
    }

    bool MoveValidator::canPassantTake(Move move) {
        if (moveHistory.empty())
            return false;
        Move lastMove = moveHistory.back();
        if (!lastMove.isPawnDoublePush() || lastMove.getTo().file != move.getTo().file)
            return false;
        return move.getTo().rank == 2 || move.getTo().rank == 5;
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