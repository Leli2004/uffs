#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "interfaces.h"

// Pilhas

// gcc -Wall file.c interfaces.c -lm -o file

int main() {
    Stack* stack = newStack();

    pushStack(stack, '(');
    printStack(stack);

    pushStack(stack, ')');
    printStack(stack);

    printf("\n");
    printf("Head: %c\n", stack->top->value);

    printf("\n");
    Node* aux;
    aux = popStack(stack);
    printf("Removido: %c\n", aux->value);
    free(aux);

    aux = popStack(stack);
    printf("Removido: %c", aux->value);
    free(aux);

    printStack(stack);
    freeAll(stack);
    printf("\n");

    return 0;
}
