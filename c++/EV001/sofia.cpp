#include <iostream>
using namespace std;

int main()
{
    int referencia;  
    char descripcion[40];
    char talla[10];  
    char disponible[3];  
    int costo;
    int precio;

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

    
    cout << "La Referencia es: " << referencia << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "La Talla es: " << talla << endl;
    cout << "Esta disponible: " << disponible << endl;
    cout << "El costo es: " << costo << endl;
    cout << "El precio al publico es: " << precio << endl;

    system("pause");
    return 0;
}