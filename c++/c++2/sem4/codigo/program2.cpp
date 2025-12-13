#include <iostream>
#include <iomanip>
using namespace std;

void solicitarDatos(double &salarioAnual, int &antiguedad);
void calcularAumento(double salarioAnual, int antiguedad, double &salarioNuevo, double &porcentajeAumento);
void calcularSalarioMensual(double salarioAnual, double &salarioMensual);
void mostrarResultados(double salarioActual, double salarioNuevo, int antiguedad, 
                       double porcentajeAumento, double mensualActual, double mensualNuevo);
void mostrarMenu();

int main() {
    double salarioAnual, salarioNuevo, porcentajeAumento;
    double salarioMensualActual, salarioMensualNuevo;
    int antiguedad;
    char continuar;
    
    do {
        mostrarMenu();
        

        solicitarDatos(salarioAnual, antiguedad);
        

        calcularAumento(salarioAnual, antiguedad, salarioNuevo, porcentajeAumento);
        

        calcularSalarioMensual(salarioAnual, salarioMensualActual);
        calcularSalarioMensual(salarioNuevo, salarioMensualNuevo);
        

        mostrarResultados(salarioAnual, salarioNuevo, antiguedad, 
                         porcentajeAumento, salarioMensualActual, salarioMensualNuevo);
        

        cout << "\n¿Desea calcular otro salario? (S/N): ";
        cin >> continuar;
        cout << endl;
        
    } while (continuar == 'S' || continuar == 's');
    
    cout << "Gracias por usar el sistema de calculo de salarios." << endl;
    
    return 0;
}




void mostrarMenu() {
    cout << "========================================" << endl;
    cout << "  CALCULADORA DE AUMENTO SALARIAL" << endl;
    cout << "========================================" << endl;
    cout << "\nPorcentajes de aumento segun antiguedad:" << endl;
    cout << "- 0 a 5 años: 6% de aumento" << endl;
    cout << "- 5 a 10 años: 8% de aumento" << endl;
    cout << "- Mas de 10 años: 10% de aumento" << endl;
    cout << "========================================\n" << endl;
}

void solicitarDatos(double &salarioAnual, int &antiguedad) {

    do {
        cout << "Ingrese el salario anual actual del empleado: $";
        cin >> salarioAnual;
        
        if (salarioAnual <= 0) {
            cout << "Error: El salario debe ser mayor que cero." << endl;
            cout << "Por favor, intente nuevamente.\n" << endl;
        }
    } while (salarioAnual <= 0);
    

    do {
        cout << "Ingrese la antiguedad del empleado (en años): ";
        cin >> antiguedad;
        
        if (antiguedad < 0) {
            cout << "Error: La antiguedad no puede ser negativa." << endl;
            cout << "Por favor, intente nuevamente.\n" << endl;
        }
    } while (antiguedad < 0);
}


void calcularAumento(double salarioAnual, int antiguedad, double &salarioNuevo, double &porcentajeAumento) {

    if (antiguedad >= 0 && antiguedad <= 5) {
        porcentajeAumento = 6.0;
    } else if (antiguedad > 5 && antiguedad <= 10) {
        porcentajeAumento = 8.0;
    } else { 
        porcentajeAumento = 10.0;
    }
    

    double aumento = salarioAnual * (porcentajeAumento / 100.0);
    salarioNuevo = salarioAnual + aumento;
}


void calcularSalarioMensual(double salarioAnual, double &salarioMensual) {
    salarioMensual = salarioAnual / 12.0;
}


void mostrarResultados(double salarioActual, double salarioNuevo, int antiguedad, 
                       double porcentajeAumento, double mensualActual, double mensualNuevo) {
    cout << "\n========================================" << endl;
    cout << "         RESULTADOS DEL CALCULO" << endl;
    cout << "========================================" << endl;
    cout << fixed << setprecision(2);
    
    cout << "\nDATOS DEL EMPLEADO:" << endl;
    cout << "Antiguedad: " << antiguedad << " años" << endl;
    cout << "Porcentaje de aumento aplicado: " << porcentajeAumento << "%" << endl;
    
    cout << "\n----------------------------------------" << endl;
    cout << "SALARIO ACTUAL:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Salario anual: $" << salarioActual << endl;
    cout << "Salario mensual: $" << mensualActual << endl;
    

    cout << "\n----------------------------------------" << endl;
    cout << "SALARIO PROXIMO AÑO:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Salario anual: $" << salarioNuevo << endl;
    cout << "Salario mensual: $" << mensualNuevo << endl;

    double diferenciaAnual = salarioNuevo - salarioActual;
    double diferenciaMensual = mensualNuevo - mensualActual;
    
    cout << "\n----------------------------------------" << endl;
    cout << "INCREMENTO:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Incremento anual: $" << diferenciaAnual << endl;
    cout << "Incremento mensual: $" << diferenciaMensual << endl;
    cout << "========================================" << endl;
}


/*
programa: Aplicación de parámetros por valor
Presentado: Aprendiz Digital IJ Gallardo Navarro
Centro ColomboAleman 
*/
