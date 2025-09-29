#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For srand()

struct Sector {
    int damage;      // 0-100
    bool repaired;   // Initially false
};

int main() {
    const int GRID_SIZE = 5;
    std::vector<std::vector<Sector>> grid(GRID_SIZE, std::vector<Sector>(GRID_SIZE));

    srand(static_cast<unsigned>(time(0)));  // Seed random

    std::cout << "🤖 Scanning sectors for damage...\n";

    // Initialize sectors with random damage
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j].damage = rand() % 101;  // 0-100
            grid[i][j].repaired = false;
        }
    }

    // Nested loops to scan and repair
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            std::cout << "Sector [" << i << "][" << j << "]: Damage " << grid[i][j].damage << "% - ";
            if (grid[i][j].damage > 50) {
                grid[i][j].repaired = true;
                std::cout << "REPAIRED\n";
            } else {
                std::cout << "OK\n";
            }
        }
    }

    // Count repaired sectors
    int repairedCount = 0;
    for (const auto& row : grid) {
        for (const auto& sector : row) {
            if (sector.repaired) ++repairedCount;
        }
    }

    std::cout << "\n✅ Repair complete. " << repairedCount << " sectors repaired. Colony stabilized.\n";

    return 0;
}
