cmake_minimum_required(VERSION 3.10)
project(Mission05-InventorySurvival)

set(CMAKE_CXX_STANDARD 20)  # C++20 for ranges
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(inventory_survival solution.cpp)
