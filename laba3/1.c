#include <stdlib.h>
#include <stdio.h>

#define N 5

int main(){

    unsigned short Ms[N] = { 0xC0DE, 0xC0DE, 0xC0DE, 0xC0DE, 0xC0DE };
    unsigned int Ml[N] = { 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF };
    unsigned long long Mq[N] = { 0x000D15A550C1A7ED, 0x000D15A550C1A7ED, 0x000D15A550C1A7ED, 0x000D15A550C1A7ED, 0x000D15A550C1A7ED };

    for(int j=0;j<N;j++)
        printf("%04x ", Ms[j]);
    printf("\n");

    for(int j=0;j<N;j++)
        printf("%08x ", Ml[j]);
    printf("\n");

    for(int j=0;j<N;j++)
        printf("%016llx ", Mq[j]);
    printf("\n\n");


    __asm__ volatile(
        "movw $18, %0\n\t"
        "movl $18, %1\n\t"
        "movq $18, %2\n\t"
        : "=m"(Ms[2]), "=m"(Ml[2]), "=m"(Mq[2])
        :
        :"memory"
    );


    for(int j=0;j<N;j++)
        printf("%04x ", Ms[j]);
    printf("\n");

    for(int j=0;j<N;j++)
        printf("%08x ", Ml[j]);
    printf("\n");

    for(int j=0;j<N;j++)
        printf("%016llx ", Mq[j]);
    printf("\n\n");


    return 0;
}

