#include <stdio.h>
#include <stdint.h>


extern void asm_syst(int16_t *px, int16_t *py, int16_t *pz, int16_t *pw);

int main() {
    int16_t x = 20;
    int16_t y = 6;

    int16_t z = 0;
    int16_t w = 0;

    asm_syst(&x, &y, &z, &w);

    // Вывод результата
    printf("Input: x=%d, y=%d\n", x, y);
    printf("Result: z = %d, w = %d\n", z, w);

    getchar();

    return 0;
}