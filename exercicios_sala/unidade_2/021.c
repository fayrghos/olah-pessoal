#include <stdio.h>

typedef struct {
    int codigo;
    int ano_publi;
} Livro;

int main() {
    int n;

    printf("Insira a quantidade de livros: ");
    scanf("%i", &n);

    Livro livros[n];

    for (int i = 0; i < n; i++) {
        printf("  Insira o código %i: ", i + 1);
        scanf("%i", &livros[i].codigo);

        printf("  Insira seu ano de publicação: ");
        scanf("%i", &livros[i].ano_publi);
    }

    // Por código
    for (int i = 0; i < n; i++) {
        Livro temp_menor = livros[i];
        int pos_menor = i;

        for (int j = i + 1; j < n; j++) {
            if (livros[j].codigo < temp_menor.codigo) {
                temp_menor = livros[j];
                pos_menor = j;
            }
        }

        livros[pos_menor] = livros[i];
        livros[i] = temp_menor;
    }

    printf("Ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", livros[i].codigo);
    }
    printf("\n");

    // Por ano
    for (int i = 0; i < n; i++) {
        Livro temp_mais_recente = livros[i];
        int pos_menor = i;

        for (int j = i + 1; j < n; j++) {
            if (livros[j].ano_publi > temp_mais_recente.ano_publi) {
                temp_mais_recente = livros[j];
                pos_menor = j;
            }
        }

        livros[pos_menor] = livros[i];
        livros[i] = temp_mais_recente;
    }

    printf("Quinto mais recente: ");
    if (n >= 5) {
        printf("Livro cód %i (%i)\n", livros[4].codigo, livros[4].ano_publi);
    } else {
        printf("[Quantidade menor que 5!]");
    }

    return 0;
}