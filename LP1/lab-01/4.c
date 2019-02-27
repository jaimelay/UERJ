#include <stdio.h>

int main (void) {
	int v;
	printf("Digite a velocidade atual do carro em mph: ");
	scanf("%d", &v);
	int b;
	b = (v * 1.6);
	printf("A velocidade atual do carro transformada para kph: %d\n", b);
	if ( b >= 80 && b <= 100 ){
		printf("MANTENHA\n");
	} else if ( b < 80 ){
		printf("ACELERE.\n");
	} else if ( b > 100 ){
		printf("DESACELERE\n");
	}
	return 0;
}
