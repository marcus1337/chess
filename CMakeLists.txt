
cmake_minimum_required(VERSION 3.10)
project(chesslib)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC "src/chess.cpp" "include/chess/Tile.h" "src/Tile.cpp" "include/chess/Position.h" "src/Position.cpp" "include/chess/NotationInterpreter.h" "src/NotationInterpreter.cpp" "include/chess/Piece.h"  "src/Piece.cpp")

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

