#include <stdio.h>

int main(void){
	int a, b, y;
	int* p;
	printf("Valor de A e B: ");
	scanf("%d %d", &a, &b);
	printf("%d %d\n", a, b);

	if(a > b){
		p = &a;
	}else if(a < b){
		p = &b;
	}else{
		printf("Números Iguais");
	}
	*p = *p - 50;
	printf("O valor novo de A é %d e de B é %d \n", a, b);
	return 0;
}
