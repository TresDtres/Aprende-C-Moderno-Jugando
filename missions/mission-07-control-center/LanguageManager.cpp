#include "LanguageManager.h"
#include <stdexcept>

// Constructor - initialize with default language
LanguageManager::LanguageManager() : currentLanguage(Language::ENGLISH) {
    loadTranslations();
}

// Load all translations - best practice: separate translation loading
void LanguageManager::loadTranslations() {
    // Clear existing translations
    translations.clear();

    // Load English translations
    if (currentLanguage == Language::ENGLISH) {
        translations[TextID::WELCOME] = "Welcome to Space Colony Control Center!";
        translations[TextID::MENU_START] = "1. Start Mission";
        translations[TextID::MENU_SETTINGS] = "2. Settings";
        translations[TextID::MENU_QUIT] = "3. Quit";
        translations[TextID::SYSTEM_STATUS] = "System Status";
        translations[TextID::ALERT_CRITICAL] = "CRITICAL ALERT";
        translations[TextID::ALERT_WARNING] = "WARNING";
        translations[TextID::ALERT_INFO] = "INFO";
        translations[TextID::MISSION_COMPLETE] = "Mission Complete!";
        translations[TextID::MISSION_FAILED] = "Mission Failed!";
        translations[TextID::OXYGEN_LEVEL] = "Oxygen Level";
        translations[TextID::ENERGY_LEVEL] = "Energy Level";
        translations[TextID::COMMUNICATION_STATUS] = "Communication Status";
        translations[TextID::ROBOT_STATUS] = "Robot Status";
        translations[TextID::INVENTORY_STATUS] = "Inventory Status";
        translations[TextID::ALARM_STATUS] = "Alarm Status";
        translations[TextID::CONTROL_CENTER_READY] = "Control Center Ready";
    }
    // Load Spanish translations
    else if (currentLanguage == Language::SPANISH) {
        translations[TextID::WELCOME] = "¡Bienvenido al Centro de Control de la Colonia Espacial!";
        translations[TextID::MENU_START] = "1. Iniciar Misión";
        translations[TextID::MENU_SETTINGS] = "2. Configuración";
        translations[TextID::MENU_QUIT] = "3. Salir";
        translations[TextID::SYSTEM_STATUS] = "Estado del Sistema";
        translations[TextID::ALERT_CRITICAL] = "ALERTA CRÍTICA";
        translations[TextID::ALERT_WARNING] = "ADVERTENCIA";
        translations[TextID::ALERT_INFO] = "INFORMACIÓN";
        translations[TextID::MISSION_COMPLETE] = "¡Misión Completada!";
        translations[TextID::MISSION_FAILED] = "¡Misión Fallida!";
        translations[TextID::OXYGEN_LEVEL] = "Nivel de Oxígeno";
        translations[TextID::ENERGY_LEVEL] = "Nivel de Energía";
        translations[TextID::COMMUNICATION_STATUS] = "Estado de Comunicación";
        translations[TextID::ROBOT_STATUS] = "Estado del Robot";
        translations[TextID::INVENTORY_STATUS] = "Estado del Inventario";
        translations[TextID::ALARM_STATUS] = "Estado de la Alarma";
        translations[TextID::CONTROL_CENTER_READY] = "Centro de Control Listo";
    }
}

// Set language and reload translations - best practice: reload on language change
void LanguageManager::setLanguage(Language lang) {
    currentLanguage = lang;
    loadTranslations();
}

// Get translated text - with error handling
std::string LanguageManager::getText(TextID id) const {
    auto it = translations.find(id);
    if (it != translations.end()) {
        return it->second;
    }
    // Fallback to English key name if translation missing
    return "MISSING_TRANSLATION_" + std::to_string(static_cast<int>(id));
}

// Get human-readable language name
std::string LanguageManager::getLanguageName(Language lang) {
    switch (lang) {
        case Language::ENGLISH: return "English";
        case Language::SPANISH: return "Español";
        default: return "Unknown";
    }
}
