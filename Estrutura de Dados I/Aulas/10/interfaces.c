#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "interfaces.h"

Stack* newStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Adiciona elemento na
void pushStack(Stack* stack, char value) {
    Node* new = (Node*) malloc(sizeof(Node));

    new->value = value;
    new->next = stack->top;
    
    stack->top = new;
}

Node* popStack(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    Node* top = stack->top;
    stack->top = stack->top->next;

    return top;
}

void printStack(Stack* stack) {
    printf("\n======================\n");
    printf("Pilha: \n");
    for (Node* current = stack->top; current != NULL; current = current->next) {
        printf("%c \n", current->value);
    }
}

void freeAll(Stack* stack) {
    while (!isEmpty(stack)) {
        free(popStack(stack));
    }
}
