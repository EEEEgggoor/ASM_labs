// 7.c
#include <stdlib.h>
#include <stdio.h>

extern void print_mas(int* arr, int len);
int main() {
    int N = 10;
    int* arr = (int*)malloc(N * sizeof(int));
    
    print_mas(arr, N);  
    
    free(arr);

    getchar();
    return 0;
}