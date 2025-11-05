#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int referencia;  
    char descripcion[40];
    char talla[10];  
    char disponible[3];  
    int costo;
    int precio;
    int precio5Uni;
    int utilidad;
    int utilidadTotal;
    int porcentaje;

    cout << "Digita la Referencia..." << endl;
    cin >> referencia;
    
    cin.ignore();
    
    cout << "Digita una Descripcion Breve" << endl;
    cin.getline(descripcion, 40);
    
    cout << "Digite la Talla.." << endl;
    cin.getline(talla, 10);
    
    cout << "Esta Disponible?... Digite S o N " << endl;
    cin.getline(disponible, 3);
    
    cout << "Digite el Costo..." << endl;
    cin >> costo;
    
    cout << "Digite el precio de Venta" << endl;
    cin >> precio;

    utilidad = precio - costo;
    
    precio5Uni = (precio * 5) - ((precio * 5) / 10); 
    
    utilidadTotal = precio5Uni - (costo * 5); 

    porcentaje = static_cast<int>((static_cast<double>(utilidad) / costo) * 100);

    cout << "\n--- Datos Ingresados ---\n";
    cout << "La Referencia es: " << referencia << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "La Talla es: " << talla << endl;
    cout << "Esta disponible: " << disponible << endl;
    cout << "El costo es: " << costo << endl;
    cout << "El precio al publico es: " << precio << endl;

    cout << "\n--- Variables Calculadas ---\n";
    cout << "El precio por 5 unidades con descuento es: " << precio5Uni << endl;
    cout << "La utilidad por unidad es: " << utilidad << endl;
    cout << "La utilidad total (por 5 unidades) es: " << utilidadTotal << endl;
    cout << "El porcentaje de utilidad es: " << porcentaje << " %" << endl;
    
    return 0;
}
