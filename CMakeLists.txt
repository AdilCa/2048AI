cmake_minimum_required(VERSION 3.27)
project(2048AI)

set(CMAKE_CXX_STANDARD 20)

link_libraries(libeasyx.a)

include_directories(include src)

add_executable(2048AI main.cpp
        src/game.cpp
        include/game.h)
