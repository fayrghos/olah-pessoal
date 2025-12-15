#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} Ward;

typedef struct no {
    Ward ward;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void ler_ward(Ward *ward) {
    printf("Insira o ID da nova ward: ");
    scanf("%i", &ward->id);

    printf("Insira o nome da nova ward: ");
    scanf(" %s", ward->nome);
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
        printf("Lista vazia.\n");
        return;
    }

    printf("Wards:\n");
    while (atual != NULL) {
        printf("  %i - %s\n", atual->ward.id, atual->ward.nome);
        atual = atual->proximo;
    }
}

void deletar_apos(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Não há wards na lista.\n");
        return;
    }

    int id_desejado;
    printf("Insira o ID da ward para aplicar o shatter: ");
    scanf("%i", &id_desejado);

    No *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->ward.id == id_desejado) {
            break;
        }

        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("A ward não foi encontrada.\n");
        return;
    }

    else if (atual->proximo == NULL) {
        printf("Não foi possível aplicar o shatter, a ward encontrada é a "
               "última da lista.\n");
        return;
    }

    No *temp = atual->proximo;
    atual->proximo = atual->proximo->proximo;
    free(temp);
}

int main() {
    Lista lista = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir Ward\n");
        printf(" 2 - Aplicar Ward Shatter\n");
        printf(" 3 - Mostrar Wards Ativas\n");
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
            deletar_apos(&lista);
            break;

        case 3:
            mostrar_wards(&lista);
            break;

        default:
            return 0;
        }
    }
}