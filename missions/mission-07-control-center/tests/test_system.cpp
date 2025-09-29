#include <iostream>
#include <memory>
#include <cassert>

// Simple test for polymorphism
class System {
public:
    virtual void status() const = 0;
    virtual ~System() = default;
};

class TestSystem : public System {
private:
    int value;

public:
    TestSystem(int v) : value(v) {}
    void status() const override {
        std::cout << "Value: " << value << "\n";
    }
};

void testPolymorphism() {
    std::unique_ptr<System> sys = std::make_unique<TestSystem>(42);
    // Can't directly test output, but ensure no crash
    sys->status();
    std::cout << "Test polymorphism passed.\n";
}

int main() {
    testPolymorphism();
    std::cout << "All tests passed!\n";
    return 0;
}
