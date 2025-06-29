/***
**/


function radioEsfera(volumen) {
  return Math.sqrt(Math.sqrt(3 * volumen / (4 * Math.PI)));
}

const volumen = 100;
const radio = radioEsfera(volumen);
console.log(`El radio de la esfera es: ${radio.toFixed(2)}`);
