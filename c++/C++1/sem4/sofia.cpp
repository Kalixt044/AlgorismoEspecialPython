#include <iostream>
#include <iomanip>
#include <limits> 
#include <cctype> 
using namespace std;

int main()
{
    int referencia;  
    char descripcion[40];
    char talla[10];  
    char disponible[3];  
    int costo;
    int precio;
    char tipoZapato;
    int precio5Uni;
    int utilidad;
    int utilidadTotal;
    int porcentaje;
    
    char opcion = 'S'; 
    
    while (opcion == 'S')
    {
        cout << "\n========================================\n";
        cout << "      INGRESO DE NUEVO PRODUCTO\n";
        cout << "========================================\n";
        cout << "Digita la Referencia..." << endl;
        
        if (!(cin >> referencia)) {
            cout << "ERROR: Entrada no válida para la referencia." << endl;
            opcion = 'N'; 
            break; 
        }
        
        cin.ignore();
        
        cout << "Digita una Descripcion Breve" << endl;
        cin.getline(descripcion, 40);
        
        cout << "Digite la Talla.." << endl;
        cin.getline(talla, 10);
        
        cout << "Esta Disponible?... Digite S o N " << endl;
        cin.getline(disponible, 3);
        
        cout << "Digite el Costo..." << endl;
        
        if (!(cin >> costo)) {
            cout << "ERROR: Entrada no válida para el costo." << endl;
            opcion = 'N'; 
            break;
        }
        
        
        if (costo <= 30000) {
            tipoZapato = 'A';
        } else if (costo <= 60000) {
            tipoZapato = 'B';
        } else {
            tipoZapato = 'C';
        }
        
        
        switch(tipoZapato) {
            case 'A':
                porcentaje = 50;
                break;
            case 'B':
                porcentaje = 40;
                break;
            case 'C':
                porcentaje = 30;
                break;
            default:
                porcentaje = 0;
                cout << "ERROR: Tipo de zapato no reconocido." << endl;
                break;
        }
        
        precio = costo + static_cast<int>(costo * (static_cast<double>(porcentaje) / 100.0));
        
        utilidad = precio - costo;
        precio5Uni = (precio * 5) - ((precio * 5) / 10); 
        utilidadTotal = precio5Uni - (costo * 5); 
        
        cout << "\n--- Datos Ingresados y Calculados ---\n";
        cout << "La Referencia es: " << referencia << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "La Talla es: " << talla << endl;
        cout << "Esta disponible: " << disponible << endl;
        cout << "El costo es: " << costo << endl;
        
        cout << "\n--- Resumen de Utilidad ---\n";
        cout << "El tipo de zapato es: " << tipoZapato << endl;
        cout << "El porcentaje de utilidad aplicado es: " << porcentaje << " %" << endl;
        cout << "El precio al publico es: " << precio << endl;
        cout << "La utilidad por unidad es: " << utilidad << endl;
        cout << "El precio por 5 unidades con descuento es: " << precio5Uni << endl;
        cout << "La utilidad total (por 5 unidades) es: " << utilidadTotal << endl;
        
        cout << "\n¿Desea ingresar un nuevo producto? (S/N): ";
        cin >> opcion;
        opcion = toupper(opcion);
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    
    
    switch(opcion) {
        case 'S':
            
            break;
        case 'N':
            cout << "\nProceso finalizado. Gracias por usar el sistema." << endl;
            break;
        default:
            cout << "\nOperación finalizada. Opción ingresada no reconocida." << endl;
            break;
    }
    
    return 0;
}
