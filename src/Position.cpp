#include "chess/Position.h"

namespace chess {

    std::string Position::toString() {
        return { getFileChar() , getRankChar() };
    }

    char Position::getFileChar() {
        return 'a' + file;;
    }

    char Position::getRankChar() {
        return '1' + rank;
    }

    bool Position::isWithinBounds() const {
        return file >= 0 && file <= 7 && rank >= 0 && rank <= 7;
    }
}