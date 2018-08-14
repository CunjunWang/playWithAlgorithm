cmake_minimum_required(VERSION 3.12)
project(MergeSort)

set(CMAKE_CXX_STANDARD 11)

add_executable(MergeSort main.cpp SortTestHelper.h InsertionSort.h)