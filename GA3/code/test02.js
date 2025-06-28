// 4. Registro de estudiantes y sus materias favoritas usando estructuras básicas
// Enunciado: Registrar la información de dos estudiantes junto con sus materias favoritas
let nombres = ["Ana", "Luis"];
let edades = [20, 22];
let emails = ["ana@email.com", "luis@email.com"];
let materias = [["Matemáticas", "Física"], ["Historia", "Arte"]];

console.log("Información del primer estudiante:");
console.log("Nombre: " + nombres[0]);
console.log("Edad: " + edades[0]);
console.log("Email: " + emails[0]);
console.log("Materias favoritas: " + materias[0].join(", "));

console.log("\nInformación del segundo estudiante:");
console.log("Nombre: " + nombres[1]);
console.log("Edad: " + edades[1]);
console.log("Email: " + emails[1]);
console.log("Materias favoritas: " + materias[1].join(", "));
