cmake_minimum_required(VERSION 3.5)

project(Numeric2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NumericAlgorithm main.cpp pow.hpp fibonacci.hpp fibonacci.cpp prime.hpp simple_matrix.hpp)
