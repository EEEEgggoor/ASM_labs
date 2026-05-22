#include <stdio.h>
#include <limits.h>

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


int main(){

    unsigned short min_unsigned = 0;
    unsigned short max_unsigned = USHRT_MAX;
    short min_signed = SHRT_MIN;
    short max_signed = SHRT_MAX; 
    short x = 9;
    short y = -9;
    short a = 1;
    short b = 2;


    printf("Минимальное беззнаковое (0):\n");
    printf16(&min_unsigned);
    
    printf("\nМаксимальное беззнаковое (USHRT_MAX = %u):\n", max_unsigned);
    printf16(&max_unsigned);


    printf("\nМинимальное знаковое (SHRT_MIN = %d):\n", min_signed);
    printf16(&min_signed);
    
    printf("\nМаксимальное знаковое (SHRT_MAX = %d):\n", max_signed);
    printf16(&max_signed);


    printf("x = 9:\n");
    printf16(&x);
    
    printf("\ny = -9:\n");
    printf16(&y);
    
    printf("\na = 1:\n");
    printf16(&a);
    
    printf("\nb = 2:\n");
    printf16(&b);

    return 0;
}