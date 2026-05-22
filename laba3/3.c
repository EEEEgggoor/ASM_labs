#include <stddef.h>
#include <stdio.h>
#define N 5

int main(){
    size_t i = 2;

    unsigned long long Mq[N] = {0x000D15A550C1A7ED,
                                0x000D15A550C1A7ED,
                                0x000D15A550C1A7ED,
                                0x000D15A550C1A7ED,
                                0x000D15A550C1A7ED};
    for(int j=0;j<N;j++)
        printf("%016llx ", Mq[j]);
    printf("\n\n");

    __asm__ volatile(
        "movb $0x55, 5(%0, %1, 8)"
        :
        : "r" (Mq), "r" (i)
        :"memory"
    );
    
    for(int j=0;j<N;j++)
        printf("%016llx ", Mq[j]);
    printf("\n\n");
    
    
    
    return 0;
}