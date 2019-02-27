#include <stdio.h>

int main(void){
    int i;
    FILE* f = fopen("lp1-08-arquivos-exerc8.1.txt", "r");
    while(!feof(f)){
        int l = fgetc(f);
        printf("%c", l);
    }
    printf("\n");
    fclose(f);
    return 0;
}
