#include <iostream>
#include <cmath>
#include <algorithm> // para std::clamp (C++17) o std::min/max

// Constante PI compatible con todos los compiladores
constexpr float PI = 3.14159265358979323846f;

// Constantes configurables (pero fijas en esta misión)
constexpr float INTENSIDAD_SOLAR_DEFAULT = 1361.0f; // W/m²
constexpr float AREA_PANEL_DEFAULT = 10.0f;         // m²

float calcularEnergiaSolar(float anguloGrados, float eficiencia) {
    // 🔒 Validación y corrección de eficiencia
    if (eficiencia < 0.0f || eficiencia > 1.0f) {
        std::cerr << "⚠️ Advertencia: Eficiencia fuera de rango [0.0, 1.0]. Ajustando automáticamente.\n";
        eficiencia = std::clamp(eficiencia, 0.0f, 1.0f); // C++17
        // Si prefieres compatibilidad con C++14 o anterior:
        // eficiencia = std::max(0.0f, std::min(1.0f, eficiencia));
    }

    // Normalizar ángulo a [0, 360)
    anguloGrados = std::fmod(anguloGrados, 360.0f);
    if (anguloGrados < 0) anguloGrados += 360.0f;

    // Si el ángulo está entre 90° y 270°, el panel no recibe luz directa
    if (anguloGrados > 90.0f && anguloGrados < 270.0f) {
        return 0.0f;
    }

    // Convertir a radianes
    float anguloRadianes = anguloGrados * (PI / 180.0f);

    // Calcular energía (solo si coseno es positivo)
    float coseno = std::cos(anguloRadianes);
    if (coseno <= 0.0f) {
        return 0.0f;
    }

    return INTENSIDAD_SOLAR_DEFAULT * coseno * eficiencia * AREA_PANEL_DEFAULT;
}