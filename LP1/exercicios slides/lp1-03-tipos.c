#include <stdio.h>

int main(void){
    char temps[5];
    int i, temperatura, media, somaTemp = 0, somaAcimaMedia = 0, qntValVet = 5;

    for(i = 0; i < 5; i++){
        printf("Digite a temperatura:");
        scanf("%d", &temperatura);
        temps[i] = temperatura;
        somaTemp += temps[i];
        printf("Valor da posi��o %i foi adicionado, valor: %d\n", i, temps[i]);
    }

    media = somaTemp/qntValVet;

    for(i = 0; i < 5; i++){
        if(temps[i] > media){
            printf("Valor acima da m�dia achado: %d\n", temps[i]);
            somaAcimaMedia += 1;
        }
    }

    printf("A soma dos valores dentro do vetor � %d\n", somaTemp);
    printf("A m�dia dos valores do vetor � %d\n", media);
    printf("A quantidade de leituras acima da m�dia � de: %d\n", somaAcimaMedia);

    return 0;
}
