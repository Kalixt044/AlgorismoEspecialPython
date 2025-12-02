#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float nota1, nota2, nota3, nota4;
    float promedio;
    int continuar = 1; // Variable para controlar el bucle. 1 = Continuar, 0 = Terminar.
    
    // **********************************************
    // Autor: Aprendiz Digital I J Gallardo Navarro
    // Fecha:  Noviembre de 2025
    // Descripción: Aplicación para calcular el promedio de 4 notas y determinar 
    //              el estado de aprobación de la materia de tecnología.
    // **********************************************

    cout << "--- Sistema de Cálculo de Notas de Tecnología ---" << endl;
    
    do { 
        cout << "\n-----------------------------------------------" << endl;
        cout << "Ingrese las 4 notas del estudiante (en una escala de 0.0 a 5.0):" << endl;


        cout << "Nota 1: ";
        if (!(cin >> nota1)) {
            cout << "Error: Entrada no válida. Terminando programa." << endl;
            return 1;
        }

        cout << "Nota 2: ";
        if (!(cin >> nota2)) {
            cout << "Error: Entrada no válida. Terminando programa." << endl;
            return 1;
        }

        cout << "Nota 3: ";
        if (!(cin >> nota3)) {
            cout << "Error: Entrada no válida. Terminando programa." << endl;
            return 1;
        }

        cout << "Nota 4: ";
        if (!(cin >> nota4)) {
            cout << "Error: Entrada no válida. Terminando programa." << endl;
            return 1;
        }
        // ------------------------------------

        promedio = (nota1 + nota2 + nota3 + nota4) / 4.0;

        // --- Bloque de Resultados ---
        cout << fixed << setprecision(2);
        cout << "\nEl promedio final del estudiante es: " << promedio << " puntos." << endl;

        if (promedio >= 3.5) {
            cout << "Estado: Aprobado ✅" << endl;
        } 
        else {
            if (promedio >= 3.0) {
                cout << "Estado: En este momento no tiene aprobada la materia de tecnología, pero tiene la oportunidad de recuperar. ⚠️" << endl;
            } 
            else {
                cout << "Estado: No aprobado " << endl;
            }
        }


        cout << "\n-----------------------------------------------" << endl;
        cout << "¿Desea digitar las notas de otro estudiante?" << endl;
        cout << "Digite **1** para CONTINUAR o **0** para TERMINAR: ";
        

        if (!(cin >> continuar)) {
            cout << "Error: Entrada no válida para la opción de continuar. Terminando programa." << endl;

            continuar = 0; 
        }

    } while (continuar == 1);

    cout << "\nPrograma terminado. ¡Hasta pronto! " << endl;
    cout << "-----------------------------------------------" << endl;

    return 0;
}
