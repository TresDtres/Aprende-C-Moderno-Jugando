#include <iostream>
#include <vector>
#include <string>

class Meteorite {
private:
    double position;
    double velocity;
    int threatLevel;

public:
    Meteorite(double pos, double vel, int threat) : position(pos), velocity(vel), threatLevel(threat) {}

    double getPosition() const { return position; }
    double getVelocity() const { return velocity; }
    int getThreatLevel() const { return threatLevel; }

    void setPosition(double pos) { position = pos; }
    void setVelocity(double vel) { velocity = vel; }
    void setThreatLevel(int threat) { threatLevel = threat; }

    void updatePosition(double time) {
        position += velocity * time;
    }
};

class Sensor {
private:
    std::vector<Meteorite> meteorites;

public:
    void addMeteorite(const Meteorite& m) {
        meteorites.push_back(m);
    }

    void removeMeteorite(size_t index) {
        if (index < meteorites.size()) {
            meteorites.erase(meteorites.begin() + index);
        }
    }

    void scanForThreats() const {
        std::cout << "Scanning for threats / Escaneando amenazas:\n";
        for (size_t i = 0; i < meteorites.size(); ++i) {
            const auto& m = meteorites[i];
            if (m.getThreatLevel() > 5) {
                std::cout << "ALERT! High threat meteorite at position " << m.getPosition() 
                          << " with velocity " << m.getVelocity() << " / ¡ALERTA! Meteorito de alta amenaza en posición " 
                          << m.getPosition() << " con velocidad " << m.getVelocity() << "\n";
            }
        }
    }

    void updateAll(double time) {
        for (auto& m : meteorites) {
            m.updatePosition(time);
        }
    }
};

int main() {
    Sensor sensor;

    sensor.addMeteorite(Meteorite(100.0, 10.0, 3));
    sensor.addMeteorite(Meteorite(200.0, 15.0, 7));
    sensor.addMeteorite(Meteorite(300.0, 5.0, 2));

    sensor.scanForThreats();

    sensor.updateAll(1.0);  // Update positions after 1 second

    sensor.scanForThreats();

    return 0;
}
