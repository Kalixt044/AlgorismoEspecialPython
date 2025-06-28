// Definición de las notas (en escala de 100)

let nota1 = 85;
let nota2 = 68;
let nota3 = 72;
let nota4 = 90;
let nota5 = 55;

// Calcular el promedio
let promedio = (nota1 + nota2 + nota3 + nota4 + nota5) / 5;

// Evaluar si el promedio es mayor o igual a 70
if (promedio >= 70) {
    console.log('Aprobado con promedio: ${promedio.toFixed(1)}');
} else {
    console.log('Reprobado con promedio: ${promedio.toFixed(1)}');
}

// Identificar y numerar las notas que no pasan el promedio de 70
console.log('\nNotas que no alcanzaron 70:');

let contadorNotasBajas = 0;
const notas = [nota1, nota2, nota3, nota4, nota5];

notas.forEach((nota, index) => {
    if (nota < 70) {
        contadorNotasBajas++;
        console.log('${contadorNotasBajas}. Nota ${index + 1}: ${nota}');
    }
});

// Mostrar resumen final
console.log(`\nResumen:
- Total de notas evaluadas: ${notas.length}
- Notas bajo 70: ${contadorNotasBajas}
- Porcentaje de aprobación: ${((notas.length - contadorNotasBajas) / notas.length * 100).toFixed(1)}%`);
