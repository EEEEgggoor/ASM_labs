#include <stddef.h>
#include <stdio.h>
#define N 5

int main(){
    size_t i = 2;
    unsigned long long x = 12;
    unsigned long long M[N] = {0x000D15A550C1A7ED,
                                0x000D15A550C1A7ED,
                                0x000D15A550C1A7ED,
                                0x000D15A550C1A7ED,
                                0x000D15A550C1A7ED};

    for(int j=0;j<N;j++)
        printf("%016llx ", M[j]);
    printf("\n\n");
            
    __asm__ volatile(
        "movq (%2), %%r8\n"
        "movq %%r8, (%0, %1, 8)"
        :
        : "r" (M),
          "r" (i),
          "r" (&x)
        : "r8", "memory"
    );

    for(int j=0;j<N;j++)
        printf("%016llx ", M[j]);
    printf("\n\n");
    return 0;
}