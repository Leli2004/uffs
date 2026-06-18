#include<stdio.h>
#include<stdlib.h>

/* Implementa uma BST */
// gcc -Wall exemplo1_aula.c -o exemplo1_aula

struct _node{
    int value;
    struct _node *left, *right;
};

typedef struct _node Node;

Node *createNode(int val){
    Node *new = malloc (sizeof(Node));

    new->value = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

// Insere um nó em uma Árvore Binária de Busca (BST)
Node *addElement (Node *root, Node *new){
    printf("Root %d\n", (root != NULL ? root->value: -1));

    // Encontrou uma posição vazia: insere o nó aqui.
    if (root == NULL){
        printf("Virou folha %d\n", new->value);
        return new;
    }

    if (new->value <= root->value){
        // Valor menor ou igual: vai para a esquerda.
        printf("FUi pra esquerda!\n");
        root->left = addElement(root->left, new);
    }else {
        // Valor maior: vai para a direita.
        printf("FUi pra direita!\n");
        root->right = addElement(root->right, new);
    }

    return root;
}

// Procura um valor na BST
Node *searchElement (Node *root, int value){
    // Caso base: árvore vazia ou valor encontrado.
    if (root == NULL || root->value == value ){
        return root;
    }

    // Procura na subárvore esquerda.
    if (value < root->value){
        return searchElement(root->left, value);
    } else {
    // Procura na subárvore direita.
        return searchElement(root->right, value);
    }
}

int main(){
    // Cria uma árvore vazia
    Node *root = NULL;

    // Insere os valores:
    root = addElement(root, createNode(45));
    root = addElement(root, createNode(15));
    root = addElement(root, createNode(55));
    root = addElement(root, createNode(10));

    // Procura o valor 10
    if (!searchElement(root, 10)){
        printf("Não achou!\n");
    }else{
        printf("Achou o elemento");
    }

    return 1;
}
