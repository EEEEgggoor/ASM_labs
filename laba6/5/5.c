#include <stdio.h>
#include <stdint.h>

extern void calc_lea_asm(int64_t x, int64_t *z);

int main() {
    int64_t x = 10;
    int64_t z = 0;

    calc_lea_asm(x, &z);

    printf("x=%lld -> z=%lld\n", x, z);

    getchar();
    return 0;
}