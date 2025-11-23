#include <iostream>
using namespace std;

int main() {
    int numero;
    
    cout << "Ingrese un número: ";
    cin >> numero;
    
    cout << "\nTabla de multiplicar del " << numero << ":\n";
    cout << "================================\n";
    
    for (int i = 1; i <= 10; i++) {
        cout << numero << " x " << i << " = " << (numero * i) << "\n";
    }
    
    return 0;
}
