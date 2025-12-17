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

void mostrar(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }

    No *aux = fila->inicio;

    while (aux != NULL) {
        printf(" Jogador %i - %s\n", aux->jogador.id, aux->jogador.nickname);

        aux = aux->proximo;
    }
}

Jogador remover(Fila *fila) {
    Jogador saida = {.id = -1};

    if (fila->inicio == NULL) {
        printf("Fila vazia.\n");
        return saida;
    }

    if (fila->inicio->proximo == NULL) {
        saida = fila->inicio->jogador;

        free(fila->inicio);
        fila->inicio = NULL;
        fila->fim = NULL;

        return saida;
    }

    No *atual = fila->inicio;
    fila->inicio = atual->proximo;

    saida = atual->jogador;
    free(atual);
    return saida;
}

int main() {
    Fila fila = {};
    Jogador jog_temp = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir jogador\n");
        printf(" 2 - Mostrar jogadores\n");
        printf(" 3 - Remover jogador\n");
        printf(" 4 - Sair\n");
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

        case 2:
            mostrar(&fila);
            break;

        case 3:
            jog_temp = remover(&fila);

            if (jog_temp.id < 0) {
                continue;
            }

            printf("O jogador %s (ID: %i) foi removido da fila e entrou em uma "
                   "partida.\n",
                   jog_temp.nickname, jog_temp.id);
            break;

        default:
            return 0;
        }
    }
}