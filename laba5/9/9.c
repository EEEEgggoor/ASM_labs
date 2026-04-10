#include <stdio.h>
#include <stdlib.h>

extern void mre(void *pM, size_t R, size_t C, size_t j);

 void print_matrix(int *M, size_t R, size_t C) {
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            printf("%4d ", M[i * C + j]);
        }
        printf("\n");
    }
}

int main() {
    
    size_t R = 5; 
    size_t C = 6; 
    size_t j = 2; 
    
    int *M = (int*)malloc(R * C * sizeof(int));
    if (M == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    
 
    for (size_t i = 0; i < R; i++) {
        for (size_t col = 0; col < C; col++) {
            M[i * C + col] = i * C + col + 1;
        }
    }
    
    printf("Матрица ДО замены:\n");
    print_matrix(M, R, C);
    
 
    mre(M, R, C, j);
    
    printf("\nМатрица ПОСЛЕ замены столбца %zu на -1:\n", j);
    print_matrix(M, R, C);
    
    free(M);
    return 0;
}