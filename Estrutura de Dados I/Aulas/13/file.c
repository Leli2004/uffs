#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// gcc -Wall file.c -o file

struct TMaxHeap{
   int heap[SIZE];
   int size;
};
typedef struct TMaxHeap MaxHeap;

void initMaxHeap(MaxHeap *h) {
	h->size=0;
}

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

    int maior;
    int v, i, left, right;
    
    v = h->heap[0];
    
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    i = 0;

    while(i < h->size) {
        //printf("%d\n",maior);
        left =(2*i)+1;
        right =(2*i)+2;

        if (left < h->size && h->heap[i] < h->heap[left]) maior=left;;

        if (right < h->size && h->heap[right] > h->heap[left]) maior=right;

        swap (&h->heap[i], &h->heap[maior]);

        if (i==maior) break;
        i=maior;
    }

    return v;
}

// Exibe o heap
void printHeap(MaxHeap h) {
    printf("\nHeap:\n");
    for (int i=0; i<h.size; i++)
	   printf("%d ",h.heap[i]);
    printf("\n");
}

int main() {
    MaxHeap h;
	initMaxHeap(&h);
	insereHeapMax(&h,40);
	insereHeapMax(&h,20);
	insereHeapMax(&h,50);
	insereHeapMax(&h,30);
	insereHeapMax(&h,45);
	insereHeapMax(&h,60);

	printHeap(h);

    printf("\nValor max removido: %d\n", removeMaxHeap(&h));

	printHeap(h);

    return 0;
}
