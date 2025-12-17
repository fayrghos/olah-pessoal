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

void adicionar_inicio(Lista *lista, No *novo) {
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void adicionar_final(Lista *lista, No *novo) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        adicionar_inicio(lista, novo);
        return;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

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

Lista carregar_guilda() {
    Lista lista_saida = {};

    FILE *bin = fopen("./guild_roster.b", "rb");
    Membro membro;

    while (fread(&membro, sizeof(Membro), 1, bin)) {
        No *novo = malloc(sizeof(No));
        novo->membro = membro;

        adicionar_final(&lista_saida, novo);
    }

    fclose(bin);
    return lista_saida;
}

void salvar_guilda_test() {
    No no3 = {
        .membro = {.id = 3, .nome = "Ccc"},
        .proximo = NULL,
    };

    No no2 = {
        .membro = {.id = 2, .nome = "Bbb"},
        .proximo = &no3,
    };

    No no1 = {
        .membro = {.id = 1, .nome = "Aaa"},
        .proximo = &no2,
    };

    Lista lista = {.inicio = &no1};

    FILE *bin = fopen("./guild_roster.b", "wb");
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
        printf(" 1 - Criar roster\n");
        printf(" 2 - Carregar membros\n");
        printf(" 3 - Mostrar membros\n");
        printf(" 4 - Sair\n");
        printf("----------\n");

        int escolha;
        printf("Escolha: ");
        scanf("%i", &escolha);
        printf("----------\n\n");

        switch (escolha) {
        case 1:
            salvar_guilda_test();
            break;

        case 2:
            lista = carregar_guilda();
            break;

        case 3:
            mostrar_itens(&lista);
            break;

        default:
            return 0;
        }
    }
}