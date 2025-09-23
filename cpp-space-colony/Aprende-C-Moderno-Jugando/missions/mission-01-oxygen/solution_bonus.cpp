#include <iostream>
#include <unistd.h> // Para sleep(). En Windows: #include <windows.h>.

int main() {
    float oxigeno = 100.0f;
    int tiempo = 0; // Contador de segundos.

    while (oxigeno > 0) {
        oxigeno -= 10.0f; // Caída de oxígeno.
        std::cout << "Oxígeno: " << oxigeno << "%\n";

        // Reparación cada 2 segundos.
        if (tiempo % 2 == 0 && oxigeno > 0) {
            oxigeno += 5.0f;
            std::cout << "  + Reparación: +5% oxígeno\n";
        }

        sleep(1); // Pausa de 1 segundo.
        tiempo++;
    }

    std::cout << "¡Colonia perdida!\n";
    return 0;
}

