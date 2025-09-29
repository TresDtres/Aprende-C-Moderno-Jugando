#include <iostream>
#include <vector>
#include <memory>

// Bonus: Add modules (C++20) for system separation

// Assume module interface (for demonstration, using headers)
class System {
public:
    virtual void status() const = 0;
    virtual ~System() = default;
};

class MaintenanceSystem : public System {
public:
    void status() const override {
        std::cout << "Maintenance System: All sectors operational / Todos los sectores operativos\n";
    }
};

int main() {
    std::vector<std::unique_ptr<System>> systems;
    systems.push_back(std::make_unique<MaintenanceSystem>());

    for (const auto& sys : systems) {
        sys->status();
    }

    return 0;
}
