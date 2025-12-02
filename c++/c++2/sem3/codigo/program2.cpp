#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ============================================
// VARIABLES GLOBALES
// ============================================
const double PI = 3.14159265359;  // Constante PI para cálculos de círculo
double area = 0.0;                // Variable global para almacenar el área calculada
double perimetro = 0.0;           // Variable global para almacenar el perímetro calculado
string nombreFigura = "";         // Variable global para el nombre de la figura

// ============================================
// DECLARACIÓN DE FUNCIONES (PROTOTIPOS)
// ============================================
void mostrarMenu();
void calcularCuadrado();
void calcularRectangulo();
void calcularCirculo();
void calcularTriangulo();
void mostrarResultado();
void limpiarPantalla();

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                calcularCuadrado();
                mostrarResultado();
                break;
            case 2:
                calcularRectangulo();
                mostrarResultado();
                break;
            case 3:
                calcularCirculo();
                mostrarResultado();
                break;
            case 4:
                calcularTriangulo();
                mostrarResultado();
                break;
            case 5:
                cout << "\n¡Gracias por usar el programa!\n";
                cout << "Programa desarrollado con funciones y variables globales/locales\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
        }
        
        if (opcion >= 1 && opcion <= 4) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while(opcion != 5);
    
    return 0;
}

// ============================================
// IMPLEMENTACIÓN DE FUNCIONES
// ============================================

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "  CALCULADORA DE FIGURAS GEOMETRICAS\n";
    cout << "========================================\n";
    cout << "1. Cuadrado\n";
    cout << "2. Rectangulo\n";
    cout << "3. Circulo\n";
    cout << "4. Triangulo\n";
    cout << "5. Salir\n";
    cout << "========================================\n";
    cout << "Seleccione una opcion: ";
}

// Función para calcular área y perímetro de un cuadrado
void calcularCuadrado() {
    // Variables locales (solo existen dentro de esta función)
    double lado;
    
    nombreFigura = "CUADRADO";  // Modificando variable global
    
    cout << "\n--- CUADRADO ---\n";
    cout << "Ingrese el lado del cuadrado: ";
    cin >> lado;
    
    // Validación de datos
    if (lado <= 0) {
        cout << "Error: El lado debe ser mayor que cero.\n";
        area = 0;
        perimetro = 0;
        return;
    }
    
    // Cálculos usando variables globales
    area = lado * lado;
    perimetro = 4 * lado;
}

// Función para calcular área y perímetro de un rectángulo
void calcularRectangulo() {
    // Variables locales
    double base, altura;
    
    nombreFigura = "RECTANGULO";
    
    cout << "\n--- RECTANGULO ---\n";
    cout << "Ingrese la base del rectangulo: ";
    cin >> base;
    cout << "Ingrese la altura del rectangulo: ";
    cin >> altura;
    
    // Validación
    if (base <= 0 || altura <= 0) {
        cout << "Error: Los valores deben ser mayores que cero.\n";
        area = 0;
        perimetro = 0;
        return;
    }
    
    // Cálculos
    area = base * altura;
    perimetro = 2 * (base + altura);
}

// Función para calcular área y perímetro de un círculo
void calcularCirculo() {
    // Variable local
    double radio;
    
    nombreFigura = "CIRCULO";
    
    cout << "\n--- CIRCULO ---\n";
    cout << "Ingrese el radio del circulo: ";
    cin >> radio;
    
    // Validación
    if (radio <= 0) {
        cout << "Error: El radio debe ser mayor que cero.\n";
        area = 0;
        perimetro = 0;
        return;
    }
    
    // Cálculos usando la constante global PI
    area = PI * radio * radio;
    perimetro = 2 * PI * radio;  // Circunferencia
}

// Función para calcular área y perímetro de un triángulo
void calcularTriangulo() {
    // Variables locales
    double base, altura, lado1, lado2, lado3;
    
    nombreFigura = "TRIANGULO";
    
    cout << "\n--- TRIANGULO ---\n";
    cout << "Ingrese la base del triangulo: ";
    cin >> base;
    cout << "Ingrese la altura del triangulo: ";
    cin >> altura;
    cout << "Ingrese el lado 1: ";
    cin >> lado1;
    cout << "Ingrese el lado 2: ";
    cin >> lado2;
    cout << "Ingrese el lado 3: ";
    cin >> lado3;
    
    // Validación
    if (base <= 0 || altura <= 0 || lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
        cout << "Error: Todos los valores deben ser mayores que cero.\n";
        area = 0;
        perimetro = 0;
        return;
    }
    
    // Cálculos
    area = (base * altura) / 2.0;
    perimetro = lado1 + lado2 + lado3;
}

// Función para mostrar los resultados (usa variables globales)
void mostrarResultado() {
    cout << "\n========================================\n";
    cout << "         RESULTADOS - " << nombreFigura << "\n";
    cout << "========================================\n";
    cout << fixed << setprecision(2);
    cout << "Area: " << area << " unidades cuadradas\n";
    cout << "Perimetro: " << perimetro << " unidades\n";
    cout << "========================================\n";
}

// Función auxiliar para limpiar pantalla
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
