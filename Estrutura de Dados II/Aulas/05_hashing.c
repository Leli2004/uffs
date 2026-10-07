#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 05_hashing.c -o hashing

struct no {
    int k;
    struct no *next;
};
typedef struct no nodo;

nodo** create(int m) {
    // aloca espaço
    nodo **h_table = (nodo**)malloc(m * sizeof(nodo*));

    // inicializa todos os elementos com null
    for (int i=0; i<m; i++) {
        h_table[i] = NULL;
    }

    return h_table;
}

int hash(int x, int m) {
    return x % m;
}

void inserir(nodo **n, int pos, int x) {
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    aux->k = x;
    aux->next = n[pos];
    n[pos] = aux;
}

void imprimir(nodo **n, int m) {
    printf("\nImprimindo...\n");
    for(int i=0; i<m; i++) {
        printf("Posição %d => ", i);

        nodo *aux = n[i];

        for(aux=n[i]; aux!=NULL; aux=aux->next) {
            printf("%d -> ", aux->k);
        }

        printf("NULL \n");
    };
}

int main() {
    int x = 0;
    int m = 3;

    // Teste 1
    x = 2;
    int pos = hash(x, m);
    nodo **h_table = create(m);
    inserir(h_table, pos, x);
    imprimir(h_table, m);

    // Teste 2
    x = 5;
    int pos2 = hash(x, m);
    inserir(h_table, pos2, x);
    imprimir(h_table, m);

    // Teste 3
    x = 3;
    int pos3 = hash(x, m);
    inserir(h_table, pos3, x);
    imprimir(h_table, m);
    
    return 0;
}
