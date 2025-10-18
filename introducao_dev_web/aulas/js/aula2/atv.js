console.log("***********************************************************************")
console.log("EXERCICIO A");
// a) 
// Escreva uma função que receba dois parâmetros: uma string e um caractere.
// A função deve mostrar e retornar a quantidade de vezes que o caractere aparece na string.
// A posição i da string pode ser acessada através de string[i]. O último elemento da string é string.length - 1. 
// Chame a função com valores de exemplo e imprima o resultado.

function contarCaractere(texto, caractere) {
    let contador = 0;
    for (let i = 0; i < texto.length; i++) {
        if (texto[i] === caractere) {
            contador++;
        }
    }
    return contador;
}

// let str = prompt("a) Informe uma string:");
// let char = prompt("a) informa um caractere:");
// let contador = contarCaractere(str, char);
// console.log(`O caractere '${char}' aparece ${contador} vezes em "${str}".`);

// exemplo:
let str = "banana";
let char = "a";
let contador = contarCaractere("banana", "a");
console.log(`O caractere '${char}' aparece ${contador} vezes em "${str}".`);

console.log("***********************************************************************")
console.log("\nEXERCICIO B");
// b) 
// Escreva uma função chamada calcularAreaRetangulo que receba dois parâmetros: largura e altura. 
// A função deve retornar a área do retângulo (largura * altura). 
// Para este exercício, utilize Arrow Functions. Em seguida, chame a função com valores de exemplo e imprima o resultado.

const calcularAreaRetangulo = (largura, altura) => largura * altura;

// exemplo:
let area = calcularAreaRetangulo(5,10);
console.log("Area do retangulo:", area);

console.log("***********************************************************************")
console.log("\nEXERCICIO C");
// c) 
// Crie uma função chamada verificarPrimo que receba um número inteiro como parâmetro e retorne true se o número for primo, 
// ou false caso contrário. Um número primo é um número maior que 1 que não possui divisores positivos além de 1 e dele mesmo.

function verificarPrimo(numero) {
    if (numero <= 1) return false;
    for (let i = 2; i <= Math.sqrt(numero); i++) {
        if (numero % i === 0) return false;
    }
    return true;
}

// exemplo:
let numeroTeste = 3;
console.log(`O numero ${numeroTeste} eh primo? ${verificarPrimo(numeroTeste)}`);

console.log("***********************************************************************")
console.log("\nEXERCICIO D");
// d)
// Desenvolva um programa que solicite ao usuário três números inteiros e, em seguida, calcule e imprima a média desses números. 
// A saída deve ser formatada com duas casas decimais.

let n1 = parseFloat(prompt("Digite o primeiro numero inteiro:"));
let n2 = parseFloat(prompt("Digite o segundo numero inteiro:"));
let n3 = parseFloat(prompt("Digite o terceiro numero inteiro:"));

let media = (n1 + n2 + n3) / 3;
let mediaFormatada = media.toFixed(2);

console.log("A media dos numeros eh: ", mediaFormatada);

console.log("***********************************************************************")
