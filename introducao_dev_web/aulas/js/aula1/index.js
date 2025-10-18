// Introdução ao JS - variáveis, operadores, condicionais, loops e funções

// console.log("Teste Console Log");
// console.error("Teste Console Error");
// console.warn("Teste Console Warn");
// console.info("Teste Console Info");

console.log("***********************************************************************")
// 1) Mostre no console a sequencia de números entre 1 e 100
console.log("Exercício 1")
for (let i=1; i<=100; i++) {
    console.log(i);
}

console.log("***********************************************************************")
// 2) Mostre no console a sequencia de números entre 1 e 100
// porém, caso o número seja divisível por 3, mostre "chuchu" no lugar.
console.log("\nExercício 2")
for (let i=1; i<=100; i++) {
    if (i % 3 === 0) {
        console.log(i + " - chuchu");
    } else {
        console.log(i);
    }
}

console.log("***********************************************************************")
// Funções

function soma(a, b) {
    console.log("function soma = ", a + b);
}
soma(3,2);

const somaComArrowReturn = (a, b) => {
 return a + b;
}
console.log("somaComArrowReturn = ", somaComArrowReturn(4, 3));

console.log("***********************************************************************")
// Janelas de diálogo
alert("Isso é um alerta!");

let opcao = confirm("Tem certeza que deseja continuar?");
if (opcao) {
    console.log("opcao is true");
} else {
    console.log("opcao is false");
}

let nome = prompt("Digite seu nome:");
console.log("nome = ", nome)

console.log("***********************************************************************")
