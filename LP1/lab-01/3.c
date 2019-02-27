#include <stdio.h>

int main (void) {
	int a;
	printf("Digite o valor do produto em dólar: ");
	scanf("%d", &a);
	int b;
	b = (a * 3.17);
	printf("O valor do produto transformado para real: %d\n", b);
	if (b <= 1000){
		printf("BOM NEGÓCIO!");
	}
    return 0;
}
