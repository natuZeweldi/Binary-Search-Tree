cmake_minimum_required(VERSION 3.24)
project(BinSearchTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(BinSearchTree main.cpp BinSearchTree.cpp BinSearchTree.hpp TreeNode.hpp)
