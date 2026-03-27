#include <stdio.h>

double f2(double x, double y){
    double result;
    __asm__(
        "vdivsd %2, %1, %0"     
        : "=x" (result)
        : "x" (x), "x" (y)
    );
    return result;
}

int main(){
    double x, y;
    printf("Введите x и y: ");
    scanf("%lf %lf", &x, &y);
    
    double result = f2(x, y);
    printf("f2(%lf, %lf) = %lf\n", x, y, result);
    
    return 0;
}