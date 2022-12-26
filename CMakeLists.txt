
cmake_minimum_required(VERSION 3.10)
project(chesslib)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC "src/chess.cpp" "src/Tile.cpp" "src/Point.cpp" "src/NotationInterpreter.cpp" "src/Piece.cpp" "src/Move.cpp" "include/chess/MoveValidator.h" "src/MoveValidator.cpp" "include/chess/Board.h" "src/Board.cpp" "include/chess/MoveGenerator.h" "src/MoveGenerator.cpp" "include/chess/KingThreatChecker.h" "src/KingThreatChecker.cpp")

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

