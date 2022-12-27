#include "chess.h"

namespace chess {

    Chess::Chess() : moveFinder(boardUpdater), status(boardUpdater, moveFinder) {

    }

}