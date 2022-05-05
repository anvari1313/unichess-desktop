cmake_minimum_required(VERSION 3.22)
project(unichess)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
find_package (Threads)

add_executable(unichess main.cpp)

target_link_libraries(unichess ${SDL2_LIBRARIES})
target_link_libraries (unichess Threads::Threads)
