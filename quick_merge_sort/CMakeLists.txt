cmake_minimum_required(VERSION 3.5)

project(quick_merge_sort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(quick_merge_sort counting_sort.hpp file_sort.hpp merge_sort.hpp quick_sort.hpp bucket_sort.hpp file_sort.cpp main.cpp)
