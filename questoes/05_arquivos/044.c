#include <stdio.h>

typedef struct {
    int id;
    int pontos;
} Conquista;

int main() {
    FILE *txt = fopen("./player_log.txt", "r+");

    int conquista_atual;
    int experiencia_atual;
    int experiencia_total = 0;

    int n;
    fscanf(txt, "%i", &n);

    for (int i = 0; i < n; i++) {
        fscanf(txt, "%i %i", &conquista_atual, &experiencia_atual);
        experiencia_total += experiencia_atual;
    }

    fprintf(txt, "\n--- SESSION CONCLUDED ---");

    printf("Ganhos na sessão: %i\n", experiencia_total);
    return 0;
}