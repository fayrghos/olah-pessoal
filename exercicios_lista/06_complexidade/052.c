#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Unidade;

int main() {
    int n;
    printf("Insira a quantidade de unidades: ");
    scanf("%i", &n);

    float raio;
    printf("Insira o raio: ");
    scanf("%f", &raio);

    Unidade *inimigos = malloc(sizeof(Unidade) * n);
    for (int i = 0; i < n; i++) {
        printf("[Unidade %i] Insira o X e Y: ", i + 1);
        scanf("%i %i", &inimigos[i].x, &inimigos[i].y);
    }

    int duplas_proximas = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Vendo se são o mesmo inimigo
            if (&inimigos[i] == &inimigos[j]) {
                continue;
            }

            float distancia = sqrt(pow(inimigos[i].x - inimigos[j].x, 2) +
                                   pow(inimigos[i].y - inimigos[j].y, 2));

            if (distancia <= raio) {
                duplas_proximas++;
            }
        }
    }

    printf("Duplas próximas: %i\n", duplas_proximas);

    free(inimigos);
    return 0;
}