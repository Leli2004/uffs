#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 02_selection_sort.c -o 02_selection_sort

void swap(int * v, int i, int n){
    int aux = v[i];
    
    v[i] = v[n];
    v[n] = aux;
}


void orderInsertionSort(int *v, int size) {
    if(v == NULL) return;
    
    // TODO: implementar
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
    
    orderInsertionSort(v, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}
