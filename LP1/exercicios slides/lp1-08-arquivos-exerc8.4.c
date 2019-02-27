#include <stdio.h>
#include <string.h>

void escreva_string(FILE* f, char* str){
    for(int i = 0; i < strlen(str); i++){
        fputc(str[i], f);
    }
}

int main(void){
    FILE* f;
    char p[25];
    printf("Digite a palavra que você deseja inserir no arquivo: ");
    scanf("%[^\n]s", p);
    f = fopen("lp1-08-arquivos-exerc8.4.txt", "w");
    escreva_string(f, p);
    fclose(f);
    return 0;
}
