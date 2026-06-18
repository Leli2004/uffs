#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Implementa uma Árvore AVL (BST auto-balanceada) */
// gcc -Wall exemplo2_aula.c -o exemplo2_aula

#define COUNT 5
#define SIZE 20

struct tinfo {
  int age;
};

struct tnode {
  struct tinfo info;
  struct tnode *left, *right;
};

struct ttree {
   struct tnode *root;
};

typedef struct tinfo vinfo;
typedef struct tnode vnode;
typedef struct ttree vtree;

// Inicializa a árvore vazia
void initTree(vtree *t){
	t->root=NULL;
}

// Cria um novo nó
vnode *newNode(vinfo i) {
	vnode *n;
	n=(vnode *)malloc(sizeof(vnode));
	n->info.age=i.age;
	n->left=NULL;
	n->right=NULL;
	return n;
}

// Profundidade apenas pela esquerda
// Segue apenas os ponteiros esquerdos
int depthLeft(vnode *r){ 
	if (r==NULL) return 0;
	return 1+depthLeft(r->left);
}

// Profundidade apenas pela direita
// Segue apenas os ponteiros direitos
int depthRight(vnode *r)
{
	if (r==NULL) return 0;
	return 1+depthRight(r->right);
}

/// AVL methods

// Calcula a altura máxima
int depthSubTree(vnode *root){
	int depthLeft, depthRight;

	if (root==NULL)
	   return 0;

	depthLeft = depthSubTree(root->left); // calcula a profundidade da subárvore esquerda
	depthRight = depthSubTree(root->right); // calcula a profundidade da subárvore direita

	return 1 + (depthLeft > depthRight? depthLeft: depthRight); // verifica a subárvore mais profunda e adiciona + 1
}

// Rotação LL (Left Left)
vnode *ll(vnode *root){
	vnode *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	return newRoot;
}

// Rotação RR (Right Right)
vnode *rr(vnode *root){
	vnode *newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;

	return newRoot;
}

// Rotação LR (Left Right)
vnode *lr(vnode *root){
	root->left = rr(root->left);
	return ll(root);
}

// Rotação RL (Right Left)
vnode *rl(vnode *root){
	root->right = ll(root->right);
	return rr(root);
}

// Verificação de balanceamento
vnode *balanceCheck(vnode *root){
	int rootBalance, childBalance;

	rootBalance = depthSubTree(root->left) - depthSubTree(root->right);
	
	if (rootBalance > 1){
		//calculates the balance value of the left child
		childBalance = depthSubTree(root->left->left) - depthSubTree(root->left->right);
		root = (childBalance > 0)? ll(root): lr(root);

	}else if (rootBalance < -1){
		//calculates the balance value of the right child
		childBalance = depthSubTree(root->right->left) - depthSubTree(root->right->right);
		root = (childBalance < 0)? rr(root): rl(root);
	}
	return root;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(vnode *root, int space) {
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    print2DUtil(root->right, space);
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info.age);
  
    // Process left child
    print2DUtil(root->left, space);
}
  
// Wrapper over print2DUtil()
void print2D(vnode *root) {
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

/// end of AVL

// Funciona igual a uma BST comum
vnode *insertNodeR (vnode *root, vnode *n) { // recursiva
	if (root==NULL)
	   return n;

	if (n->info.age < root->info.age) // go to left
	   root->left=insertNodeR(root->left,n);
	else
	   root->right=insertNodeR(root->right,n);

	root = balanceCheck(root);
	
	return root;
}

// Percurso InOrder
void showTreeRIn(vnode *root) {
	if (root==NULL) 
	{
		printf("\n");
	    return;
	}
	showTreeRIn(root->left);
	printf("%d ",root->info.age);
	showTreeRIn(root->right);
}

// Liberação de memória
void freeTree(vnode *n) {
	if (n==NULL) return;
	freeTree(n->left);
	freeTree(n->right);
    free(n);
}

// main
int main()
{
	// Cria a árvore
	vtree tree;
	vinfo inf;

	// Gera números aleatórios
	clock_t begin, end;
    double time_spent;
    srand(time(NULL));

	initTree(&tree);
	begin=clock();

	// Insere 20 valores
    for (int i=1;i<=SIZE;i++)
    {
	    inf.age=rand()%(SIZE*10);
    	tree.root=insertNodeR(tree.root,newNode(inf));
    }

    end=clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime to build the tree (in s)%5.2f: \n",time_spent);

	//Imprime a árvore
	print2D(tree.root);

	// Mostra alturas
	printf("Left: %d\n",depthLeft(tree.root));
	printf("Right: %d\n",depthRight(tree.root));
	printf("Tree: %d\n",depthSubTree(tree.root));

	// Libera memória
	freeTree(tree.root);
	return 0;
}
