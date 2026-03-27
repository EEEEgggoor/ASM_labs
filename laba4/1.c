#include <stdio.h>

int f1(int x, int y) {
    int result;
    __asm__ (
        "leal (%1, %2), %0\n\t"
        "addl $12, %0"
        : "=r" (result)
        : "r" (x), "r" (y)
    );
    return result;
}

int main() {
    int x, y;
    
    printf("Введите x и y: ");
    scanf("%d %d", &x, &y);
    
    int result = f1(x, y);
    printf("f1(%d, %d) = %d\n", x, y, result);
    
    return 0;
}