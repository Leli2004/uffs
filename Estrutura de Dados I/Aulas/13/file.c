#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// gcc -Wall file.c -o file

struct TMaxHeap{
   int heap[SIZE];
   int size;
};
typedef struct TMaxHeap MaxHeap;

// Troca valores de ponteiros a e b
void swap(int *a, int *b) {
    if (a == NULL || b == NULL) return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insere no vetor
void insereHeapMax(MaxHeap *h, int v) {
    int pai, i;

    h->heap[h->size] = v; // adiciona v no vetor
    i = h->size;  // índice = size atual
    h->size++; // incrementa size para o próximo elemento

    if (i==0) return; 

    while(i > 0) {
        pai = (i-1) / 2; // fórmula para saber índice do pai
        if (h->heap[i] > h->heap[pai]) {
            swap(&h->heap[i], &h->heap[pai]);
            i = pai;
        } else break;
    }
}

// Remove elemento (sempre remove o maior)
int removeMaxHeap(MaxHeap *h) {
    if (h->size == 0) return -1;
    int removed = h->heap[0];
    
    // todo: implementar

    return removed;
}

int main() {
    return 0;
}
