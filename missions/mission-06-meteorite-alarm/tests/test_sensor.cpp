#include <iostream>
#include <cassert>

// Simple test for Meteorite class
class Meteorite {
private:
    double position;
    double velocity;
    int threatLevel;

public:
    Meteorite(double pos, double vel, int threat) : position(pos), velocity(vel), threatLevel(threat) {}

    double getPosition() const { return position; }
    void setPosition(double pos) { position = pos; }
    int getThreatLevel() const { return threatLevel; }
};

void testMeteorite() {
    Meteorite m(100.0, 10.0, 5);
    assert(m.getPosition() == 100.0);
    assert(m.getThreatLevel() == 5);
    m.setPosition(150.0);
    assert(m.getPosition() == 150.0);
    std::cout << "Test Meteorite passed.\n";
}

int main() {
    testMeteorite();
    std::cout << "All tests passed!\n";
    return 0;
}
