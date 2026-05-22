#include <stdint.h>
#include <stdio.h>

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

void c16to32(void *p){

    unsigned short *p16 = (unsigned short*)p;
    short *p16_s = (short*)p;
    
    unsigned short v16 = *p16;
    short v16_s = *p16_s;

    uint32_t v32 = (uint32_t)v16;
    int32_t v32_s = (int32_t)v16_s;
    printf("\n Расширение до 32 бит знаковое:\n");
    printf32(&v32_s);

    printf("\n Расширение до 32 бит беззнаковое:\n");
    printf32(&v32);
    printf("\n----------------------------------------\n");
}

int main(){
    int m = 57;
    int n = -21;

    c16to32(&m);
    c16to32(&n);

    return 0;
}