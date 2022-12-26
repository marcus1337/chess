#include "chess/BoardUpdater.h"

namespace chess {

    Board BoardUpdater::previewMove(Move move) {
        Board boardCopy = board;
        applyMoveToBoard(move, boardCopy);
        return boardCopy;
    }

    void BoardUpdater::applyMoveToBoard(Move move, Board& board) {
        board.setPiece(move.getTo(), move.getFromPiece());
        board.removePiece(move.getFrom());
        if(move.isCapture())
            board.removePiece(move.getCapturePoint());
        PieceColor color = move.getFromPiece().getColor();
        if (move.isKingSideCastle())
            board.setPiece(move.getFrom() + Point{ 1,0 }, Piece{ PieceType::ROOK, color });
        else if (move.isQueenSideCastle())
            board.setPiece(move.getFrom() + Point{ -1,0 }, Piece{ PieceType::ROOK, color });
    }

    void BoardUpdater::revertMoveFromBoard(Move move, Board& board) {
        board.removePiece(move.getTo());
        if (move.isCapture()) {
            Point capturePoint = move.getCapturePoint();
            Piece capturedPiece = move.getCapturedPiece();
            board.setPiece(capturePoint, capturedPiece); 
        }
        board.setPiece(move.getFrom(), move.getFromPiece());
        PieceColor color = move.getFromPiece().getColor();
        int fromRank = move.getFrom().rank;
        if (move.isKingSideCastle()) {
            board.removePiece(move.getFrom() + Point{ 1,0 });
            board.setPiece(Point{ 7, fromRank }, Piece{ PieceType::ROOK, color });
        }
        else if (move.isQueenSideCastle()) {
            board.removePiece(move.getFrom() + Point{ -1,0 });
            board.setPiece(Point{ 0, fromRank }, Piece{ PieceType::ROOK, color });
        }
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

    PieceColor BoardUpdater::getTurnColor() {
        if (history.size() % 2 == 0)
            return PieceColor::WHITE;
        else
            return PieceColor::BLACK;
    }
}