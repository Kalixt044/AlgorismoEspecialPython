console.log("=== ANÁLISIS ESTADÍSTICO DE EDADES ===");


let edades = [25, 17, 45, 65, 30, 19, 72, 8, 35, 50];
let MAX_PERSONAS = 10;

let sumaEdades = 0;
let edadMinima = 121; 
let edadMaxima = 0;   
let menores = 0;      
let mayores = 0;      
let adultosMayores = 0; 

console.log("Edades a analizar:");
let i = 0;
while (i < MAX_PERSONAS) {
    console.log("Persona " + (i + 1) + ": " + edades[i] + " años");
    i = i + 1;
}

console.log("\n--- PROCESANDO DATOS ---");


for (let j = 0; j < MAX_PERSONAS; j++) {
    let edad = edades[j];
    

    if (edad >= 1 && edad <= 120) {
        // Sumar para el promedio
        sumaEdades = sumaEdades + edad;
        
        // Encontrar edad mínima
        if (edad < edadMinima) {
            edadMinima = edad;
        }
        
        // Encontrar edad máxima
        if (edad > edadMaxima) {
            edadMaxima = edad;
        }
        
        // Clasificar por grupos de edad
        if (edad < 18) {
            menores = menores + 1;
        } else {
            mayores = mayores + 1;
        }
        
        // Contar adultos mayores
        if (edad >= 60) {
            adultosMayores = adultosMayores + 1;
        }
    } else {
        console.log("Edad inválida detectada: " + edad);
    }
}

// Calcular promedio
let promedio = sumaEdades / MAX_PERSONAS;


console.log("\n=== RESULTADOS ESTADÍSTICOS ===");
console.log("Total de personas encuestadas: " + MAX_PERSONAS);
console.log("Menores de edad (<18): " + menores);
console.log("Mayores de edad (>=18): " + mayores);
console.log("Adultos mayores (>=60): " + adultosMayores);
console.log("Edad más baja: " + edadMinima + " años");
console.log("Edad más alta: " + edadMaxima + " años");
console.log("Promedio de edades: " + promedio.toFixed(2) + " años");


console.log("\n--- DISTRIBUCIÓN POR RANGOS ---");
let ninos = 0;        // 1-12 años
let adolescentes = 0; // 13-17 años  
let adultos = 0;      // 18-59 años
let ancianos = 0;     // 60+ años

for (let k = 0; k < MAX_PERSONAS; k++) {
    let edad = edades[k];
    
    if (edad >= 1 && edad <= 12) {
        ninos = ninos + 1;
    } else if (edad >= 13 && edad <= 17) {
        adolescentes = adolescentes + 1;
    } else if (edad >= 18 && edad <= 59) {
        adultos = adultos + 1;
    } else if (edad >= 60) {
        ancianos = ancianos + 1;
    }
}

console.log("Niños (1-12 años): " + ninos);
console.log("Adolescentes (13-17 años): " + adolescentes);
console.log("Adultos (18-59 años): " + adultos);
console.log("Adultos mayores (60+ años): " + ancianos);