#include "chess/move/MoveFinder.h"
#include <algorithm>
#include <iterator>

namespace chess {

    MoveFinder::MoveFinder(const BoardUpdater& _boardUpdater) : moveValidator(_boardUpdater), moveGenerator(_boardUpdater.getBoard())  {

    }

    std::vector<Move> MoveFinder::getMoves(Point from) const {
        std::vector<Move> moves;
        moves = moveGenerator.getPossibleMoves(from);
        moves = moveValidator.getValidMoves(moves);
        return moves;
    }

    std::vector<Move> MoveFinder::getMoves() const {
        std::vector<Move> allMoves;
        for (int file = 0; file < 8; file++) {
            for (int rank = 0; rank < 8; rank++) {
                std::vector<Move> moves = getMoves(Point{ file, rank });
                allMoves.insert(allMoves.end(), moves.begin(), moves.end());
            }
        }
        return allMoves;
    }

}

