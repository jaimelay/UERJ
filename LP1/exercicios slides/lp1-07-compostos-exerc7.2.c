#include <stdio.h>

struct Endereco {
	char estado[30];
	char cidade[30];
	char rua[30];
	int cep;
	int numero;
	char complemento[30];
};

struct Pessoa {
	char nome[30];
	int idade;
	int cpf;
	int rg;
	int tel;
	struct Endereco end;
};

void preenche(struct Endereco *e){
    printf("Digite o estado onde a pessoa mora: ");
    scanf("%s", (*e).estado);
    printf("Digite a cidade onde a pessoa mora: ");
    scanf("%s", (*e).cidade);
    printf("Digite a rua: ");
    scanf("%s", (*e).rua);
    printf("Digite o CEP: ");
    scanf("%d", &(*e).cep);
    printf("Digite o número: ");
    scanf("%d", &(*e).numero);
    printf("Digite o complemento: ");
    scanf("%s", (*e).complemento);
}

void preenche2(struct Pessoa *p){
	printf("Digite o nome da pessoa que você deseja cadastrar: ");
	scanf("%s", (*p).nome);
	printf("Digite a idade: ");
	scanf("%d", &(*p).idade);
	printf("Digite o CPF: ");
	scanf("%d", &(*p).cpf);
	printf("Digite o RG: ");
	scanf("%d", &(*p).rg);
	printf("Digite o Telefone: ");
	scanf("%d", &(*p).tel);
	printf("Preencha agora com as informações de Endereço: \n");
	preenche(&(*p).end);
}

int main(void){
    struct Pessoa p;
    preenche2(&p);
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("CPF: %d\n", p.cpf);
    printf("RG: %d\n", p.rg);
    printf("Telefone: %d\n", p.tel);
    printf("Estado: %s\n", p.end.estado);
    printf("Cidade: %s\n", p.end.cidade);
    printf("Rua: %s\n", p.end.rua);
    printf("CEP: %d\n", p.end.cep);
    printf("Numero: %d\n", p.end.numero);
    printf("Complemento: %d\n", p.end.complemento);

    return 0;
}
