#include "chess/board/Piece.h"

namespace chess {
    Piece::Piece(PieceType _type, PieceColor _color) : type(_type), color(_color) {
    }

    std::vector<Point> Piece::getPossibleEndPoints(Point from) {
        std::vector<Point> endPoints;
        for (Point relativeEndPoint : getPossibleRelativeEndPoints(type, color)) {
            Point endPoint = from + relativeEndPoint;
            if (endPoint.isWithinBounds())
                endPoints.push_back(endPoint);
        }
        return endPoints;
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
        if (color == PieceColor::WHITE)
            positions = { {1,1}, {0,2}, {-1,1}, {0,1} };
        else
            positions = { {1,-1}, {0,-2}, {-1,-1}, {0,-1} };
        return positions;
    }

    PieceType Piece::getType() const {
        return type;
    }

    PieceColor Piece::getColor() const {
        return color;
    }

}