#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

// Simple test for inventory functions
struct Resource {
    std::string name;
    int quantity;
    int threshold;
};

void testAddResource() {
    std::vector<Resource> inventory;
    inventory.push_back({"Food", 50, 10});
    assert(inventory.size() == 1);
    assert(inventory[0].name == "Food");
    std::cout << "Test addResource passed.\n";
}

void testConsumeResource() {
    std::vector<Resource> inventory = {{"Food", 50, 10}};
    auto it = std::find_if(inventory.begin(), inventory.end(), [](const Resource& r) { return r.name == "Food"; });
    if (it != inventory.end() && it->quantity >= 15) {
        it->quantity -= 15;
    }
    assert(inventory[0].quantity == 35);
    std::cout << "Test consumeResource passed.\n";
}

int main() {
    testAddResource();
    testConsumeResource();
    std::cout << "All tests passed!\n";
    return 0;
}
