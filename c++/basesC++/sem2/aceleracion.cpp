#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void calcularAceleracion() {
    cout << "\n--- Calculadora de Aceleración (a = (Vf - Vi) / t) ---" << endl;
    
    double velocidadInicial, velocidadFinal, tiempo, aceleracion;

    cout << "Introduce la velocidad inicial (m/s): ";
    if (!(cin >> velocidadInicial)) {
        cout << "Error: Entrada no válida para la velocidad inicial. Se esperaba un número." << endl;
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        return;
    }

    cout << "Introduce la velocidad final (m/s): ";
    if (!(cin >> velocidadFinal)) {
        cout << "Error: Entrada no válida para la velocidad final. Se esperaba un número." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    cout << "Introduce el tiempo transcurrido (segundos): ";
    if (!(cin >> tiempo)) {
        cout << "Error: Entrada no válida para el tiempo. Se esperaba un número." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    if (tiempo <= 0) {
        cout << "Error: El tiempo transcurrido debe ser mayor que cero para calcular la aceleración." << endl;
    } else {
        aceleracion = (velocidadFinal - velocidadInicial) / tiempo;

        cout << fixed << setprecision(2);
        cout << "\n--- Resultado del Cálculo ---" << endl;
        cout << "Datos ingresados:" << endl;
        cout << "   Velocidad Inicial (Vi): " << velocidadInicial << " m/s" << endl;
        cout << "   Velocidad Final (Vf):   " << velocidadFinal << " m/s" << endl;
        cout << "   Tiempo (t):             " << tiempo << " s" << endl;
        
        cout << "\nCálculo: a = (" << velocidadFinal << " - " << velocidadInicial << ") / " << tiempo << endl;
        cout << "La aceleración del vehículo es: " << aceleracion << " m/s^2" << endl;
        cout << "---------------------------" << endl;
    }
}

int main() {

    calcularAceleracion();

    return 0;
}
