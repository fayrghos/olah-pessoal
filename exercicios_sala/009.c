#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Insira o valor de N: ");
    scanf("%i", &n);

    int *linhas = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1) {
                *(linhas + (i * n) + j) = 2;
            }

            else if (i == j) {
                *(linhas + (i * n) + j) = 1;
            }

            else {
                *(linhas + (i * n) + j) = 3;
            }

            printf("%i ", *(linhas + (i * n) + j));
        }
        printf("\n");
    }

    return 0;
}