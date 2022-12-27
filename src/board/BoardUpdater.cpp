#include "chess/board/BoardUpdater.h"

namespace chess {

    Board BoardUpdater::previewMove(Move move) const {
        Board boardCopy = board;
        applyMoveToBoard(move, boardCopy);
        return boardCopy;
    }

    Board BoardUpdater::getBoard() const {
        return board;
    }

    void BoardUpdater::applyMoveToBoard(Move move, Board& board) {
        board.setPiece(move.getTo(), move.getFromPiece());
        board.removePiece(move.getFrom());
        if(move.isCapture())
            board.removePiece(move.getCapturePoint());
        if (move.isCastle())
            applyCastlingToBoard(move, board);
    }

    void BoardUpdater::applyCastlingToBoard(Move move, Board& board) {
        Piece rook = Piece{ PieceType::ROOK, move.getFromPiece().getColor() };
        PieceColor color = move.getFromPiece().getColor();
        if (move.isKingSideCastle())
            board.setPiece(move.getFrom() + Point{ 1,0 }, rook);
        else if (move.isQueenSideCastle())
            board.setPiece(move.getFrom() + Point{ -1,0 }, rook);
    }

    void BoardUpdater::revertMoveFromBoard(Move move, Board& board) {
        board.removePiece(move.getTo());
        if (move.isCapture())
            board.setPiece(move.getCapturePoint(), move.getCapturedPiece());
        board.setPiece(move.getFrom(), move.getFromPiece());
        if (move.isCastle())
            revertCastledRookFromBoard(move, board);
    }

    void BoardUpdater::revertCastledRookFromBoard(Move move, Board& board) {
        PieceColor color = move.getFromPiece().getColor();
        int rank = move.getFrom().rank;
        Piece rook = Piece{ PieceType::ROOK, color };
        Point rookStartPoint = move.isKingSideCastle() ? Point{ 0, rank } : Point{ 7, rank };
        Point rookEndPoint = move.isKingSideCastle() ? move.getFrom() + Point{ 1,0 } : move.getFrom() + Point{ -1,0 };
        board.removePiece(rookEndPoint);
        board.setPiece(rookStartPoint, rook);
    }

    void BoardUpdater::revertMove() {
        Move lastMove = history.back();
        revertMoveFromBoard(lastMove, board);
        history.pop_back();
    }

    void BoardUpdater::executeMove(Move move) {
        applyMoveToBoard(move, board);
        history.push_back(move);
    }

    std::vector<Move> BoardUpdater::getHistory() const {
        return history;
    }

    PieceColor BoardUpdater::getTurnColor() const {
        if (history.size() % 2 == 0)
            return PieceColor::WHITE;
        else
            return PieceColor::BLACK;
    }
}