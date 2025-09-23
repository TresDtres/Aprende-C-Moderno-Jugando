#include <iostream>
// #include <windows.h> // Descomenta esta línea si estás en Windows.

int main() {
    float oxigeno = 100.0f; // Nivel inicial de oxígeno (100%).
    int tiempo = 0;         // Contador de segundos.

    // TODO: Simula la caída de oxígeno (10% por segundo).
    // Pista: Usa un bucle `while` para restar 10% de oxígeno en cada iteración.
    // Ejemplo: oxigeno -= 10.0f;

    // TODO: Si el oxígeno llega a 0%, imprime "¡Colonia perdida!" y termina el programa.
    // Pista: Usa un condicional `if` para verificar si oxigeno <= 0.

    // BONUS: Implementa un sistema de reparación (oxígeno +5% cada 2 segundos).
    // Pista: Usa un contador `tiempo` y un condicional para reparar cada 2 segundos.

    // sleep(1); // Usa esta función para pausar 1 segundo entre iteraciones (Linux/Mac).
    // Sleep(1000); // Usa esta función si estás en Windows (1000 milisegundos = 1 segundo).

    return 0;
}

