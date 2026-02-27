#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>

void printf64(void *p) {
    uint64_t *x = (uint64_t*)p;
    int64_t *x_s = (int64_t*)p;
    double *d = (double*)p;
    
    uint64_t v = *x;
    int64_t v_s = *x_s;
    double d_v = *d;
    
    printf("%016llX ", (unsigned long long)v);
    
    for (int i = 63; i >= 0; i--) {
        printf("%d", (int)((v >> i) & 1LL));
        if (i % 8 == 0 && i > 0) printf(" ");
    }
    printf(" ");
    
    printf("%llu ", (unsigned long long)v);
    
    if (v_s >= 0) {
        printf("+%lld", (long long)v_s);
    } else {
        printf("%lld", (long long)v_s);
    }
    
    printf("\n      %+A ", d_v);
    printf("%+E ", d_v);
    printf("%+f", d_v);
    
    printf("\n");
}

int main() {
    
    uint64_t min_unsigned = 0;
    uint64_t max_unsigned = ULLONG_MAX;
    
    printf("Минимальное беззнаковое (0):\n");
    printf64(&min_unsigned);
    
    printf("\n Максимальное беззнаковое (ULLONG_MAX):\n");
    printf64(&max_unsigned);
    
    int64_t min_signed = LLONG_MIN;
    int64_t max_s = LLONG_MAX;
    
    printf("\n Минимальное знаковое (LLONG_MIN):\n");
    printf64(&min_signed);
    
    printf("\n Максимальное знаковое (LLONG_MAX):\n");
    printf64(&max_s);
    
    
    int64_t x = 9;
    int64_t y = -9;
    int64_t a = 1;
    int64_t b = 2;
    int64_t c = 12345678;
    int64_t d = 123456789;
    
    printf("x = 9 (long long и double):\n");
    printf64(&x);
    
    printf("\na = 1 (long long и double):\n");
    printf64(&a);


    printf("x = 9 (long long и double):\n");
    printf64(&x);
    
    printf("\ny = -9 (long long и double):\n");
    printf64(&y);
    
    printf("\na = 1 (long long и double):\n");
    printf64(&a);
    
    printf("\nb = 2 (long long и double):\n");
    printf64(&b);
    
    printf("\nc = 12345678 (long long и double):\n");
    printf64(&c);
    
    printf("\nd = 123456789 (long long и double):\n");
    printf64(&d);
    
    
    
    return 0;
}