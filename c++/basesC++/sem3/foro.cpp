#include <iostream>
using namespace std;

int main(){

int score = 75;
bool hasBonus = true;

if (score >= 70) {
    cout << "aprobaste el examen.\n";
    
    if (hasBonus) {
        cout << "Tienes un bono de puntos!\n";
    } else {
        cout << "No tienes bono de puntos \n";
    }
} else {
    cout << "No aprobaste el examen";
}
return 0;
}
