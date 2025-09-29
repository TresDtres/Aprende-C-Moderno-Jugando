cmake_minimum_required(VERSION 3.10)
project(Mission07-ControlCenter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable with internationalization support
add_executable(control_center solution.cpp LanguageManager.cpp)
