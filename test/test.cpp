
#include <iostream>
#include "chess.h"
#include "chess/Board.h"

using namespace std;

int main() {
    cout << "Testing chess...\n";
    chess::Chess chess;
    chess::Board board;
  
    std::cout << "TEST " << board.getTile(chess::Point{ 2,5 }).getPoint().rank << "\n";

    return 0;
}

