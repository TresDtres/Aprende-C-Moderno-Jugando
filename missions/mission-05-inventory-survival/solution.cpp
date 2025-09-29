#include <iostream>
#include <vector>
#include <string>
#include <ranges>  // C++20
#include <algorithm>  // For sort if needed
#include <optional>   // For error handling

struct Resource {
    std::string name;
    int quantity;
    int threshold;
};

std::optional<Resource> addResource(std::vector<Resource>& inventory, const std::string& name, int qty, int thresh) {
    if (qty < 0 || thresh < 0) return std::nullopt;  // Error handling
    inventory.push_back({name, qty, thresh});
    return inventory.back();
}

void consumeResource(std::vector<Resource>& inventory, const std::string& name, int amount) {
    auto it = std::find_if(inventory.begin(), inventory.end(), [&name](const Resource& r) { return r.name == name; });
    if (it != inventory.end() && it->quantity >= amount) {
        it->quantity -= amount;
    }
}

int main() {
    std::vector<Resource> inventory;

    std::cout << "📦 Colony Inventory Management (English)\n";
    std::cout << "Gestión de Inventario de la Colonia (Español)\n\n";

    // Add initial resources
    addResource(inventory, "Food", 50, 10);
    addResource(inventory, "Water", 100, 20);
    addResource(inventory, "Tools", 30, 5);

    // Consume some
    consumeResource(inventory, "Food", 15);
    consumeResource(inventory, "Water", 30);

    // Filter low-stock items (using std::find_if for C++17 compatibility)
    std::vector<Resource> lowStock;
    std::copy_if(inventory.begin(), inventory.end(), std::back_inserter(lowStock), [](const Resource& r) { return r.quantity < r.threshold; });

    std::cout << "Current Inventory / Inventario Actual:\n";
    for (const auto& res : inventory) {
        std::cout << res.name << ": " << res.quantity << " (threshold: " << res.threshold << ")\n";
    }

    std::cout << "\nLow Stock Items / Artículos de Bajo Stock:\n";
    for (const auto& res : lowStock) {
        std::cout << res.name << " is low! / " << res.name << " está bajo!\n";
    }

    // Lambda for sorting by quantity
    std::sort(inventory.begin(), inventory.end(), [](const Resource& a, const Resource& b) {
        return a.quantity < b.quantity;
    });

    std::cout << "\nSorted by Quantity / Ordenado por Cantidad:\n";
    for (const auto& res : inventory) {
        std::cout << res.name << ": " << res.quantity << "\n";
    }

    return 0;
}
