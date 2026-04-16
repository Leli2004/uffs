#include <stdio.h>

// gcc -Wall file.c -o file
/*
Desafios da recursividade:
- achar caso base
- amarrar a recursão
*/

int calculaFatorial(int);
void executaExemploFatorial();
int calculaPotencia(int, int);
void executaExemploPotencia();

int main() {
    //executaExemploFatorial();
    executaExemploPotencia();
    return 0;
}

// Exemplo fatorial
void executaExemploFatorial() {
    int fat = 0;
    printf("Informe um n° inteiro: ");
    scanf("%d", &fat);
    printf("Resultado: !%d = %d\n", fat, calculaFatorial(fat));
}

int calculaFatorial(int n) {
    if (n == 0) {
        return 1; // caso base 
    }
    return n*calculaFatorial(n-1);
}

// Exemplo Potência
int calculaPotencia(int num, int p) {
    if (p == 1) {
        return num; // caso base 
    }
    return num*calculaPotencia(num, p-1);
}

void executaExemploPotencia() {
    int pot = 0;
    int num = 0;

    printf("N° inteiro: ");
    scanf("%d", &num);
    printf("Potência: ");
    scanf("%d", &pot);

    printf("Resultado: %d^%d = %d\n", num, pot, calculaPotencia(num, pot));
}
