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
}