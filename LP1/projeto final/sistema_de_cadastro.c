//=============================================================================
// PROJETO FINAL - LINGUAGEM DE PROGRAMAÇÃO 1
//             SISTEMA DE CADASTRO
// ALUNO: JAIME LAY     PROFESSOR: FRANCISCO SANTANNA
//=============================================================================
// OBSERVAÇÕES:
// - Utilizei system("cls"); ja que fiz o programa no windows.
// Substituir por system("clear"); no define LIMPAR_TELA se for linux.
//
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//=============================================================================
// DEFININDO AS CONSTANTES
//=============================================================================
#define MAX_CADASTROS 5                     // DEFINIR QUANTAS PESSOAS PODEM SER CADASTRADAS.
#define SENHA_ADMIN 1234                    // DEFINIR SENHA PARA ADMINISTRAR O SISTEMA.
#define MAX_STRING 50                       // TAMANHO MÁXIMO DE CARACTERES
#define ARQUIVO_TXT "banco_de_dados.txt"    // NOME DO ARQUIVO
#define LIMPAR_TELA system("cls");          // FUNÇÃO PARA LIMPAR TELA
//=============================================================================
// STRUCTS
//=============================================================================
typedef struct {
	char estado[MAX_STRING], cidade[MAX_STRING], bairro[MAX_STRING], rua[MAX_STRING], complemento[MAX_STRING];
	int numero, cep;
}Enderecos;

typedef struct {
	char nome[MAX_STRING];
	int idade, telefone, id, cadastrado;
	long long int cpf, rg;
	Enderecos ender;
}Pessoas;
Pessoas pessoa[MAX_CADASTROS];

//=============================================================================
// DECLARANDO AS FUNÇÕES QUE VOU USAR
//=============================================================================
void menu();
void menuAdmin();
void cadastro();
void preencheEndereco();
void preenchePessoas();
void listar();
void pesquisar();
void alterar();
void excluir();
//=============================================================================
// MENU PRINCIPAL
//=============================================================================
int main(void){
    menu();
    return 0;
}
//=============================================================================
// FUNÇÃO MENU NORMAL
//=============================================================================
void menu(){
    setlocale(LC_ALL, "Portuguese");    // PARA RESOLVER ERROS NOS ACENTOS
    int menu, senha;
    do{
        LIMPAR_TELA
        printf("#################################################\n");
        printf("\t # Sistema de Cadastro #\n");
        printf("\t Criado por: Jaime Lay \n");
        printf("#################################################\n");
        printf("Menu:\n");
        printf("1 - Listar Cadastros\n");
        printf("2 - Pesquisar Cadastros\n");
        printf("3 - Administração\n");
        printf("4 - Sair\n");
        scanf("%d", &menu);
        switch(menu){
        case 1:
            listar();
            break;
        case 2:
            pesquisar();
            break;
        case 3:
            printf("Digite a senha para acessar a administração: ");
            scanf("%d", &senha);
            if(senha == SENHA_ADMIN){
                menuAdmin();
            }else{
                LIMPAR_TELA
                printf("SENHA INCORRETA! DIGITE NOVAMENTE\n");
                system("pause");
            }
            break;
        }
    }while(menu != 4);
}
//=============================================================================
// FUNÇÃO MENU ADMINISTRAÇÃO
//=============================================================================
void menuAdmin(){
    setlocale(LC_ALL, "Portuguese");    // PARA RESOLVER ERROS NOS ACENTOS
	int menuAdmin, i;
	do{
        LIMPAR_TELA
        printf("#################################################\n");
        printf("\t # Administração do Sistema #\n");
        printf("#################################################\n");
        printf("Menu de Administrador:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar Cadastros\n");
        printf("3 - Pesquisar Cadastros\n");
        printf("4 - Alterar Cadastros\n");
        printf("5 - Excluir Cadastros\n");
        printf("6 - Sair\n");
        printf("Qual dessas opções você deseja escolher? ");
        scanf("%d", &menuAdmin);
        switch(menuAdmin){
            case 1:
                cadastro();
                break;
            case 2:
                listar();
                break;
            case 3:
                pesquisar();
                break;
            case 4:
                alterar();
                break;
            case 5:
                excluir();
                break;
        }
	}while(menuAdmin != 6);
}
//=============================================================================
// FUNÇÕES PARA PREENCHER AS STRUCTS
//=============================================================================
void preencheEndereco(Enderecos *ender){
    setlocale(LC_ALL, "Portuguese");    // PARA RESOLVER ERROS NOS ACENTOS
    printf("-- Digite as Informações de Endereço --\n");
    getchar();                      // LIMPA BUFFER
    printf("Digite o Estado: ");
    scanf("%[^\n]s", (*ender).estado);
    getchar();                      // LIMPA BUFFER
    printf("Digite a Cidade: ");
    scanf("%[^\n]s", (*ender).cidade);
    getchar();                      // LIMPA BUFFER
    printf("Digite o CEP: ");
    scanf("%d", &(*ender).cep);
    getchar();                      // LIMPA BUFFER
    printf("Digite o Bairro: ");
    scanf("%[^\n]s", (*ender).bairro);
    getchar();                      // LIMPA BUFFER
    printf("Digite a Rua: ");
    scanf("%[^\n]s", (*ender).rua);
    getchar();                      // LIMPA BUFFER
    printf("Digite o Complemento: ");
    scanf("%[^\n]s", (*ender).complemento);
    getchar();                      // LIMPA BUFFER
    printf("Digite o Número: ");
    scanf("%d", &(*ender).numero);
    getchar();                      // LIMPA BUFFER
}

void preenchePessoas(Pessoas *p){
    setlocale(LC_ALL, "Portuguese");    // PARA RESOLVER ERROS NOS ACENTOS
    getchar();                      // LIMPA BUFFER
    printf("Digite o nome da pessoa que você deseja cadastrar: ");
    scanf("%[^\n]s", (*p).nome);
    getchar();                      // LIMPA BUFFER
    printf("Digite a idade: ");
    scanf("%d", &(*p).idade);
    printf("Digite o CPF: ");
    scanf("%lld", &(*p).cpf);
    printf("Digite o RG: ");
    scanf("%lld", &(*p).rg);
    printf("Digite o Telefone: ");
    scanf("%d", &(*p).telefone);
    (*p).cadastrado = 1;
    preencheEndereco(&(*p).ender);
}
//=============================================================================
// FUNÇÃO CADASTRO
//=============================================================================
void cadastro(){
    setlocale(LC_ALL, "Portuguese");            // PARA RESOLVER ERROS NOS ACENTOS
	int opcao, i;
	do{
        LIMPAR_TELA
        printf("#################################################\n");
        printf("\t # Menu de Cadastramento #\n");
        printf("#################################################\n");
        FILE* f = fopen(ARQUIVO_TXT, "ab");
        if(f == NULL){
            printf("PROBLEMAS EM ABRIR O ARQUIVO.");
        }else{
            for(i = 0; i < MAX_CADASTROS; i++){
                if(pessoa[i].cadastrado == 0){      // CONFERE SE O ESTÁ CADASTRADO OU NÃO (0 = NÃO E 1 = SIM)
                        preenchePessoas(&pessoa[i]);
                        pessoa[i].id = i + 1;
                        fwrite(&pessoa[i], sizeof(Pessoas), 1, f);
                        printf("\nO cadastro de ID '%d' foi realizado com sucesso.\n", pessoa[i].id);
                        break;
                }
            }
        }
        fclose(f);
        printf("\n1 - Cadastrar uma nova pessoa.\n");
        printf("0 - Voltar para o menu principal.\n");
        scanf("%d", &opcao);
	}while(opcao != 0);
}
//=============================================================================
// FUNÇÃO PARA LISTAR CADASTROS
//=============================================================================
void listar(){
    setlocale(LC_ALL, "Portuguese");    // PARA RESOLVER ERROS NOS ACENTOS
    int opcao;
    do{
        LIMPAR_TELA
        printf("#################################################\n");
        printf("\t # Lista de Cadastrados #\n");
        printf("#################################################\n");
        FILE* f = fopen(ARQUIVO_TXT, "rb");
        if(f == NULL){
            printf("PROBLEMAS EM ABRIR O ARQUIVO OU NÃO FOI CADASTRADO NENHUMA PESSOA. ACESSE A ADMINISTRAÇÃO PARA CADASTRAMENTOS.");
        }else{
            for(int i = 0; i < MAX_CADASTROS; i++){
                fread(&pessoa[i], sizeof(Pessoas), 1, f);
                if(pessoa[i].cadastrado == 1){
                    printf("ID de Cadastro: %d\n", pessoa[i].id);
                    printf("Nome: %s\n", pessoa[i].nome);
                    printf("Idade: %d\n", pessoa[i].idade);
                    printf("CPF: %lld\n", pessoa[i].cpf);
                    printf("RG: %lld\n", pessoa[i].rg);
                    printf("Telefone %d\n", pessoa[i].telefone);
                    printf("- Informações de Endereço -\n");
                    printf("Estado: %s\n", pessoa[i].ender.estado);
                    printf("Cidade: %s\n", pessoa[i].ender.cidade);
                    printf("CEP: %d\n", pessoa[i].ender.cep);
                    printf("Bairro: %s\n", pessoa[i].ender.bairro);
                    printf("Rua: %s Complemento: %s Número: %d\n", pessoa[i].ender.rua, pessoa[i].ender.complemento, pessoa[i].ender.numero);
                    printf("=====================================================\n");
                }
            }
        }
        fclose(f);
        printf("\nDeseja voltar ao menu principal?\n");
        printf("1 - Sim.\n");
        printf("2 - Não.\n");
        scanf("%d", &opcao);
    }while(opcao != 1);
}
//=============================================================================
// FUNÇÃO PARA PESQUISAR CADASTROS
//=============================================================================
void pesquisar(){
    setlocale(LC_ALL, "Portuguese");    // PARA RESOLVER ERROS NOS ACENTOS
    char nome[MAX_STRING], cidade[MAX_STRING];
    int idade, opcao, opcao2;
    do{
        LIMPAR_TELA
        printf("#################################################\n");
        printf("\t # Pesquisar Cadastros #\n");
        printf("#################################################\n");
        FILE* f = fopen(ARQUIVO_TXT, "rb");
        if(f != NULL){
            printf("Você deseja usar que tipo de pesquisa?\n");
            printf("1 - Pesquisar por Nome.\n");
            printf("2 - Pesquisar por Idade.\n");
            printf("3 - Pesquisar por Cidade.\n");
            scanf("%d", &opcao2);
            switch(opcao2){
                case 1:
                    LIMPAR_TELA
                    printf("#################################################\n");
                    printf("\t # Pesquisar Cadastros #\n");
                    printf("#################################################\n");
                    printf("Digite o nome do cadastrado que você deseja pesquisar: ");
                    getchar();                      // LIMPA BUFFER
                    scanf("%[^\n]s", nome);
                    for(int i = 0; i < MAX_CADASTROS; i++){
                        fread(&pessoa[i], sizeof(Pessoas), 1, f);
                        if(strcmp(pessoa[i].nome, nome) == 0){
                            printf("ID de Cadastro: %d\n", pessoa[i].id);
                            printf("Nome: %s\n", pessoa[i].nome);
                            printf("Idade: %d\n", pessoa[i].idade);
                            printf("CPF: %lld\n", pessoa[i].cpf);
                            printf("RG: %lld\n", pessoa[i].rg);
                            printf("Telefone %d\n", pessoa[i].telefone);
                            printf("- Informações de Endereço -\n");
                            printf("Estado: %s\n", pessoa[i].ender.estado);
                            printf("Cidade: %s\n", pessoa[i].ender.cidade);
                            printf("CEP: %d\n", pessoa[i].ender.cep);
                            printf("Bairro: %s\n", pessoa[i].ender.bairro);
                            printf("Rua: %s Complemento: %s Número: %d\n", pessoa[i].ender.rua, pessoa[i].ender.complemento, pessoa[i].ender.numero);
                            printf("=====================================================\n");
                        }
                    }
                    break;
                case 2:
                    LIMPAR_TELA
                    printf("#################################################\n");
                    printf("\t # Pesquisar Cadastros #\n");
                    printf("#################################################\n");
                    printf("Digite a idade do cadastrado que você deseja pesquisar: ");
                    scanf("%d", &idade);
                    printf("\n");
                    for(int i = 0; i < MAX_CADASTROS; i++){
                        fread(&pessoa[i], sizeof(Pessoas), 1, f);
                        if(pessoa[i].idade == idade){
                            printf("ID de Cadastro: %d\n", pessoa[i].id);
                            printf("Nome: %s\n", pessoa[i].nome);
                            printf("Idade: %d\n", pessoa[i].idade);
                            printf("CPF: %lld\n", pessoa[i].cpf);
                            printf("RG: %lld\n", pessoa[i].rg);
                            printf("Telefone %d\n", pessoa[i].telefone);
                            printf("- Informações de Endereço -\n");
                            printf("Estado: %s\n", pessoa[i].ender.estado);
                            printf("Cidade: %s\n", pessoa[i].ender.cidade);
                            printf("CEP: %d\n", pessoa[i].ender.cep);
                            printf("Bairro: %s\n", pessoa[i].ender.bairro);
                            printf("Rua: %s Complemento: %s Número: %d\n", pessoa[i].ender.rua, pessoa[i].ender.complemento, pessoa[i].ender.numero);
                            printf("=====================================================\n");
                        }
                    }
                    break;
                case 3:
                    LIMPAR_TELA
                    printf("#################################################\n");
                    printf("\t # Pesquisar Cadastros #\n");
                    printf("#################################################\n");
                    printf("Digite a cidade do cadastrado que você deseja pesquisar: ");
                    getchar();                      // LIMPA BUFFER
                    scanf("%[^\n]s", cidade);
                    printf("\n");
                    for(int i = 0; i < MAX_CADASTROS; i++){
                        fread(&pessoa[i], sizeof(Pessoas), 1, f);
                        if(strcmp(pessoa[i].ender.cidade, cidade) == 0){
                            printf("ID de Cadastro: %d\n", pessoa[i].id);
                            printf("Nome: %s\n", pessoa[i].nome);
                            printf("Idade: %d\n", pessoa[i].idade);
                            printf("CPF: %lld\n", pessoa[i].cpf);
                            printf("RG: %lld\n", pessoa[i].rg);
                            printf("Telefone %d\n", pessoa[i].telefone);
                            printf("- Informações de Endereço -\n");
                            printf("Estado: %s\n", pessoa[i].ender.estado);
                            printf("Cidade: %s\n", pessoa[i].ender.cidade);
                            printf("CEP: %d\n", pessoa[i].ender.cep);
                            printf("Bairro: %s\n", pessoa[i].ender.bairro);
                            printf("Rua: %s Complemento: %s Número: %d\n", pessoa[i].ender.rua, pessoa[i].ender.complemento, pessoa[i].ender.numero);
                            printf("=====================================================\n");
                        }
                    }
                    break;
            }
        }else{
            printf("PROBLEMAS EM ABRIR O ARQUIVO OU NÃO FOI CADASTRADO NENHUMA PESSOA. ACESSE A ADMINISTRAÇÃO PARA CADASTRAMENTOS.");
        }
        fclose(f);
        printf("\nDeseja pesquisar outro cadastro?\n");
        printf("1 - Sim.\n");
        printf("2 - Não.\n");
        scanf("%d", &opcao);
    }while(opcao != 2);

}
//=============================================================================
// FUNÇÃO PARA ALTERAR CADASTROS
//=============================================================================
void alterar(){
    setlocale(LC_ALL, "Portuguese");    // PARA RESOLVER ERROS NOS ACENTOS
    int id, opcao, opcao2, alterar, tmpInt;
    int idade, telefone, cep, numero;
    long long int cpf, rg, tmpLongInt;
    char nome[MAX_STRING], estado[MAX_STRING], cidade[MAX_STRING], bairro[MAX_STRING], rua[MAX_STRING], complemento[MAX_STRING], tmpChar[MAX_STRING];
    do{
        LIMPAR_TELA
        printf("#################################################\n");
        printf("\t # Alterar Cadastros #\n");
        printf("#################################################\n");
        printf("Digite o ID do Cadastro que você deseja alterar: ");
        scanf("%d", &id);
        id = id - 1;
        if(pessoa[id].id > 0){
            LIMPAR_TELA
            printf("#################################################\n");
            printf("\t # Alterar Cadastros #\n");
            printf("#################################################\n");
            printf("ID de Cadastro: %d\n", pessoa[id].id);
            printf("Nome: %s\n", pessoa[id].nome);
            printf("Idade: %d\n", pessoa[id].idade);
            printf("CPF: %lld\n", pessoa[id].cpf);
            printf("RG: %lld\n", pessoa[id].rg);
            printf("Telefone %d\n", pessoa[id].telefone);
            printf("- Informações de Endereço -\n");
            printf("Estado: %s\n", pessoa[id].ender.estado);
            printf("Cidade: %s\n", pessoa[id].ender.cidade);
            printf("CEP: %d\n", pessoa[id].ender.cep);
            printf("Bairro: %s\n", pessoa[id].ender.bairro);
            printf("Rua: %s Complemento: %s Número: %d\n", pessoa[id].ender.rua, pessoa[id].ender.complemento, pessoa[id].ender.numero);
            printf("=====================================================\n");
            printf("O que você deseja alterar neste cadastro?\n");
            printf("1 - Nome\n2 - Idade\n3 - CPF\n4 - RG\n5 - Telefone\n");
            printf("6 - Estado\n7 - Cidade\n8 - CEP\n9 - Bairro\n10 - Rua\n");
            printf("11 - Complemento\n12 - Número\n");
            scanf("%d", &alterar);
            switch(alterar){
                case 1:
                    printf("O Nome desse cadastro é '%s'\n", pessoa[id].nome);
                    strcpy(tmpChar, pessoa[id].nome);
                    printf("Digite o novo Nome do cadastro: ");
                    getchar();
                    scanf("%[^\n]s", nome);
                    strcpy(pessoa[id].nome, nome);
                    printf("O nome foi alterado de '%s' para '%s'.\n", tmpChar, nome);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 2:
                    printf("A Idade desse cadastro é '%d'\n", pessoa[id].idade);
                    tmpInt = pessoa[id].idade;
                    printf("Digite a nova Idade do cadastro: ");
                    getchar();
                    scanf("%d", &idade);
                    pessoa[id].idade = idade;
                    printf("A idade foi alterado de '%d' para '%d'.\n", tmpInt, idade);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 3:
                    printf("O CPF desse cadastro é '%lld'\n", pessoa[id].cpf);
                    tmpLongInt = pessoa[id].cpf;
                    printf("Digite o novo CPF do cadastro: ");
                    getchar();
                    scanf("%lld", &cpf);
                    pessoa[id].cpf = cpf;
                    printf("O CPF foi alterado de '%lld' para '%lld'.\n", tmpLongInt, cpf);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 4:
                    printf("O RG desse cadastro é '%lld'\n", pessoa[id].rg);
                    tmpLongInt = pessoa[id].rg;
                    printf("Digite o novo RG do cadastro: ");
                    getchar();
                    scanf("%lld", &rg);
                    pessoa[id].rg = rg;
                    printf("O RG foi alterado de '%lld' para '%lld'.\n", tmpLongInt, rg);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 5:
                    printf("O Telefone desse cadastro é '%d'\n", pessoa[id].telefone);
                    tmpInt = pessoa[id].telefone;
                    printf("Digite o novo Telefone do cadastro: ");
                    getchar();
                    scanf("%d", &telefone);
                    pessoa[id].telefone = telefone;
                    printf("O Telefone foi alterado de '%d' para '%d'.\n", tmpInt, telefone);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 6:
                    printf("O Estado desse cadastro é '%s'\n", pessoa[id].ender.estado);
                    strcpy(tmpChar, pessoa[id].ender.estado);
                    printf("Digite o novo Estado do cadastro: ");
                    getchar();
                    scanf("%[^\n]s", estado);
                    strcpy(pessoa[id].ender.estado, estado);
                    printf("O Estado foi alterado de '%s' para '%s'.\n", tmpChar, estado);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 7:
                    printf("A Cidade desse cadastro é '%s'\n", pessoa[id].ender.cidade);
                    strcpy(tmpChar, pessoa[id].ender.cidade);
                    printf("Digite a nova Cidade do cadastro: ");
                    getchar();
                    scanf("%[^\n]s", cidade);
                    strcpy(pessoa[id].ender.cidade, cidade);
                    printf("A Cidade foi alterada de '%s' para '%s'.\n", tmpChar, cidade);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 8:
                    printf("O CEP desse cadastro é '%d'\n", pessoa[id].ender.cep);
                    tmpInt = pessoa[id].ender.cep;
                    printf("Digite o novo CEP do cadastro: ");
                    getchar();
                    scanf("%d", &cep);
                    pessoa[id].ender.cep = cep;
                    printf("O CEP foi alterado de '%d' para '%d'.\n", tmpInt, cep);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 9:
                    printf("O bairro desse cadastro é '%s'\n", pessoa[id].ender.bairro);
                    strcpy(tmpChar, pessoa[id].ender.bairro);
                    printf("Digite a nova Cidade do cadastro: ");
                    getchar();
                    scanf("%[^\n]s", bairro);
                    strcpy(pessoa[id].ender.bairro, bairro);
                    printf("O Bairro foi alterado de '%s' para '%s'.\n", tmpChar, bairro);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 10:
                    printf("A Rua desse cadastro é '%s'.\n", pessoa[id].ender.rua);
                    strcpy(tmpChar, pessoa[id].ender.rua);
                    getchar();
                    printf("Digite a nova Rua do cadastro: ");
                    scanf("%[^\n]s", rua);
                    strcpy(pessoa[id].ender.rua, rua);
                    printf("A Rua foi alterado de '%s' para '%s'.\n", tmpChar, rua);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 11:
                    printf("O Complemento desse cadastro é '%s'.\n", pessoa[id].ender.complemento);
                    strcpy(tmpChar, pessoa[id].ender.complemento);
                    getchar();
                    printf("Digite o novo Complemento do cadastro: ");
                    scanf("%[^\n]s", complemento);
                    strcpy(pessoa[id].ender.complemento, complemento);
                    printf("O Complemento foi alterado de '%s' para '%s'.\n", tmpChar, complemento);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
                case 12:
                    printf("O Número desse cadastro é '%d'.\n", pessoa[id].ender.numero);
                    tmpInt = pessoa[id].ender.numero;
                    getchar();
                    printf("Digite o novo Número do cadastro: ");
                    scanf("%d", &numero);
                    pessoa[id].ender.numero = numero;
                    printf("O Número foi alterado de '%d' para '%d'.\n", tmpInt, numero);
                    printf("\nCadastro de ID '%d' foi alterado com sucesso.\n", id+1);
                    break;
            }
        }else{
            printf("Não há cadastro com este ID.");
        }
        printf("\nDeseja alterar alguma outra coisa?\n");
        printf("1 - Sim.\n");
        printf("2 - Não.\n");
        scanf("%d", &opcao);
    }while(opcao != 2);
}
//=============================================================================
// FUNÇÃO PARA EXCLUIR CADASTROS
//=============================================================================
void excluir(){
    setlocale(LC_ALL, "Portuguese");    // PARA RESOLVER ERROS NOS ACENTOS
    int id, opcao;
    do{
        LIMPAR_TELA
        printf("#################################################\n");
        printf("\t # Excluir Cadastros #\n");
        printf("#################################################\n");
        printf("Digite o ID de Cadastro a ser removido: ");
        scanf("%d", &id);
        id = id - 1;
        pessoa[id].cadastrado = 0;
        printf("\nCadastro de ID '%d' foi removido com sucesso.\n", id+1);
        printf("\nDeseja excluir mais algum cadastro?\n");
        printf("1 - Sim.\n");
        printf("2 - Não.\n");
        scanf("%d", &opcao);
    }while(opcao != 2);
}
