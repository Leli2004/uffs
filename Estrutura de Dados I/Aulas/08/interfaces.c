#include <stdio.h>
#include <stdlib.h>
#include "interfaces.h"

// Implemente uma função que receba um vetor de valores inteiros com N elementos e construa uma lista duplamente encadeada
// n = quantidade de elementos do vetor | v = vetor
ListaInt *constroiLista (int n, int *v) {
    ListaInt *first = NULL;
    ListaInt *last = NULL;

    for (int i = 0; i < n; i++) {
        ListaInt *aux = malloc(sizeof(ListaInt));

        aux->valor = v[i];
        aux->next = NULL;
        aux->prev = NULL;

        if (first == NULL) {
            first = aux; 
            last = aux;
        } else {
            last->next = aux; 
            aux->prev = last; 
            last = aux;
        }
    }

    return first;
}

void printListaInt(ListaInt *first) {
    ListaInt *aux;
    printf("\n********************************\n");

    for (aux = first; aux != NULL; aux = aux->next) {
        printf("Valor: %d\n", aux->valor);
    }
}

// Implementar fluxo de inserir, deletar e listar funcionários

Func *inserePrimeiroElemento(Func *first, int id, int idade, float salario) {
    if (first != NULL) {
        return first;
    }

    first = (Func*)malloc (sizeof(Func));
    first->id = id;
    first->idade = idade;
    first->salario = salario;

    first->next = NULL;
    first->prev = NULL;

    return first;
}

Func *insereElementoNoInicio(Func *first, int id, int idade, float salario) {
    Func *aux;
    aux = (Func*)malloc(sizeof(Func));

    aux->id = id;
    aux->idade = idade;
    aux->salario = salario;
    aux->next = NULL;
    aux->prev = NULL;

    if (first != NULL) {
        aux->next = first;
        first->prev = aux;
    }

    first = aux;
    return first;
}

Func *insereElementoNoFim(Func *last, int id, int idade, float salario) {
    Func *aux;
    aux = (Func*) malloc(sizeof(Func));

    aux->id = id;
    aux->idade = idade;
    aux->salario = salario;
    aux->next = NULL;
    aux->prev = NULL;

    if (last != NULL) {
        aux->prev = last;
        last->next = aux;
    }

    last = aux;
    return last;
}

// Adiciona elemento antes do id do parâmetro
Func *insereElementoNoMeio(Func *first, int idReferencia, int id, int idade, float salario) {
    Func *aux;
    Func *elemento;
    aux = (Func*) malloc(sizeof(Func));

    aux->id = id;
    aux->idade = idade;
    aux->salario = salario;
    aux->next = NULL;
    aux->prev = NULL;

    // Procura o elemento que possui o id informado. O novo elemento será inserido ANTES dele.
    for (elemento = first; elemento != NULL; elemento = elemento->next) {
        if (elemento->id == idReferencia)  {
            // Se o elemento encontrado for o primeiro, reutiliza a lógica de inserção no início.
            if (elemento == first) {
                aux->next = first;
                first->prev = aux;
                first = aux;
            } else {
                // Liga o novo elemento ao próximo
                aux->next = elemento;

                // Liga o anterior ao novo elemento
                elemento->prev->next = aux;

                // Liga o novo elemento ao anterior
                aux->prev = elemento->prev;

                // Liga o elemento ao novo elemento
                elemento->prev = aux;
            }
            break;
        }
    }

    return first;
}

// Deleta elemento pelo id
Func *deletaElemento(Func *first, int idDelete) {
    Func *aux;

    for (aux = first; aux != NULL; aux = aux->next) {

        if (aux->id == idDelete) {
            if (aux == first)  { // remover primeiro elemento
                first = first->next;
                if (first != NULL) {
                    first->prev = NULL;
                }
            } else { // remover elemento do meio ou fim
                aux->prev->next = aux->next;
                if (aux->next != NULL) {
                    aux->next->prev = aux->prev;
                }
            }

            free(aux);
            break;
        }

    }

    return first;
}

void listaElementos(Func *first) {
    Func *aux;
    printf("\n********************************\n");

    for (aux = first; aux != NULL; aux = aux->next) {
        printf("Id: %d | Idade: %d | Salario: %.2f\n",
               aux->id,
               aux->idade,
               aux->salario);
    }
}

void listaElementoPorId(Func *first, int id) {
    Func *aux;
    printf("\n********************************\n");

    for (aux = first; aux != NULL; aux = aux->next) {
        if(aux->id == id) {
           printf("Id: %d | Idade: %d | Salario: %.2f\n",
               aux->id,
               aux->idade,
               aux->salario); 
        }
    }
}
