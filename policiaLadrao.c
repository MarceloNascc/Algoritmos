//URI 1905
#include <stdio.h>

void preencher(int tabuleiro[][5]){
    int i;
    for (i = 0; i < 5; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            scanf(" %d", &tabuleiro[i][j]);
        }
    }
}

int percorrerTab(int l, int c, int tabuleiro[][5]){
    if(l == 4 && c == 4){
        return 1;
    }

    tabuleiro[l][c] = 1;
    int polVenceu = 0;

    if(l > 0 && tabuleiro[l-1][c] != 1){
        polVenceu = percorrerTab(l-1, c, tabuleiro);

        if(polVenceu){
            return 1;
        }
    }

    if(c < 4 && tabuleiro[l][c+1] != 1){
        polVenceu = percorrerTab(l, c+1, tabuleiro);

        if(polVenceu){
            return 1;
        }
    }

    if(l < 4 && tabuleiro[l+1][c] != 1){
        polVenceu = percorrerTab(l+1, c, tabuleiro);

        if(polVenceu){
            return 1;
        }
    }

    if(c > 0 && tabuleiro[l][c-1] != 1){
        polVenceu = percorrerTab(l, c-1, tabuleiro);

        if(polVenceu){
            return 1;
        }
    }

    return 0;
}

int main()
{
    int testes;
    scanf(" %d", &testes);

    int tabuleiro[5][5];

    int i;
    for (i = 0; i < testes; i++) {
        preencher(tabuleiro);

        int polVenceu = 0;
        if(tabuleiro[0][0] != 1) {
            polVenceu = percorrerTab(0, 0, tabuleiro);
        }

        if(polVenceu){
            printf("COPS\n");
        }
        else{
            printf("ROBBERS\n");
        }
    }

    return 0;
}