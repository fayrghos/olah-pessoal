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

void ler_ward(Ward *heroi) {
    printf("Insira o ID do novo herói: ");
    scanf("%i", &heroi->id);

    printf("Insira o nome do novo herói: ");
    scanf(" %s", heroi->nome);
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

void adicionar_antes(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_ward(&novo->ward);

    int id_desejado;
    printf("Insira o ID do herói a ser protegido: ");
    scanf("%i", &id_desejado);

    if (lista->inicio == NULL) {
        printf("A inserção falhou. Formação vazia.\n");
        free(novo);
        return;
    }

    else if (lista->inicio->ward.id == id_desejado) {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        return;
    }

    No *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->proximo != NULL) {
            if (atual->proximo->ward.id == id_desejado) {
                break;
            }
        }

        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("A inserção falhou. O herói não foi encontrado.\n");
        free(novo);
        return;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

void mostrar_wards(Lista *lista) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        printf("Formação vazia.\n");
        return;
    }

    printf("Formação:\n");
    while (atual != NULL) {
        printf("  %i - %s\n", atual->ward.id, atual->ward.nome);
        atual = atual->proximo;
    }
}

int main() {
    Lista lista = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir herói no final\n");
        printf(" 2 - Inserir guarda-costas\n");
        printf(" 3 - Mostrar formação\n");
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
            adicionar_antes(&lista);
            break;

        case 3:
            mostrar_wards(&lista);
            break;

        default:
            return 0;
        }
    }
}