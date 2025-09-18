#include <stdio.h>

typedef struct {
    char nome[20];
    float hp;
    float atk;
} Inimigo;

int main() {
    Inimigo inimigos[3];
    FILE *txt = fopen("./inimigos.txt", "r");

    for (int i = 0; i < 3; i++) {
        fscanf(txt, "%s", inimigos[i].nome);
        fscanf(txt, "%f", &inimigos[i].hp);
        fscanf(txt, "%f", &inimigos[i].atk);

        if (inimigos[i].hp + inimigos[i].atk >= 200) {
            printf("%s é um inimigo de elite.\n", inimigos[i].nome);
        }
    }

    fclose(txt);
    return 0;
}