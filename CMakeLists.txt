
cmake_minimum_required(VERSION 3.10)
project(chesslib)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC "src/chess.cpp" 
"src/board/Tile.cpp" "src/board/Point.cpp" "src/NotationInterpreter.cpp" 
"src/board/Piece.cpp" "src/move/Move.cpp" "src/move/MoveValidator.cpp" 
"src/board/Board.cpp" "src/move/MoveGenerator.cpp" "src/KingThreatChecker.cpp" 
"src/board/BoardUpdater.cpp" "src/GameStatus.cpp")

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

