//URI 1798
#include <stdio.h>

void iniciarM(int linhas, int colunas, int dinam[][colunas + 1]){
    int i;
    for (i = 0; i < linhas; i++) {
        int j;
        for (j = 0; j <= colunas; j++) {
            dinam[i][j] = -1;
        }
    }
}

void ler(int canos[][2], int tam){
    int i;
    for (i = 0; i < tam; i++) {
        scanf(" %d %d", &canos[i][0], &canos[i][1]);
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

int cortarCano(int canos[][2], int quantModCan, int tamCano, int pos, int tamanhoCano, int dinam[][tamanhoCano + 1]){
    if(pos == quantModCan){
        if(tamCano >= canos[pos][0]){
            dinam[pos][tamCano] = 1;
            return canos[pos][1];
        }
        else{
            dinam[pos][tamCano] = 0;
            return 0;
        }
    }

    if(dinam[pos][tamCano] != -1){
        if(dinam[pos][tamCano] == 1){
            return canos[pos][1] + cortarCano(canos, quantModCan, tamCano - canos[pos][0], pos, tamanhoCano, dinam);
        }
        else{
            return cortarCano(canos, quantModCan, tamCano, pos + 1, tamanhoCano, dinam);
        }
    }

    if(tamCano >= canos[pos][0]){
        int esq = cortarCano(canos, quantModCan, tamCano, pos + 1, tamanhoCano, dinam);
        int dir = canos[pos][1] + cortarCano(canos, quantModCan, tamCano - canos[pos][0], pos, tamanhoCano, dinam);

        dinam[pos][tamCano] = dir > esq ? 1 : 0;

        return max(dir, esq);
    }
    else{
        dinam[pos][tamCano] = 0;

        return cortarCano(canos, quantModCan, tamCano, pos + 1, tamanhoCano, dinam);
    }
}

int main(){
    int quantModCan, tamCano;
    scanf(" %d %d", &quantModCan, &tamCano);

    int canos[quantModCan][2];
    ler(canos, quantModCan);

    int dinam[quantModCan][tamCano + 1];
    iniciarM(quantModCan, tamCano, dinam);

    int valorMax = cortarCano(canos, quantModCan - 1, tamCano, 0, tamCano, dinam);

    printf("%d\n", valorMax);

    return 0;
}