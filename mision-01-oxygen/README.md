# 🚀 MISIÓN 1: OXÍGENO CRÍTICO
**Módulo:** Supervivencia Básica  
**Dificultad:** ⭐☆☆☆ (Principiante)  
**Conceptos clave:** Variables, bucles `while`, condicionales `if/else`, operaciones básicas.

---

## 📖 NARRATIVA
> 🚨 ALERTA DE EMERGENCIA 🚨  
> ¡FUGA DE OXÍGENO DETECTADA EN LA COLONIA!  
> El generador principal ha fallado.  
> El oxígeno cae un **10% cada segundo**.  
> ¡Activa el sistema de reparación de emergencia antes de que sea demasiado tarde!

---

## 🎯 OBJETIVOS DE APRENDIZAJE
✅ Declarar e inicializar variables (`float`, `int`, `bool`).  
✅ Usar bucles `while` para simular tiempo real.  
✅ Aplicar condicionales `if/else` para activar sistemas.  
✅ Realizar operaciones aritméticas básicas (`+=`, `-=`, `%`).  
✅ Comprender el impacto del orden de ejecución en sistemas dinámicos.

---

## 💻 CÓDIGO BASE
```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main() {
    float oxigeno = 100.0f;
    int segundo = 0;
    bool reparando = false;
    const float FUGA_POR_SEGUNDO = 10.0f;
    const float REPARACION_POR_CICLO = 5.0f;

    cout << "🚨 ALERTA DE EMERGENCIA 🚨\n";
    cout << "¡FUGA DE OXÍGENO DETECTADA EN LA COLONIA!\n";
    cout << "El generador principal ha fallado.\n";
    cout << "El oxígeno cae un 10% cada segundo.\n";
    cout << "¡Activa el sistema de reparación de emergencia antes de que sea demasiado tarde!\n\n";

    while (oxigeno > 0.0f) {
        segundo++;
        cout << "[" << segundo << "s] 💨 Oxígeno: " 
             << fixed << setprecision(1) << oxigeno << "%\n";

        oxigeno -= FUGA_POR_SEGUNDO;

        if (segundo % 2 == 0) {
            reparando = true;
            oxigeno += REPARACION_POR_CICLO;
            cout << "🔧 [SISTEMA DE REPARACIÓN ACTIVADO] +5% de oxígeno recuperado.\n";
        } else {
            reparando = false;
        }

        if (oxigeno < 0.0f) oxigeno = 0.0f;

        if (oxigeno <= 0.0f) {
            cout << "\n💀 ¡NIVEL DE OXÍGENO 0%! ¡COLONIA PERDIDA!\n";
            cout << "Los últimos colonos susurran... 'Deberíamos haber usado C++ moderno...'\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

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