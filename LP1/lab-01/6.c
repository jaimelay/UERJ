#include <stdio.h>

int main (void) {
	int n;
	int i;
	int soma = 0;
	printf("Digite o valor: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		soma += (i * i);
	}
	printf("A soma: %d\n", soma);
	return 0;
}
