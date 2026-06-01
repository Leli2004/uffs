#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaces.h"

// Listas Duplas

// gcc -Wall file.c interfaces.c -lm -o file

int main() {
    Func *first = NULL;
    Func *last = NULL;

    listaElementos(first);

    // cria primeiro
    first = inserePrimeiroElemento(first, 1, 30, 2000);
    last = first;

    listaElementos(first);

    // insere no inicio
    first = insereElementoNoInicio(first, 2, 25, 1800);

    listaElementos(first);

    // insere no fim
    last = insereElementoNoFim(last, 3, 40, 5000);
    last = insereElementoNoFim(last, 4, 35, 3500);

    listaElementos(first);

    // insere no meio (antes do id 3)
    first = insereElementoNoMeio(first, 3, 10, 28, 2500);

    listaElementos(first);

    // deleta id 10
    listaElementoPorId(first, 10);
    deletaElemento(first, 10);

    listaElementos(first);

    return 0;
}

// int main() {
//     int tam = 4;
//     int vetor[4] = {1,21,4,6};

//     ListaInt *lista;

//     lista = constroiLista(tam, vetor);
//     printListaInt(lista);
// }
