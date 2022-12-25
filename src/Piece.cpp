#include "chess/Piece.h"

namespace chess {
    Piece::Piece(PieceType _type, PieceColor _color) : type(_type), color(_color) {
    }

    std::vector<Position> Piece::getMoves(Position from) {
        std::vector<Position> moves;

        return moves;
    }
    std::vector<Position> Piece::getMoves(PieceType type, PieceColor color) {
        std::vector<Position> moves;
        using enum PieceType;
        if(type == KING)
            moves = { {1,0}, {1,1}, {0,1}, {-1,0}, {-1,-1}, {0,-1}, {2,0}, {-2,0} }; //Last two moves symbolize castling.
        if (type == PAWN)
            moves = Piece::getPawnMoves(color);
        if (type == KNIGHT)
            moves = { {2,1}, {1,2}, {-2,1}, {1,-2}, {-2,-1}, {-1,-2}, {2,-1}, {-1,2} };
        if (type == ROOK)
            moves = Piece::getLineMoves();
        if (type == BISHOP)
            moves = Piece::getDiagonalMoves();
        if (type == QUEEN) {
            moves = Piece::getLineMoves();
            auto diagonalMoves = Piece::getDiagonalMoves();
            moves.insert(moves.end(), diagonalMoves.begin(), diagonalMoves.end());
        }
        return moves;
    }

    std::vector<Position> Piece::getLineMoves() {
        std::vector<Position> moves;
        for (int i = 0; i < 8; i++) {
            moves.push_back({ 0,i });
            moves.push_back({ 0,-i });
            moves.push_back({ i,0 });
            moves.push_back({ -i,0 });
        }
        return moves;
    }

    std::vector<Position> Piece::getDiagonalMoves() {
        std::vector<Position> moves;
        for (int i = 0; i < 8; i++) {
            moves.push_back({ i,i });
            moves.push_back({ -i,-i });
            moves.push_back({ i,-i });
            moves.push_back({ -i,i });
        }
        return moves;
    }

    std::vector<Position> Piece::getPawnMoves(PieceColor color) {
        std::vector<Position> moves;
        std::vector <Position> promoteMoves;
        if (color == PieceColor::WHITE)
            moves = { {1,1}, {0,2}, {-1,1}, {0,1} };
        else
            moves = { {1,-1}, {0,-2}, {-1,-1}, {0,-1} };
        for (int i = 3; i <= 6; i++)
            promoteMoves = { {-1,i}, {1,i}, {0,i} };
        moves.insert(moves.end(), promoteMoves.begin(), promoteMoves.end());
        return moves;
    }

}