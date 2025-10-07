
const PI = 3.14159;

console.log("=== CALCULADORA DE ÁREAS DE FIGURAS GEOMÉTRICAS ===");


let figura = 2; 

console.log("Figura seleccionada: " + figura);

if (figura === 1) {

    console.log("Calculando área del TRIÁNGULO");
    let base = 10;
    let altura = 8;
    console.log("Base: " + base);
    console.log("Altura: " + altura);
    let area = (base * altura) / 2;
    console.log("El área del triángulo es: " + area);
    
} else if (figura === 2) {
    
    console.log("Calculando área del RECTÁNGULO");
    let largo = 12;
    let ancho = 5;
    console.log("Largo: " + largo);
    console.log("Ancho: " + ancho);
    let area = largo * ancho;
    console.log("El área del rectángulo es: " + area);
    
} else if (figura === 3) {
    
    console.log("Calculando área del CUADRADO");
    let lado = 7;
    console.log("Lado: " + lado);
    let area = lado * lado;
    console.log("El área del cuadrado es: " + area);
    
} else if (figura === 4) {
    
    console.log("Calculando área del CÍRCULO");
    let radio = 6;
    console.log("Radio: " + radio);
    let area = PI * radio * radio;
    console.log("El área del círculo es: " + area);
    
} else {
    console.log("Opción no válida. Por favor seleccione 1, 2, 3 o 4.");
}

