#include "chess/Piece.h"

namespace chess {
    Piece::Piece(PieceType _type, PieceColor _color) : type(_type), color(_color) {
    }

    std::vector<Point> Piece::getPossibleEndPoints(Point from) {
        std::vector<Point> endPositions;
        for (Point relativePosition : getPossibleRelativeEndPoints(type, color)) {
            Point endPosition = from + relativePosition;
            if (endPosition.isWithinBounds())
                endPositions.push_back(endPosition);
        }
        return endPositions;
    }

    std::vector<Point> Piece::getPossibleRelativeEndPoints(PieceType type, PieceColor color) {
        std::vector<Point> endPositions;
        using enum PieceType;
        if(type == KING)
            endPositions = { {1,0}, {1,1}, {0,1}, {-1,0}, {-1,-1}, {0,-1}, {2,0}, {-2,0} }; //Last two moves symbolize castling.
        if (type == PAWN)
            endPositions = Piece::getPawnPoints(color);
        if (type == KNIGHT)
            endPositions = { {2,1}, {1,2}, {-2,1}, {1,-2}, {-2,-1}, {-1,-2}, {2,-1}, {-1,2} };
        if (type == ROOK)
            endPositions = Piece::getLinePoints();
        if (type == BISHOP)
            endPositions = Piece::getDiagonalPoints();
        if (type == QUEEN) {
            endPositions = Piece::getLinePoints();
            auto diagonalMoves = Piece::getDiagonalPoints();
            endPositions.insert(endPositions.end(), diagonalMoves.begin(), diagonalMoves.end());
        }
        return endPositions;
    }

    std::vector<Point> Piece::getLinePoints() {
        std::vector<Point> positions;
        for (int i = 0; i < 8; i++) {
            positions.push_back({ 0,i });
            positions.push_back({ 0,-i });
            positions.push_back({ i,0 });
            positions.push_back({ -i,0 });
        }
        return positions;
    }

    std::vector<Point> Piece::getDiagonalPoints() {
        std::vector<Point> positions;
        for (int i = 0; i < 8; i++) {
            positions.push_back({ i,i });
            positions.push_back({ -i,-i });
            positions.push_back({ i,-i });
            positions.push_back({ -i,i });
        }
        return positions;
    }

    std::vector<Point> Piece::getPawnPoints(PieceColor color) {
        std::vector<Point> positions;
        std::vector <Point> promotePositions;
        if (color == PieceColor::WHITE)
            positions = { {1,1}, {0,2}, {-1,1}, {0,1} };
        else
            positions = { {1,-1}, {0,-2}, {-1,-1}, {0,-1} };
        for (int i = 3; i <= 6; i++)
            promotePositions = { {-1,i}, {1,i}, {0,i} };
        positions.insert(positions.end(), promotePositions.begin(), promotePositions.end());
        return positions;
    }

}