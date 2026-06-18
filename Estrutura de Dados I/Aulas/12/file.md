
# Árvore AVL

Uma árvore AVL é uma BST (Binary Search Tree) auto-balanceada.  

## Fator de Balanceamento (FB) 

Balanced Factor (FB) = Height Left Subtree - Height Right Subtree.  
A BST é considerada balanceada quando FB = {-1,0,1}.   
Viola quando |FB|>1.   
Se violar essa regra, a árvore deve ser reestrutura para manter |FB|<=1.  
 
## Reestruturação da AVL
Rotação das sub-árvores que causaram |FB|>1

Tipos:
* Left-left case
* Right-right case
* Left-right case
* Right-left case

### Left-left case
- Ocorre quando FB>1
- A sub-árvore da esquerda está mais pesada
- Deve ser executada uma rotação simples à direita

### Right-right case
- Ocorre quando FB<-1
- A sub-árvore da direita está mais pesada
- Deve ser executada uma rotação simples à esquerda

### Left-right case
- Ocorre quando FB>1 e a sub-árvore da esquerda FB < 0
- A sub-árvore da esquerda está mais pesada
- Uma rotação simples não resolve

### Right-left case
- Ocorre quando FB<-1 e a sub-árvore da esquerda FB > 0
- A sub-árvore da direita está mais pesada
- Uma rotação simples não resolve

AVL Tree Visualization: 
```https://www.cs.usfca.edu/~galles/visualization/AVLtree.html ```

## Inserção

### Pseudo-código (inserção)

1. Percorre a árvore em pré-ordem (raíz->esquerda->direita) para adicionar o elemento.  

2. Calcula o FB do pai do nó inserido.
    - fb(no)=height(no->left)-height(no->right)

3. Se |FB|>1, árvore não respeita AVL.
    - Aplica-se uma das regras de balanceamento

4. Repete-se a verificação dos nós antecessores até chegar a raiz.

Regras:

Se fb(no) é positivo:
- calcula o FB do pai do nó inserido
- Balanceamento do no->left
    * Negativo: LR
    * Positivo: LL

Se fb(no) é negativo:
- calcula o FB do pai do nó inserido
- Balanceamento do no->right
    * Negativo: RR
    * Positivo: RL
