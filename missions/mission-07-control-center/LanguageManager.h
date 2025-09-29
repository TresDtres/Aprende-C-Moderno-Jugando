#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

// Enum for text identifiers - best practice: use enums instead of strings for type safety
enum class TextID {
    WELCOME,
    MENU_START,
    MENU_SETTINGS,
    MENU_QUIT,
    SYSTEM_STATUS,
    ALERT_CRITICAL,
    ALERT_WARNING,
    ALERT_INFO,
    MISSION_COMPLETE,
    MISSION_FAILED,
    OXYGEN_LEVEL,
    ENERGY_LEVEL,
    COMMUNICATION_STATUS,
    ROBOT_STATUS,
    INVENTORY_STATUS,
    ALARM_STATUS,
    CONTROL_CENTER_READY
};

// Enum for supported languages
enum class Language {
    ENGLISH,
    SPANISH
};

// Language Manager class - implements internationalization best practices
class LanguageManager {
private:
    Language currentLanguage;
    std::unordered_map<TextID, std::string> translations;

    // Initialize translations for all supported languages
    void loadTranslations();

public:
    LanguageManager();
    ~LanguageManager() = default;

    // Set the current language
    void setLanguage(Language lang);

    // Get translated text by ID
    std::string getText(TextID id) const;

    // Get current language
    Language getCurrentLanguage() const { return currentLanguage; }

    // List available languages (for UI)
    static std::string getLanguageName(Language lang);
};
