#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Item;

typedef struct no {
    Item ward;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void ler_ward(Item *item) {
    printf("Insira o ID do item: ");
    scanf("%i", &item->id);

    printf("Insira o nome do item: ");
    scanf(" %s", item->nome);
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

void adicionar_apos(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_ward(&novo->ward);

    int id_desejado;
    printf("Insira o ID do item antes do catalisador: ");
    scanf("%i", &id_desejado);

    No *atual = lista->inicio;
    if (atual == NULL) {
        printf("A inserção falhou. O inventário está vazio.\n");
        free(novo);
        return;
    }

    while (atual != NULL) {
        if (atual->ward.id == id_desejado) {
            break;
        }

        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf(
            "A inserção falhou. O item pesquisado não está no inventário.\n");
        free(novo);
        return;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
    printf("O item pesquisado foi encontrado! Catalisador adicionado.\n");
}

void mostrar_wards(Lista *lista) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        printf("Inventário vazio.\n");
        return;
    }

    printf("Inventário:\n");
    while (atual != NULL) {
        printf("  %i - %s\n", atual->ward.id, atual->ward.nome);
        atual = atual->proximo;
    }
}

int main() {
    Lista lista = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir item no início\n");
        printf(" 2 - Inserir item no final\n");
        printf(" 3 - Inserir catalisador após item\n");
        printf(" 4 - Mostrar inventário\n");
        printf(" 5 - Sair\n");
        printf("----------\n");

        int escolha;
        printf("Escolha: ");
        scanf("%i", &escolha);
        printf("----------\n\n");

        switch (escolha) {
        case 1:
            adicionar_inicio(&lista);
            break;

        case 2:
            adicionar_final(&lista);
            break;

        case 3:
            adicionar_apos(&lista);
            break;

        case 4:
            mostrar_wards(&lista);
            break;

        default:
            return 0;
        }
    }
}