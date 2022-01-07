cmake_minimum_required(VERSION 3.5)

project(Bits LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bits count_bits.cpp count_bits.hpp bitboart_calculation.cpp bitboard_calculation.hpp main.cpp)
