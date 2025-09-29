#include <iostream>
#include <cmath>     // Para std::cos, std::acos, std::max, std::min
#include <iomanip>   // Para std::fixed, std::setprecision
#include <vector>    // Para std::vector
#include <numbers>   // Para std::numbers::pi_v (C++20) o definirla manualmente para versiones anteriores

// Definición de PI para C++ < 20
#if __cplusplus < 202002L
    const float MY_PI = std::acos(-1.0f);
#endif

// Estructura para agrupar los datos de cada día
struct DatosDia {
    float anguloGrados;
    float eficiencia; // Ya representa la eficiencia real para ese día
};

// ✅ FUNCIÓN: Protocolo de cálculo de energía solar
// Recibe ángulo en grados, eficiencia (0.0 a 1.0), intensidad solar y área del panel.
// Retorna energía en vatios (W)
float calcularEnergiaSolar(float anguloGrados, float eficiencia, float intensidadSolar, float areaPanel) {
    // 1. Validación y ajuste de la eficiencia
    if (eficiencia < 0.0f || eficiencia > 1.0f) {
        std::cerr << "AVISO: Eficiencia fuera de rango [0.0, 1.0]. Ajustando a: "
                  << std::max(0.0f, std::min(1.0f, eficiencia)) * 100.0f << "%\n";
        eficiencia = std::max(0.0f, std::min(1.0f, eficiencia)); // Clampar entre 0 y 1
    }
    
    // 2. Convertimos grados a radianes (std::cos espera radianes)
    // Usamos std::numbers::pi_v para C++20, o MY_PI para versiones anteriores
#if __cplusplus >= 202002L
    const float anguloRadianes = anguloGrados * std::numbers::pi_v<float> / 180.0f;
#else
    const float anguloRadianes = anguloGrados * MY_PI / 180.0f;
#endif
    
    // 3. Fórmula física simplificada:
    // Energía = Intensidad solar * cos(ángulo) * eficiencia * área
    float energia = intensidadSolar * std::cos(anguloRadianes) * eficiencia * areaPanel;

    // 4. Evitamos energía negativa (si ángulo > 90°, cos es negativo, o por otros factores)
    return std::max(0.0f, energia); // Garantiza que la energía no sea menor a 0
}

int main() {
    float energiaTotal = 0.0f;

    std::cout << "🌞 SIMULACIÓN DE ENERGÍA SOLAR — COLONIA ESPACIAL\n";
    std::cout << "Los paneles están dañados. Calcula la energía recolectada por día.\n\n";

    // Constantes de configuración de la simulación
    const float INTENSIDAD_SOLAR_BASE = 1361.0f; // W/m² (Intensidad solar en órbita terrestre)
    const float AREA_PANEL_COLONIA = 10.0f;      // m²
    const float UMBRAL_ENERGIA_CRITICA = 5000.0f; // W

    // Datos de la simulación para cada día
    std::vector<DatosDia> datosPorDia = {
        {0.0f, 0.9f},  // Día 1: 0 grados, 90% eficiencia
        {30.0f, 0.7f}, // Día 2: 30 grados, 70% eficiencia
        {60.0f, 0.5f}, // Día 3: 60 grados, 50% eficiencia
        {75.0f, 0.3f}, // Día 4: 75 grados, 30% eficiencia
        {90.0f, 0.1f}  // Día 5: 90 grados, 10% eficiencia
    };

    for (size_t dia = 0; dia < datosPorDia.size(); ++dia) { // Usamos size_t para el índice del vector
        const DatosDia& datosActuales = datosPorDia[dia]; // Referencia constante para fácil acceso

        // ✅ LLAMAMOS A LA FUNCIÓN → reutilizamos lógica con más flexibilidad
        float energiaDia = calcularEnergiaSolar(
            datosActuales.anguloGrados, 
            datosActuales.eficiencia, 
            INTENSIDAD_SOLAR_BASE, 
            AREA_PANEL_COLONIA
        );

        energiaTotal += energiaDia;
        std::cout << "📅 Día " << (dia + 1) 
                  << " — Ángulo: " << datosActuales.anguloGrados << "°, Eficiencia: " << datosActuales.eficiencia * 100 << "%\n"
                  << "⚡ Energía recolectada: " << std::fixed << std::setprecision(2) << energiaDia << " W\n\n";
    }

    std::cout << "🔋 ENERGÍA TOTAL EN " << datosPorDia.size() << " DÍAS: " 
              << std::fixed << std::setprecision(2) << energiaTotal << " W\n";

    if (energiaTotal < UMBRAL_ENERGIA_CRITICA) {
        std::cout << "⚠️  ¡ALERTA! Energía insuficiente. Los sistemas críticos podrían fallar.\n";
    } else {
        std::cout << "✅ ¡Energía suficiente! La colonia sobrevivirá al menos una semana.\n";
    }

    return 0;
}