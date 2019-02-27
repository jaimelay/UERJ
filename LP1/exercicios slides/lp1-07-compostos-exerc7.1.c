#include <stdio.h>

struct Pessoa {
	char nome[30];
	int idade;
	int cpf;
	int rg;
};

void preenche(struct Pessoa *p){
	printf("Digite o nome da pessoa que você deseja cadastrar: ");
	scanf("%s", (*p).nome);
	printf("Digite a idade: ");
	scanf("%d", &(*p).idade);
	printf("Digite o CPF: ");
	scanf("%d", &(*p).cpf);
	printf("Digite o RG: ");
	scanf("%d", &(*p).rg);
}

int main(void){
	struct Pessoa p;
	preenche(&p);
	printf("Nome: %s\n", p.nome);
	printf("Idade: %d\n", p.idade);
	printf("CPF: %d\n", p.cpf);
	printf("RG: %d\n", p.rg);

	return 0;
}
