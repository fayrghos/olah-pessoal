#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Aventureiro;

typedef struct no {
    Aventureiro aventureiro;
    struct no *proximo;
} No;

typedef struct {
    struct no *inicio;
} Lista;

int main() {
    Lista lista = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir Aventureiro\n");
        printf(" 2 - Mostrar Grupo\n");
        printf(" 3 - Sair\n");
        printf("----------\n");
        printf("\n");

        int opcao;
        printf("Escolha: ");
        scanf("%i", &opcao);

        if (opcao == 1) {
            No *novo = malloc(sizeof(No));

            printf("Insira o ID do aventureiro: ");
            scanf("%i", &novo->aventureiro.id);

            printf("Insira o nome do aventureiro: ");
            scanf(" %s", novo->aventureiro.nome);

            novo->proximo = lista.inicio;
            lista.inicio = novo;
        }

        else if (opcao == 2) {
            No *atual = lista.inicio;

            while (atual != NULL) {
                printf("[Membro %i] Nome: %s\n", atual->aventureiro.id,
                       atual->aventureiro.nome);

                atual = atual->proximo;
            }
        }

        else {
            return 0;
        }
    }
}