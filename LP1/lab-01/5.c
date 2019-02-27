#include <stdio.h>

int main (void) {
	int v;
	int soma = 0;
	printf("Digite os valores: ");
	scanf("%d", &v);
	while (v != 0){
		soma+=v;
		printf("Digite os valores: ");
		scanf("%d", &v);		
	}
	printf("A soma dos valores: %d\n", soma);
	return 0;
}