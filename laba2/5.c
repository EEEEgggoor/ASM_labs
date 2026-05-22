#include <stdio.h>
#include <limits.h>
#include <stdint.h>

void printf32(void *p){
    uint32_t *x = (uint32_t*)p;
    int32_t *x_s = (int32_t*)p;
    float *fx = (float*)p;


    uint32_t v = *x;
    int32_t v_s = *x_s;
    float fv = *fx;

    printf("%08X ", v);

    for (int i = 31; i>=0; i--){
        printf("%d", (v>>i)&1);
        if (i%8 == 0 & i > 0) printf(" ");
    }
    printf(" ");

    printf("u ", v);

    if(v_s>=0) printf("+%d", v_s);
    else printf("%d", v_s);


    printf("\n      %+A ", fv);
    
    printf("%+E ", fv);
    
    printf("%+f", fv);
    
    printf("\n");


}


int main(){

    uint32_t min_unsigned = 0;
    uint32_t max_unsigned = UINT_MAX;  
    
    printf("Минимальное беззнаковое (0):\n");
    printf32(&min_unsigned);
    
    printf("\n Максимальное беззнаковое (UINT_MAX = %u):\n", max_unsigned);
    printf32(&max_unsigned);
    
    int32_t min_signed = INT_MIN;
    int32_t max_signed = INT_MAX;
    
    printf("\n Минимальное знаковое (INT_MIN = %d):\n", min_signed);
    printf32(&min_signed);
    
    printf("\n Максимальное знаковое (INT_MAX = %d):\n", max_signed);
    printf32(&max_signed);
    
    
    int32_t x = 9;
    int32_t y = -9;
    int32_t a = 1;
    int32_t b = 2;
    int32_t c = 12345678;
    int32_t d = 123456789;
    
    printf("x = 9 (целое и float):\n");
    printf32(&x);
    
    printf("\ny = -9 (целое и float):\n");
    printf32(&y);
    
    printf("\na = 1 (целое и float):\n");
    printf32(&a);
    
    printf("\nb = 2 (целое и float):\n");
    printf32(&b);
    
    printf("\nc = 12345678 (целое и float):\n");
    printf32(&c);
    
    printf("\nd = 123456789 (целое и float):\n");
    printf32(&d);

    return 0;
}