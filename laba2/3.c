#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("=== ЦЕЛЫЕ ТИПЫ ===\n");
    
    // 8-битные типы
    printf("char (8-bit):\n");
    printf("  MIN = %d\n", CHAR_MIN);
    printf("  MAX = %d\n", CHAR_MAX);
    
    printf("unsigned char (8-bit):\n");
    printf("  MIN = %d\n", 0);
    printf("  MAX = %d\n", UCHAR_MAX);
    
    // 16-битные типы
    printf("\nshort (16-bit):\n");
    printf("  MIN = %d\n", SHRT_MIN);
    printf("  MAX = %d\n", SHRT_MAX);
    
    printf("unsigned short (16-bit):\n");
    printf("  MIN = %d\n", 0);
    printf("  MAX = %u\n", USHRT_MAX);
    
    // 32-битные типы
    printf("\nint (32-bit):\n");
    printf("  MIN = %d\n", INT_MIN);
    printf("  MAX = %d\n", INT_MAX);
    
    printf("unsigned int (32-bit):\n");
    printf("  MIN = %d\n", 0);
    printf("  MAX = %u\n", UINT_MAX);
    
    // 64-битные типы
    printf("\nlong long (64-bit):\n");
    printf("  MIN = %lld\n", LLONG_MIN);
    printf("  MAX = %lld\n", LLONG_MAX);
    
    printf("unsigned long long (64-bit):\n");
    printf("  MIN = %d\n", 0);
    printf("  MAX = %llu\n", ULLONG_MAX);
    
    printf("\n=== ТИПЫ С ПЛАВАЮЩЕЙ ЗАПЯТОЙ ===\n");
    
    printf("float (32-bit IEEE 754):\n");
    printf("  MIN = %e\n", FLT_MIN);
    printf("  MAX = %e\n", FLT_MAX);
    
    printf("double (64-bit IEEE 754):\n");
    printf("  MIN = %e\n", DBL_MIN);
    printf("  MAX = %e\n", DBL_MAX);
    
    printf("\n=== ОТВЕТЫ НА ВОПРОСЫ ===\n");
    
    return 0;
}