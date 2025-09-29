# 🚀 MISIÓN 2: ENERGÍA DE RESERVA
**Módulo:** Sistemas de Soporte Vital  
**Dificultad:** ⭐⭐☆☆ (Fácil)  
**Conceptos clave:** Funciones, parámetros, retorno de valores, ámbito de variables, buenas prácticas de C++ moderno.

---

## 📖 NARRATIVA
> 🌞 **ALERTA SOLAR**  
> Los paneles solares de la colonia están dañados. Solo capturan energía según su **ángulo respecto al sol** y su **eficiencia actual**.  
>  
> **Tu misión:**  
> - Diseña una **función** que calcule la energía recolectada.  
> - Usa esa función para simular varios días.  
> - **¡Evita el apagón total!** Si la energía cae a 0%, los sistemas críticos fallan.

---

## 🎯 OBJETIVOS DE APRENDIZAJE
✅ Entender qué es una **función** y por qué usarla.  
✅ Aprender a **pasar parámetros** y **retornar valores**.  
✅ Comprender el **ámbito de variables** (local vs global).  
✅ Aplicar **buenas prácticas**: nombres claros, constantes, comentarios útiles.  
✅ Pensar en **reutilización**: “¿Puedo usar esta función en otras misiones?”

---

## 💡 CÓMO PENSAR EN C++ MODERNO: FUNCIONES = PROTOCOLOS DE EMERGENCIA

> “Una función no es solo código. Es un **protocolo reutilizable** que salva vidas.”

- **¿Por qué funciones?**  
  Porque si necesitas calcular energía en 5 misiones distintas, **no copias el código**.  
  Creas una función `calcularEnergia()` y la llamas cuando quieras.

- **¿Parámetros?**  
  Son los **datos de entrada del protocolo**: ángulo, eficiencia, área del panel.

- **¿Retorno?**  
  Es el **resultado del protocolo**: cuánta energía obtuviste.

- **¿Ámbito local?**  
  Las variables dentro de la función **mueren al terminar** → no contaminan el sistema global.

---

## 💻 CÓDIGO BASE — `mission-02.cpp`

```cpp
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
