cmake_minimum_required(VERSION 3.5)

project(BST LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BST bst.hpp avl_tree.hpp main.cpp)
