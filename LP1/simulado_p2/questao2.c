/*
Considere um arquivo texto com o formato a seguir:

    Ana Almeida, 05/06/1990, Jacarepagua
    Joao Silva, 12/10/1960, Flamengo
    Maria Amelia, 01/09/1970, Santa Teresa
    ...

Cada linha possui um nome, uma data e um bairro, separados por vírgulas.

    - Todos os campos são textuais.
    - Os nomes e bairros possuem, no máximo, 25 caracteres.
    - O arquivo contém, no máximo, 100 linhas.

    a. Crie uma struct para representar uma linha.
    b. Crie um vetor para guardar as linhas já no formato de struct.
    c. Leia o arquivo inteiro para o vetor.

*/

#include <stdio.h>
#include <string.h>

#define MAX_CADASTRO 50

struct Cadastro {
    char nome[26];
    char data[12];
    char bairro[26];
};

int main(void){
    struct Cadastro vet[MAX_CADASTRO];
    int i = 0, c, j;
    char nome[26];
    char data[11];
    char bairro[26];

    FILE* f = fopen("questao2.txt", "r");

    while(!feof(f)){
        for(j = 0; j < MAX_CADASTRO; j++){
            if(feof(f)) break;
            while(c != ','){
                nome[i] = c;
                c = getc(f);
                i++;
            }
            nome[i] = '\0';
            i = 0;
            strcpy(vet[j].nome, nome);

            c = getc(f);
            while(c != ','){
                data[i] = c;
                c = getc(f);
                i++;
            }
            data[i] = '\0';
            i = 0;
            strcpy(vet[j].data, data);

            c = getc(f);
            while(c != '\n' && c != EOF){
                bairro[i] = c;
                c = getc(f);
                i++;
            }
            bairro[i] = '\0';
            i = 0;
            strcpy(vet[j].bairro, bairro);

            c = getc(f);
        }
    }
    fclose(f);

    for(i = 0; i < MAX_CADASTRO; i++){
        if(strlen(vet[i].nome) == 0) break;
        printf("Nome: %s\n", vet[i].nome);
        printf("Data: %s\n", vet[i].data);
        printf("Bairro: %s\n", vet[i].bairro);
    }

    return 0;
}
