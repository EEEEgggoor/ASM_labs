// 7.c
#include <stdlib.h>

extern void print_mas(int* arr, int len);  // исправлено: fill_and_print → print_mas

int main() {
    int N = 10;
    int* arr = (int*)malloc(N * sizeof(int));
    
    print_mas(arr, N);  // вызываем функцию
    
    free(arr);
    return 0;
}