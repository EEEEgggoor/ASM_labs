#include <stdint.h>
#include <stdio.h>


extern void fc16_asm(void * p);

#define D 64

void printf16(void *p){
    unsigned short *x = (unsigned short*)p;
    short *x_s = ( short*)p;
    
    unsigned short v = *x;
    short v_s = *x_s;

    printf("%04X ", v);
    printf(" ");
    for (int i = 15; i>=0; i--){ printf("%d", (1&(v>>i))); }
    printf(" ");
    printf("%5u ", v);
    if (v_s >= 0) printf("%+d ", v_s);
    else printf("%d ", v_s);
    printf("\n");
}

void fc16_c(void * p) {
    uint16_t x = *(uint16_t *)p;

    uint16_t mask = ~(D - 1);

    // а) Округление вниз
    uint16_t x1 = x & mask;

    // б) Округление вверх
    uint16_t x2 = (x + D - 1) & mask;

    printf(" Num - ");
    printf16(&x);
    printf(" Down -");
    printf16(&x1);
    printf(" Up - ");
    printf16(&x2);
}

int main()
{   
    printf("D = %d\n", D);
    int x = -8;
    printf("fc16_c \n");
    fc16_c(&x);
    printf("fc16_asm \n");
    fc16_asm(&x);
    getchar();
    return 0;
}