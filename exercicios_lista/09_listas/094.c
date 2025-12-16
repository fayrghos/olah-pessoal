#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Mercenario;

typedef struct no {
    Mercenario merc;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void ler_item(Mercenario *merc) {
    printf("Insira o ID do novo item: ");
    scanf("%i", &merc->id);

    printf("Insira o nome do novo item: ");
    scanf(" %s", merc->nome);
}

void adicionar_inicio(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_item(&novo->merc);

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
    ler_item(&novo->merc);

    novo->proximo = NULL;
    atual->proximo = novo;
}

void mostrar_itens(Lista *lista) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Itens:\n");
    while (atual != NULL) {
        printf("  %i - %s\n", atual->merc.id, atual->merc.nome);
        atual = atual->proximo;
    }
}

int tamanho(Lista *lista) {
    if (lista->inicio == NULL) {
        return 0;
    }

    int quant_itens = 0;
    No *atual = lista->inicio;

    while (atual != NULL) {
        quant_itens++;
        atual = atual->proximo;
    }

    return quant_itens;
}

int main() {
    Lista lista = {};

    char novo_nome_temp[100];
    int id_desejado;

    for (;;) {
        printf("----------\n");
        printf(" 1 - Adicionar mercenário\n");
        printf(" 2 - Exibir lista\n");
        printf(" 3 - Contar membros\n");
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
            printf("Quantidade de mercenários: %i\n", tamanho(&lista));
            break;

        default:
            return 0;
        }
    }
}