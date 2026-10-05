#include <stdio.h>
#include <stdlib.h>

// gcc -Wall file.c -o file

struct no {
    int k;
    struct no *next;
};
typedef struct no nodo;

nodo** create(int m) {
    // aloca espaço
    nodo **h_table = (nodo**)malloc(m * sizeof(nodo));

    // inicializa todos os elementos com null
    for (int i=0; i<m; i++) {
        h_table[i]->next = NULL;
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
    for(int i=0; i<m; i++) {
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        for(aux=n[i]; aux!=NULL; aux=aux->next) {
            printf("%d ", aux->k);
        }
        printf("\n");
    }
}

int main() {
    int x = 2;
    int m = 3;

    int pos = hash(x, m);

    nodo **h_table = create(m);

    inserir(h_table, pos, x);

    imprimir(h_table, m);
    
    return 0;
}
