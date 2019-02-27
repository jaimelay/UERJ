#include <stdio.h>
#include <math.h>

#define MAX_VETOR 10

struct Ponto{
	int x, y;
};

void preenchePt(struct Ponto* pt){
	printf("Digite o ponto (x,y) separados por espaço: ");
	scanf("%d %d", &(*pt).x, &(*pt).y);
}

void preencheVet(struct Ponto vetPt[MAX_VETOR]){
    for(int i = 0; i < MAX_VETOR; i++){
        struct Ponto pt;
        preenchePt(&pt);
        vetPt[i] = pt;
    }
}

struct Ponto func_maisDistante(struct Ponto vetPt[MAX_VETOR]){
    float dis = 0, distancia = 0;
    struct Ponto maisDistante;
    for(int i = 0; i < MAX_VETOR; i++){
        dis = sqrt( pow(vetPt[i].x, 2) + pow(vetPt[i].y, 2) );
        if(dis > distancia){
            distancia = dis;
            maisDistante = vetPt[i];
        }
    }
    return maisDistante;
}

int main(void){
	struct Ponto vetPt[MAX_VETOR];
	preencheVet(vetPt);
	for(int i = 0; i < MAX_VETOR; i++){
        	printf("Ponto %d (x,y): (%d,%d)\n", i, vetPt[i].x, vetPt[i].y);
	}
	struct Ponto maisDistante;
	maisDistante = func_maisDistante(vetPt);
	printf("O ponto mais distante de (0,0) é (%d,%d).\n", maisDistante.x, maisDistante.y);
	return 0;
}
