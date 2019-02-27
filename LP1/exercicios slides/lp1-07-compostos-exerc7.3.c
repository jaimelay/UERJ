#include <stdio.h>

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
    struct Personagem vetor[10];
    for(int i = 0; i < 10; i++){
        preenchePersonagem(&vetor[i]);
    }
    for(int j = 0; j < 10; j++){
        printf("Identidade: %d\n", vetor[j].identidade);
        printf("Pontuação: %d\n", vetor[j].pontuacao);
        printf("Posição: X = %d Y = %d\n", vetor[j].pos.x, vetor[j].pos.y);
    }
    return 0;
}
