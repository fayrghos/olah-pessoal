#include <stdio.h>
#include <stdlib.h>

int *pedir_antigos(int *dest_quant) {
    int n;
    printf("Insira a quantidade no SISTEMA ANTIGO: ");
    scanf("%i", &n);

    int *cod_antigos = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("  Insira o código do Livro %i: ", i + 1);
        scanf("%i", &cod_antigos[i]);
    }

    *dest_quant = n;
    return cod_antigos;
}

int *pedir_recentes(int *dest_quant) {
    int n;
    printf("Insira a quantidade de RECENTEMENTE IMPORTADOS: ");
    scanf("%i", &n);

    int *cod_antigos = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("  Insira o código do Livro %i: ", i + 1);
        scanf("%i", &cod_antigos[i]);
    }

    *dest_quant = n;
    return cod_antigos;
}

int *pedir_fisicos(int *dest_quant) {
    int n;
    printf("Insira a quantidade de ESTOQUE FÍSICO: ");
    scanf("%i", &n);

    int *cod_antigos = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("  Insira o código do Livro %i: ", i + 1);
        scanf("%i", &cod_antigos[i]);
    }

    *dest_quant = n;
    return cod_antigos;
}

int main() {
    int q_antigos;
    int *antigos = pedir_antigos(&q_antigos);

    int q_recentes;
    int *recentes = pedir_recentes(&q_recentes);

    int q_fisicos;
    int *fisicos = pedir_fisicos(&q_fisicos);

    // Hadouken!
    printf("Em comum: ");
    for (int i = 0; i < q_antigos; i++) {
        for (int j = 0; j < q_recentes; j++) {
            if (antigos[i] == recentes[j]) {
                for (int k = 0; k < q_fisicos; k++) {
                    if (antigos[i] == fisicos[k]) {
                        printf("%i ", antigos[i]);
                        break;
                    }
                }
                break;
            }
        }
    }
    printf("\n");

    free(antigos);
    free(recentes);
    free(fisicos);
    return 0;
}