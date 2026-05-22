#include <stdio.h>
#include <stdint.h>

extern int mce_si(void *p, size_t N);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t N = sizeof(arr) / sizeof(arr[0]);

    int result = mce_si(arr, N);

    printf("Result: %d\n", result);
    getchar();
    return 0;
}