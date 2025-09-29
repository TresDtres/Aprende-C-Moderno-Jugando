#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <array>
#include <optional>  // Para std::optional (C++17)

// Espacio de nombres para constantes relacionadas con la simulación
namespace SimulationConstants {
    // Usamos double para mayor precisión en cálculos científicos
    constexpr double PI = 3.14159265358979323846;  // Constante PI precisa
    constexpr double DEFAULT_SOLAR_INTENSITY = 1361.0;  // W/m²
    constexpr double DEFAULT_PANEL_AREA = 10.0;         // m²
    constexpr double CRITICAL_ENERGY_THRESHOLD = 5000.0; // W
}

// Estructura para encapsular los datos de un día de simulación
// Esto mejora la organización y legibilidad del código
struct DailyData {
    double angleDegrees;  // Ángulo en grados
    double efficiency;    // Eficiencia (0.0 a 1.0)

    // Constructor para inicialización fácil
    DailyData(double ang, double eff) : angleDegrees(ang), efficiency(eff) {}
};

// Función mejorada con validación robusta y uso de parámetros
// Retorna std::optional<double> para manejar errores de manera moderna (C++17)
std::optional<double> calculateSolarEnergy(double angleDegrees, double efficiency,
                                           double solarIntensity = SimulationConstants::DEFAULT_SOLAR_INTENSITY,
                                           double panelArea = SimulationConstants::DEFAULT_PANEL_AREA) {
    // Validación de eficiencia con std::clamp (C++17)
    if (efficiency < 0.0 || efficiency > 1.0) {
        std::cerr << "⚠️ Advertencia: Eficiencia fuera de rango [0.0, 1.0]. Ajustando automáticamente a "
                  << std::clamp(efficiency, 0.0, 1.0) << "\n";
        efficiency = std::clamp(efficiency, 0.0, 1.0);
    }

    // Normalización del ángulo usando std::fmod
    angleDegrees = std::fmod(angleDegrees, 360.0);
    if (angleDegrees < 0) angleDegrees += 360.0;

    // Conversión a radianes
    double angleRadians = angleDegrees * (SimulationConstants::PI / 180.0);

    // Cálculo del coseno
    double cosine = std::cos(angleRadians);

    // Si el coseno no es positivo, no hay energía solar directa
    if (cosine <= 0.0) {
        return 0.0;
    }

    // Cálculo de la energía
    double energy = solarIntensity * cosine * efficiency * panelArea;
    return energy;
}

int main() {
    double totalEnergy = 0.0;

    std::cout << "🌞 SIMULACIÓN DE ENERGÍA SOLAR — COLONIA ESPACIAL\n";
    std::cout << "Los paneles están dañados. Calcula la energía recolectada por día.\n\n";

    // Usamos std::vector para datos dinámicos, pero aquí podríamos usar std::array para tamaño fijo
    // std::array es más eficiente para tamaños conocidos en compile-time
    const std::array<DailyData, 5> dailyData = {{
        {0.0, 0.9},   // Día 1
        {30.0, 0.7},  // Día 2
        {60.0, 0.5},  // Día 3
        {75.0, 0.3},  // Día 4
        {90.0, 0.1}   // Día 5
    }};

    // Bucle tradicional con índice para compatibilidad amplia (C++11+)
    // Usamos size_t para índices, que es el tipo unsigned apropiado para tamaños
    for (size_t day = 0; day < dailyData.size(); ++day) {
        const auto& data = dailyData[day];  // Referencia constante para eficiencia

        // Llamada a la función con manejo de optional (aunque en este caso siempre retorna valor)
        auto energyResult = calculateSolarEnergy(data.angleDegrees, data.efficiency);

        // Dado que la función siempre retorna un valor válido, extraemos directamente
        double dailyEnergy = *energyResult;
        totalEnergy += dailyEnergy;

        std::cout << "📅 Día " << (day + 1)
                  << " — Ángulo: " << data.angleDegrees << "°, Eficiencia: " << (data.efficiency * 100) << "%\n"
                  << "⚡ Energía recolectada: " << std::fixed << std::setprecision(2) << dailyEnergy << " W\n\n";
    }

    std::cout << "🔋 ENERGÍA TOTAL EN " << dailyData.size() << " DÍAS: "
              << std::fixed << std::setprecision(2) << totalEnergy << " W\n";

    // Uso de expresión condicional para simplificar
    std::cout << (totalEnergy < SimulationConstants::CRITICAL_ENERGY_THRESHOLD ?
                  "⚠️  ¡ALERTA! Energía insuficiente. Los sistemas críticos podrían fallar.\n" :
                  "✅ ¡Energía suficiente! La colonia sobrevivirá al menos una semana.\n");

    return 0;
}

/*
EXPLICACIÓN DE MEJORAS PARA ESTUDIANTES DE C++ MODERNO:

1. **Uso de double en lugar de float**: Para cálculos científicos, double ofrece mayor precisión.

2. **Espacio de nombres (namespace)**: Agrupa constantes relacionadas, evitando contaminación del espacio global.

3. **Estructura (struct) con constructor**: Encapsula datos relacionados, mejorando la mantenibilidad.

4. **std::optional (C++17)**: Maneja errores de manera funcional, evitando excepciones para casos simples.

5. **std::array (C++11)**: Contenedor seguro y eficiente para arrays de tamaño fijo, con métodos como size().

6. **Bucle range-based (C++11)**: Sintaxis más limpia y menos propensa a errores que bucles tradicionales.

7. **std::numbers::pi_v (C++20)**: Constante PI precisa y portable.

8. **std::clamp (C++17)**: Función utilitaria para limitar valores, más expresiva que min/max anidados.

9. **Referencias constantes**: Mejoran el rendimiento y previenen modificaciones accidentales.

10. **Expresión condicional en cout**: Sintaxis más concisa para decisiones simples.

Estas mejoras hacen el código más seguro, legible y alineado con las mejores prácticas de C++ moderno.
*/
