cmake_minimum_required(VERSION 3.10)
project(Mission02-Energy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(energy_solution solution.cpp)
add_executable(energy_base base.cpp)
