/*
a. Crie uma struct para representar uma lista encadeada de alunos com nome, P1 e P2:
    - nome é uma string de até 25 caracteres.
    - P1 é um inteiro.
    - P2 é um inteiro.
b. Crie um loop para ler e criar 5 alunos usando malloc.
c. Crie um loop para calcular a média dos alunos considerando as duas provas.
d. Crie um loop para remover todos os alunos usando free.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nome[26];
    int P1;
    int P2;
    struct Node *next;
};

void exibe(struct Node *no){
    if(!no) printf("LISTA VAZIA!\n");
    while(no != NULL){
        printf("Nome: %s\n", no->nome);
        printf("P1: %d\n", no->P1);
        printf("P2: %d\n", no->P2);
        no = no->next;
    }
}

void removeLista(struct Node **head){ // RECEBE O ENDEREÇO DA CABEÇA
   struct Node *current = *head;
   struct Node *next;

   while (current != NULL){
       next = current->next;
       free(current);
       current = next;
   }
   *head = NULL;
}

int media(struct Node *no){
    int media = 0;
    while(no != NULL){
        media += (no->P1 + no->P2)/2;
        no = no->next;
    }
    return media;
}

int main(void){
    char nome[26];
    int P1, P2;

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for(int i = 0; i < 5; i++){
        struct Node *tmp = malloc(sizeof(struct Node));
        printf("Digite o nome: ");
        scanf("%s", nome);
        strcpy(tmp->nome, nome);
        printf("Digite a nota P1: ");
        scanf("%d", &P1);
        tmp->P1 = P1;
        printf("Digite a nota P2: ");
        scanf("%d", &P2);
        tmp->P2 = P2;

        if(head == NULL){
            head = tmp;
            tail = tmp;
        }else{
            tail->next = tmp;
            tail = tmp;
        }

        tmp->next = NULL;
    }
    exibe(head);

    printf("A média é: %d\n", media(head));

    removeLista(&head);

    exibe(head);

    return 0;
}
