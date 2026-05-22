#include <stdio.h>
#include <stdint.h>
#include <limits.h>

void print16(void *p) {
    unsigned short *x = (unsigned short*)p;
    short *x_s = (short*)p;
    
    unsigned short val = *x;
    short val_signed = *x_s;
    
    printf("%04X ", val);
    
    for (int i = 15; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
    printf(" ");
    
    printf("%5u ", val);
    
    if (val_signed >= 0) {
        printf("+%5d", val_signed);
    } else {
        printf("%6d", val_signed);
    }
}

void ab16(void *p) {
    unsigned short x = *(unsigned short*)p;
    short x_s = *(short*)p;
    
    unsigned short res_u;
    short res_s;
    
    printf("Исходное значение x: ");
    print16(&x);
    printf("\n\n");
    
    res_u = x * 2;
    printf("a1) беззнаковое умножение на 2:       ");
    print16(&res_u);
    printf("\n");
    
    res_u = x << 1;
    printf("b1) беззнаковый сдвиг влево на 1:     ");
    print16(&res_u);
    printf("\n");
    
    res_s = x_s * 2;
    printf("a2) знаковое умножение на 2:           ");
    print16(&res_s);
    printf("\n");
    
    res_s = x_s << 1;
    printf("b2) знаковый сдвиг влево на 1:         ");
    print16(&res_s);
    printf("\n");
    
    res_u = x / 2;
    printf("a3) беззнаковое деление на 2:         ");
    print16(&res_u);
    printf("\n");
    
    res_u = x >> 1;
    printf("b3) беззнаковый сдвиг вправо на 1:    ");
    print16(&res_u);
    printf("\n");
    
    res_s = x_s / 2;
    printf("a4) знаковое деление на 2:             ");
    print16(&res_s);
    printf("\n");
    
    res_s = x_s >> 1;
    printf("b4) знаковый сдвиг вправо на 1:       ");
    print16(&res_s);
    printf("\n");
    
    res_u = x % 16;
    printf("a5) остаток от деления на 16:         ");
    print16(&res_u);
    printf("\n");
    
    res_u = x & 15;
    printf("b5) x & 15:                            ");
    print16(&res_u);
    printf("\n");
    
    res_u = (x / 16) * 16;
    printf("a6) округление вниз до кратного 16:   ");
    print16(&res_u);
    printf("\n");
    
    res_s = x_s & -16;
    printf("b6) x & -16:                            ");
    print16(&res_s);
    printf("\n");
    
    printf("\n");
}

int main() {
   
    short m = 9;
    short n = -9;
    
    printf("m = %d:\n", m);
    ab16(&m);
    
    printf("n = %d:\n", n);
    ab16(&n);
    
    return 0;
}