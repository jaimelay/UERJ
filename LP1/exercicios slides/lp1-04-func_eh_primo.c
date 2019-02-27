// Exercicio 1 de Funções
// Crie uma função eh_primo que recebe um inteiro n e retorna se ele é primo ou não.

#include <stdio.h>

int eh_primo(int p){
	int i;

	if (p == 1){
		return 0;
	}

	for(i = 2; i <= p/2; i++){
		if(p % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int p;
	printf("Digite um número: ");
	scanf("%d", &p);
	if(eh_primo(p) == 1){
		printf("É PRIMO\n");
	}else{
		printf("NÃO É PRIMO\n");
	}
	return 0;
}
