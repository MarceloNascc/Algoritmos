//URI 1025
#include <stdio.h>
#include <stdlib.h>

void ler(int list[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        scanf(" %d", &list[i]);
    }
}

int cmp (const void *x, const void *y) {
   return (*(int *)x - *(int *)y); 
}

int buscaB(int list[], int chave, int ini, int fim){
    if(ini > fim){
        return -1;
    }
    
    int meio = (ini + fim) / 2;
    
    if(chave == list[meio]){
        return meio;
    }
    else if(chave > list[meio]){
        return buscaB(list, chave, meio + 1, fim);
    }
    else{
        return buscaB(list, chave, ini, meio - 1);
    }
}

int acharPrim(int list[], int pos){
    int valor = list[pos];
    
    while(pos > 0 && list[pos - 1] == valor){
        pos--;
    }
    
    return pos;
}

int main()
{
    int marm, tes;
    scanf(" %d %d", &marm, &tes);
    
    int c = 1;
    while(marm != 0 || tes != 0){
        printf("CASE# %d:\n", c++);
        
        int marms[marm];
        ler(marms, marm);
        
        int tests[tes];
        ler(tests, tes);
        
        qsort(marms, marm, sizeof(int), cmp);
        
        int i;
        for(i = 0; i < tes; i++){
            int pos = buscaB(marms, tests[i], 0, marm - 1);
            
            if(pos == -1){
                printf("%d not found\n", tests[i]);
                continue;
            }
            
            pos = acharPrim(marms, pos);
            printf("%d found at %d\n", marms[pos], pos + 1);
        }
        
        scanf(" %d %d", &marm, &tes);
    }

    return 0;
}