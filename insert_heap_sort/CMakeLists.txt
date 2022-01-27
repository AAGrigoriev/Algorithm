cmake_minimum_required(VERSION 3.5)

project(insert_heap_sort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(insert_heap_sort heap_sort.hpp selection_sort.hpp main.cpp)
