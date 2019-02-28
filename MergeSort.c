#include <stdlib.h>
#include <stdio.h>

//ETAPA DA CONQUISTA
void Merge(int lista[], int ini, int meio, int fim){
    int tam = (meio - ini) + (fim - meio); //TAMANHO DAS DUAS SUBLISTAS JUNTAS
    int listAux[tam];

//INTERCALAÇÃO NA ĆÓPIA
    int i, j, k;
    for(i = ini, j = meio, k = 0; i < meio && j < fim; k++){
        if(lista[i] < lista[j]){
            listAux[k] = lista[i];
            i++;
        }
        else{
            listAux[k] = lista[j];
            j++;
        }
    }

    if(i < meio){ //SOBRARAM ELEMENTOS NA LISTA DA ESQUERDA
        for(;i < meio; i++, k++){
            listAux[k] = lista[i];
        }
    }
    else if(j < fim){ //SOBRARAM ELEMENTOS NA LISTA DA DIREITA
        for(;j < fim; j++, k++){
            listAux[k] = lista[j];
        }
    }
//INTERCALAÇÃO NA CÓPIA

//VETOR ORIGINAL
    for(i = ini, k = 0; i < fim; i++, k++){
        lista[i] = listAux[k];
    }
//VETOR ORIGINAL
}

//ETAPA DA DIVISÃO
void Sort(int lista[], int ini, int fim){
    if((fim - ini) <= 1){
        return;
    }

    int meio = (ini + fim)/2;
    Sort(lista, ini, meio);
    Sort(lista, meio, fim);

    Merge(lista, ini, meio, fim);
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

    Sort(lista, 0, n);

    for(int i = 0; i < n; i++){
        printf("%d ", lista[i]);
    }

    return 0;
}
