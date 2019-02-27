#include <stdio.h>
#include <string.h>

int main(void){
    char palavra[25];
    int i;
    printf("Digite uma palavra: ");
    scanf("%[^\n]s", palavra);
    FILE* f = fopen("lp1-08-arquivos-exerc8.1.txt", "w");
    for(i = 0; i < strlen(palavra); i++){
        fputc(palavra[i], f);
    }
    fclose(f);
    return 0;
}
