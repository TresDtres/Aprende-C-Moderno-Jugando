# 🚀 Misión 1: Oxígeno Crítico

**Dificultad:** ⭐ (Principiante)
**Conceptos clave:** Variables, bucles `while`, condicionales `if/else`, operaciones básicas.

---

## 📖 Narrativa
La colonia espacial **C++ Space Colony** ha sufrido una **fuga crítica de oxígeno**. El generador principal falló, y el nivel de oxígeno está cayendo un **10%** cada segundo. ¡Tu misión es **simular la caída de oxígeno** y evitar que la colonia colapse!

**Objetivos:**
1. Simular la caída de oxígeno usando un bucle `while`.
2. Detener la simulación cuando el oxígeno llegue a **0%** (imprimir: *"¡Colonia perdida!"*).
3. **Bonus:** Implementar un sistema de reparación que **aumente el oxígeno en 5%** cada 2 segundos.

---

## 🎯 Objetivos de Aprendizaje
- Declarar y usar **variables** (`float`, `int`).
- Implementar un bucle `while` para simular el paso del tiempo.
- Usar condicionales (`if/else`) para manejar eventos críticos.
- Practicar la **salida por consola** (`std::cout`).

---

## 💻 Código Base
*(Copiar en `base_code.cpp`)*

```cpp
#include <iostream>
// Incluir <unistd.h> para sleep() en Linux/Mac.
// Para Windows, usa #include <windows.h> y Sleep(miliseconds).

int main() {
    float oxigeno = 100.0f; // Nivel inicial de oxígeno (100%).
    int tiempo = 0;         // Contador de segundos.

    // TODO: Simula la caída de oxígeno (10% por segundo).
    // TODO: Si el oxígeno llega a 0%, imprime "¡Colonia perdida!" y termina el programa.
    // BONUS: Implementa un sistema de reparación (oxígeno +5% cada 2 segundos).

    return 0;
}

