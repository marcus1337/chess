#include "chess/Point.h"

namespace chess {

    std::string Point::toString() {
        return { getFileChar() , getRankChar() };
    }

    char Point::getFileChar() {
        return 'a' + file;;
    }

    char Point::getRankChar() {
        return '1' + rank;
    }

    bool Point::isWithinBounds() const {
        return file >= 0 && file <= 7 && rank >= 0 && rank <= 7;
    }
}