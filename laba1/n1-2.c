#include <stdio.h>
#include <wchar.h>
#include <stddef.h>


#define PRINT_SYZE_TYPE(type) printf("Размер %-20s = %zu байт\n", #type, sizeof(type))

int main (){

    puts("ЗАДАНИЕ №11\n");
    puts("ГРУППА: ПИН-25\n \
            УЧАСТНИКИ:\n \
            Лыгач Георгий\n \
            Холин Дмитрий\n");



    puts("ЗАДАНИЕ №2");
    PRINT_SYZE_TYPE(void*);
    PRINT_SYZE_TYPE(char);
    PRINT_SYZE_TYPE(signed char);
    PRINT_SYZE_TYPE(unsigned char);
    PRINT_SYZE_TYPE(char*);
    PRINT_SYZE_TYPE(wchar_t);
    PRINT_SYZE_TYPE(wchar_t*);
    PRINT_SYZE_TYPE(short);
    PRINT_SYZE_TYPE(unsigned short);
    PRINT_SYZE_TYPE(short*);
    PRINT_SYZE_TYPE(int);
    PRINT_SYZE_TYPE(unsigned int);
    PRINT_SYZE_TYPE(int*);
    PRINT_SYZE_TYPE(long);
    PRINT_SYZE_TYPE(unsigned long);
    PRINT_SYZE_TYPE(long long);
    PRINT_SYZE_TYPE(unsigned long long);
    PRINT_SYZE_TYPE(float);
    PRINT_SYZE_TYPE(double);
    PRINT_SYZE_TYPE(long double);
    PRINT_SYZE_TYPE(double*);
    PRINT_SYZE_TYPE(size_t);
    PRINT_SYZE_TYPE(ptrdiff_t);


        printf("\n--- Платформа ---\n");
#ifdef __linux__
    printf("ОС: Linux\n");
#elif _WIN32
    printf("ОС: Windows\n");
#elif __APPLE__
    printf("ОС: macOS\n");
#else
    printf("ОС: неизвестная\n");
#endif

#ifdef __x86_64__
    printf("Разрядность ОС: 64-bit\n");
#elif __i386__
    printf("Разрядность ОС: 32-bit\n");
#endif

#if defined(__GNUC__)
    printf("Компилятор: GCC %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(__clang__)
    printf("Компилятор: Clang\n");
#endif

#ifdef __LP64__
    printf("Разрядность сборки: 64-bit\n");
#else
    printf("Разрядность сборки: 32-bit\n");
#endif

#if defined(__amd64__) || defined(__x86_64__)
    printf("Архитектура: x86_64 (AMD64)\n");
#elif defined(__i386__)
    printf("Архитектура: x86 (IA-32)\n");
#endif


    return 0;
}