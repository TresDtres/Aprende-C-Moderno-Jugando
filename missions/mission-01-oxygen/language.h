#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

// Enum to represent available languages
enum class Language {
    ENGLISH,
    SPANISH
};

// Function declarations for language handling
Language selectLanguage();
std::string getAlertMessage(Language lang);
std::string getEmergencyMessage(Language lang);
std::string getGeneratorFailureMessage(Language lang);
std::string getLeakMessage(Language lang);
std::string getRepairMessage(Language lang);
std::string getOxygenStatusMessage(Language lang, int second, float oxygen);
std::string getRepairActivatedMessage(Language lang);
std::string getColonyLostMessage(Language lang);
std::string getLastWordsMessage(Language lang);
std::string getMissionSummaryMessage(Language lang);
std::string getTimeSurvivedMessage(Language lang, int seconds);
std::string getRepairSystemStatusMessage(Language lang, bool active);
std::string getColonySavedMessage(Language lang);
std::string getColonyFailedMessage(Language lang);

// Inline functions to get string literals based on language
inline std::string getAlertMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "🚨 EMERGENCY ALERT 🚨" : "🚨 ALERTA DE EMERGENCIA 🚨";
}

inline std::string getEmergencyMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "OXYGEN LEAK DETECTED IN THE COLONY!" : "¡FUGA DE OXÍGENO DETECTADA EN LA COLONIA!";
}

inline std::string getGeneratorFailureMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "Main generator has failed." : "El generador principal ha fallado.";
}

inline std::string getLeakMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "Oxygen drops 10% every second." : "El oxígeno cae un 10% cada segundo.";
}

inline std::string getRepairMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "Activate emergency repair system before it's too late!" : "¡Activa el sistema de reparación de emergencia antes de que sea demasiado tarde!";
}

inline std::string getOxygenStatusMessage(Language lang, int second, float oxygen) {
    std::string prefix = (lang == Language::ENGLISH) ? "[" : "[";
    std::string suffix = (lang == Language::ENGLISH) ? "s] 💨 Oxygen: " : "s] 💨 Oxígeno: ";
    std::string oxygen_str = std::to_string(oxygen);
    // Find the decimal point and keep only 1 decimal place
    size_t decimal_pos = oxygen_str.find('.');
    if (decimal_pos != std::string::npos && decimal_pos + 2 < oxygen_str.length()) {
        oxygen_str = oxygen_str.substr(0, decimal_pos + 2); // Keep 1 decimal place
    }
    return prefix + std::to_string(second) + suffix + oxygen_str + "%";
}

inline std::string getRepairActivatedMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "🔧 [REPAIR SYSTEM ACTIVATED] +5% oxygen recovered." : "🔧 [SISTEMA DE REPARACIÓN ACTIVADO] +5% de oxígeno recuperado.";
}

inline std::string getColonyLostMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "\n💀 OXYGEN LEVEL 0%! COLONY LOST!" : "\n💀 ¡NIVEL DE OXÍGENO 0%! ¡COLONIA PERDIDA!";
}

inline std::string getLastWordsMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "The last colonists whisper... 'We should have used modern C++...'" : "Los últimos colonos susurran... 'Deberíamos haber usado C++ moderno...'";
}

inline std::string getMissionSummaryMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "\n📊 MISSION SUMMARY:\n" : "\n📊 RESUMEN DE LA MISIÓN:\n";
}

inline std::string getTimeSurvivedMessage(Language lang, int seconds) {
    return (lang == Language::ENGLISH) ? "Time survived: " + std::to_string(seconds) + " seconds.\n" : "Tiempo sobrevivido: " + std::to_string(seconds) + " segundos.\n";
}

inline std::string getRepairSystemStatusMessage(Language lang, bool active) {
    std::string prefix = (lang == Language::ENGLISH) ? "Repair system status: " : "Estado final del sistema de reparación: ";
    std::string status = (active) ? 
        ((lang == Language::ENGLISH) ? "ACTIVE" : "ACTIVO") : 
        ((lang == Language::ENGLISH) ? "INACTIVE" : "INACTIVO");
    return prefix + status + ".\n";
}

inline std::string getColonySavedMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "🎉 Colony saved! Repair system worked.\n" : "🎉 ¡La colonia fue salvada! El sistema de reparación funcionó.\n";
}

inline std::string getColonyFailedMessage(Language lang) {
    return (lang == Language::ENGLISH) ? "☠️  Total failure. You need to improve the system... Try again!\n" : "☠️  Fracaso total. Necesitas mejorar el sistema... ¡Prueba de nuevo!\n";
}

#endif // LANGUAGE_H