#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <filesystem>
#include <string>
#include "LanguageManager.h"

// Global language manager - best practice: use dependency injection in real apps
LanguageManager* g_langManager = nullptr;

class System {
protected:
    const LanguageManager* langManager;

public:
    System() : langManager(g_langManager) {}
    virtual ~System() = default;
    virtual void status() const = 0;
    virtual void save(const std::string& filename) = 0;
    virtual void load(const std::string& filename) = 0;
};

class CommunicationSystem : public System {
private:
    std::string lastMessage;

public:
    void status() const override {
        std::cout << langManager->getText(TextID::COMMUNICATION_STATUS) << ": "
                  << langManager->getText(TextID::ALERT_INFO) << " - " << lastMessage << "\n";
    }

    void save(const std::string& filename) override {
        std::ofstream file(filename);
        file << lastMessage;
    }

    void load(const std::string& filename) override {
        std::ifstream file(filename);
        std::getline(file, lastMessage);
    }

    void setMessage(const std::string& msg) { lastMessage = msg; }
};

class InventorySystem : public System {
private:
    int foodStock;

public:
    InventorySystem() : foodStock(100) {}

    void status() const override {
        std::cout << langManager->getText(TextID::INVENTORY_STATUS) << ": "
                  << langManager->getText(TextID::ALERT_INFO) << " - " << foodStock << " units\n";
    }

    void save(const std::string& filename) override {
        std::ofstream file(filename);
        file << foodStock;
    }

    void load(const std::string& filename) override {
        std::ifstream file(filename);
        file >> foodStock;
    }
};

int main() {
    // Initialize language manager
    LanguageManager langManager;

    // Language selection - best practice: allow user to choose language
    std::cout << "Select language / Seleccionar idioma (1: English, 2: Español): ";
    int choice;
    std::cin >> choice;

    Language selectedLang = (choice == 2) ? Language::SPANISH : Language::ENGLISH;
    langManager.setLanguage(selectedLang);

    // Set global reference (in real app, use dependency injection)
    g_langManager = &langManager;

    // Welcome message
    std::cout << langManager.getText(TextID::WELCOME) << "\n";
    std::cout << langManager.getText(TextID::CONTROL_CENTER_READY) << "\n\n";

    std::vector<std::unique_ptr<System>> systems;

    auto comm = std::make_unique<CommunicationSystem>();
    comm->setMessage("SOS - Colony under attack / SOS - Colonia bajo ataque");
    systems.push_back(std::move(comm));

    systems.push_back(std::make_unique<InventorySystem>());

    std::cout << langManager.getText(TextID::SYSTEM_STATUS) << " - " << langManager.getText(TextID::ALERT_INFO) << ":\n";
    for (const auto& sys : systems) {
        sys->status();
    }

    // Save to files - best practice: use filesystem for cross-platform compatibility
    std::filesystem::create_directory("data");
    systems[0]->save("data/comm.txt");
    systems[1]->save("data/inventory.txt");

    std::cout << "\n" << langManager.getText(TextID::ALERT_INFO) << ": " << "Data saved / Datos guardados\n";

    // Simulate system reset
    systems.clear();
    systems.push_back(std::make_unique<CommunicationSystem>());
    systems.push_back(std::make_unique<InventorySystem>());

    // Load from files
    systems[0]->load("data/comm.txt");
    systems[1]->load("data/inventory.txt");

    std::cout << "\n" << langManager.getText(TextID::SYSTEM_STATUS) << " - " << langManager.getText(TextID::ALERT_INFO) << " (Loaded / Cargado):\n";
    for (const auto& sys : systems) {
        sys->status();
    }

    std::cout << "\n" << langManager.getText(TextID::MISSION_COMPLETE) << "\n";

    return 0;
}
