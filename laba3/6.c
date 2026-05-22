#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#define N 5

int main(){
    uint16_t x = 10;
    uint16_t y = 1;
    uint16_t z = 0; 
    uint16_t w = 0;
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    printf("z = %d\n", z);
    printf("w = %d\n", w);
    __asm__ volatile(
         "addl %%ebx, %%eax;\n"
         "subl %%ebx, %%edx"  
        : "=a" (z), "=d" (w)
        : "a" (x), "b" (y), "d" (x)
        : "cc"
    );

    printf("z = x + y = %d\n", z);
    printf("w = x - y = %d\n", w);





    return 0;
}