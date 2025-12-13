#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// ============================================
// DECLARACIÓN DE FUNCIONES
// ============================================
void limpiarBuffer();
void mostrarMenuPrincipal();
int solicitarCantidadProductos();
void ingresarProductos(string productos[], int cantidad);
void mostrarListaProductos(string productos[], int cantidad);
bool preguntarSatisfaccion();
void menuAcciones(string productos[], int cantidad);
void calcularValorTotal(string productos[], int cantidad);
void ingresarDatosCalculos(string productos[], int cantidad, int cantidades[], 
                           double valoresUnitarios[], double descuentos[]);
void mostrarResumenCalculos(string productos[], int cantidad, int cantidades[], 
                            double valoresUnitarios[], double descuentos[], 
                            double totales[], double granTotal);


int main() {
    const int MAX_PRODUCTOS = 100; //declaracion arrreglo unidimensional
    string productos[MAX_PRODUCTOS];
    int numProductos;
    bool satisfecho = false;
    
    cout << "=================================================" << endl;
    cout << "     BIENVENIDO AL MÓDULO DE CLIENTES" << endl;
    cout << "   COMERCIALIZADORA DE ARTÍCULOS TECNOLÓGICOS" << endl;
    cout << "=================================================" << endl;
    
    do {
        cout << "\n>>> Generación de Lista de Compras <<<" << endl;
        
        numProductos = solicitarCantidadProductos();
        
        ingresarProductos(productos, numProductos);
        
        mostrarListaProductos(productos, numProductos);
        
        satisfecho = preguntarSatisfaccion();
        
        if (satisfecho) {
            menuAcciones(productos, numProductos);
        }
        
    } while (!satisfecho);
    
    cout << "\n=================================================" << endl;
    cout << "  ¡Gracias por su visita! ¡Vuelva pronto! " << endl;
    cout << "=================================================" << endl;
    
    return 0;
}



void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void mostrarMenuPrincipal() {
    cout << "\n========================================" << endl;
    cout << "           MENÚ DE ACCIONES" << endl;
    cout << "========================================" << endl;
    cout << "1. Calcular valor total de productos" << endl;
    cout << "2. Generar una nueva lista de productos" << endl;
    cout << "3. Salir del sistema" << endl;
    cout << "========================================" << endl;
}


int solicitarCantidadProductos() {
    int cantidad;
    
    do {
        cout << "\n¿Cuántos productos desea agregar a su lista? (1-100): ";
        
        if (!(cin >> cantidad)) {
            cout << "Error: Debe ingresar un número válido." << endl;
            cin.clear();
            limpiarBuffer();
            cantidad = 0;
        } else if (cantidad <= 0 || cantidad > 100) {
            cout << "Error: La cantidad debe estar entre 1 y 100." << endl;
        }
    } while (cantidad <= 0 || cantidad > 100);
    
    limpiarBuffer();
    return cantidad;
}


void ingresarProductos(string productos[], int cantidad) {
    cout << "\nPor favor, ingrese el nombre de cada producto:" << endl;
    cout << "---------------------------------------------" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        cout << "Producto " << (i + 1) << ": ";
        getline(cin, productos[i]);
        
        while (productos[i].empty()) {
            cout << "Error: El nombre no puede estar vacío." << endl;
            cout << "Producto " << (i + 1) << ": ";
            getline(cin, productos[i]);
        }
    }
}


void mostrarListaProductos(string productos[], int cantidad) {
    cout << "\n========================================" << endl;
    cout << "     LISTA DE PRODUCTOS INGRESADOS" << endl;
    cout << "========================================" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << productos[i] << endl;
    }
    
    cout << "========================================" << endl;
    cout << "Total de productos: " << cantidad << endl;
    cout << "========================================" << endl;
}


bool preguntarSatisfaccion() {
    int opcion;
    
    cout << "\n¿Se encuentra satisfecho con esta lista?" << endl;
    cout << "1. Sí, estoy satisfecho" << endl;
    cout << "0. No, deseo generar una nueva lista" << endl;
    cout << "Opción: ";
    
    while (!(cin >> opcion) || (opcion != 0 && opcion != 1)) {
        cout << "Error: Ingrese 1 (satisfecho) o 0 (nueva lista): ";
        cin.clear();
        limpiarBuffer();
    }
    
    limpiarBuffer();
    return (opcion == 1);
}


void menuAcciones(string productos[], int cantidad) {
    int opcion;
    bool continuar = true;
    
    do {
        mostrarMenuPrincipal();
        cout << "Seleccione una opción: ";
        
        if (!(cin >> opcion)) {
            cout << "Error: Debe ingresar un número." << endl;
            cin.clear();
            limpiarBuffer();
            continue;
        }
        
        limpiarBuffer();
        
        switch (opcion) {
            case 1:
                calcularValorTotal(productos, cantidad);
                break;
                
            case 2:
                cout << "\nRegresando para generar una nueva lista..." << endl;
                continuar = false;
                break;
                
            case 3:
                cout << "\nSaliendo del sistema..." << endl;
                continuar = false;
                break;
                
            default:
                cout << "\nOpción inválida. Intente nuevamente." << endl;
        }
        
        if (opcion == 1 && continuar) {
            cout << "\nPresione Enter para continuar...";
            cin.get();
        }
        
    } while (continuar && opcion != 2 && opcion != 3);
}


void calcularValorTotal(string productos[], int cantidad) {
    int cantidades[100];
    double valoresUnitarios[100];
    double descuentos[100];
    double totales[100];
    double granTotal = 0.0;
    
    cout << "\n========================================" << endl;
    cout << "       CÁLCULO DE VALOR TOTAL" << endl;
    cout << "========================================" << endl;
    
    ingresarDatosCalculos(productos, cantidad, cantidades, valoresUnitarios, descuentos);
    
    for (int i = 0; i < cantidad; i++) {
        double subtotal = cantidades[i] * valoresUnitarios[i];
        double montoDescuento = subtotal * (descuentos[i] / 100.0);
        totales[i] = subtotal - montoDescuento;
        granTotal += totales[i];
    }
    
    mostrarResumenCalculos(productos, cantidad, cantidades, valoresUnitarios, 
                          descuentos, totales, granTotal);
}


void ingresarDatosCalculos(string productos[], int cantidad, int cantidades[], 
                           double valoresUnitarios[], double descuentos[]) {
    cout << "\nIngrese los datos para cada producto:" << endl;
    cout << "---------------------------------------------" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        cout << "\n>>> " << productos[i] << " <<<" << endl;
        
        do {
            cout << "Cantidad: ";
            if (!(cin >> cantidades[i]) || cantidades[i] <= 0) {
                cout << "Error: Ingrese una cantidad válida (mayor a 0)." << endl;
                cin.clear();
                limpiarBuffer();
                cantidades[i] = 0;
            }
        } while (cantidades[i] <= 0);
        
        do {
            cout << "Valor unitario ($): ";
            if (!(cin >> valoresUnitarios[i]) || valoresUnitarios[i] <= 0) {
                cout << "Error: Ingrese un valor válido (mayor a 0)." << endl;
                cin.clear();
                limpiarBuffer();
                valoresUnitarios[i] = 0;
            }
        } while (valoresUnitarios[i] <= 0);
        
        do {
            cout << "Descuento (%): ";
            if (!(cin >> descuentos[i]) || descuentos[i] < 0 || descuentos[i] > 100) {
                cout << "Error: Ingrese un descuento entre 0 y 100." << endl;
                cin.clear();
                limpiarBuffer();
                descuentos[i] = -1;
            }
        } while (descuentos[i] < 0 || descuentos[i] > 100);
    }
    
    limpiarBuffer();
}


void mostrarResumenCalculos(string productos[], int cantidad, int cantidades[], 
                            double valoresUnitarios[], double descuentos[], 
                            double totales[], double granTotal) {
    cout << "\n========================================" << endl;
    cout << "         RESUMEN DE COMPRA" << endl;
    cout << "========================================" << endl;
    cout << fixed << setprecision(2);
    
    for (int i = 0; i < cantidad; i++) {
        cout << "\n" << (i + 1) << ". " << productos[i] << endl;
        cout << "   Cantidad: " << cantidades[i] << " unidad(es)" << endl;
        cout << "   Valor unitario: $" << valoresUnitarios[i] << endl;
        cout << "   Subtotal: $" << (cantidades[i] * valoresUnitarios[i]) << endl;
        cout << "   Descuento: " << descuentos[i] << "% (-$" 
             << (cantidades[i] * valoresUnitarios[i] * descuentos[i] / 100.0) << ")" << endl;
        cout << "   TOTAL: $" << totales[i] << endl;
    }
    
    cout << "\n========================================" << endl;
    cout << "   TOTAL GENERAL: $" << granTotal << endl;
    cout << "========================================" << endl;
}

/*
Isidro J. Gallardo Navarro

Centro ColomboAleman

Módulos, Estructura de Almacenamiento y POO
Utilizando el Lenguaje de Programación C++ (Nivel II)
*/