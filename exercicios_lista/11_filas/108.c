#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nickname[50];
} Jogador;

typedef struct no {
    Jogador jogador;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inserir(Fila *fila, Jogador jogador) {
    No *novo = malloc(sizeof(No));
    novo->jogador = jogador;
    novo->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
        return;
    }

    fila->fim->proximo = novo;
    fila->fim = novo;
}

int main() {
    Fila fila = {};
    Jogador jog_temp = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir jogador\n");
        printf(" 2 - Sair\n");
        printf("----------\n");

        int escolha;
        printf("Escolha: ");
        scanf("%i", &escolha);
        printf("----------\n");
        printf("\n");

        switch (escolha) {
        case 1:
            printf("Insira o ID do novo jogador: ");
            scanf("%i", &jog_temp.id);

            printf("Insira o nome do novo jogador: ");
            scanf(" %s", jog_temp.nickname);

            inserir(&fila, jog_temp);
            break;

        default:
            return 0;
        }
    }
}