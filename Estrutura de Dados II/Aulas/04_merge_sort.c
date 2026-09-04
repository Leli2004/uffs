#include <stdio.h>
#include <stdlib.h>

// gcc -Wall 04_merge_sort.c -o 04_merge_sort

void merge(int *v, int low, int medium, int high) {
    if(v == NULL) return;

    int size = high - low + 1;

    // cria vetor auxiliar para ordenar "sub vetores" do original
    int *aux = malloc(size*sizeof(int));
    if(aux==NULL) return;

    int i = low; // inicio da primeira metade => [low:medium]
    int j = medium + 1; // início da segunda metade => [medium+1:high]
    int k = 0; // contador pro while

    // preencher vetor auxiliar já ordenando
    /// compara os elementos, escolhe o menor e adiciona-o ao aux
    while(i <= medium || j <= high) { 

        if (i <= medium && j <= high) {
            // comparo a primeira metade com a segunda metade, oq for menor adiciona em aux
            if(v[i] <= v[j]) {
                aux[k] = v[i];
                i++;       
            } else {
                aux[k] = v[j];
                j++;
            }
        } else if (i <= medium) { 
            // oq sobrou da primeira metade (já ordenado, só adiciona em aux)
            aux[k] = v[i];
            i++;
        } else if (j <= high) { 
            // oq sobrou da segunda metade (já ordenado, só adiciona em aux)
            aux[k] = v[j];
            j++;
        }
        
        k++;
    }
    
    // devolver para o vetor original v
    for(int k=0; k<size; k++) {
        v[low+k] = aux[k];
    }

    free(aux);
}

void mergeSort(int *v, int low, int high){    
    if(low >= high) return;

    int medium = (low + high) / 2;

    // recursivamente dividir a lista original ao meio sucessivas vezes
    mergeSort(v, low, medium);
    mergeSort(v, medium+1, high);

    // juntar e ordenar sublistas (na ordem inversa da divisão anterior)
    merge(v, low, medium, high);
}

void printArray(int *v, int size) {
    for(int i=0; i<size; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main ( void ) {
    int size, n;
    
    scanf("%d", &size);
    n = size;
    
    int v[size];
    
    while(size)
        scanf("%d", &v[--size]);
    
    mergeSort(v, 0, n-1);
    
    printArray(v, n);

    return 0;
}
