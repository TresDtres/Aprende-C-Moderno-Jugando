#include <iostream>
#include <thread>     // Para pausas realistas (simula segundos)
#include <chrono>     // Para controlar el tiempo
#include <iomanip>    // Para formatear decimales
#include "language.h"

// Evitamos "using namespace std;" global → buena práctica C++ moderno
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::cin;

int main() {
    // ✅ SELECCIÓN DE IDIOMA
    cout << "Select language / Seleccione idioma:\n";
    cout << "1 - English\n";
    cout << "2 - Español\n";
    cout << "Enter choice / Ingrese opción: ";
    
    int choice;
    cin >> choice;
    
    Language lang = (choice == 1) ? Language::ENGLISH : Language::SPANISH;
    
    // ✅ VARIABLES: Estado de la colonia
    float oxigeno = 100.0f;           // Nivel inicial de oxígeno (en %)
    int segundo = 0;                  // Contador de segundos transcurridos
    bool reparando = false;           // ¿Está activo el sistema de reparación?
    const float FUGA_POR_SEGUNDO = 10.0f;   // Constante: oxígeno que se pierde cada segundo
    const float REPARACION_POR_CICLO = 5.0f; // Bonus: oxígeno que se recupera cada 2 segundos

    // 📢 Narrativa inicial
    cout << getAlertMessage(lang) << "\n";
    cout << getEmergencyMessage(lang) << "\n";
    cout << getGeneratorFailureMessage(lang) << "\n";
    cout << getLeakMessage(lang) << "\n";
    cout << getRepairMessage(lang) << "\n\n";

    // ✅ BUCLE WHILE: Simula el paso del tiempo segundo a segundo
    while (oxigeno > 0.0f) {
        segundo++;

        // Mostramos estado actual
        cout << getOxygenStatusMessage(lang, segundo, oxigeno) << "\n";

        // ✅ OPERACIÓN BÁSICA: Reducimos oxígeno por fuga
        oxigeno -= FUGA_POR_SEGUNDO;

        // ✅ CONDICIONAL IF/ELSE + OPERADOR MÓDULO (%): Bonus - Sistema de reparación cada 2 segundos
        if (segundo % 2 == 0) { // Cada 2 segundos
            reparando = true;
            oxigeno += REPARACION_POR_CICLO;
            cout << getRepairActivatedMessage(lang) << "\n";
        } else {
            reparando = false;
        }

        // ✅ CONDICIONAL: Si el oxígeno baja de 0, lo fijamos en 0 para evitar negativos
        if (oxigeno < 0.0f) {
            oxigeno = 0.0f;
        }

        // 🛑 Si el oxígeno llega a 0, ¡la colonia colapsa!
        if (oxigeno <= 0.0f) {
            cout << getColonyLostMessage(lang) << "\n";
            cout << getLastWordsMessage(lang) << "\n";
            break; // Salimos del bucle
        }

        // Pausa de 1 segundo para simular tiempo real (didáctico y dramático)
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // ✅ Mensaje final de estadísticas (aprendizaje + reflexión)
    cout << getMissionSummaryMessage(lang);
    cout << getTimeSurvivedMessage(lang, segundo);
    cout << getRepairSystemStatusMessage(lang, reparando);

    if (oxigeno > 0) {
        cout << getColonySavedMessage(lang);
    } else {
        cout << getColonyFailedMessage(lang);
    }

    return 0;
}
