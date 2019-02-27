#include <stdio.h>

int strlen2(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void strjoin(char destino[], char str1[], char str2[]){
    int i = 0;
    while(i < strlen2(str1)){
        destino[i] = str1[i];
        i++;
    }

    int j = 0;
    while(j < strlen2(str2)){
        destino[strlen2(str1) + j] = str2[j];
        j++;
    }

    destino[strlen2(str1) + strlen2(str2)] = '\0';
}

int main(void){
    char str1[50], str2[50];

    printf("Digite uma palavra: ");
    scanf("%s", str1);
    printf("Tamanho de %s é %d: \n", str1, strlen2(str1));

    printf("Digite uma segunda palavra: ");
    scanf("%s", str2);
    printf("Tamanho de %s é %d: \n", str2, strlen2(str2));

    char destino[256];
    strjoin(destino, str1, str2);
    printf("As duas palavras juntas: %s\n", destino);
    printf("A junção das duas palavras possuem %d letras.", strlen2(destino));

	return 0;
}
