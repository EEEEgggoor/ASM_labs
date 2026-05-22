#include <stdio.h>
#include <stdlib.h>

extern void* mmul(void *pM1, size_t R1, size_t C1, void *pM2, size_t R2, size_t C2);

int main() {
    int m1[] = {1, 2, 3, 4};
    int m2[] = {5, 6, 7, 8};
    
    int *res = (int*)mmul(m1, 2, 2, m2, 2, 2);
    
    if (res) {
        printf("Result: %d %d %d %d\n", res[0], res[1], res[2], res[3]);
        free(res); 
    }
    getchar();
    return 0;
}