#include <stdio.h>

int main() {
    float nums[3];

    printf("Insira 3 números: ");
    scanf("%f %f %f", &nums[0], &nums[1], &nums[2]);

    printf("Soma: %.2f\n", nums[0] + nums[1] + nums[2]);
    return 0;
}