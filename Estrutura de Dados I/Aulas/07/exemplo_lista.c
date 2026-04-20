#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -Wall exemplo_lista.c -o exemplo_lista

struct tlista {
    int value;
    struct Lista *next; 
};
typedef struct tlista Lista; 

Lista *getList(int *v, int t);
Lista *newListaPar(Lista *l);
Lista *getInter(Lista *l1, Lista *l2);

int main() {
    // int tamanho = 3;
    // int vetor[3] = {1,2,3};
    // Lista *p, *first=NULL;
    // first = getList(vetor, tamanho);
    // for (p=first; p!=NULL; p=p->next)
	//   printf("%d\n",p->value);

    return 0;
}

// Exemplo: tranformar lista de int em tipo Lista
Lista *getList(int *v, int t) { // *v = vetor, t = tamanho do vetor 
    Lista *p, *aux, *f=NULL;

    for (int i=0; i<t; i++) {
        p = (Lista *) malloc(sizeof(Lista));
        
        p->value = v[i];
        p->next = NULL;

        if(f == NULL) {
            f = p;
            aux = p;
        } else {
            aux->next = p;
            aux = p;
        }
    }

    return f;
}

// Exercício 1: 
// fazer uma função que recebe o endereço de uma lista do tipo Lista e crie uma nova lista com apenas 
// os valores pares da lista original. Retornar o primeiro elemento da lista nova.
Lista *newListaPar(Lista *l) {
    Lista *novaLista, *first=NULL, *aux;

    for (aux=l; aux!=NULL; aux=aux->next) {
        if (aux->value % 2 == 0) {
            // 1. Alocar espaço
            novaLista = (Lista *) malloc(sizeof(Lista));
            
            // 2. Colocar valores e nullificar a lista
            novaLista->value = aux->value;
            novaLista->next = NULL;

            // 3. Encadear a lista
            if (first == NULL) {
                first = novaLista;
                aux = novaLista;
            } else {
                aux->next = novaLista;
                aux = novaLista;
            }

        }
    }

    return first; 
}

// Exercício 2: 
// faça uma função que receba 2 ponteiros que apontam para listas do tipo Lista e retorne um ponteiro para uma nova lista
// que contenha somente os elementos iguais que estejam nas listas passadas nos parâmetros. Considere que os números de cada lista
// são únicos, ou seja, não há repetição.
/* Exemplo:
    L1 = 9,7,5,4
    L2 = 5,3,7
    Nova = 5,7
*/
Lista *getInter(Lista *l1, Lista *l2) {
    Lista *aux1, *aux2, *aux;
    Lista *new, *nf=NULL;

    for (aux1=l1; aux1!=NULL; aux1=aux1->next) { // Percorre L1
        
        for (aux2=l1; aux2!=NULL; aux2=aux2->next) { // Percorre L2
            
            // Validar se elemento está presente em ambas as listas
            int shouldAdd = 1; // true

            // Se sim, inserir na nova lista
            if (shouldAdd==1) {
                new = (Lista *)malloc(sizeof(Lista));

                new->value = aux->value;
                new->next = NULL; 

                if (nf==NULL) {
                    nf = new;
                    aux = new;
                } else {
                    aux->next = new;
                    aux = new;
                }
            }

        }

    }

    return nf;
}
