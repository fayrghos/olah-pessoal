#include "spellbook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Spellbook *create_spellbook() {
    Spellbook *livro = malloc(sizeof(Spellbook));

    livro->inicio = NULL;
    return livro;
}

void add_spell(Spellbook *book, int id, const char *name, int mana_cost) {
    No *novo = malloc(sizeof(No));

    novo->proximo = NULL;
    novo->spell.id = id;
    novo->spell.mana_cost = mana_cost;
    strcpy(novo->spell.nome, name);

    No *atual = book->inicio;

    if (atual == NULL) {
        novo->proximo = book->inicio;
        book->inicio = novo;
        return;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    novo->proximo = NULL;
    atual->proximo = novo;
}

void display_spellbook(Spellbook *book) {
    No *atual = book->inicio;
    if (atual == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Spells:\n");
    while (atual != NULL) {
        printf("ID: %i, Feitiço: %s, Custo de Mana: %i\n", atual->spell.id,
               atual->spell.nome, atual->spell.mana_cost);
        atual = atual->proximo;
    }
}

void destroy_spellbook(Spellbook *book) {
    if (book->inicio == NULL) {
        printf("O grimório está vazio.\n");
        return;
    }

    No *atual = book->inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    book->inicio = NULL;
}