cmake_minimum_required(VERSION 3.5)

project(SimpleSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SimpleSort simple_sort.hpp main.cpp)
