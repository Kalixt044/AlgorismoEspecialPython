#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct InformacionBasica {
    string cedula;
    string nombres;
    string telefono;
    string cargo;
    double salarioBasico;
};

struct InformacionLaboral {
    int horasExtras;
    double descuentosPrestamos;
    double ahorroVoluntario;
    double descuentosSeguridadSocial;
};

struct Empleado {
    InformacionBasica basica;
    InformacionLaboral laboral;
    double valorPagar;
};

vector<Empleado> empleados;

string convertirMinusculas(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    return texto;
}

void diligenciarInformacionBasica(Empleado &emp) {
    cout << "\n=== INFORMACION BASICA ===" << endl;
    cout << "Cedula: ";
    cin.ignore();
    getline(cin, emp.basica.cedula);
    
    cout << "Nombres: ";
    getline(cin, emp.basica.nombres);
    
    cout << "Telefono: ";
    getline(cin, emp.basica.telefono);
    
    cout << "Cargo: ";
    getline(cin, emp.basica.cargo);
    
    cout << "Salario basico: $";
    cin >> emp.basica.salarioBasico;
}

void diligenciarInformacionLaboral(Empleado &emp) {
    cout << "\n=== INFORMACION LABORAL ===" << endl;
    cout << "Horas extras laboradas: ";
    cin >> emp.laboral.horasExtras;
    
    cout << "Descuentos por prestamos: $";
    cin >> emp.laboral.descuentosPrestamos;
    
    cout << "Ahorro voluntario: $";
    cin >> emp.laboral.ahorroVoluntario;
    
    cout << "Descuentos por seguridad social: $";
    cin >> emp.laboral.descuentosSeguridadSocial;
}

void calcularValorPagar(Empleado &emp) {
    const double VALOR_HORA_EXTRA = 15000; // Valor por hora extra
    double valorHorasExtras = emp.laboral.horasExtras * VALOR_HORA_EXTRA;
    
    emp.valorPagar = emp.basica.salarioBasico + valorHorasExtras 
                    - emp.laboral.descuentosPrestamos 
                    - emp.laboral.ahorroVoluntario 
                    - emp.laboral.descuentosSeguridadSocial;
    
    if (emp.valorPagar < 0) {
        emp.valorPagar = 0;
    }
}

void mostrarInformacionPago(const Empleado &emp) {
    cout << "\n=== COMPROBANTE DE PAGO ===" << endl;
    cout << "Cedula: " << emp.basica.cedula << endl;
    cout << "Nombres: " << emp.basica.nombres << endl;
    cout << "Cargo: " << emp.basica.cargo << endl;
    cout << "Telefono: " << emp.basica.telefono << endl;
    cout << "--------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Salario basico: $" << emp.basica.salarioBasico << endl;
    cout << "Horas extras: " << emp.laboral.horasExtras << " horas" << endl;
    cout << "Descuentos por prestamos: $" << emp.laboral.descuentosPrestamos << endl;
    cout << "Ahorro voluntario: $" << emp.laboral.ahorroVoluntario << endl;
    cout << "Seguridad social: $" << emp.laboral.descuentosSeguridadSocial << endl;
    cout << "--------------------------------" << endl;
    cout << "VALOR TOTAL A PAGAR: $" << emp.valorPagar << endl;
    cout << "=================================" << endl;
}

void buscarEmpleadoPorNombre() {
    if (empleados.empty()) {
        cout << "\nNo hay empleados registrados." << endl;
        return;
    }
    
    string nombreBuscar;
    cout << "\nIngrese el nombre del empleado a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscar);
    
    string nombreBuscarMin = convertirMinusculas(nombreBuscar);
    vector<int> empleadosEncontrados;
    
    for (size_t i = 0; i < empleados.size(); i++) {
        string nombreEmpleado = convertirMinusculas(empleados[i].basica.nombres);
        
        if (nombreEmpleado.find(nombreBuscarMin) != string::npos) {
            empleadosEncontrados.push_back(i);
        }
    }
    
    if (empleadosEncontrados.empty()) {
        cout << "\nNo se encontraron empleados con ese nombre." << endl;
    } else {
        cout << "\n=== EMPLEADOS ENCONTRADOS ===" << endl;
        cout << "Se encontraron " << empleadosEncontrados.size() << " empleado(s):\n" << endl;
        
        for (size_t i = 0; i < empleadosEncontrados.size(); i++) {
            int indice = empleadosEncontrados[i];
            cout << (i + 1) << ". " << empleados[indice].basica.nombres 
                 << " - Cedula: " << empleados[indice].basica.cedula << endl;
        }
        
        cout << "\n¿Desea ver el comprobante de pago? (1=Si, 0=No): ";
        int verDetalle;
        cin >> verDetalle;
        
        if (verDetalle == 1) {
            if (empleadosEncontrados.size() == 1) {
                calcularValorPagar(empleados[empleadosEncontrados[0]]);
                mostrarInformacionPago(empleados[empleadosEncontrados[0]]);
            } else {
                cout << "Seleccione el empleado (1-" << empleadosEncontrados.size() << "): ";
                int seleccion;
                cin >> seleccion;
                
                if (seleccion >= 1 && seleccion <= static_cast<int>(empleadosEncontrados.size())) {
                    int indice = empleadosEncontrados[seleccion - 1];
                    calcularValorPagar(empleados[indice]);
                    mostrarInformacionPago(empleados[indice]);
                } else {
                    cout << "\nSeleccion invalida!" << endl;
                }
            }
        }
    }
}


void mostrarTodosLosPagos() {
    if (empleados.empty()) {
        cout << "\nNo hay empleados registrados." << endl;
        return;
    }
    
    cout << "\n=== PAGOS DE TODOS LOS EMPLEADOS ===" << endl;
    for (size_t i = 0; i < empleados.size(); i++) {
        cout << "\nEmpleado " << (i + 1) << ":" << endl;
        calcularValorPagar(empleados[i]);
        mostrarInformacionPago(empleados[i]);
    }
}

void mostrarMenu() {
    cout << "\n=== SISTEMA DE GESTION DE NOMINA ===" << endl;
    cout << "1. Registrar nuevo empleado" << endl;
    cout << "2. Calcular y mostrar pago de un empleado (por indice)" << endl;
    cout << "3. Buscar empleado por nombre" << endl;
    cout << "4. Mostrar todos los pagos" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}


int main() {
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                Empleado nuevoEmpleado;
                diligenciarInformacionBasica(nuevoEmpleado);
                diligenciarInformacionLaboral(nuevoEmpleado);
                empleados.push_back(nuevoEmpleado);
                cout << "\nEmpleado registrado exitosamente!" << endl;
                break;
            }
            
            case 2: {
                if (empleados.empty()) {
                    cout << "\nNo hay empleados registrados." << endl;
                    break;
                }
                
                int indice;
                cout << "\nSeleccione el empleado (1-" << empleados.size() << "): ";
                cin >> indice;
                
                if (indice >= 1 && indice <= static_cast<int>(empleados.size())) {
                    calcularValorPagar(empleados[indice - 1]);
                    mostrarInformacionPago(empleados[indice - 1]);
                } else {
                    cout << "\nIndice invalido!" << endl;
                }
                break;
            }
            
            case 3: {
                buscarEmpleadoPorNombre();
                break;
            }
            
            case 4: {
                mostrarTodosLosPagos();
                break;
            }
            
            case 5: {
                cout << "\nGracias por usar el sistema de nomina!" << endl;
                break;
            }
            
            default: {
                cout << "\nOpcion invalida! Intente nuevamente." << endl;
                break;
            }
        }
        
    } while (opcion != 5);
    
    return 0;
}