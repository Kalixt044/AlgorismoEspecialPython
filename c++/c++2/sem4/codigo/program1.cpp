#include <iostream>
#include <iomanip>
using namespace std;


double calcularCostoEnvio(double peso);
void mostrarResultado(double peso, double costo);
void mostrarMenu();


int main() {
    double peso, costoTotal;
    char continuar;
    
    do {
        mostrarMenu();
        

        cout << "\nIngrese el peso del paquete (en kilogramos): ";
        cin >> peso;
        

        if (peso <= 0) {
            cout << "\nError: El peso debe ser mayor que cero." << endl;
            cout << "Por favor, intente nuevamente.\n" << endl;
            continue;
        }
        

        costoTotal = calcularCostoEnvio(peso);
        

        mostrarResultado(peso, costoTotal);
        

        cout << "\n¿Desea calcular otro envio? (S/N): ";
        cin >> continuar;
        cout << endl;
        
    } while (continuar == 'S' || continuar == 's');
    
    cout << "Gracias por usar nuestro sistema de calculo de envios." << endl;
    
    return 0;
}


void mostrarMenu() {
    cout << "========================================" << endl;
    cout << "   CALCULADORA DE COSTO DE ENVIO" << endl;
    cout << "========================================" << endl;
    cout << "\nTarifas de envio:" << endl;
    cout << "- 0 a 10 kg: Cargo fijo $28,000" << endl;
    cout << "- 10 a 30 kg: $34,000 + $1,600 por cada kg adicional" << endl;
    cout << "- 50 kg o mas: $60,000 + $1,900 por cada kg adicional" << endl;
    cout << "========================================" << endl;
}


double calcularCostoEnvio(double peso) {
    double costoTotal = 0.0;
    const double CARGO_0_10 = 28000.0;
    const double CARGO_10_30_BASE = 34000.0;
    const double CARGO_10_30_ADICIONAL = 1600.0;
    const double CARGO_50_MAS_BASE = 60000.0;
    const double CARGO_50_MAS_ADICIONAL = 1900.0;
    

    if (peso > 0 && peso <= 10) {
        costoTotal = CARGO_0_10;
    }

    else if (peso > 10 && peso < 30) {
        double pesoAdicional = peso - 10;
        costoTotal = CARGO_10_30_BASE + (pesoAdicional * CARGO_10_30_ADICIONAL);
    }

    else if (peso >= 30 && peso < 50) {
        double pesoAdicional = peso - 10;
        costoTotal = CARGO_10_30_BASE + (pesoAdicional * CARGO_10_30_ADICIONAL);
    }

    else if (peso >= 50) {
        double pesoAdicional = peso - 50;
        costoTotal = CARGO_50_MAS_BASE + (pesoAdicional * CARGO_50_MAS_ADICIONAL);
    }
    
    return costoTotal;
}


void mostrarResultado(double peso, double costo) {
    cout << "\n========================================" << endl;
    cout << "         RESULTADO DEL CALCULO" << endl;
    cout << "========================================" << endl;
    cout << fixed << setprecision(2);
    cout << "Peso del paquete: " << peso << " kg" << endl;
    

    if (peso > 0 && peso <= 10) {
        cout << "Categoria: 0 a 10 kg (Cargo fijo)" << endl;
    } else if (peso > 10 && peso < 30) {
        cout << "Categoria: 10 a 30 kg (Con cargo adicional)" << endl;
    } else if (peso >= 30 && peso < 50) {
        cout << "Categoria: 30 a 50 kg (Con cargo adicional)" << endl;
    } else {
        cout << "Categoria: 50 kg o mas (Con cargo adicional)" << endl;
    }
    
    cout << "----------------------------------------" << endl;
    cout << "COSTO TOTAL DE ENVIO: $" << costo << endl;
    cout << "========================================" << endl;
}

/*
programa: Aplicación de parámetros por valor
Presentado: Aprendiz Digital IJ Gallardo Navarro
Centro ColomboAleman 
*/
