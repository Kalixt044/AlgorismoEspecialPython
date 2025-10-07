console.log("=== ENCUESTA DE GUSTOS MUSICALES ===");


let MAX_PERSONAS = 6;
let contadorPersonas = 3; // Datos de ejemplo para 3 personas


let nombres = ["Juan Pérez", "María González", "Carlos Rodríguez"];
let cedulas = ["12345678", "87654321", "11223344"];
let fechasNacimiento = ["15/03/1990", "22/07/1985", "08/12/1992"];
let correos = ["juan@email.com", "maria@email.com", "carlos@email.com"];
let ciudadesResidencia = ["Bogotá", "Medellín", "Cali"];
let ciudadesOrigen = ["Cartagena", "Barranquilla", "Bucaramanga"];

let cancionesArtista1 = ["Shakira", "Manu Chao", "Jesse & Joy"];
let cancionesTitulo1 = ["Hips Don't Lie", "Me Gustas Tu", "Corre"];
let cancionesArtista2 = ["Juanes", "Jesse & Joy", ""];
let cancionesTitulo2 = ["La Camisa Negra", "Te Esperé", ""];
let cancionesArtista3 = ["", "", "Shakira"];
let cancionesTitulo3 = ["", "", "Waka Waka"];

console.log("Sistema con datos de " + contadorPersonas + " personas encuestadas");
console.log("Mostrando información registrada...\n");


console.log("=== INFORMACIÓN DE PERSONAS ENCUESTADAS ===");

for (let i = 0; i < contadorPersonas; i++) {
    console.log("\n--- PERSONA " + (i + 1) + " ---");
    console.log("Nombre: " + nombres[i]);
    console.log("Cédula: " + cedulas[i]);
    console.log("Fecha de Nacimiento: " + fechasNacimiento[i]);
    console.log("Correo: " + correos[i]);
    console.log("Ciudad de Residencia: " + ciudadesResidencia[i]);
    console.log("Ciudad de Origen: " + ciudadesOrigen[i]);
    
    console.log("Canciones Favoritas:");
    let contadorCanciones = 0;
    
    if (cancionesTitulo1[i] !== "") {
        console.log("  1. " + cancionesTitulo1[i] + " - " + cancionesArtista1[i]);
        contadorCanciones = contadorCanciones + 1;
    }
    if (cancionesTitulo2[i] !== "") {
        console.log("  2. " + cancionesTitulo2[i] + " - " + cancionesArtista2[i]);
        contadorCanciones = contadorCanciones + 1;
    }
    if (cancionesTitulo3[i] !== "") {
        console.log("  3. " + cancionesTitulo3[i] + " - " + cancionesArtista3[i]);
        contadorCanciones = contadorCanciones + 1;
    }
    
    if (contadorCanciones === 0) {
        console.log("  No registró canciones favoritas");
    }
}


console.log("\n=== ESTADÍSTICAS DE LA ENCUESTA ===");

let personasConCanciones = 0;
let totalCanciones = 0;


for (let i = 0; i < contadorPersonas; i++) {
    let cancionesPersona = 0;
    
    if (cancionesTitulo1[i] !== "") {
        cancionesPersona = cancionesPersona + 1;
    }
    if (cancionesTitulo2[i] !== "") {
        cancionesPersona = cancionesPersona + 1;
    }
    if (cancionesTitulo3[i] !== "") {
        cancionesPersona = cancionesPersona + 1;
    }
    
    if (cancionesPersona > 0) {
        personasConCanciones = personasConCanciones + 1;
    }
    
    totalCanciones = totalCanciones + cancionesPersona;
}

console.log("Total de personas encuestadas: " + contadorPersonas);
console.log("Personas que registraron canciones: " + personasConCanciones);
console.log("Total de canciones registradas: " + totalCanciones);

let promedioCanciones = totalCanciones / contadorPersonas;
console.log("Promedio de canciones por persona: " + promedioCanciones.toFixed(2));


console.log("\n--- ANÁLISIS DE ARTISTAS ---");


let artistasUnicos = [];
let conteoArtistas = [];


for (let i = 0; i < contadorPersonas; i++) {
    
    if (cancionesArtista1[i] !== "") {
        let encontrado = false;
        for (let j = 0; j < artistasUnicos.length; j++) {
            if (artistasUnicos[j] === cancionesArtista1[i]) {
                conteoArtistas[j] = conteoArtistas[j] + 1;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            artistasUnicos[artistasUnicos.length] = cancionesArtista1[i];
            conteoArtistas[conteoArtistas.length] = 1;
        }
    }
    
    
    if (cancionesArtista2[i] !== "") {
        let encontrado = false;
        for (let j = 0; j < artistasUnicos.length; j++) {
            if (artistasUnicos[j] === cancionesArtista2[i]) {
                conteoArtistas[j] = conteoArtistas[j] + 1;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            artistasUnicos[artistasUnicos.length] = cancionesArtista2[i];
            conteoArtistas[conteoArtistas.length] = 1;
        }
    }
    
    
    if (cancionesArtista3[i] !== "") {
        let encontrado = false;
        for (let j = 0; j < artistasUnicos.length; j++) {
            if (artistasUnicos[j] === cancionesArtista3[i]) {
                conteoArtistas[j] = conteoArtistas[j] + 1;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            artistasUnicos[artistasUnicos.length] = cancionesArtista3[i];
            conteoArtistas[conteoArtistas.length] = 1;
        }
    }
}


console.log("Artistas mencionados:");
for (let k = 0; k < artistasUnicos.length; k++) {
    console.log("- " + artistasUnicos[k] + ": " + conteoArtistas[k] + " mención(es)");
}


if (artistasUnicos.length > 0) {
    let maxMenciones = 0;
    let artistaPopular = "";
    
    for (let m = 0; m < conteoArtistas.length; m++) {
        if (conteoArtistas[m] > maxMenciones) {
            maxMenciones = conteoArtistas[m];
            artistaPopular = artistasUnicos[m];
        }
    }
    
    console.log("\n🏆 Artista más mencionado: " + artistaPopular + " (" + maxMenciones + " menciones)");
}

console.log("\n--- FIN DE LA ENCUESTA ---");
