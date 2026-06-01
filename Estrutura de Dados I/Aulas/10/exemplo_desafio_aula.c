#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Desafio:
Receber uma expressão matemática (expression) com operadores aritméticos "()[]{}";
Verificar se a ordem dos operadores é válida ou inválida;
Usar estrutura de pilha -> se isOpenChar, insere na pilha e se isCloseChar, remove.
*/

/// Structs

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

/// Operações

// inicializa pilha
Stack* newStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// verifica se pilha é vazia
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// cria novo elemento na pilha
void push(Stack* stack, char value) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// remove elemento da pilha
Node* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    Node* top = stack->top;
    stack->top = stack->top->next;

    return top;
}

// lista pilha
void printStack(Stack* stack) {
    printf("Pilha:\n");
    for (Node* current = stack->top; current != NULL; current = current->next) {
        printf("%c\n", current->value);
    }
}

// faz pop em todos os elementos da pilha
void freeAll(Stack* stack) {
    while (!isEmpty(stack)) {
        free(pop(stack));
    }
}

// verifica se é caractere "aberto"
int isOpenChar(char value) {
    return value == '(' || value == '[' || value == '{';
}

// verifica se é caractere "fechado"
int isCloseChar(char value) {
    return value == ')' || value == ']' || value == '}';
}

// verifica se caracteres open e close dão match
int isMatchingChar(char open, char close) {
    return
        (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

/// Main

// gcc -Wall exemplo_desafio_aula.c -o exemplo_desafio_aula
int main() {
    Stack* stack = newStack();
    char* expression = "(a * 1){[b / 2] + [1/a]} = 0";
    
    int isValid = 1;
    
    for (int i = 0; expression[i] != '\0'; i++) {
        if(isOpenChar(expression[i])) { 
            push(stack, expression[i]);
        }
        
        if (isCloseChar(expression[i])) {
            isValid = isMatchingChar(pop(stack)->value, expression[i]);
            if (!isValid) {
                break;
            }
        }
    }
    
    if (isValid) {
        printf("Válido!");
    } else {
        printf("Inválido!");
    }

    freeAll(stack);

    return 0;
}
