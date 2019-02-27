// Exercicio 2
// Cria uma função todos_os_primos que recebe um inteiro max e exibe todos os primos entre 1 e max.

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

int todos_os_primos(max){
    int j;
    for(j = 1; j <= max; j++){
        if(eh_primo(j)){
            printf("%d\n", j);
        }
    }
    return 0;
}

int main(void){
    int max;
    printf("Digite o máximo: ");
    scanf("%d", &max);
    todos_os_primos(max);
    return 0;
}
