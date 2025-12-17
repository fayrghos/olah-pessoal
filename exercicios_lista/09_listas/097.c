#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} Membro;

typedef struct no {
    Membro membro;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void ler_item(Membro *membro) {
    printf("Insira o ID do novo item: ");
    scanf("%i", &membro->id);

    printf("Insira o nome do novo item: ");
    scanf(" %s", membro->nome);
}

void adicionar_inicio(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_item(&novo->membro);

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
    ler_item(&novo->membro);

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
        printf("  %i - %s\n", atual->membro.id, atual->membro.nome);
        atual = atual->proximo;
    }
}

void salvar_guild_arquivo(Lista lista) {
    FILE *bin = fopen("./guild_roster.bin", "wb");
    No *atual = lista.inicio;

    for (atual = lista.inicio; atual != NULL; atual = atual->proximo) {
        fwrite(&atual->membro, sizeof(Membro), 1, bin);
    }

    fclose(bin);
}

int main() {
    Lista lista = {};

    char novo_nome_temp[100];
    int id_desejado;

    for (;;) {
        printf("----------\n");
        printf(" 1 - Adicionar membro\n");
        printf(" 2 - Mostrar membros\n");
        printf(" 3 - Salvar membros\n");
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
            salvar_guild_arquivo(lista);
            break;

        default:
            return 0;
        }
    }
}