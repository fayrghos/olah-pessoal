#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Mercenario;

typedef struct no {
    Mercenario merc;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void ler_merc(Mercenario *merc) {
    printf("Insira o ID do novo mercenário: ");
    scanf("%i", &merc->id);

    printf("Insira o nome do novo mercenário: ");
    scanf(" %s", merc->nome);
}

void adicionar_inicio(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_merc(&novo->merc);

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
    ler_merc(&novo->merc);

    novo->proximo = NULL;
    atual->proximo = novo;
}

void mostrar_itens(Lista *lista) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Mercenários:\n");
    while (atual != NULL) {
        printf("  %i - %s\n", atual->merc.id, atual->merc.nome);
        atual = atual->proximo;
    }
}

void demitir_todos_mercenarios(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("A companhia está vazia.\n");
        return;
    }

    No *atual = lista->inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    lista->inicio = NULL;
}

int main() {
    Lista lista = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Contratar mercenário\n");
        printf(" 2 - Exibir companhia\n");
        printf(" 3 - Declarar falência\n");
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
            mostrar_itens(&lista);
            break;

        case 3:
            demitir_todos_mercenarios(&lista);
            break;

        default:
            return 0;
        }
    }
}