cmake_minimum_required(VERSION 3.22)
project(unichess)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package (Threads)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(unichess main.cpp src/game.cpp src/game.h src/piece.cpp src/piece.h src/king.cpp src/king.h src/queen.cpp src/queen.h src/bishop.cpp src/bishop.h src/knight.cpp src/knight.h src/rock.cpp src/rock.h src/pawn.cpp src/pawn.h src/board.cpp src/board.h)

target_link_libraries(unichess ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries (unichess Threads::Threads)
