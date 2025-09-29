#include <iostream>
#include <vector>

struct Sector {
    int damage;
    bool repaired;
};

int main() {
    std::vector<std::vector<Sector>> grid(2, std::vector<Sector>(2));  // Small 2x2 for test

    // Set test data
    grid[0][0] = {60, false};
    grid[0][1] = {40, false};
    grid[1][0] = {80, false};
    grid[1][1] = {20, false};

    int repaired = 0;
    for (auto& row : grid) {
        for (auto& sector : row) {
            if (sector.damage > 50) {
                sector.repaired = true;
                ++repaired;
            }
        }
    }

    if (repaired == 2) {  // 60 and 80
        std::cout << "✅ Test passed: 2 sectors repaired\n";
    } else {
        std::cout << "❌ Test failed: " << repaired << " sectors repaired\n";
    }

    return 0;
}

// Compile: g++ test_robot.cpp -o test && ./test
