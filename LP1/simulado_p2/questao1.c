/*
Considere a struct a seguir:

    struct Cadastro {
        char nome[255];
        int idade;
    };

Crie um programa que leia novos cadastros para um vetor até que seja digitado um nome vazio.
Considere que serão digitados, no máximo, 50 cadastros.

Em seguida, grave todos os cadastros digitados em um arquivo binário.
    - O início do arquivo deve conter um inteiro com a quantidade de cadastros existentes no arquivo.
    - O arquivo deve guardar a quantidade exata de caracteres dos nomes(e não o máximo de 255 caracteres).
*/

#include <stdio.h>
#include <string.h>

#define MAX_CADASTRO 50

struct Cadastro {
    char nome[255];
    int idade;
};

int main(void){
    char nome[255];
    char string[] = "vazio";
    int idade, count = 0;

    struct Cadastro c[MAX_CADASTRO];
    for(int i = 0; i < MAX_CADASTRO; i++){
        printf("Digite o nome do cadastro: ");
        scanf("%s", nome);
        if(strcmp(string, nome) == 0){
            break;
        }
        strcpy(c[i].nome, nome);
        printf("Digite a idade do cadastro: ");
        scanf("%d", &c[i].idade);
        count++;
    }

    FILE* f = fopen("cadastros.bin", "wb");
    fwrite(&count, sizeof(int), 1, f);
    for(int i = 0; i < count; i++){
        fwrite(&c[i].nome, strlen(c[i].nome), 1, f);
        fwrite(&c[i].idade, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;
}
