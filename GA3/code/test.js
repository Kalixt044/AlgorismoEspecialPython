let lista1 = [1, 3, 5, 7];
let lista2 = [2, 4, 6, 8];
let listaCombinada = [];
let i = 0, j = 0;

while (i < lista1.length && j < lista2.length) {
    if (lista1[i] < lista2[j]) {
        listaCombinada.push(lista1[i]);
        i++;
    } else {
        listaCombinada.push(lista2[j]);
        j++;
    }
}
while (i < lista1.length) {
    listaCombinada.push(lista1[i]);
    i++;
}
while (j < lista2.length) {
    listaCombinada.push(lista2[j]);
    j++;
}
console.log("Lista combinada: " + listaCombinada);

