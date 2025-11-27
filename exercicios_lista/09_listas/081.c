#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Movimento;

typedef struct no {
    Movimento movimento;
    struct no *proximo;
} No;

typedef struct {
    struct no *inicio;
} Lista;

int main() {
    Lista lista = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir movimento no inicio\n");
        printf(" 2 - Sair\n");
        printf("----------\n");
        printf("\n");

        int opcao;
        printf("Escolha: ");
        scanf("%i", &opcao);

        if (opcao == 1) {
            No *novo = malloc(sizeof(No));

            printf("Insira o ID do movimento: ");
            scanf("%i", &novo->movimento.id);

            printf("Insira o nome do movimento: ");
            scanf(" %s", novo->movimento.nome);

            novo->proximo = lista.inicio;
            lista.inicio = novo;
        }

        else {
            return 0;
        }
    }
}