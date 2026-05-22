#include <stdio.h>

extern void ab16_asm(void * p);

extern void printf16(void *p){
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

int main() {
    short x = 8;
    
    printf("ab16_asm\n");
    ab16_asm(&x);

    getchar();
    
    return 0;
}