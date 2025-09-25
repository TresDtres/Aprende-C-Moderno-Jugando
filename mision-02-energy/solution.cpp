#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

constexpr float PI = 3.14159265358979323846f;
constexpr float INTENSIDAD_SOLAR_DEFAULT = 1361.0f;
constexpr float AREA_PANEL_DEFAULT = 10.0f;

float calcularEnergiaSolar(float anguloGrados, float eficiencia) {
    if (eficiencia < 0.0f || eficiencia > 1.0f) {
        std::cerr << "⚠️ Advertencia: Eficiencia fuera de rango [0.0, 1.0]. Ajustando automáticamente.\n";
        eficiencia = std::clamp(eficiencia, 0.0f, 1.0f);
    }

    // Normalizar ángulo a [0, 360)
    anguloGrados = std::fmod(anguloGrados, 360.0f);
    if (anguloGrados < 0) anguloGrados += 360.0f;

    // Convertir a radianes
    float anguloRadianes = anguloGrados * (PI / 180.0f);
    float coseno = std::cos(anguloRadianes);

    // Si el coseno no es positivo, no hay energía solar directa
    if (coseno <= 0.0f) {
        return 0.0f;
    }

    return INTENSIDAD_SOLAR_DEFAULT * coseno * eficiencia * AREA_PANEL_DEFAULT;
}

// ... resto del main() igual

int main() {
    float energiaTotal = 0.0f;

    std::cout << "🌞 SIMULACIÓN DE ENERGÍA SOLAR — COLONIA ESPACIAL\n";
    std::cout << "Los paneles están dañados. Calcula la energía recolectada por día.\n\n";

    float angulos[] = {0.0f, 30.0f, 60.0f, 75.0f, 90.0f};
    float eficiencias[] = {0.9f, 0.7f, 0.5f, 0.3f, 0.1f};

    for (int dia = 0; dia < 5; ++dia) {
        // ✅ LLAMAMOS A LA FUNCIÓN → reutilizamos lógica
        float energiaDia = calcularEnergiaSolar(angulos[dia], eficiencias[dia]);

        energiaTotal += energiaDia;
        std::cout << "📅 Día " << (dia + 1) 
                  << " — Ángulo: " << angulos[dia] << "°, Eficiencia: " << eficiencias[dia] * 100 << "%\n"
                  << "⚡ Energía recolectada: " << std::fixed << std::setprecision(2) << energiaDia << " W\n\n";
    }

    std::cout << "🔋 ENERGÍA TOTAL EN 5 DÍAS: " << std::fixed << std::setprecision(2) << energiaTotal << " W\n";

    if (energiaTotal < 5000.0f) {
        std::cout << "⚠️  ¡ALERTA! Energía insuficiente. Los sistemas críticos podrían fallar.\n";
    } else {
        std::cout << "✅ ¡Energía suficiente! La colonia sobrevivirá al menos una semana.\n";
    }

    return 0;
}
