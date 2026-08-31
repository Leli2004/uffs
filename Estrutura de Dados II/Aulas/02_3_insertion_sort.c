#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 02_3_insertion_sort.c -o 02_3_insertion_sort

void swap(int * v, int i, int n){
    int aux = v[i];
    
    v[i] = v[n];
    v[n] = aux;
}

void insertionSort(int *v, int size) {
    if(v == NULL) return;

    for(int i=1; i<size; i++) { // i = posição limite (antes já está ordenado)
        int aux = v[i];
        int j = i-1; // parcela já ordenada da lista

        while(j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

int main ( void ) {
    int size, n;
    
    printf("Informe o size: ");
    scanf("%d", &size);
    n = size;
    
    int v[size];
    
    printf("\nInforme os elementos: \n");
    while(size)
        scanf("%d", &v[--size]);
    
    insertionSort(v, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}
