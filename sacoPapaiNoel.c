//URI 1767
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

void ler(int sacosB[][2], int tam){
    int i;
    for (i = 0; i < tam; i++) {
        scanf(" %d %d", &sacosB[i][0], &sacosB[i][1]);
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

int encherSaco(int sacosB[][2], int quantS, int capac, int pos, int* quantF, int* capacidade, int dinam[][51]){
    if(pos == quantS){
        if(sacosB[pos][1] <= capac){
            *capacidade = capac - sacosB[pos][1];
            *quantF -= 1;

            dinam[pos][capac] = 1;
            return sacosB[pos][0];
        }
        else{
            *capacidade = capac;

            dinam[pos][capac] = 0;
            return 0;
        }
    }

    if(dinam[pos][capac] != -1){
        if(dinam[pos][capac] == 1){
            *quantF -= 1;

            return sacosB[pos][0] + encherSaco(sacosB, quantS, capac - sacosB[pos][1], pos + 1, quantF, capacidade, dinam);
        }
        else{
            return encherSaco(sacosB, quantS, capac, pos + 1, quantF, capacidade, dinam);
        }
    }

    if(capac >= sacosB[pos][1]){
        int quantFRE, quantFRD, capacidadeRE, capacidadeRD;
        quantFRE = *quantF;
        quantFRD = *quantF - 1;
        capacidadeRE = *capacidade;
        capacidadeRD = *capacidade;

        int esq = encherSaco(sacosB, quantS, capac, pos + 1, &quantFRE, &capacidadeRE, dinam);
        int dir = sacosB[pos][0] + encherSaco(sacosB, quantS, capac - sacosB[pos][1], pos + 1, &quantFRD, &capacidadeRD, dinam);

        dinam[pos][capac] = dir > esq ? 1 : 0;
        *quantF = dir > esq ? quantFRD : quantFRE;
        *capacidade = dir > esq ? capacidadeRD : capacidadeRE;

        return max(dir, esq);
    }
    else{
        dinam[pos][capac] = 0;

        return encherSaco(sacosB, quantS, capac, pos + 1, quantF, capacidade, dinam);
    }
}

int main(){
    int viagens;
    scanf(" %d", &viagens);

    int i;
    for (i = 0; i < viagens; i++) {
        int quantS;
        scanf(" %d", &quantS);
        int sacosB[quantS][2];
        ler(sacosB, quantS);

        int capac = 50;

        int dinam[quantS][capac + 1];
        iniciarM(quantS, capac, dinam);

        int quantF = quantS;
        int capacidade = 0;
        int brinquedos = encherSaco(sacosB, quantS - 1, capac, 0, &quantF, &capacidade, dinam);

        printf("%d brinquedos\n", brinquedos);
        printf("Peso: %d kg\n", 50 - capacidade);
        printf("sobra(m) %d pacote(s)\n\n", quantF);
    }

    return 0;
}