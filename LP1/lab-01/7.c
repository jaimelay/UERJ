#include <stdio.h>
#include <string.h>

int main(void){
	int v, e, d, i, ptsTotal, maiorPontuacao, menorPontuacao;
	int vitoria = 3;
	int empate = 1;
	int derrota = 0;
	char nome[20], nomeMaior[20], nomeMenor[20];

	for(i = 0; i < 20; i++){
		printf("Digite o nome do time: ");
		scanf("%s", nome);
		printf("Digite o número de vitórias do mesmo: ");
		scanf("%d", &v);
		printf("Digite o número de empates do mesmo: ");
		scanf("%d", &e);
		printf("Digite o número de derrotas do mesmo: ");
		scanf("%d", &d);

		ptsTotal = (vitoria * v) + (empate * e) + (derrota * e);

		if(ptsTotal > maiorPontuacao){
			strcpy (nomeMaior, nome);
			maiorPontuacao = ptsTotal;
		}

		if(ptsTotal < menorPontuacao){
			strcpy (nomeMenor, nome);
			menorPontuacao = ptsTotal;
		}
	}
	printf("O time com a maior pontuação é o time %s com %d pontos e o de menor pontuação é o time %s com %d pontos.\n", nomeMaior, maiorPontuacao, nomeMenor, menorPontuacao);
	return 0;
}
