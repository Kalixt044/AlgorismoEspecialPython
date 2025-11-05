#include <iostream>
#include <cstdlib>  

using namespace std;

int main()
{
    int a, b, suma, resta, mult, div, mod;  // Corregido: punto por coma

    cout << "Digite dos numeros para realizar las operaciones Basicas";  
    cout << endl << endl << "Digite el primer numero a =" << endl;
    cin >> a;
    cout << endl << "Digite el segundo numero b = " << endl;  
    cin >> b;

    suma = a + b;
    resta = a - b;
    mult = a * b;
    div = a / b;
    mod = a % b;

    cout << endl << "El resultado con operadores aritmeticos es...";
    cout << endl << endl;

    cout << a << " + " << b << " = " << suma << endl;
    cout << a << " - " << b << " = " << resta << endl; 
    cout << a << " * " << b << " = " << mult << endl; 
    cout << a << " / " << b << " = " << div << endl; 
    cout << a << " % " << b << " = " << mod << endl; 

    system("pause");
    return EXIT_SUCCESS;
}
