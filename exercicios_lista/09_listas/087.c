#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Ward;

typedef struct no {
    Ward ward;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void ler_ward(Ward *jogador) {
    printf("Insira o ID do novo jogador: ");
    scanf("%i", &jogador->id);

    printf("Insira o nome do novo jogador: ");
    scanf(" %s", jogador->nome);
}

void adicionar_inicio(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_ward(&novo->ward);

    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void adicionar_final(Lista *lista) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        adicionar_inicio(lista);
        return;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    No *novo = malloc(sizeof(No));
    ler_ward(&novo->ward);

    novo->proximo = NULL;
    atual->proximo = novo;
}

void mostrar_wards(Lista *lista) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila:\n");
    while (atual != NULL) {
        printf("  %i - %s\n", atual->ward.id, atual->ward.nome);
        atual = atual->proximo;
    }
}

void remover_inicio(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Não há jogadores na fila.\n");
        return;
    }

    No *primeiro = lista->inicio;
    lista->inicio = primeiro->proximo;
    free(primeiro);
}

int main() {
    Lista lista = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir jogador no final\n");
        printf(" 2 - Iniciar partida\n");
        printf(" 3 - Mostrar fila\n");
        printf(" 4 - Sair\n");
        printf("----------\n");

        int escolha;
        printf("Escolha: ");
        scanf("%i", &escolha);
        printf("----------\n\n");

        switch (escolha) {
        case 1:
            adicionar_final(&lista);
            break;

        case 2:
            remover_inicio(&lista);
            break;

        case 3:
            mostrar_wards(&lista);
            break;

        default:
            return 0;
        }
    }
}