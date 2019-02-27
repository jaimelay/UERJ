#include <stdio.h>

#define LINHA 10
#define COLUNA 10
#define PERSONAGENS 10

struct Posicao {
    int x;
    int y;
};

struct Personagem {
    int identidade;
    int pontuacao;
    struct Posicao pos;
};

void preenchePos(struct Posicao *pos){
    printf("Posição X: ");
    scanf("%d", &(*pos).x);
    printf("Posição Y: ");
    scanf("%d", &(*pos).y);
}

void preenchePersonagem(struct Personagem *p){
    printf("Identidade do Personagem: ");
    scanf("%d", &(*p).identidade);
    (*p).pontuacao = 0;
    preenchePos(&(*p).pos);
}

int main(void){
    int arr[LINHA][COLUNA] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    struct Personagem personagens[PERSONAGENS];

    for(int i = 0; i < PERSONAGENS; i++){
        preenchePersonagem(&personagens[i]);
    }

    for(int i = 0; i < PERSONAGENS; i++){
        printf("Identidade: %d\n", personagens[i].identidade);
        printf("Pontuação: %d\n", personagens[i].pontuacao);
        printf("Posição: (%d, %d)\n", personagens[i].pos.x, personagens[i].pos.y);
    }

    for(int i = 0; i < PERSONAGENS; i++){
        arr[personagens[i].pos.x][personagens[i].pos.y] = personagens[i].identidade;
    }

	printf("  ");
	for(int j = 0; j < COLUNA; j++){
		printf("%d ", j);
	}
	printf("\n");
    for(int i = 0; i < LINHA; i++){
        printf("%d ", i);
        for(int j = 0; j < COLUNA; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
	return 0;
}
