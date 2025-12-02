#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits> 

using namespace std;

/**
 * @brief Función para limpiar el buffer de entrada después de leer números.
 * Esto previene problemas al mezclar cin >> int/float con getline.
 */
void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


const int CANTIDAD = 0;
const int VALOR_UNITARIO = 1;
const int DESCUENTO_PORCENTAJE = 2; // Almacenado como decimal (ej: 0.10)
const int NUM_ATRIBUTOS = 3;


int main() {

    cout << fixed << setprecision(2);
    
    int opcionAccion = 2; 
    
    cout << "=================================================" << endl;
    cout << "           BIENVENIDO AL MÓDULO DE EMPLEADOS" << endl;
    cout << "=================================================" << endl;

 
    do {
        int numProductos;
 
        vector<vector<float>> datosProductos; 
 
        vector<string> nombresProductos; 

 
        cout << "\n>>> Cálculo de Venta por Unidad <<<" << endl;
        cout << "¿Cuántos productos desea calcular? ";
        while (!(cin >> numProductos) || numProductos <= 0) {
            cout << "Entrada inválida. Por favor, ingrese un número entero positivo: ";
            cin.clear();
            limpiarBuffer();
        }
        
        limpiarBuffer(); 


        cout << "\nPor favor, ingrese el nombre, la cantidad, el valor unitario y el descuento para cada producto:" << endl;
        for (int i = 0; i < numProductos; ++i) {
            
            cout << "--- Producto " << i + 1 << " ---" << endl;
            

            string nombre;
            cout << "Nombre del Producto: ";
            getline(cin, nombre);
            nombresProductos.push_back(nombre);


            vector<float> filaDatos(NUM_ATRIBUTOS);
            

            cout << "Cantidad: ";
            while (!(cin >> filaDatos[CANTIDAD]) || filaDatos[CANTIDAD] <= 0) {
                cout << "Entrada inválida. Ingrese una cantidad positiva: ";
                cin.clear();
                limpiarBuffer();
            }


            cout << "Valor Unitario ($): ";
            while (!(cin >> filaDatos[VALOR_UNITARIO]) || filaDatos[VALOR_UNITARIO] < 0) {
                cout << "Entrada inválida. Ingrese un valor unitario no negativo: ";
                cin.clear();
                limpiarBuffer();
            }


            float descuento_porcentaje;
            cout << "Porcentaje de Descuento (ej: 15 para 15%): ";
            while (!(cin >> descuento_porcentaje) || descuento_porcentaje < 0 || descuento_porcentaje > 100) {
                cout << "Entrada inválida. Ingrese un porcentaje entre 0 y 100: ";
                cin.clear();
                limpiarBuffer();
            }

            filaDatos[DESCUENTO_PORCENTAJE] = descuento_porcentaje / 100.0f; 

            datosProductos.push_back(filaDatos);
            limpiarBuffer();
        }


        cout << "\n--- Resumen de Información Ingresada ---" << endl;
        cout << left << setw(20) << "Producto"
             << setw(10) << "Cant." 
             << setw(15) << "Valor Unit." 
             << setw(15) << "Desc. (%)" << endl;
        cout << "--------------------------------------------------------" << endl;
        
        for (size_t i = 0; i < datosProductos.size(); ++i) {
            cout << fixed << setprecision(2);
            cout << left << setw(20) << nombresProductos[i]
                 << setw(10) << datosProductos[i][CANTIDAD]
                 << setw(15) << datosProductos[i][VALOR_UNITARIO]
                 << setw(15) << (datosProductos[i][DESCUENTO_PORCENTAJE] * 100.0f) << endl; // Mostrar en %
        }
        cout << "--------------------------------------------------------" << endl;


        cout << "\n¿Qué acción desea realizar ahora?" << endl;
        cout << "1. Calcular el valor total de cada producto." << endl;
        cout << "2. Regresar al paso anterior (Generar nueva lista de productos)." << endl;
        cout << "Ingrese su opción (1 o 2): ";
        
        while (!(cin >> opcionAccion) || (opcionAccion != 1 && opcionAccion != 2)) {
            cout << "Opción inválida. Ingrese **1** o **2**: ";
            cin.clear();
            limpiarBuffer();
        }
        limpiarBuffer();


        if (opcionAccion == 1) {
            cout << "\n--- Resultados de Cálculo de Venta ---" << endl;
            cout << left << setw(20) << "Producto"
                 << setw(15) << "Valor Base" 
                 << setw(15) << "Descuento" 
                 << setw(15) << "Valor Total" << endl;
            cout << "----------------------------------------------------------------" << endl;
            
            for (size_t i = 0; i < datosProductos.size(); ++i) {

                float cantidad = datosProductos[i][CANTIDAD];
                float valorUnitario = datosProductos[i][VALOR_UNITARIO];
                float descuentoRatio = datosProductos[i][DESCUENTO_PORCENTAJE]; 
                

                float subtotal = valorUnitario * cantidad;
                float descuentoAplicado = subtotal * descuentoRatio;
                float valorTotal = subtotal - descuentoAplicado;

                cout << fixed << setprecision(2);
                cout << left << setw(20) << nombresProductos[i]
                     << setw(15) << subtotal
                     << setw(15) << descuentoAplicado
                     << setw(15) << valorTotal << endl;
            }
            cout << "----------------------------------------------------------------" << endl;


            cout << "¿Desea generar una NUEVA lista de cálculos (2) o SALIR (0)?" << endl;
            cout << "Ingrese **2** para Nueva Lista o **0** para Salir: ";
            int salir_o_repetir;

            while (!(cin >> salir_o_repetir) || (salir_o_repetir != 0 && salir_o_repetir != 2)) {
                cout << "Opción inválida. Ingrese **2** o **0**: ";
                cin.clear();
                limpiarBuffer();
            }
            limpiarBuffer();
            
            opcionAccion = salir_o_repetir; 
        }
        
    } while (opcionAccion == 2); 
    
    cout << "\nSaliendo del Módulo de Empleados. ¡Hasta pronto!" << endl;

    return 0;
}
