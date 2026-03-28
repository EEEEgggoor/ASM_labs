#include <stdio.h>

extern double f2(double x, double y);

int main() {
    double x, y;

    printf("x: ");
    scanf("%lf", &x);
    printf("y: ");
    scanf("%lf", &y);

    double result = f2(x, y);

    printf("f2(%f, %f) = %f\n", x, y, result);

    return 0;
}