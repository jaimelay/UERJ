#include <stdio.h>

void preenche(int* v, int n){
    int i, x;
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        *(v + i) = x;
    }
}

int media(int* v, int n){
    int i, soma = 0, media = 0;
    for(i = 0; i < n; i++){
        soma += *(v + i);
    }
    media = soma / n;
    return media;
}
int main(void){
    int i, n, media_notas = 0;
    printf("Tamanho do Vetor: ");
    scanf("%d", &n);
    int v[n];
    preenche(v, n);
    for(i = 0; i < n; i++){
        printf("%d ", *(v + i));
    }
    media_notas = media(v, n);
    printf("\nMédia: %d\n", media_notas);
	return 0;
}
