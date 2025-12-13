#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int solicitarTamano();
void ingresarElementos(double arreglo[], int tamano);
void mostrarArreglo(double arreglo[], int tamano, string titulo);
void elevarAlCubo(double arreglo[], int tamano);
double calcularCubo(double numero);
void mostrarMenu();
bool validarTamano(int tamano);


int main() {
    int tamano;
    double* arreglo;
    char continuar;
    
    do {
        mostrarMenu();
        

        tamano = solicitarTamano();
        

        arreglo = new double[tamano];
        

        ingresarElementos(arreglo, tamano);
        

        mostrarArreglo(arreglo, tamano, "ARREGLO ORIGINAL");
        

        elevarAlCubo(arreglo, tamano);
        

        mostrarArreglo(arreglo, tamano, "ARREGLO CON ELEMENTOS AL CUBO");
        

        delete[] arreglo;
        
        cout << "\n¿Desea procesar otro arreglo? (S/N): ";
        cin >> continuar;
        cout << endl;
        
    } while (continuar == 'S' || continuar == 's');
    
    cout << "Gracias por usar el programa." << endl;
    
    return 0;
}


void mostrarMenu() {
    cout << "========================================" << endl;
    cout << "   PROCESADOR DE ARREGLOS - CUBO" << endl;
    cout << "========================================" << endl;
    cout << "Este programa:" << endl;
    cout << "1. Solicita el tamano del arreglo" << endl;
    cout << "2. Permite ingresar los elementos" << endl;
    cout << "3. Muestra el arreglo original" << endl;
    cout << "4. Eleva cada elemento al cubo" << endl;
    cout << "5. Muestra el arreglo resultante" << endl;
    cout << "========================================\n" << endl;
}


int solicitarTamano() {
    int tamano;
    
    do {
        cout << "Ingrese la cantidad de elementos del arreglo: ";
        cin >> tamano;
        
        if (!validarTamano(tamano)) {
            cout << "Error: El tamano debe ser un numero positivo." << endl;
            cout << "Por favor, intente nuevamente.\n" << endl;
        }
    } while (!validarTamano(tamano));
    
    return tamano;
}


bool validarTamano(int tamano) {
    return tamano > 0;
}


void ingresarElementos(double arreglo[], int tamano) {
    cout << "\n--- INGRESO DE ELEMENTOS ---" << endl;
    
    for (int i = 0; i < tamano; i++) {
        cout << "Ingrese el elemento [" << i << "]: ";
        cin >> arreglo[i];
    }
}


void mostrarArreglo(double arreglo[], int tamano, string titulo) {
    cout << "\n========================================" << endl;
    cout << "   " << titulo << endl;
    cout << "========================================" << endl;
    cout << fixed << setprecision(2);
   
    cout << "Elementos: [ ";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i];
        if (i < tamano - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
    

    cout << "\nIndice | Valor" << endl;
    cout << "-------+---------" << endl;
    for (int i = 0; i < tamano; i++) {
        cout << setw(6) << i << " | " << setw(8) << arreglo[i] << endl;
    }
    cout << "========================================" << endl;
}


void elevarAlCubo(double arreglo[], int tamano) {
    cout << "\nElevando elementos al cubo..." << endl;
    
    for (int i = 0; i < tamano; i++) {
        arreglo[i] = calcularCubo(arreglo[i]);
    }
    
    cout << "Proceso completado!" << endl;
}


double calcularCubo(double numero) {
    return numero * numero * numero;

}


/*
programa: Aplicación de parámetros por valor
Presentado: Aprendiz Digital IJ Gallardo Navarro
Centro ColomboAleman 
*/
