#include <stdio.h>
#include <string.h>

int main(void){
	char v[10][25];

	for(int i = 0; i < 10; i++){
		printf("Digite a palavra %d: ", i);
		scanf("%s", v[i]);
	}

	FILE* f = fopen("lp1-08-arquivos-exerc8.3.txt", "w");
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < strlen(v[i]); j++){
			fputc(v[i][j], f);
		}
	}
	fclose(f);

	return 0;
}
