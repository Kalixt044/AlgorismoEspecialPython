#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char casilla[3];
    char columna;
    int fila;
    int valor_columna, suma;
    
    printf("=== DETERMINADOR DE COLOR DE CASILLAS DE AJEDREZ ===\n\n");
    printf("Ingrese la casilla (ejemplo: f6, a1, h8): ");
    
    scanf("%2s", casilla);
    
    columna = tolower(casilla[0]);
    fila = casilla[1] - '0'; 
    
    if (columna < 'a' || columna > 'h' || fila < 1 || fila > 8) {
        printf("Error: Casilla inválida. Use formato como a1, f6, h8, etc.\n");
        return 1;
    }
    

    valor_columna = columna - 'a' + 1;
    
    suma = valor_columna + fila;
    
    printf("\nAnálisis de la casilla %c%d:\n", columna, fila);
    printf("Columna '%c' = %d\n", columna, valor_columna);
    printf("Fila = %d\n", fila);
    printf("%d + %d = %d", valor_columna, fila, suma);
    
    if (suma % 2 == 0) {
        printf(" (par)\n");
        printf("La casilla %c%d es OSCURA.\n", columna, fila);
    } else {
        printf(" (impar)\n");
        printf("La casilla %c%d es CLARA.\n", columna, fila);
    }
    
    printf("\n¿Desea probar otra casilla? (s/n): ");
    char respuesta;
    scanf(" %c", &respuesta);
    
    if (respuesta == 's' || respuesta == 'S') {
        main(); 
    }
    
    return 0;
}
