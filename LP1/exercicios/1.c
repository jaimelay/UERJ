//
// Achar quantidade de palavras iguais numa frase.
//
#include <stdio.h>
#include <string.h>

int main(void){
    int i, c, qtdPalavras = 0, cont = 0, aux;
    char frase[80];
    char palavras[20][80];
    int tamPalavra[20];

    fgets(frase, 80, stdin);
    for(i = 0; frase[i] != '\0'; i++){
        if(frase[i] == ' '){
            palavras[qtdPalavras][cont] = '\0';
            qtdPalavras++;
            cont = 0;
        }else if(frase[i] != '\n'){
            palavras[qtdPalavras][cont] = frase[i];
            cont++;
            tamPalavra[qtdPalavras] = cont;
        }
    }
    palavras[qtdPalavras][cont] = '\0';
    qtdPalavras++;

    printf("%d Palavras.\n", qtdPalavras);

    for(i = 0; i < qtdPalavras; i++){
        printf("Palavra %d: ", i);
        for(c = 0; c < tamPalavra[i]; c++){
            printf("%c", palavras[i][c]);
        }
        printf(" Tamanho da Palavra: %d", tamPalavra[i]);
        printf("\n");
    }

    int k;
    int contadorIgual = 0;
    int chave = 0;
    for(i = 0; i < qtdPalavras; i++){
        for(k = i + 1; k < qtdPalavras; k++){
            if(strcmp(palavras[k], "X") == 0) continue;
            else if(strcmp(palavras[i], palavras[k]) == 0){
                strcpy(palavras[k], "X");
                contadorIgual++;
                chave = 1;
            }
        }
        if(chave){
            printf("A palavra %s foi achada %d vezes.\n", palavras[i], contadorIgual + 1);
        }
        chave = 0;
        contadorIgual = 0;
    }
    
    return 0;
}