def convert_seconds():
    # Pedir input al usuario
    str_seconds = input("Por favor ingrese el número de segundos: ")
    
    # Convertir el input a entero
    total_secs = int(str_seconds)
    
    # Calcular horas
    hours = total_secs // 3600
    
    # Calcular segundos restantes después de las horas
    secs_still_remaining = total_secs % 3600
    
    # Calcular minutos
    minutes = secs_still_remaining // 60
    
    # Calcular segundos finales
    secs_finally_remaining = secs_still_remaining % 60
    
    # Imprimir resultado
    print("Hrs=", hours, "mins=", minutes, "secs=", secs_finally_remaining)

# Ejemplo de uso
convert_seconds()

