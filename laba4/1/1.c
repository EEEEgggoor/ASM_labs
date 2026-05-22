#include <stdio.h>

extern int f1(int x, int y);

int main() {
    int x, y;

    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    int result = f1(x, y);

    printf("f1(%d, %d) = %d\n", x, y, result);

    return 0;
}