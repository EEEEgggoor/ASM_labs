#include <stdio.h>
#include <stddef.h>

int main() {
    printf("=== Размеры типов данных (в байтах) ===\n");
    printf("Платформа: ARM64 / Android (Clang)\n\n");

    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));

    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("long double: %zu\n", sizeof(long double));

    printf("void*: %zu\n", sizeof(void*));
    printf("int*: %zu\n", sizeof(int*));
    printf("double*: %zu\n", sizeof(double*));

    printf("size_t: %zu\n", sizeof(size_t));
    printf("ptrdiff_t: %zu\n", sizeof(ptrdiff_t));

    return 0;
}