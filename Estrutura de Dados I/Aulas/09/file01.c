#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////// Filas

// Structs
typedef int Item;

typedef struct TQueue {
    Item item;
    struct TQueue *next;
} EQueue;

typedef struct {
    EQueue *head;
    EQueue *tail;
} Queue;

// Operações

void enQueue(Queue *queue, Item item) {
    EQueue *aux;

    // Cria um novo elemento da lista encadeada que representa a fila e
    // armazena neste novo elemento o item a ser inserido na fila
    aux = (EQueue*) malloc(sizeof(EQueue));
    aux->item = item;
    aux->next = NULL;

    // Insere o novo elemento no fim da lista encadeada que representa a
    // fila
    if (queue->head == NULL) { // Se a fila esta vazia
        queue->head = aux;
        queue->tail = aux;
    } else { // Se a fila nao esta vazia
        queue->tail->next = aux;
        queue->tail = aux;
    }
}

void deQueue(Queue *queue, Item *item)  {
    EQueue *aux;

    // Armazena o item a ser removido da fila
    *item = queue->head->item;

    // Armazena o primeiro elemento da lista encadeada que representa a fila e
    // remove este primeiro elemento da lista
    aux = queue->head;

    if (queue->head == queue->tail) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
    }

    // Libera a memoria alocada para o elemento removido
    free(aux);
}

void initQueue(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

int isEmpty(Queue *queue) {
    if (queue->head == NULL)
       return 1;
    else
       return 0;
}

void freeAll(Queue *queue) {
    EQueue *aux;

    while (queue->head != NULL) {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // fila e remove este primeiro elemento da lista
        aux = queue->head;
        queue->head = queue->head->next;

        // Libera a memoria alocada para o elemento removido
        free(aux);
    }

    queue->tail = NULL;
}

void listQueue(Queue *queue) {
    EQueue *aux;

    printf("\n************************************************\n");

    for(aux=queue->head; aux != NULL; aux = aux->next) {
        printf("%d\n", aux->item);
    }
}

// Main
// gcc -Wall file01.c -o file01

int main() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    Item item;

    // Inicializa fila
    initQueue(queue);
    listQueue(queue);

    // Insere elementos na fila
    for (int i = 0; i < 10; i++) {
        item = i;
        printf("Inserindo na fila o item %d.\n", item);
        enQueue(queue, item);
    }

    listQueue(queue);

    // Remove elementos, um a um
    while (isEmpty(queue) == 0) { // Enquanto a fila não estiver vazia
        listQueue(queue);
        deQueue(queue, &item);
    }

    return 0;
}

/*
Operações básicas:
- enqueue (Inserir um novo item na fila)
- dequeue (Remover um item da fila)
*/
