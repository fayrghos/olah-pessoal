#include <stdio.h>

typedef struct {
    int id;
    int pontos;
} Conquista;

int main() {
    FILE *txt = fopen("./player_log.txt", "r+");

    int experiencia_total = 0;
    Conquista conquista_temp;

    int n;
    fscanf(txt, "%i", &n);

    for (int i = 0; i < n; i++) {
        fscanf(txt, "%i %i", &conquista_temp.id, &conquista_temp.pontos);
        experiencia_total += conquista_temp.pontos;
    }

    fprintf(txt, "\n--- SESSION CONCLUDED ---");

    printf("Ganhos na sessão: %i\n", experiencia_total);
    return 0;
}