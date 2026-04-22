#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -Wall exemplo_lista.c -o exemplo_lista

struct tlista {
    int value;
    struct tlista *next; 
};
typedef struct tlista Lista; 

Lista* getList(int *v, int t);
Lista* newListaPar(Lista *l);
Lista* getInter(Lista *l1, Lista *l2);

int main() {
    // Exemplo getList:
    printf("\n***************************************************\nExemplo getList...\n");
    int tamanho = 10;
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    Lista *p, *first=NULL;

    first = getList(vetor, tamanho);

    for (p=first; p!=NULL; p=p->next)
	  printf("%d ",p->value);

    // Exemplo newListaPar:
    printf("\n***************************************************\nExemplo newListaPar...\n");
    Lista *i, *pares=NULL;

    pares = newListaPar(first);

    for (i=pares; i!=NULL; i=i->next)
	  printf("%d ",i->value);

    // Exemplo getInter:
    printf("\n***************************************************\nExemplo getInter...\n");
    int v1[4] = {9,7,5,4};
    int v2[3] = {5,3,7};
    Lista *l1=NULL, *l2=NULL, *inter=NULL;

    l1 = getList(v1, 4);
    l2 = getList(v2, 3);

    inter = getInter(l1, l2);

    printf("Intersecao:\n");
    for (p=inter; p!=NULL; p=p->next)
    printf("%d\n", p->value);

    return 0;
}

// Exemplo: tranformar lista de int em tipo Lista
Lista* getList(int *v, int t) { // *v = vetor, t = tamanho do vetor 
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
Lista* newListaPar(Lista *l) { // l=lista original
    Lista *laux; // laux=para percorrer lista original
    Lista *new, *first=NULL, *aux; // new=novo elemento, first=inicio da nova lista, aux=ultimo elemento da nova lista

    for (laux=l; laux!=NULL; laux=laux->next) { // Percorrer lista original
        // Se value for par, cria nova lista já encadeando os elementos
        if (laux->value % 2 == 0) {
            // 1. Alocar espaço
            new = (Lista *) malloc(sizeof(Lista));
            
            // 2. Colocar valores e nullificar a lista
            new->value = laux->value;
            new->next = NULL;

            // 3. Encadear a lista
            if (first == NULL) {
                first = new;
                aux = new;
            } else {
                aux->next = new;
                aux = new;
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
Lista* getInter(Lista *l1, Lista *l2) {
    Lista *auxl1, *auxl2, *aux;
    Lista *new, *nf=NULL;

    for (auxl1=l1; auxl1!=NULL; auxl1=auxl1->next) { // Percorre L1
        
        for (auxl2=l2; auxl2!=NULL; auxl2=auxl2->next) { // Percorre L2
            
            // Validar se elemento está presente em ambas as listas
            if (auxl1->value==auxl2->value) {
                // Se sim, inserir na nova lista
                new = (Lista *)malloc(sizeof(Lista));

                new->value = auxl1->value;
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
