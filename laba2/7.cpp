#include <stdio.h>
#include <string.h>
#include <wchar.h>

void printDump(void *p, size_t N) {
    unsigned char *p1 = (unsigned char*)p;
    
    for (size_t i = 0; i < N; i++) {
        printf("%02hhX", p1[i]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    
    int x = 9;
    printf("а) x = %d (int): ", x);
    printDump(&x, sizeof(x));
    
    double dx = 9.0;
    printf("б) x = %f (double): ", dx);
    printDump(&dx, sizeof(dx));
    
    char str1[] = "abc012";
    char str2[] = "абв012";
    
    printf("в1) \"abc012\": ");
    printDump(str1, sizeof(str1));
    
    printf("в2) \"абв012\": ");
    printDump(str2, sizeof(str2));
    
    wchar_t wstr1[] = L"abc012";
    wchar_t wstr2[] = L"абв012";
    
    printf("г1) L\"abc012\": ");
    printDump(wstr1, sizeof(wstr1));
    
    printf("г2) L\"абв012\": ");
    printDump(wstr2, sizeof(wstr2));
    
    return 0;
}