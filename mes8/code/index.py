def main():
    """
    Determina el color de una casilla de ajedrez basándose en la suma
    del valor numérico de la columna y la fila.
    """
    print("=== DETERMINADOR DE COLOR DE CASILLAS DE AJEDREZ ===\n")
    
    while True:
        # Solicitar entrada al usuario
        casilla = input("Ingrese la casilla (ejemplo: f6, a1, h8): ").strip().lower()
        
        # Validar longitud de entrada
        if len(casilla) != 2:
            print("Error: Formato inválido. Use formato como a1, f6, h8, etc.\n")
            continue
        
        columna = casilla[0]
        fila_char = casilla[1]
        
        # Validar columna (a-h)
        if columna < 'a' or columna > 'h':
            print("Error: La columna debe estar entre 'a' y 'h'.\n")
            continue
        
        # Validar fila (1-8)
        if not fila_char.isdigit() or int(fila_char) < 1 or int(fila_char) > 8:
            print("Error: La fila debe estar entre 1 y 8.\n")
            continue
        
        fila = int(fila_char)
        
        # Convertir letra de columna a número (a=1, b=2, ..., h=8)
        valor_columna = ord(columna) - ord('a') + 1
        
        # Calcular la suma
        suma = valor_columna + fila
        
        # Mostrar el proceso
        print(f"\nAnálisis de la casilla {columna}{fila}:")
        print(f"Columna '{columna}' = {valor_columna}")
        print(f"Fila = {fila}")
        print(f"{valor_columna} + {fila} = {suma}", end="")
        
        # Determinar el color según si la suma es par o impar
        if suma % 2 == 0:
            print(" (par)")
            print(f"La casilla {columna}{fila} es OSCURA.")
        else:
            print(" (impar)")
            print(f"La casilla {columna}{fila} es CLARA.")
        
        # Preguntar si desea continuar
        print("\n¿Desea probar otra casilla? (s/n): ", end="")
        respuesta = input().strip().lower()
        
        if respuesta not in ['s', 'si', 'sí', 'y', 'yes']:
            break
        
        print()  # Línea en blanco para separar

if __name__ == "__main__":
    main()
