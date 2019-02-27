#include <stdio.h>

void compra(int* conta, int valor){
	*conta = *conta - valor;
}

int main(void){
	int conta1, conta2, i;
	int* conta;
	int compras[] = {100, 50, 80, 30, 20};
	printf("Digite o saldo da primeira conta: ");
	scanf("%d", &conta1);
	printf("Digite o saldo da segunda conta: ");
	scanf("%d", &conta2);
	for(i = 0; i < 5; i++){
		if(conta1 > conta2){
		    conta = &conta1;
		}else{
		    conta = &conta2;
		}
		compra(conta, compras[i]);
		printf("O valor descontado da conta de maior valor foi de: %d\n", compras[i]);
		printf("O saldo novo da conta 1 é %d e o da conta 2 é %d.\n", conta1, conta2);
	}
	return 0;
}
