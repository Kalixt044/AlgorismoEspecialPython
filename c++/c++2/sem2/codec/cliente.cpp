#include <iostream>
#include <vector>
#include <string>
#include <limits> 

using namespace std;

/**
 * @brief Función para limpiar el buffer de entrada después de leer números.
 * Esto previene problemas al mezclar cin >> int/float con getline.
 */
void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// =================================================================
//                      MÓDULO DE CLIENTES
// =================================================================

int main() {
    int satisfecho = 0; 
    
    cout << "=================================================" << endl;
    cout << "           BIENVENIDO AL MÓDULO DE CLIENTES" << endl;
    cout << "=================================================" << endl;


    do {
        int numProductos;

        vector<string> listaCompra; 


        cout << "\n>>> Generación de Lista de Compras <<<" << endl;
        cout << "¿Cuántos productos desea agregar a su lista de compra? ";
        while (!(cin >> numProductos) || numProductos <= 0) {
            cout << "Entrada inválida. Por favor, ingrese un número entero positivo: ";
            cin.clear(); 
            limpiarBuffer();
        }
        limpiarBuffer(); 


        cout << "\nPor favor, ingrese el nombre de cada uno de los " << numProductos << " productos:" << endl;
        for (int i = 0; i < numProductos; ++i) {
            string nombre;
            cout << "Producto " << i + 1 << ": ";
            getline(cin, nombre);
            listaCompra.push_back(nombre);
        }


        cout << "\n--- Lista de Productos Ingresados ---" << endl;
        for (size_t i = 0; i < listaCompra.size(); ++i) {
            cout << i + 1 << ". " << listaCompra[i] << endl;
        }
        cout << "-------------------------------------" << endl;


        cout << "\n¿Se encuentra satisfecho con esta lista o desea una nueva?" << endl;
        cout << "Ingrese **1** si está SATISFECHO o **0** para generar una NUEVA lista: ";
        
        while (!(cin >> satisfecho) || (satisfecho != 0 && satisfecho != 1)) {
            cout << "Opción inválida. Ingrese **1** o **0**: ";
            cin.clear();
            limpiarBuffer();
        }

    } while (satisfecho == 0); 


    cout << "\n=================================================" << endl;
    cout << "¡Gracias por su visita! ¡Esperamos verte pronto! 👋" << endl;
    cout << "=================================================" << endl;

    return 0;
}
