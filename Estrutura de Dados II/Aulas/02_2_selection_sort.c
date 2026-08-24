#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 02_selection_sort.c -o 02_selection_sort

void swap(int * v, int i, int n){
    int aux = v[i];
    
    v[i] = v[n];
    v[n] = aux;
}


void orderSelectionSort(int *v, int size) {
    if(v == NULL) return;
    int menor;

    for(int i=0; i<size-1; i++) {
        menor = i;
        for(int j=i+1; j<size; j++) {
            if(v[j] < v[menor]) menor = j;
        }
        swap(v, i, menor);
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
    
    orderSelectionSort(v, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}
