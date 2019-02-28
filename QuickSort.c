#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b){
    int tem = *a;
    *a = *b;
    *b = tem;
}

int ParticionarRand(int lista[], int ini, int fim){
    int pivo = rand() % fim;
    swap(&lista[pivo], &lista[fim-1]);

    int i, j;
    for(i = ini - 1, j = ini; j < fim-1; j++){
        if(lista[j] < lista[fim-1]){
            i++;
            swap(&lista[i], &lista[j]);
        }
    }

    swap(&lista[i++], &lista[fim-1]);

    return i;
}

void QuickSort(int lista[], int ini, int fim){
    if((fim - ini) <= 1){
        return;
    }

    int pivo = ParticionarRand(lista, ini, fim);

    QuickSort(lista, ini, pivo - 1);
    QuickSort(lista, pivo + 1, fim);
}

//TESTE
int main (){
    int n;
    printf("Tamanho: ");
    scanf("%d", &n);

    printf("Lista: ");
    int lista[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &lista[i]);
    }

    srand(6);
    QuickSort(lista, 0, n);

    for(int i = 0; i < n; i++){
        printf("%d ", lista[i]);
    }

    return 0;
}

