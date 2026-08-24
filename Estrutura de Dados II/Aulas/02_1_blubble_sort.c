#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 02_1_blubble_sort.c -o 02_1_blubble_sort

void swap(int * v, int i, int n){
    int aux = v[i];
    
    v[i] = v[n];
    v[n] = aux;
}

void orderBubbleSort(int *v, int size) {
    if(v == NULL) return;

    for(int i=size-1; i>0; i--) { // i = posição limite (após já está ordenado)
        for(int j=0; j<i; j++) {
            if(v[j] > v[j+1]) swap(v, j, j+1);
        }
    }
}

int main ( void ) {
    int size, n;
    
    scanf("%d", &size);
    n = size;
    
    int v[size];
    
    while(size)
        scanf("%d", &v[--size]);
    
    orderBubbleSort(v, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}
