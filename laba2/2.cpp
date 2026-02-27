#include <stdio.h>


void viewPointer(void *p){

    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);

    printf("Адреса:\n");
    printf("p  = %p\n", p);
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    printf("p3 = %p\n", p3);
    
    printf("\n Смежные адреса:\n");
    printf("p1 + 1 = %p\n", p1 + 1);
    printf("p2 + 1 = %p\n", p2 + 1);
    printf("p3 + 1 = %p\n", p3 + 1);
}

void printPointer(void *p){
    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);

    printf("\n Значения адресов:\n");

    printf("*(p1) = 0x%02X\n", (unsigned char)*p1);  
    printf("*(p2) = 0x%04X\n", *p2);   
    printf("*(p3) = f\n", *p3);

    printf("\n Значения смежных адресов:\n");

    printf("*(p1 + 1) = 0x%02X\n", (unsigned char)*(p1+1));  
    printf("*(p2 + 1) = 0x%04X\n", *(p2+1));   
    printf("*(p3 + 1) = f\n", *(p3+1));
}


int main(){

    long long ll = 0x1122334455667788LL;
    printf("Значение: 0x%llX\n", ll);
    printf("Размер: %lu байт\n", sizeof(ll));
    viewPointer(&ll);
    printPointer(&ll);
    printf("\n");
    char str[] = "0123456789abcdef";
    printf("Строка: %s\n", str);
    printf("Размер: %lu байт\n", sizeof(str));
    viewPointer(str);
    printPointer(str);


    return 0;
}