/***
**/


function calcularHipotenusa(a, b) {
  return Math.sqrt(a * a + b * b);
}

const catetoA = 3;
const catetoB = 4;
const hipotenusa = calcularHipotenusa(catetoA, catetoB);
console.log(`La hipotenusa es: ${hipotenusa}`); // Resultado: 5
