#include <iostream>
#include <unistd.h> // Para sleep(). En Windows, usa #include <windows.h>.

int main() {
    float oxigeno = 100.0f;

    while (oxigeno > 0) {
        oxigeno -= 10.0f; // Caída de oxígeno: 10% por segundo.
        std::cout << "Oxígeno: " << oxigeno << "%\n";
        sleep(1); // Pausa de 1 segundo (Linux/Mac). En Windows: Sleep(1000);
    }

    std::cout << "¡Colonia perdida!\n";
    return 0;
}

