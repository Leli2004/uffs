
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   struct node * left; 
   struct node * right;
   struct node * parent;
   int height;
   int data; 
} node;


node * create( int data ) {
    node * new = (node*)malloc(sizeof(node));
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;
    new->data = data;
    new->height = 1;
    return new; 
}


node * minimum(node * n){
   if(n->left) return minimum(n->left);
   return n; 
}

node * sucessor(node * n){
    if(n->right){
        return minimum(n->right);
    }    
    node * x = n->parent;
    while(x != NULL && x->right == n){
        n = x;
        x = n->parent;
    }
    return x;
}

//caso esteja vazio, a altura e 0
int height(node * tree){
    if(tree == NULL) return 0;
    return tree->height;
}

//atualiza a altura de uma arvore baseada nos filhos
void fix_height(node * tree){
     int hl = height(tree->left);
     int hr = height(tree->right);
     
     tree->height = (hl > hr ? hl+1: hr+1); //altura do maior filho mais um 
}




node * rotate_left(node * x){
     //printf("rotacao esquerda em: %d", x->data);
     node * y = x->right;
     
     x->right = y->left;
     
     if(x->right)
        x->right->parent = x; 
     y->left = x;

     node * tmp = x->parent;
 
     //se não for nulo
     if(x->parent){    
        if(x->parent->left == x){
            x->parent->left = y;
        }else  x->parent->right = y;
     }
     
     x->parent = y;
     y->parent = tmp;
     //todo: atualizar os parents
     
     
     fix_height(x);
     fix_height(y);

     return y;
}


node * rotate_right(node * y){
//@requires y != NULL && y->left != NULL;
     //printf("rotacao direita em: %d", y->data);
     node * x = y->left;

     y->left = x->right; 
     if(y->left)
     y->left->parent = y;    
     x->right = y;
      

     //se não for nulo - nao e raiz
     if(y->parent){
         if(y->parent->left == y){
	    y->parent->left = x;
         }else  y->parent->right = x;
     }

     node * tmp = y->parent;
     y->parent = x;
     x->parent = tmp;
     
     fix_height(y);  //a ordem importa
     fix_height(x);
     
     return x;
}


node * search(node * tree, int d){
    if(tree->data ==d || tree==NULL) return tree;    
    if(tree->data >= d) return search(tree->left, d);
    else return search(tree->right, d);
}



//insere new em uma arvore enraizada por root. Retorna o ponteiro para a raiz. 

node * fix_right(node * tree){
     fix_height(tree);
    //sempre vai ser dois ou um. So arrumamos quando for dois
    if(abs(height(tree->right) - height(tree->left)) == 2){
    	//esse e o caso com apenas uma rotacao
    	if(height(tree->right->right) < height(tree->right->left))
    	    tree->right = rotate_right(tree->right); //ja atualiza o filho a direita
    	return rotate_left(tree);
    }
    return tree;
}


node * fix_left(node * tree){
    fix_height(tree);
    //sempre vai ser dois ou um. So arrumamos quando for dois
    if(abs(height(tree->right) - height(tree->left)) == 2){
    	//rotacao dupla? caso forem iguais nao e necessario, faz a rotacao simples
    	if(height(tree->left->left) < height(tree->left->right)){
    	    tree->left = rotate_left(tree->left); //ja atualiza o filho a direita
    	}  	    
    	return rotate_right(tree);
    }
    return tree;
}


node * insert( node * root, node * new ){
    if( root == NULL ) {
        return new;
    }else{
        if( root->data >= new->data ){
            if(!root->left) { //caso nao tenha nada abaixo
                root->left = new;
                new->parent = root;
            } else { 
                insert(root->left, new);
            }
            root = fix_left(root);   //isso aqui e novo na AVL.
        } else {
            if(!root->right) { //caso nao tenha nada abaixo
                root->right = new;
                new->parent = root;
            }
            else {
               insert(root->right, new);
            }
            root = fix_right(root);   //isso aqui e novo na AVL.
        }
    }
    return root;
}

//busca em profundidade. Primeiro, abre nodos a esquerda ate o possivel
void dfs( node * tree ){
    if(tree->left) dfs(tree->left);
    printf("%d ", tree->data); 
    if(tree->right) dfs(tree->right);
}

int main ( void ) {

    struct node * root = NULL;
    
    node * new = create(10);
    
    root = insert(root, new);

    new = create(20);
    
    root = insert(root, new);
   
    new = create(30);

    root = insert(root, new);
  
    new = create(40);
    
    root = insert(root, new);
       
    new = create(5);
    
    root = insert(root, new);
    
    new = create(7);
    
    root = insert(root, new);
    
    new = create(3);
    
    root = insert(root, new);  
    
    new = create(-3);
    
    root = insert(root, new);
    
    new = create(27);
    
    root = insert(root, new);
      
    new = create(15);
    
    root = insert(root, new);
    
    dfs(root);
     
    return 0;
}
