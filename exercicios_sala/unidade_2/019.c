#include <stdio.h>

int contar_pares(int n, int vetor[]) {
    if (n == 0) {
        return 0;
    }

    if (vetor[n - 1] % 2 == 0) {
        return 1 + contar_pares(n - 1, vetor);
    }

    return contar_pares(n - 1, vetor);
}

int verificar_livro(int n, int vetor[], int desejado) {
    if (n == 0) {
        return -1;
    }

    if (vetor[n - 1] == desejado) {
        return n - 1;
    }

    return verificar_livro(n - 1, vetor, desejado);
}

int main() {
    int n;

    printf("Insira a quantidade de livros: ");
    scanf("%i", &n);

    int id_livros[n];
    for (int i = 0; i < n; i++) {
        printf("Insira o ID %i: ", i + 1);
        scanf("%i", &id_livros[i]);
    }

    int id_desejado;
    printf("Insira o ID desejado: ");
    scanf("%i", &id_desejado);

    int pos_encontrado = verificar_livro(n, id_livros, id_desejado);
    printf("\n");

    if (pos_encontrado > 0) {
        printf("Posição do livro: Índice %i.\n", pos_encontrado);
    } else {
        printf("Livro não encontrado.\n");
    }

    printf("Quantidade de pares: %i\n", contar_pares(n, id_livros));
    return 0;
}