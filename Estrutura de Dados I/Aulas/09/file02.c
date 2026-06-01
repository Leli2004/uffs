#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// EXERCÍCIOS SLIDE

// Descrição:
// Faça um programa que receba uma string, caractere por caractere.
// Cada caractere é colocado em uma fila.
// No fim da entrada, esvazie a fila imprimindo os caracteres armazenados.

/// Structs
typedef struct input {
    char item;
    struct input *next;
} Input;

typedef struct {
    Input *head;
    Input *tail;
} Queue;

/// Operações

// insere item na fila
void enQueue(Queue *queue, char item) {
    Input *aux = (Input*) malloc(sizeof(Input));

    aux->item = item;
    aux->next = NULL;

    if (queue->head == NULL) {
        queue->head = aux;
        queue->tail = aux;
    } else {
        queue->tail->next = aux;
        queue->tail = aux;
    }
}

// remove item da fila
void deQueue(Queue *queue, char *item) {
    Input *aux;

    *item = queue->head->item;
    aux = queue->head;

    if (queue->head == queue->tail) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
    }

    free(aux);
}

// inicializa ponteiros
void initQueue(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

// verifica se fila está vazia
int isEmpty(Queue *queue) {
    return queue->head == NULL;
}

// remove todos os itens da fila
void freeAll(Queue *queue) {
    char item;

    while (!isEmpty(queue)) {
        deQueue(queue, &item);
    }
}

// lista file
void listQueue(Queue *queue) {
    Input *aux;

    printf("\n************************************************\nFila:\n");

    for(aux=queue->head; aux != NULL; aux = aux->next) {
        printf("%c\n", aux->item);
    }
}

/// Main
// gcc -Wall file02.c -o file02
int main() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    char str[100];
    char item;

    initQueue(queue);

    printf("Digite uma string: ");
    scanf("%s", str);

    // Insere caractere por caractere na fila
    for (int i = 0; str[i] != '\0'; i++) {
        enQueue(queue, str[i]);
    }

    listQueue(queue);

    printf("\nEsvaziando fila:\n");
    // Remove e imprime
    while (!isEmpty(queue)) {
        deQueue(queue, &item);
        printf("%c ", item);
    }

    listQueue(queue);

    return 0;
}
