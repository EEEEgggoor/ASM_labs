#include <stdio.h>

#define K1 20  
#define K2 10  
#define K3 50  

int main() {
    char s1[K1];
    char s2[K2];
    char s3[K3];

    printf("Cлово s1 без пробелов: ");
    scanf("%s", s1); 
    while (getchar() != '\n');

    printf("Cлово s2 без переполнения: ");
    scanf("%9s", s2);
    while (getchar() != '\n');

    printf("Введите s3 строку с пробелами: ");
    scanf(" %[^\n]", s3);


    printf("\n=== ВЫВОД РЕЗУЛЬТАТОВ ===\n");
    printf("***%s***\n", s1);
    printf("***%s***\n", s2);
    printf("***%s***\n", s3);

    return 0;
}