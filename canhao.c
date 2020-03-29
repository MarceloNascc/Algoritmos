//URI 1288
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

void ler(int projeteis[][2], int tam){
    int i;
    for (i = 0; i < tam; i++) {
        scanf(" %d %d", &projeteis[i][0], &projeteis[i][1]);
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

int encherCanhao(int projeteis[][2], int quantP, int capac, int pos, int capacidade, int dinam[][capacidade + 1]){
    if(pos == quantP){
        if(capac >= projeteis[pos][1]){
            dinam[pos][capac] = 1;
            return projeteis[pos][0];
        }
        else{
            dinam[pos][capac] = 0;
            return 0;
        }
    }

    if(dinam[pos][capac] != -1){
        if(dinam[pos][capac] == 1){
            return projeteis[pos][0] + encherCanhao(projeteis, quantP, capac - projeteis[pos][1], pos + 1, capacidade, dinam);
        }
        else{
            return encherCanhao(projeteis, quantP, capac, pos + 1, capacidade, dinam);
        }
    }

    if(capac >= projeteis[pos][1]){
        int esq = encherCanhao(projeteis, quantP, capac, pos + 1, capacidade, dinam);
        int dir = projeteis[pos][0] + encherCanhao(projeteis, quantP, capac - projeteis[pos][1], pos + 1, capacidade, dinam);

        dinam[pos][capac] = dir > esq ? 1 : 0;

        return max(dir, esq);
    }
    else{
        dinam[pos][capac] = 0;

        return encherCanhao(projeteis, quantP, capac, pos + 1, capacidade, dinam);
    }
}

int main(){
    int tests;
    scanf(" %d", &tests);

    int i;
    for (i = 0; i < tests; i++) {
        int quantP;
        scanf(" %d", &quantP);
        int projeteis[quantP][2];
        ler(projeteis, quantP);

        int capac, resist;
        scanf(" %d", &capac);
        scanf(" %d", &resist);

        int dinam[quantP][capac + 1];
        iniciarM(quantP, capac, dinam);

        int valorMax = encherCanhao(projeteis, quantP - 1, capac, 0, capac, dinam);

        if(valorMax >= resist){
            printf("Missao completada com sucesso\n");
        }
        else{
            printf("Falha na missao\n");
        }
    }

    return 0;
}