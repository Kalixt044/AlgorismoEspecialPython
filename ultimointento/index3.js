console.log("=== MEZCLA DE DOS VECTORES ORDENADOS (SIN DUPLICADOS) ===");

let TAMANO_VECTOR = 5;
let vectorA = [1, 3, 5, 7, 9];    
let vectorB = [1, 4, 6, 8, 10];   
let vectorMezclado = [];

console.log("Datos de entrada:");
console.log("Vector A: [1, 3, 5, 7, 9]");
console.log("Vector B: [1, 4, 6, 8, 10]");
console.log("Nota: El número 1 aparece en ambos vectores - se incluirá solo una vez");

console.log("\n--- VALIDANDO ORDEN ASCENDENTE ---");

let ordenCorrectoA = true;
for (let i = 1; i < TAMANO_VECTOR; i++) {
    if (vectorA[i] < vectorA[i - 1]) {
        ordenCorrectoA = false;
        console.log("ERROR: Vector A no está en orden ascendente");
        break;
    }
}
if (ordenCorrectoA) {
    console.log("Vector A: Orden ascendente correcto ✓");
}

let ordenCorrectoB = true;
for (let j = 1; j < TAMANO_VECTOR; j++) {
    if (vectorB[j] < vectorB[j - 1]) {
        ordenCorrectoB = false;
        console.log("ERROR: Vector B no está en orden ascendente");
        break;
    }
}
if (ordenCorrectoB) {
    console.log("Vector B: Orden ascendente correcto ✓");
}

if (ordenCorrectoA && ordenCorrectoB) {
    console.log("\n--- PROCESO DE MEZCLA SIN DUPLICADOS ---");
    

    let i = 0; // Índice para Vector A
    let j = 0; // Índice para Vector B
    let k = 0; // Índice para Vector Mezclado
    

    while (i < TAMANO_VECTOR || j < TAMANO_VECTOR) {
        if (i < TAMANO_VECTOR && j < TAMANO_VECTOR) {

            if (vectorA[i] < vectorB[j]) {

                vectorMezclado[k] = vectorA[i];
                console.log("Paso " + (k + 1) + ": Agregando " + vectorA[i] + " del Vector A");
                i = i + 1;
                k = k + 1;
            } else if (vectorA[i] > vectorB[j]) {

                vectorMezclado[k] = vectorB[j];
                console.log("Paso " + (k + 1) + ": Agregando " + vectorB[j] + " del Vector B");
                j = j + 1;
                k = k + 1;
            } else {

                vectorMezclado[k] = vectorA[i];
                console.log("Paso " + (k + 1) + ": Agregando " + vectorA[i] + " (duplicado encontrado - se incluye solo una vez)");
                i = i + 1;
                j = j + 1;
                k = k + 1;
            }
        } else if (i < TAMANO_VECTOR) {

            vectorMezclado[k] = vectorA[i];
            console.log("Paso " + (k + 1) + ": Agregando " + vectorA[i] + " del Vector A (restante)");
            i = i + 1;
            k = k + 1;
        } else if (j < TAMANO_VECTOR) {

            vectorMezclado[k] = vectorB[j];
            console.log("Paso " + (k + 1) + ": Agregando " + vectorB[j] + " del Vector B (restante)");
            j = j + 1;
            k = k + 1;
        }
    }
    
    console.log("\n=== RESULTADOS DE LA MEZCLA ===");
    

    let textoVectorA = "";
    for (let x = 0; x < TAMANO_VECTOR; x++) {
        if (x === 0) {
            textoVectorA = vectorA[x];
        } else {
            textoVectorA = textoVectorA + ", " + vectorA[x];
        }
    }
    console.log("Vector A original: [" + textoVectorA + "]");
    

    let textoVectorB = "";
    for (let y = 0; y < TAMANO_VECTOR; y++) {
        if (y === 0) {
            textoVectorB = vectorB[y];
        } else {
            textoVectorB = textoVectorB + ", " + vectorB[y];
        }
    }
    console.log("Vector B original: [" + textoVectorB + "]");
    

    let textoVectorMezclado = "";
    for (let z = 0; z < k; z++) {
        if (z === 0) {
            textoVectorMezclado = vectorMezclado[z];
        } else {
            textoVectorMezclado = textoVectorMezclado + ", " + vectorMezclado[z];
        }
    }
    console.log("Vector Mezclado Final (sin duplicados): [" + textoVectorMezclado + "]");
    console.log("Tamaño del vector resultado: " + k + " elementos");
    

    console.log("\n--- VERIFICACIÓN FINAL ---");
    let mezclaBienOrdenada = true;
    for (let w = 1; w < k; w++) {
        if (vectorMezclado[w] < vectorMezclado[w - 1]) {
            mezclaBienOrdenada = false;
            break;
        }
    }
    
    if (mezclaBienOrdenada) {
        console.log("✓ La mezcla resultante está correctamente ordenada");
    } else {
        console.log("✗ Error: La mezcla no está ordenada correctamente");
    }
    
    console.log("\n--- VERIFICACIÓN DE DUPLICADOS ---");
    let hayDuplicados = false;
    for (let d1 = 0; d1 < k - 1; d1++) {
        for (let d2 = d1 + 1; d2 < k; d2++) {
            if (vectorMezclado[d1] === vectorMezclado[d2]) {
                hayDuplicados = true;
                console.log("✗ Duplicado encontrado: " + vectorMezclado[d1]);
                break;
            }
        }
        if (hayDuplicados) {
            break;
        }
    }
    
    if (!hayDuplicados) {
        console.log("✓ No se encontraron duplicados en el vector mezclado");
    }
    
} else {
    console.log("No se puede realizar la mezcla debido a errores en el orden de los vectores.");
}
