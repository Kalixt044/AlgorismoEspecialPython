#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

const int MAX_PRODUCTOS = 100;  // Máximo número de productos
const int NUM_ATRIBUTOS = 3;    // Cantidad, Valor Unitario, Descuento

const int CANTIDAD = 0;
const int VALOR_UNITARIO = 1;
const int DESCUENTO_PORCENTAJE = 2;


void limpiarBuffer();
void mostrarMenuPrincipal();
int solicitarNumeroProductos();
void ingresarDatosProductos(string nombres[], float datosProductos[][NUM_ATRIBUTOS], int numProductos);
void mostrarResumenInformacion(string nombres[], float datosProductos[][NUM_ATRIBUTOS], int numProductos);
int menuAcciones();
void calcularYMostrarTotales(string nombres[], float datosProductos[][NUM_ATRIBUTOS], int numProductos);
void calcularValorTotal(float cantidad, float valorUnitario, float descuento, 
                        float &subtotal, float &descuentoAplicado, float &valorTotal);


int main() {
    // DECLARACIÓN DE ARREGLOS MULTIDIMENSIONALES
    
    // Arreglo unidimensional para nombres de productos
    string nombresProductos[MAX_PRODUCTOS];
    
    // ARREGLO MULTIDIMENSIONAL (MATRIZ bidimensional) para datos numéricos
    // Filas: cada producto (hasta MAX_PRODUCTOS)
    // Columnas: [0]=Cantidad, [1]=ValorUnitario, [2]=Descuento
    float datosProductos[MAX_PRODUCTOS][NUM_ATRIBUTOS];
    
    int numProductos;
    int opcionAccion;
    
    cout << fixed << setprecision(2);
    cout << "=================================================" << endl;
    cout << "      BIENVENIDO AL MÓDULO DE EMPLEADOS" << endl;
    cout << "   COMERCIALIZADORA DE ARTÍCULOS TECNOLÓGICOS" << endl;
    cout << "=================================================" << endl;
    
    do {
        mostrarMenuPrincipal();
        
        numProductos = solicitarNumeroProductos();
        
        ingresarDatosProductos(nombresProductos, datosProductos, numProductos);
        

        mostrarResumenInformacion(nombresProductos, datosProductos, numProductos);
        

        opcionAccion = menuAcciones();
        
        if (opcionAccion == 1) {

            calcularYMostrarTotales(nombresProductos, datosProductos, numProductos);
            

            cout << "\n¿Qué desea hacer ahora?" << endl;
            cout << "2. Generar nueva lista de productos" << endl;
            cout << "0. Salir del sistema" << endl;
            cout << "Opción: ";
            
            while (!(cin >> opcionAccion) || (opcionAccion != 0 && opcionAccion != 2)) {
                cout << "Error: Ingrese 2 (nueva lista) o 0 (salir): ";
                cin.clear();
                limpiarBuffer();
            }
            limpiarBuffer();
        }
        
    } while (opcionAccion == 2);
    
    cout << "\n=================================================" << endl;
    cout << "   Saliendo del Módulo de Empleados" << endl;
    cout << "   ¡Hasta pronto!" << endl;
    cout << "=================================================" << endl;
    
    return 0;
}


void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void mostrarMenuPrincipal() {
    cout << "\n========================================" << endl;
    cout << "   CÁLCULO DE VENTA POR UNIDAD" << endl;
    cout << "========================================" << endl;
}


int solicitarNumeroProductos() {
    int num;
    
    do {
        cout << "¿Cuántos productos desea calcular? (1-" << MAX_PRODUCTOS << "): ";
        
        if (!(cin >> num)) {
            cout << "Error: Debe ingresar un número válido." << endl;
            cin.clear();
            limpiarBuffer();
            num = 0;
        } else if (num <= 0 || num > MAX_PRODUCTOS) {
            cout << "Error: Ingrese un número entre 1 y " << MAX_PRODUCTOS << "." << endl;
        }
    } while (num <= 0 || num > MAX_PRODUCTOS);
    
    limpiarBuffer();
    return num;
}


void ingresarDatosProductos(string nombres[], float datosProductos[][NUM_ATRIBUTOS], int numProductos) {
    cout << "\n>>> Ingreso de Información de Productos <<<" << endl;
    cout << "--------------------------------------------" << endl;
    
    for (int i = 0; i < numProductos; i++) {
        cout << "\n--- PRODUCTO " << (i + 1) << " ---" << endl;
        
        cout << "Nombre del producto: ";
        getline(cin, nombres[i]);
        
        while (nombres[i].empty()) {
            cout << "Error: El nombre no puede estar vacío." << endl;
            cout << "Nombre del producto: ";
            getline(cin, nombres[i]);
        }
        

        do {
            cout << "Cantidad: ";
            if (!(cin >> datosProductos[i][CANTIDAD]) || datosProductos[i][CANTIDAD] <= 0) {
                cout << "Error: Ingrese una cantidad válida (mayor a 0)." << endl;
                cin.clear();
                limpiarBuffer();
                datosProductos[i][CANTIDAD] = 0;
            }
        } while (datosProductos[i][CANTIDAD] <= 0);
        

        do {
            cout << "Valor unitario ($): ";
            if (!(cin >> datosProductos[i][VALOR_UNITARIO]) || datosProductos[i][VALOR_UNITARIO] < 0) {
                cout << "Error: Ingrese un valor válido (0 o mayor)." << endl;
                cin.clear();
                limpiarBuffer();
                datosProductos[i][VALOR_UNITARIO] = -1;
            }
        } while (datosProductos[i][VALOR_UNITARIO] < 0);
        

        float descuentoPorcentaje;
        do {
            cout << "Porcentaje de descuento (0-100): ";
            if (!(cin >> descuentoPorcentaje) || descuentoPorcentaje < 0 || descuentoPorcentaje > 100) {
                cout << "Error: Ingrese un porcentaje entre 0 y 100." << endl;
                cin.clear();
                limpiarBuffer();
                descuentoPorcentaje = -1;
            }
        } while (descuentoPorcentaje < 0 || descuentoPorcentaje > 100);
        

        datosProductos[i][DESCUENTO_PORCENTAJE] = descuentoPorcentaje / 100.0f;
        
        limpiarBuffer();
    }
}


void mostrarResumenInformacion(string nombres[], float datosProductos[][NUM_ATRIBUTOS], int numProductos) {
    cout << "\n========================================" << endl;
    cout << "   RESUMEN DE INFORMACIÓN INGRESADA" << endl;
    cout << "========================================" << endl;
    
    cout << left << setw(20) << "Producto"
         << right << setw(12) << "Cantidad"
         << setw(15) << "Valor Unit."
         << setw(12) << "Desc. (%)" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for (int i = 0; i < numProductos; i++) {
        cout << left << setw(20) << nombres[i]
             << right << setw(12) << datosProductos[i][CANTIDAD]
             << setw(15) << datosProductos[i][VALOR_UNITARIO]
             << setw(12) << (datosProductos[i][DESCUENTO_PORCENTAJE] * 100.0f) << endl;
    }
    
    cout << "========================================" << endl;
}


int menuAcciones() {
    int opcion;
    
    cout << "\n¿Qué acción desea realizar?" << endl;
    cout << "1. Calcular el valor total de cada producto" << endl;
    cout << "2. Regresar y generar nueva lista de productos" << endl;
    cout << "Opción: ";
    
    while (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
        cout << "Error: Ingrese 1 o 2: ";
        cin.clear();
        limpiarBuffer();
    }
    
    limpiarBuffer();
    return opcion;
}


void calcularYMostrarTotales(string nombres[], float datosProductos[][NUM_ATRIBUTOS], int numProductos) {
    float subtotal, descuentoAplicado, valorTotal;
    float granTotal = 0.0f;
    
    cout << "\n========================================" << endl;
    cout << "      RESULTADOS DE CÁLCULO" << endl;
    cout << "========================================" << endl;
    
    cout << left << setw(20) << "Producto"
         << right << setw(15) << "Valor Base"
         << setw(15) << "Descuento"
         << setw(15) << "Total" << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    for (int i = 0; i < numProductos; i++) {
        float cantidad = datosProductos[i][CANTIDAD];
        float valorUnitario = datosProductos[i][VALOR_UNITARIO];
        float descuento = datosProductos[i][DESCUENTO_PORCENTAJE];
        
        calcularValorTotal(cantidad, valorUnitario, descuento, 
                          subtotal, descuentoAplicado, valorTotal);
        
        cout << left << setw(20) << nombres[i]
             << right << setw(15) << subtotal
             << setw(15) << descuentoAplicado
             << setw(15) << valorTotal << endl;
        
        granTotal += valorTotal;
    }
    
    cout << "----------------------------------------------------------------" << endl;
    cout << right << setw(50) << "GRAN TOTAL: $" << setw(15) << granTotal << endl;
    cout << "================================================================" << endl;
}


void calcularValorTotal(float cantidad, float valorUnitario, float descuento,
                       float &subtotal, float &descuentoAplicado, float &valorTotal) {
    subtotal = cantidad * valorUnitario;
    descuentoAplicado = subtotal * descuento;
    valorTotal = subtotal - descuentoAplicado;
}

/*
Isidro J. Gallardo Navarro

Centro ColomboAleman 

Módulos, Estructura de Almacenamiento y POO
Utilizando el Lenguaje de Programación C++ (Nivel II)

*/
