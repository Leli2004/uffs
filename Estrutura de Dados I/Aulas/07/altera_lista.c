#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -Wall altera_lista.c -o altera_lista

struct employee {
    int id;
    char name [50];
    struct employee *next; 
};
typedef struct employee Emp;

Emp* criaLista();
Emp* addEnd(Emp *first);
Emp* addAny(Emp *first, int id);
Emp* delById(Emp *first, int id);
int getIdRef(int tipo);
void imprimeLista(Emp *first);

int main() {
    Emp *first = NULL;

    first = criaLista(); // Cria lista conforme entrada do usuário
    imprimeLista(first); // Imprime lista completa

    printf("\n");
    first = addEnd(first); // Adiciona novo elemento no final da lista
    imprimeLista(first);

    printf("\n");
    first = addAny(first, getIdRef(1)); // Adiciona novo elemento após id específico (idRef)
    imprimeLista(first);

    printf("\n");
    first = delById(first, getIdRef(2)); // Remove elemento com id específico (idRef)
    imprimeLista(first);

    return 0;
}

int getIdRef(int tipo){
    printf("\n***********************************");
    int id;
    if (tipo==1) {
        printf("\nAdicionar próximo elemento após o id: ");
    } else if (tipo==2) {
        printf("\nRemover elemento com o id: ");
    }
    scanf("%d", &id);
    printf("\n***********************************");
    return id;
}

// cria lista encadeada
// quando id=0, finaliza inserção
Emp* criaLista() {
    printf("\n***********************************");
    printf("\nCriando lista de elementos (id=0 encerra)...");

    Emp *new, *aux, *first=NULL;

    while(1) {
        new = (Emp*)malloc(sizeof(Emp));
        
        printf("\nId: ");
        scanf("%d", &new->id);
        if (new->id == 0) {
            break;
        }
        printf("Nome: ");
        scanf("%s", new->name);
        new->next = NULL; 

        if (first==NULL) {
            first = new;
            aux = new;
        } else {
            aux->next = new;
            aux = new;
        }
    }

    return first;
}

// printa lista encadeada
void imprimeLista(Emp *first) {
    printf("\n***********************************");
    printf("\nLista de elementos:");

    Emp *aux;
    for (aux=first; aux!=NULL; aux=aux->next) {
        printf("\nFuncionário #%d - %s", aux->id, aux->name);
    }
}

// inclui um elemento no final da lista encadeada
Emp* addEnd(Emp *first) {
    printf("\n***********************************");
    printf("\nInserindo novo elemento...");

    Emp *new=NULL, *aux;
    new = (Emp*)malloc(sizeof(Emp));

    printf("\nId: ");
    scanf("%d", &new->id);
    printf("Nome: ");
    scanf("%s", new->name);
    new->next = NULL;

    if (first==NULL) {
        return new;
    }

    for (aux=first; aux->next!=NULL; aux=aux->next); // Percorre até o final da lista
    aux->next = new;

    return first;
}

// inclui um elemento em qualquer posição da lista encadeada
Emp* addAny(Emp *first, int id) {
    printf("\n***********************************");
    printf("\nInserindo novo elemento após id #%d...", id);

    Emp *new=NULL, *aux;
    new = (Emp*)malloc(sizeof(Emp));

    printf("\nId: ");
    scanf("%d", &new->id);
    printf("Nome: ");
    scanf("%s", new->name);
    new->next = NULL;

    if (first==NULL) {
        return new;
    } 
    
    for (aux=first; aux->next!=NULL; aux=aux->next){
        if(aux->id == id) break;
    }

    new->next = aux->next;
    aux->next = new;

    return first;
}

// exclui uma posição da lista encadeada
Emp* delById(Emp *first, int id) {
    printf("\n***********************************");
    printf("\nExcluindo elemento com id #%d...", id);

    Emp *aux, *previous;
 
    for(aux=first; aux!=NULL; aux=aux->next){
        if (aux->id == id) {
            if (aux == first) {
                first = first->next;
                break;
            }
            previous->next = aux->next;
            break;
        }
        previous = aux;
    }

    if(aux != NULL){
        free(aux);
    }

    return first;
}
