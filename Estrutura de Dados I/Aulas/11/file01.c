#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ÁRVORES BINÁRIAS DE BUSCA (BST)

typedef struct tree {
    int value;
    struct tree *left, *right;
} Tree;

Tree* createNode(int value) {
    Tree *newNode = (Tree*) malloc(sizeof(Tree));

    if (newNode == NULL)
        return NULL;

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Tree* insert(Tree *root, int value) {
    if (root == NULL)
        return createNode(value);

    // Insere à esquerda se valores forem maiores ou iguais
    if (value <= root->value)
        root->left = insert(root->left, value);

    // Insere à direita se valores forem maiores
    else if (value > root->value)
        root->right = insert(root->right, value);

    return root;
}

// Pré-ordem:
void showPreOrder (Tree *root) {
    if (root==NULL) return;
    printf("%d ",root->value); // Visita a raiz
    showPreOrder(root->left); // Percorre a subárvore esquerda
    showPreOrder(root->right); // Percorre a subárvore direita
}

// In-ordem:
void showInOrder (Tree *root) {
    if (root == NULL) return;
    showInOrder(root->left); // Percorre a subárvore esquerda
    printf("%d ", root->value); // Visita a raiz
    showInOrder(root->right); // Percorre a subárvore direita
}

// Pós-ordem:
void showPosOrder (Tree *root) {
   if (root == NULL) return;
   showPosOrder(root->left); // Percorre a subárvore esquerda
   showPosOrder(root->right); // Percorre a subárvore direita
   printf("%d ", root->value); // Visita a raiz
}

// gcc -Wall file01.c -o file01
int main() {
    Tree *root = NULL;
    int valores[] = {10, 4, 15, 2, 8, 12, 20, 6, 9};

    for (int i = 0; i < 9; i++) {
        root = insert(root, valores[i]);
    }

    printf("Pre-ordem: ");
    showPreOrder(root);

    printf("\nIn-ordem: ");
    showInOrder(root);

    printf("\nPos-ordem: ");
    showPosOrder(root);

    printf("\n");
    return 0;
}
