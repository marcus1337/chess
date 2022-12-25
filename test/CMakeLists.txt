cmake_minimum_required(VERSION 3.0)
project(test_project)

add_subdirectory("${PROJECT_SOURCE_DIR}/.." "${CMAKE_CURRENT_BINARY_DIR}/chesslib")

add_executable(${PROJECT_NAME} "test.cpp")

target_link_libraries(${PROJECT_NAME} chesslib)
