#include <stdio.h>

int main (void) {
	int a;
	printf("Digite o primeiro número: ");
	scanf("%d", &a);
	int b;
	printf("Digite o segundo número: ");
	scanf("%d", &b);
	if (a > b){
		printf("%d é maior do que %d\n", a, b);
	} else {
		printf("%d é maior do que %d\n", b, a);
	}
    return 0;
}
}
