#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define N 5
#define R 3 



#define PRINT_INT_ARRAY(type, arr, fmt, width, base, sign, prefix) \
    do { \
        printf("%s", prefix); \
        for (int i = 0; i < N; i++) { \
            type val = arr[i]; \
            if (base == 16) \
                printf("%0" #width #fmt "X", val); \
            else if (base == 2) { \
                for (int b = 8 * sizeof(type) - 1; b >= 0; b--) \
                    putchar((val >> b) & 1 ? '1' : '0'); \
            } \
            else if (base == 10) { \
                if (sign == 0) { \
                    if (sizeof(type) == sizeof(unsigned char)) \
                        printf("%0" #width #fmt "u", (unsigned char)val); \
                    else if (sizeof(type) == sizeof(unsigned short)) \
                        printf("%0" #width #fmt "u", (unsigned short)val); \
                    else if (sizeof(type) == sizeof(unsigned int)) \
                        printf("%0" #width #fmt "u", (unsigned int)val); \
                    else if (sizeof(type) == sizeof(unsigned long long)) \
                        printf("%0" #width #fmt "u", (unsigned long long)val); \
                    else \
                        printf("%0" #width #fmt "u", (unsigned int)val); \
                } \
                else if (sign == 1) \
                    printf("%0" #width #fmt "d", val); \
                else if (sign == 2) \
                    printf("%+0" #width #fmt "d", val); \
            } \
            printf(i == N-1 ? "\n" : " "); \
        } \
    } while(0)

#define PRINT_FLOAT_ARRAY(type, arr, fmt, width, prec, prefix) do { \
    printf("%s", prefix); \
    for (int i = 0; i < N; i++) { \
        printf("%0" #width "." #prec #fmt, arr[i]); \
        printf(i == N-1 ? "\n" : " "); \
    } \
} while(0)

int main() {

    printf("\n=========================№3=========================\n");


    unsigned char Mb[N] = { 0xA7, 0xA7, 0xA7, 0xA7, 0xA7 };
    unsigned short Ms[N] = { 0xC0DE, 0xC0DE, 0xC0DE, 0xC0DE, 0xC0DE };
    unsigned int Ml[N] = { 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF };
    unsigned long long Mq[N] = { 0x000D15A550C1A7ED, 0x000D15A550C1A7ED, 0x000D15A550C1A7ED, 0x000D15A550C1A7ED, 0x000D15A550C1A7ED };
    float Mfs[N] = { 4.0f/3.0f, 4.0f/3.0f, 4.0f/3.0f, 4.0f/3.0f, 4.0f/3.0f };
    double Mfl[N] = { 4.0/3.0, 4.0/3.0, 4.0/3.0, 4.0/3.0, 4.0/3.0 };



    printf("=== Mb (unsigned char) ===\n");
    PRINT_INT_ARRAY(unsigned char, Mb, hh, 2, 16, 0, "  hex: ");
    PRINT_INT_ARRAY(unsigned char, Mb, hh, 8, 2,  0, "  bin: ");
    PRINT_INT_ARRAY(unsigned char, Mb, hh, 3, 10, 0, "  dec(unsigned): ");
    PRINT_INT_ARRAY(unsigned char, Mb, hh, 3, 10, 2, "  dec(signed+): ");

    printf("\n=== Ms (unsigned short) ===\n");
    PRINT_INT_ARRAY(unsigned short, Ms, h, 4, 16, 0, "  hex: ");
    PRINT_INT_ARRAY(unsigned short, Ms, h, 16, 2, 0, "  bin: ");
    PRINT_INT_ARRAY(unsigned short, Ms, h, 5, 10, 0, "  dec(unsigned): ");
    PRINT_INT_ARRAY(unsigned short, Ms, h, 5, 10, 2, "  dec(signed+): ");

    printf("\n=== Ml (unsigned int) ===\n");
    PRINT_INT_ARRAY(unsigned int, Ml, , 8, 16, 0, "  hex: ");
    PRINT_INT_ARRAY(unsigned int, Ml, , 32, 2, 0, "  bin: ");
    PRINT_INT_ARRAY(unsigned int, Ml, , 10, 10, 0, "  dec(unsigned): ");
    PRINT_INT_ARRAY(unsigned int, Ml, , 10, 10, 2, "  dec(signed+): ");

    printf("\n=== Mq (unsigned long long) ===\n");
    PRINT_INT_ARRAY(unsigned long long, Mq, ll, 16, 16, 0, "  hex: ");
    PRINT_INT_ARRAY(unsigned long long, Mq, ll, 64, 2, 0, "  bin: ");
    PRINT_INT_ARRAY(unsigned long long, Mq, ll, 20, 10, 0, "  dec(unsigned): ");
    PRINT_INT_ARRAY(unsigned long long, Mq, ll, 20, 10, 2, "  dec(signed+): ");


    printf("\n=== Mfs (float) ===\n");
    PRINT_FLOAT_ARRAY(float, Mfs, A, 13, 2, "  hex exp: ");
    PRINT_FLOAT_ARRAY(float, Mfs, e, 13, 2, "  dec exp: ");
    PRINT_FLOAT_ARRAY(float, Mfs, f, 13, 2, "  dec fix: ");

    printf("\n=== Mfl (double) ===\n");
    PRINT_FLOAT_ARRAY(double, Mfl, A, 13, 2, "  hex exp: ");
    PRINT_FLOAT_ARRAY(double, Mfl, e, 13, 2, "  dec exp: ");
    PRINT_FLOAT_ARRAY(double, Mfl, f, 13, 2, "  dec fix: ");

    printf("\n=== Демонстрация ширины поля (на примере Mb, hex) ===\n");
    printf("  w = 2 (w <= w0):  ");
    for (int i = 0; i < N; i++) printf("%02hhX ", Mb[i]); printf("\n");
    printf("  w = 4 (w > w0):   ");
    for (int i = 0; i < N; i++) printf("%04hhX ", Mb[i]); printf("\n");
    printf("  w = 4, минус:     ");
    for (int i = 0; i < N; i++) printf("%-04hhX ", Mb[i]); printf("\n");


    printf("\n=========================№4=========================\n");
    

    for (int i = 0; i < 6; i++){
        printf("%d: ", i+1);
        switch (i) {
            case 0:{
                scanf("%hhu", &(Mb[2]));
                break;
            }
            case 1:{
                scanf("%hu", &(Ms[2]));
                break;
            }
            case 2:{
                scanf("%u", &(Ml[2]));
                break;
            }
            case 3:{
                scanf("%lld", &(Mq[2]));
                break;
            }
            case 4:{
                scanf("%f", &(Mfs[2]));
                break;
            }
            case 5:{
                scanf("%lf", &(Mfl[2]));
                break;
            }
        }       
    }


    printf("ПОСЛЕ ВВОДА\n");
    printf("=== Mb (unsigned char) ===\n");
    PRINT_INT_ARRAY(unsigned char, Mb, hh, 2, 16, 0, "  hex: ");
    PRINT_INT_ARRAY(unsigned char, Mb, hh, 8, 2,  0, "  bin: ");
    PRINT_INT_ARRAY(unsigned char, Mb, hh, 3, 10, 0, "  dec(unsigned): ");
    PRINT_INT_ARRAY(unsigned char, Mb, hh, 3, 10, 2, "  dec(signed+): ");

    printf("\n=== Ms (unsigned short) ===\n");
    PRINT_INT_ARRAY(unsigned short, Ms, h, 4, 16, 0, "  hex: ");
    PRINT_INT_ARRAY(unsigned short, Ms, h, 16, 2, 0, "  bin: ");
    PRINT_INT_ARRAY(unsigned short, Ms, h, 5, 10, 0, "  dec(unsigned): ");
    PRINT_INT_ARRAY(unsigned short, Ms, h, 5, 10, 2, "  dec(signed+): ");

    printf("\n=== Ml (unsigned int) ===\n");
    PRINT_INT_ARRAY(unsigned int, Ml, , 8, 16, 0, "  hex: ");
    PRINT_INT_ARRAY(unsigned int, Ml, , 32, 2, 0, "  bin: ");
    PRINT_INT_ARRAY(unsigned int, Ml, , 10, 10, 0, "  dec(unsigned): ");
    PRINT_INT_ARRAY(unsigned int, Ml, , 10, 10, 2, "  dec(signed+): ");

    printf("\n=== Mq (unsigned long long) ===\n");
    PRINT_INT_ARRAY(unsigned long long, Mq, ll, 16, 16, 0, "  hex: ");
    PRINT_INT_ARRAY(unsigned long long, Mq, ll, 64, 2, 0, "  bin: ");
    PRINT_INT_ARRAY(unsigned long long, Mq, ll, 20, 10, 0, "  dec(unsigned): ");
    PRINT_INT_ARRAY(unsigned long long, Mq, ll, 20, 10, 2, "  dec(signed+): ");

    printf("\n=== Mb в символьной форме ===\n  char: ");
    for (int i = 0; i < N; i++) {
        printf("%c", Mb[i]);
        printf(i == N-1 ? "\n" : " ");
    }

    printf("\n=== Mfs (float) ===\n");
    PRINT_FLOAT_ARRAY(float, Mfs, A, 13, 2, "  hex exp: ");
    PRINT_FLOAT_ARRAY(float, Mfs, e, 13, 2, "  dec exp: ");
    PRINT_FLOAT_ARRAY(float, Mfs, f, 13, 2, "  dec fix: ");

    printf("\n=== Mfl (double) ===\n");
    PRINT_FLOAT_ARRAY(double, Mfl, A, 13, 2, "  hex exp: ");
    PRINT_FLOAT_ARRAY(double, Mfl, e, 13, 2, "  dec exp: ");
    PRINT_FLOAT_ARRAY(double, Mfl, f, 13, 2, "  dec fix: ");


    
    printf("\n=========================№5=========================\n");


    printf("Адрес начала массива: %p\n", (void*)Ml);
    printf("Адрес элемента Ml[0]: %p\n", (void*)&Ml[0]);
    printf("Адрес элемента Ml[1]: %p\n", (void*)&Ml[1]);
    printf("Размер одного элемента: %zu\n", sizeof(Ml[0]));

    printf("Разница между &Ml[1] и &Ml[0]: %td байт\n", (char*)&Ml[1] - (char*)&Ml[0]);

    if ((char*)&Ml[1] - (char*)&Ml[0] == sizeof(Ml[0])) {
        printf("Элементы последовательны в памяти\n");
    } else {
        printf("Элементы не последовательны в памяти\n");
    }

    printf("\n=== Статическая матрица MM[%d][%d] ===\n", R, N);


    unsigned int MM[R][N]; 

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < N; j++) {
            MM[i][j] = (i + 1) * (j + 1) * 10;
        }
    }

    printf("Адрес MM[0][0]: %p\n", (void*)&MM[0][0]);
    printf("Адрес MM[0][1]: %p\n", (void*)&MM[0][1]);
    printf("Адрес MM[1][0]: %p\n", (void*)&MM[1][0]);
    printf("Адрес MM[1][1]: %p\n", (void*)&MM[1][1]);

    ptrdiff_t row_step = (char*)&MM[1][0] - (char*)&MM[0][0];
    ptrdiff_t col_step = (char*)&MM[0][1] - (char*)&MM[0][0];

    printf("\nСмещение между строками (MM[1][0] - MM[0][0]) : %td байт\n", row_step);
    printf("Смещение между столбцами (MM[0][1] - MM[0][0]) : %td байт\n", col_step);

    if (col_step == sizeof(unsigned int) && row_step == N * sizeof(unsigned int)) {
        printf("Матрица расположена в памяти построчно\n");
    } else {
        printf("Матрица расположена в памяти не построчно\n");
    }


    unsigned int* dyn_mat = (unsigned int*)malloc(R * N * sizeof(unsigned int));

    if (dyn_mat == NULL) {
        printf("Error malloc\n");
        return 1;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < N; j++) {
            dyn_mat[i * N + j] = (i + 1) * (j + 1) * 10;
        }
    }

    printf("\nАдрес динамической матрицы dyn_mat : %p\n", (void*)dyn_mat);
    printf("Адрес dyn_mat[0] (M[0][0]) : %p\n", (void*)&dyn_mat[0]);
    printf("Адрес dyn_mat[1] (M[0][1]) : %p\n", (void*)&dyn_mat[1]);
    printf("Адрес dyn_mat[%d] (M[1][0]) : %p\n", N, (void*)&dyn_mat[N]);
    printf("Адрес dyn_mat[%d] (M[1][1]) : %p\n", N+1, (void*)&dyn_mat[N+1]);

    printf("\nСмещения:\n");
    printf("dyn_mat[1] - dyn_mat[0]     = %td байт (равно sizeof)\n",
           (char*)&dyn_mat[1] - (char*)&dyn_mat[0]);
    printf("dyn_mat[%d] - dyn_mat[0]     = %td байт (равно N * sizeof)\n", N,
           (char*)&dyn_mat[N] - (char*)&dyn_mat[0]);

    int i = 1, j = 2;
    int idx = i * N + j;
    printf("\nПример: i=%d, j=%d | idx = %d * %d + %d = %d\n", i, j, i, N, j, idx);
    printf("Значение dyn_mat[%d] = %u (ожидалось %f)\n", idx, dyn_mat[idx], (j + 1) * (i + 1) * 10.0);

    free(dyn_mat);


    printf("\n=========================№6=========================\n");

    printf("=== ДО ВВОДА ===\n");
    for (int i = 0; i < N; i++) {
        printf("Ml[%d] = %u (0x%X)\n", i, Ml[i], Ml[i]);
    }

    
    printf("Ввод: ");
    scanf("%u %u %u %u %u", &Ml[0], &Ml[1], &Ml[2], &Ml[3], &Ml[4]);

    printf("\n=== ПОСЛЕ ВВОДА ===\n");
    for (int i = 0; i < N; i++) {
        printf("Ml[%d] = %u (0x%X)\n", i, Ml[i], Ml[i]);
    }


    return 0;
}