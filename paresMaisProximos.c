//URI 1295
#include <stdio.h>
#include <math.h>

typedef struct ponto {
    double x;
    double y;
} Ponto;

double calDist(Ponto ponto1, Ponto ponto2){
    return sqrt(((ponto1.x - ponto2.x) * (ponto1.x - ponto2.x)) + ((ponto1.y - ponto2.y) * (ponto1.y - ponto2.y)));
}

double calMenDist(Ponto pontos[], int tam){
    double dist = calDist(pontos[0], pontos[1]);

    int i;
    for (i = 1; i < tam; i++) {
        int j;
        for (j = 0; j < i; j++) {
            double distAux = calDist(pontos[i], pontos[j]);

            if(distAux < dist){
                dist = distAux;
            }
        }
    }

    return dist;
}

int main(){
    int quantPontos;
    scanf(" %d", &quantPontos);

    while(quantPontos != 0){
        Ponto pontos[quantPontos];

        int i;
        for (i = 0; i < quantPontos; i++) {
            scanf(" %lf %lf", &pontos[i].x, &pontos[i].y);
        }

        if(quantPontos != 1){
            double mDist = calMenDist(pontos, quantPontos);
            if (mDist < 10000) {
                printf("%.4lf\n", mDist);
            } else {
                printf("INFINITY\n");
            }
        }
        else {
            printf("INFINITY\n");
        }

        scanf(" %d", &quantPontos);
    }

    return 0;
}