#include <iostream>
#include <vector>
#include <string>

// Bonus: Add destructor and copy constructor to Meteorite class

class Meteorite {
private:
    double position;
    double velocity;
    int threatLevel;

public:
    Meteorite(double pos, double vel, int threat) : position(pos), velocity(vel), threatLevel(threat) {
        std::cout << "Meteorite created / Meteorito creado\n";
    }

    Meteorite(const Meteorite& other) : position(other.position), velocity(other.velocity), threatLevel(other.threatLevel) {
        std::cout << "Meteorite copied / Meteorito copiado\n";
    }

    ~Meteorite() {
        std::cout << "Meteorite destroyed / Meteorito destruido\n";
    }

    // Getters and setters...
    double getPosition() const { return position; }
    void setPosition(double pos) { position = pos; }
    // ... (similar for others)
};

int main() {
    Meteorite m1(100.0, 10.0, 5);
    Meteorite m2 = m1;  // Copy constructor
    return 0;  // Destructors called
}
