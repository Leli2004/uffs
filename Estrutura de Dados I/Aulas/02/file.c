#include <stdio.h>

/******************************************/
// Gerar build: gcc -Wall file.c -o file
/******************************************/

void pointers(); // imprime valores e endereços de ponteiros
int somaInt(int, int); // soma dois inteiros
float convertDegrees(float, char); // converte graus C° e F°
void troca(int *, int *); // troca valores de dois ponteiros

int main() {
    // int n1 = 5;
    // int n2 = 6;
    // printf("Soma = %d \n", somaInt(n1, n2));
  
    // float grau = 122;
    // char tipo = 'f';
    // printf("%.2f \n", convertDegrees(grau, tipo));

    int a = 1;
    int b = 2;
    troca(&a, &b);
    printf("a=%d , b=%d \n", a, b);

    return 0;
}

void pointers() {
    int a, *b;

    a = 10;
    printf("A: %d -> %p\n", a, &a);

    b = &a;
    printf("B: %p -> %d\n", b, *b);

    char *c, c1 = 'A';
    c  = &c1;

    for(int i=0; i<100; i++) {
        printf("C: %d", c[i]);
    }
}

int somaInt(int a, int b) {
    return a + b;
}

float convertDegrees(float degree, char type) {
    float result = 0;

    if (type == 'f') {
        result = 5*(degree-32)/9;
    } else if (type == 'c') {
        result = (9*degree/5) + 32;
    }

    return result;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
