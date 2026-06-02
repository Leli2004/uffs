
# Conceitos de Árvores

## Nós (Vértices)
Um **nó** (ou **vértice**) contém uma informação útil.

Características:
- Pode ter **filhos**;
- Possui um **pai**;
- Pode ter **irmãos**.

## Folhas
São os nós que **não possuem filhos**.

## Raiz
É o **nó principal** da árvore, geralmente o ponto inicial da estrutura.

## Caminho
Sequência de nós < v0, v1, v2, …, vk >.   
Condições:
- Todos os nós da sequência são **distintos**;
- Existe uma **aresta conectando** V(i-1) e V(i) para i = 1, 2, …, k

## Árvore
Estrutura formada por **nós e arestas** onde:
- Existe **exatamente um caminho** conectando cada par de vértices;
- Pode ser:
  - **Enraizada**
  - **Não enraizada**

## Ordem
A **ordem de uma árvore** é definida pelo nó que possui o **maior número de arestas**.

## Subárvore
É uma **estrutura de árvore contida dentro de outra árvore**.

---

# Árvore Binária

Uma **árvore binária**:
- Ou **não contém nenhum nó**;
- Ou é composta por **um nó conectado** a:
  - uma **subárvore esquerda**;
  - uma **subárvore direita**.

## Filhos em uma Árvore Binária
Para um nó:
- **Filho esquerdo** → é a raiz da **subárvore esquerda**;
- **Filho direito** → é a raiz da **subárvore direita**.

A inserção segue uma lógica semelhante à das listas:
1. Alocar memória;
2. Atribuir o valor aos campos do nó;
3. Inicializar (`NULL`) os ponteiros da esquerda e direita;
4. Encontrar a melhor posição na árvore para inserir o novo nó.

Cada nó normalmente possui:
- Um campo para armazenar o **conteúdo/dado** do nó;
- Dois ponteiros para os filhos (**esquerda** e **direita**).

Exemplo em C:
```c
typedef struct node {
    int value;
    struct node *left, *right;
} Node;
```

---

# Árvore Binária de Busca (BST)

Uma **Binary Search Tree (BST)** é uma árvore binária que restringe a forma como os nós são organizados.

Para todo nó da árvore:
- O elemento à **esquerda** deve ser **menor ou igual** ao pai;
- O elemento à **direita** deve ser **maior ou igual** ao pai;
- Valores iguais devem seguir uma regra definida previamente:
  - sempre para a esquerda **ou** sempre para a direita.

## Algoritmo de Inserção
```text
Algoritmo adicionaNo(Node *raiz, Node *new)

Início
    if (raiz == NULL)
        return new;

    else
        If (raiz→valor >= new→valor)
            raiz→left = adicionaNo(raiz→left, new);

        else
            raiz→right = adicionaNo(raiz→right, new);

        fim se
    fim se

    return raiz;

fimAlgoritmo
```

## Altura de um Nó
A **altura** de um nó `n` em uma árvore binária é a distância entre `n` e o seu **descendente mais afastado**.

Mais precisamente:
- É o número de passos no **maior caminho** até uma folha;
- Os caminhos são obtidos pela repetição das instruções:
```text
n = n→left
n = n→right
```
em qualquer ordem.

### Altura da árvore
A altura da árvore é dada pela **distância da raiz até as folhas**.

## Profundidade de um Nó
A **profundidade** de um nó é a distância deste até a **raiz**.
É semelhante ao cálculo da altura, porém:
- Não buscamos a folha mais afastada;
- Contamos o número de passos necessários para sair da raiz e chegar ao nó desejado.

## Percurso em Árvores
Existem situações onde precisamos percorrer toda a árvore, visitando todos os nós.

Existem **três formas principais** de percorrer uma árvore binária:
- **Pré-order**
- **In-order**
- **Pós-order**

## Tipos de Árvores Geradas
A construção da árvore pode gerar dois tipos:

### Balanceadas
- Folhas possuem alturas próximas;
- Melhor distribuição dos nós.

### Desbalanceadas (ou Degeneradas)
- Alturas das folhas divergem bastante;
- Em casos extremos, a complexidade pode chegar a ser **linear**.
- Solução para árvores desbalanceadas: Utilizar algoritmos de balanceamento (AVL, Red-Black Tree).

---
