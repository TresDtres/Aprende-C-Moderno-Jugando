#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Bonus: Implement a priority queue for restocking using lambdas

struct Resource {
    std::string name;
    int quantity;
    int threshold;
};

int main() {
    std::vector<Resource> inventory = {
        {"Food", 5, 10},
        {"Water", 15, 20},
        {"Tools", 2, 5}
    };

    // Sort by priority: lowest quantity first
    std::sort(inventory.begin(), inventory.end(), [](const Resource& a, const Resource& b) {
        return a.quantity < b.quantity;
    });

    std::cout << "Restocking Priority / Prioridad de Reabastecimiento:\n";
    for (const auto& res : inventory) {
        std::cout << res.name << " (quantity: " << res.quantity << ", threshold: " << res.threshold << ")\n";
    }

    return 0;
}
