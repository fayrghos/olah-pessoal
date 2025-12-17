#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} Monstro;

typedef struct no {
    Monstro monstro;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void ler_item(Monstro *monstro) {
    printf("Insira o ID do novo item: ");
    scanf("%i", &monstro->id);

    printf("Insira o nome do novo item: ");
    scanf(" %s", monstro->nome);
}

void adicionar_inicio(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_item(&novo->monstro);

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
    ler_item(&novo->monstro);

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
        printf("  %i - %s\n", atual->monstro.id, atual->monstro.nome);
        atual = atual->proximo;
    }
}

void ordenar_bestiario(Lista *lista) {
    No *pi;
    No *pj;
    No *pfim = NULL;

    if (lista->inicio == NULL) {
        return;
    }

    for (pi = lista->inicio; pi->proximo != NULL; pi = pi->proximo) {
        for (pj = lista->inicio; pj->proximo != pfim; pj = pj->proximo) {
            if (pj->monstro.id > pj->proximo->monstro.id) {
                Monstro temp = pj->monstro;
                pj->monstro = pj->proximo->monstro;
                pj->proximo->monstro = temp;
            }
        }

        pfim = pj;
    }
}

int main() {
    Lista lista = {};

    char novo_nome_temp[100];
    int id_desejado;

    for (;;) {
        printf("----------\n");
        printf(" 1 - Adicionar monstro\n");
        printf(" 2 - Ordenar bestiário\n");
        printf(" 3 - Mostrar bestiário\n");
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
            ordenar_bestiario(&lista);
            break;

        case 3:
            mostrar_itens(&lista);
            break;

        default:
            return 0;
        }
    }
}