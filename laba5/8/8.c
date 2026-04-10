#include <stdio.h>
#include <stdlib.h>

extern size_t sa(double* arr, size_t N, double x);


int main() {
    size_t N = 10;
    double* arr = (double*)malloc(N * sizeof(double));
    
   
    double vals[] = {5.2, -3.1, 8.7, -2.5, 0.3, 4.8, -1.2, 7.9, -0.5, 3.4};
    for (size_t i = 0; i < N; i++) {
        arr[i] = vals[i];
        printf("%.1f ", arr[i]);
    }
    printf("\n");
    
    size_t result = sa(arr, N, 0.0);
    printf("Res index: %zu\n", result);
    
    free(arr);
    return 0;
}