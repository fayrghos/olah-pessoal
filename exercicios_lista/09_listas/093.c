#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("Insira o ID do novo membro: ");
    scanf("%i", &membro->id);

    printf("Insira o nome do novo membro: ");
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

No *pesquisar(Lista *lista, int id_desejado) {
    if (lista->inicio == NULL) {
        return NULL;
    }

    No *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->membro.id == id_desejado) {
            break;
        }

        atual = atual->proximo;
    }

    return atual;
}

void alterar_nome(Lista *lista, int id, char novo_nome[]) {
    No *encontrado = pesquisar(lista, id);

    if (encontrado == NULL) {
        printf("Membro não encontrado.\n");
        return;
    }

    strcpy(encontrado->membro.nome, novo_nome);
}

int main() {
    Lista lista = {};

    char novo_nome_temp[100];
    int id_desejado;

    for (;;) {
        printf("----------\n");
        printf(" 1 - Adicionar membro\n");
        printf(" 2 - Exibir lista\n");
        printf(" 3 - Alterar membro\n");
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
            printf("Insira o novo nome: ");
            scanf(" %s", novo_nome_temp);

            printf("Insira o ID que vai ter o nome alterado: ");
            scanf("%i", &id_desejado);

            alterar_nome(&lista, id_desejado, novo_nome_temp);
            break;

        default:
            return 0;
        }
    }
}