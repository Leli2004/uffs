/* 
Exercício: escrever uma função de particionamento do QuickSort
=> assinatura: particiona(v, low, high)
=> v: endereço para vetor
=> low: limite da parte esquerda, com valores menores do que o pivô
=> high: limite da parte direita, com valores maiores do que o pivô
*/

// gcc -Wall 03_quick_sort.c -o 03_quick_sort

#include <stdio.h>
#include <stdlib.h>

void swap(int * v, int i, int n){
    int aux = v[i];    
    v[i] = v[n];
    v[n] = aux;
}

int particiona(int *v, int low, int high) {
    if(v == NULL) return 0;

    int p = low;
    int aux = low+1;

    for(int i=aux; i<=high; i++) {
        if(v[i] < v[p]) {
            swap(v, i, aux);
            aux++;
        }
    }

    swap(v, p, aux-1);
    
    return aux-1; // índice do pivô
}

void quickSort(int *v, int low, int high){    
    if(low >= high) return;

    int i = particiona(v, low, high);
        
    quickSort(v, low, i-1);
    quickSort(v, i+1, high); 
}

int main ( void ) {
    int size, n;
    
    scanf("%d", &size);
    n = size;
    
    int v[size];
    
    while(size)
        scanf("%d", &v[--size]);
    
    quickSort(v, 0, n-1);
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}
