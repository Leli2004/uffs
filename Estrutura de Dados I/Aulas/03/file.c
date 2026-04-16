#include <stdio.h>
#include <string.h>

void printStrReverso(char *v);
int getQtdVogais(char *vetor);

int main() {
    char v[20];
    printf("\nInforme uma string: ");
    scanf("%s", v);

    // printStrReverso(v);

    int qtd = getQtdVogais(v);
    printf("\nQuantia de vogais = %d", qtd);

    printf("\n");
    return 0;
}

// 1. Função que recebe string e imprime ela ao contrário
void printStrReverso(char *vetor) {
    int tam = strlen(vetor);
    for(int i=tam-1; i>=0; i--) {
        printf("%c", vetor[i]);
    }
}

// 2. Função que retorna numero de vogais da string em parametro
int getQtdVogais(char *vetor){
    int qtd = 0;
    int tam = strlen(vetor);

    for (int i=0; i<=tam; i++) {
        if(vetor[i] == 'a' || vetor[i] == 'e' || vetor[i] == 'i' || vetor[i] == 'o' || vetor[i] == 'u' || 
            vetor[i] == 'A' || vetor[i] == 'E' || vetor[i] == 'I' || vetor[i] == 'O' || vetor[i] == 'U') {
            qtd++;
        }
    }
    return qtd;
} 
