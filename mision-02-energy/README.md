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

## 💻 CÓDIGO BASE — `mission-02.cpp` Cambiado y notas

🔧 Sugerencias menores (opcionales, pero recomendadas):
1. Evitar redundancia lógica
Actualmente, tienes dos verificaciones que hacen algo similar:

cpp
if (anguloGrados > 90.0f && anguloGrados < 270.0f) { return 0.0f; }
// ...
if (coseno <= 0.0f) { return 0.0f; }
Esto no es un error, pero es ligeramente redundante: si el ángulo está en (90, 270), el coseno ya será ≤ 0.

✅ Recomendación: eliminar la primera condición y confiar en el cálculo del coseno.
Esto simplifica la lógica y evita duplicar la regla física.

cpp
// Elimina este bloque:
// if (anguloGrados > 90.0f && anguloGrados < 270.0f) {
//     return 0.0f;
// }
¿Por qué?
El coseno ya captura exactamente cuándo no hay luz directa.
Además, si en el futuro usamos ángulos con precisión decimal (ej. 89.999°), la lógica sigue siendo correcta. 

2. Comentario sobre std::clamp y compatibilidad
Dado que algunos entornos (especialmente antiguos o con C++14) no tienen std::clamp, podrías dejar un comentario de respaldo:

cpp
// eficiencia = std::max(0.0f, std::min(1.0f, eficiencia)); // Alternativa C++11/14
Pero como el curso apunta a C++17+, está bien dejar std::clamp como principal.

3. Constantes en mayúsculas → bien, pero considera static constexpr si se usan solo en este archivo
No es necesario, pero si el archivo crece, podrías encapsularlas:

cpp
namespace {
    constexpr float PI = 3.14159265358979323846f;
    constexpr float INTENSIDAD_SOLAR_DEFAULT = 1361.0f;
    constexpr float AREA_PANEL_DEFAULT = 10.0f;
}
→ Esto evita conflictos de nombres si se incluye en otros archivos.
Pero para Mission-02, no es necesario. Lo dejas como está.

✅ Versión final recomendada (con ajuste de redundancia):
cpp
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

