#include <iostream>
#include <thread>     // Para pausas realistas (simula segundos)
#include <chrono>     // Para controlar el tiempo
#include <iomanip>    // Para formatear decimales

// Evitamos "using namespace std;" global → buena práctica C++ moderno
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main() {
    // ✅ VARIABLES: Estado de la colonia
    float oxigeno = 100.0f;           // Nivel inicial de oxígeno (en %)
    int segundo = 0;                  // Contador de segundos transcurridos
    bool reparando = false;           // ¿Está activo el sistema de reparación?
    const float FUGA_POR_SEGUNDO = 10.0f;   // Constante: oxígeno que se pierde cada segundo
    const float REPARACION_POR_CICLO = 5.0f; // Bonus: oxígeno que se recupera cada 2 segundos

    // 📢 Narrativa inicial
    cout << "🚨 ALERTA DE EMERGENCIA 🚨\n";
    cout << "¡FUGA DE OXÍGENO DETECTADA EN LA COLONIA!\n";
    cout << "El generador principal ha fallado.\n";
    cout << "El oxígeno cae un 10% cada segundo.\n";
    cout << "¡Activa el sistema de reparación de emergencia antes de que sea demasiado tarde!\n\n";

    // ✅ BUCLE WHILE: Simula el paso del tiempo segundo a segundo
    while (oxigeno > 0.0f) {
        segundo++;

        // Mostramos estado actual
        cout << "[" << segundo << "s] 💨 Oxígeno: " 
             << fixed << setprecision(1) << oxigeno << "%\n";

        // ✅ OPERACIÓN BÁSICA: Reducimos oxígeno por fuga
        oxigeno -= FUGA_POR_SEGUNDO;

        // ✅ CONDICIONAL IF/ELSE + OPERADOR MÓDULO (%): Bonus - Sistema de reparación cada 2 segundos
        if (segundo % 2 == 0) { // Cada 2 segundos
            reparando = true;
            oxigeno += REPARACION_POR_CICLO;
            cout << "🔧 [SISTEMA DE REPARACIÓN ACTIVADO] +5% de oxígeno recuperado.\n";
        } else {
            reparando = false;
        }

        // ✅ CONDICIONAL: Si el oxígeno baja de 0, lo fijamos en 0 para evitar negativos
        if (oxigeno < 0.0f) {
            oxigeno = 0.0f;
        }

        // 🛑 Si el oxígeno llega a 0, ¡la colonia colapsa!
        if (oxigeno <= 0.0f) {
            cout << "\n💀 ¡NIVEL DE OXÍGENO 0%! ¡COLONIA PERDIDA!\n";
            cout << "Los últimos colonos susurran... 'Deberíamos haber usado C++ moderno...'\n";
            break; // Salimos del bucle
        }

        // Pausa de 1 segundo para simular tiempo real (didáctico y dramático)
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // ✅ Mensaje final de estadísticas (aprendizaje + reflexión)
    cout << "\n📊 RESUMEN DE LA MISIÓN:\n";
    cout << "Tiempo sobrevivido: " << segundo << " segundos.\n";
    cout << "Estado final del sistema de reparación: "
         << (reparando ? "ACTIVO" : "INACTIVO") << ".\n";

    if (oxigeno > 0) {
        cout << "🎉 ¡La colonia fue salvada! El sistema de reparación funcionó.\n";
    } else {
        cout << "☠️  Fracaso total. Necesitas mejorar el sistema... ¡Prueba de nuevo!\n";
    }

    return 0;
}
