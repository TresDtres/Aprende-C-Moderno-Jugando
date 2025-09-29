#include <iostream>
#include <cmath>    // Para std::cos y M_PI
#include <iomanip>  // Para setprecision

// TODO: Declara aquí tu función calcularEnergiaSolar
// Debe recibir: ángulo (en grados), eficiencia (0.0 a 1.0)
// Debe retornar: energía recolectada (float)

int main() {
    const float INTENSIDAD_SOLAR = 1361.0f; // W/m² (constante solar)
    const float AREA_PANEL = 10.0f;         // m²
    float energiaTotal = 0.0f;

    std::cout << "🌞 SIMULACIÓN DE ENERGÍA SOLAR — COLONIA ESPACIAL\n";
    std::cout << "Los paneles están dañados. Calcula la energía recolectada por día.\n\n";

    // Simulamos 5 días con distintos ángulos y eficiencias
    float angulos[] = {0.0f, 30.0f, 60.0f, 75.0f, 90.0f}; // Ángulos respecto al sol
    float eficiencias[] = {0.9f, 0.7f, 0.5f, 0.3f, 0.1f};  // Eficiencia degradada

    for (int dia = 0; dia < 5; ++dia) {
        // TODO: Llama a tu función calcularEnergiaSolar aquí
        float energiaDia = 0.0f; // ← reemplaza esto

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
