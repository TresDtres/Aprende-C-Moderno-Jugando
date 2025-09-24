#include <iostream>
#include <cmath>
#include <iomanip>

// ✅ FUNCIÓN: Protocolo de cálculo de energía solar
// Recibe ángulo en grados y eficiencia (0.0 a 1.0)
// Retorna energía en vatios (W)
float calcularEnergiaSolar(float anguloGrados, float eficiencia) {
    // Convertimos grados a radianes (std::cos espera radianes)
    float anguloRadianes = anguloGrados * static_cast<float>(M_PI) / 180.0f;
    
    // Fórmula física simplificada:
    // Energía = Intensidad solar * cos(ángulo) * eficiencia * área
    const float INTENSIDAD_SOLAR = 1361.0f; // W/m²
    const float AREA_PANEL = 10.0f;         // m²

    float energia = INTENSIDAD_SOLAR * std::cos(anguloRadianes) * eficiencia * AREA_PANEL;

    // Evitamos energía negativa (si ángulo > 90°, cos es negativo)
    if (energia < 0.0f) {
        energia = 0.0f;
    }

    return energia;
}

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
