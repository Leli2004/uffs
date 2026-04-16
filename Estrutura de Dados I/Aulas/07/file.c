#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 50
#define TAM_LISTA 2

// gcc -Wall file.c -o file

void printPonteiro();
void adicionaEmployee();
void imprimeEmployee();

struct employee {
    int id;
    char name[TAM_NOME+1];
    float income;
    struct employee *next;
};
typedef struct employee Employee;

// Ponteiros globais (necessários para manter a lista)
Employee *first = NULL;
Employee *aux = NULL;

int main() {
    //printPonteiro();
    adicionaEmployee();
    imprimeEmployee();

    return 0;
}

void printPonteiro() {
    int *p;
    p=(int*)malloc(sizeof(int));
    *p=123;

    printf("Conteúdo do p: %d \n",*p);
    printf("Local de apontamento: %p \n",p);

    // scanf(“%d”,p); // e não scanf(“%d”,&p)
}

void adicionaEmployee() {
    Employee *f; 
    int contador = 0;

    for (int i=0; i<TAM_LISTA; i++){
        contador++;

        f = (Employee *)malloc(sizeof(Employee));

        f->id = contador; //contador é uma variável qualquer

        printf("\nDigite o nome: ");
        scanf("%s", f->name);
        printf("Digite o salário R$: ");
        scanf("%f", &f->income);

        f->next = NULL;

        if (first == NULL){
            first = f; 
            aux=f; // inicialmente, todos apontam para a primeira região alocada
        } else {           
            aux->next=f; // aux deve apontar sempre para a região anterior à nova alocada
            aux=f;   
        }
    }
}

void imprimeEmployee() {
    printf("\n");
    for (aux = first; aux != NULL; aux = aux->next){
        printf(
            "Employee id: %d, name: %s, income: %.2f\n",
            aux->id,
            aux->name,
            aux->income
        );
    }
}
