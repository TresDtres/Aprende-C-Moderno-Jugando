#!/bin/bash

# Cross-platform build script for Space Colony Missions
# Supports Linux, macOS, Windows (with MSYS2 or WSL)

set -e

# Function to build a mission
build_mission() {
    local mission_dir=$1
    local executable=$2

    if [ ! -d "$mission_dir" ]; then
        echo "Mission directory $mission_dir not found."
        return 1
    fi

    cd "$mission_dir"
    mkdir -p build
    cd build

    # Detect OS
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        echo "Building on Linux..."
        cmake .. -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CXX_FLAGS="-std=c++17"
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        echo "Building on macOS..."
        cmake .. -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS="-std=c++17"
    elif [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "win32" ]]; then
        echo "Building on Windows..."
        cmake .. -G "MinGW Makefiles" -DCMAKE_CXX_FLAGS="-std=c++17"
    else
        echo "Unsupported OS: $OSTYPE"
        return 1
    fi

    make
    echo "Built $executable in $mission_dir/build/"
    cd ../..
}

# Build all missions
echo "Building Space Colony Missions..."

build_mission "mission-01-oxygen" "oxygen"
build_mission "mission-02-energy" "energy"
build_mission "mission-03-communication" "communication"
build_mission "mission-04-robot-maintenance" "robot_maintenance"
# Add more as completed

echo "All missions built successfully!"
