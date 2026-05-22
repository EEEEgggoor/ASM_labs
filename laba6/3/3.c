#include <stdint.h>
#include <stdio.h>

extern void calc_asm(void *px, void *py, void *pz);

int main() {
    short x = 5;
    short y = 4;
    short z = 0;

    calc_asm(&x, &y, &z);

    // Математика: 5 + (5 * 4) - 7 = 5 + 20 - 7 = 18
    printf("Result Z: %d\n", z); 

    getchar();
    return 0;
}