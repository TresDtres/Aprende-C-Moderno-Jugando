#include <iostream>
#include <array>  // C++11 std::array for fixed-size, safer than raw arrays
#include <cstdlib>
#include <ctime>

struct Sector {
    int damage;
    bool repaired;
};

int main() {
    constexpr int GRID_SIZE = 5;  // constexpr for compile-time constant
    std::array<std::array<Sector, GRID_SIZE>, GRID_SIZE> grid{};  // Initialize to zero

    srand(static_cast<unsigned>(time(0)));

    std::cout << "🤖 Bonus: Scanning sectors with std::array...\n";

    // Initialize
    for (auto& row : grid) {
        for (auto& sector : row) {
            sector.damage = rand() % 101;
            sector.repaired = false;
        }
    }

    // Nested loops (range-based for modern C++)
    for (auto& row : grid) {
        for (auto& sector : row) {
            std::cout << "Sector: Damage " << sector.damage << "% - ";
            if (sector.damage > 50) {
                sector.repaired = true;
                std::cout << "REPAIRED\n";
            } else {
                std::cout << "OK\n";
            }
        }
    }

    // Count repaired
    int repairedCount = 0;
    for (const auto& row : grid) {
        for (const auto& sector : row) {
            if (sector.repaired) ++repairedCount;
        }
    }

    std::cout << "\n✅ Bonus complete. " << repairedCount << " sectors repaired using std::array.\n";

    return 0;
}
