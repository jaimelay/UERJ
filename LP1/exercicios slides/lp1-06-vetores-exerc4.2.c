#include <stdio.h>

void preenche(int arr[2][2]){
	int elemento;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
				printf("Digite o elemento do Arr[%d][%d]: ", i, j);
				scanf("%d", &elemento);
				arr[i][j] = elemento;
		}
	}
}

int media(int arr[2][2]){
	float media = 0, soma = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			soma += arr[i][j];
		}
	}
	media = printf("Média: %.2f\n", soma/4);
	return media;
}

int main(void){
	int arr[2][2];
	preenche(arr);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			printf("Arr[%d][%d] = '%d' \n", i, j, arr[i][j]);
		}
		printf("\n");
	}
	media(arr);
	return 0;
}
