cmake_minimum_required(VERSION 3.13)
project(RoutingAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(RoutingAlgorithm main.cpp Mtx.cpp Mtx.h Algorithm.cpp Algorithm.h Graphe.cpp)