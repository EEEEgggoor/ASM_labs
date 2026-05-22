#include <stdio.h>
#include <stdlib.h>


extern void fill_mass(int* arr, int len);

int main(){

    int N = 10;
    int* arr = (int*)malloc(N * sizeof(int));

    fill_mass(arr, 10);
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return 0;
}