#include <stdio.h>
#include <stdint.h>
#define N 5

int check_avx_support() {
    uint32_t eax, ebx, ecx, edx;
    
    __asm__ volatile(
        "cpuid"
        : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
        : "a" (1)     
        : "cc"
    );
    
    return (ecx & (1 << 28)) != 0;
}

int main() {
    int avx_available = check_avx_support();
    
  
    size_t i = 3;  
    int x = 42;    
    
    double Mfl[N] = { 4.0/3.0, 4.0/3.0, 4.0/3.0, 4.0/3.0, 4.0/3.0 };
    
    printf("\nДо:\n");
    for (int j = 0; j < N; j++) {
        printf("%f ", Mfl[j]);
    }
    printf("\n");
    printf("x = %d (целое)\n", x);
    
    if (avx_available) {
        __asm__ volatile(
            "vcvtsi2sd %2, %%xmm5, %%xmm5\n\t" 
            "vmovsd %%xmm5, (%0, %1, 8)"
            : 
            : "r" (Mfl),    
              "r" (i),     
              "r" (x)       
            : "xmm5", "memory"
        );
    } else {
        __asm__ volatile(
            "cvtsi2sd %2, %%xmm5\n\t"           
            "movsd %%xmm5, (%0, %1, 8)" 
            : 
            : "r" (Mfl),
              "r" (i),
              "r" (x)
            : "xmm5", "memory"
        );
    }
    
    printf("\nПосле:\n");
    for (int j = 0; j < N; j++) {
        printf("%f ", Mfl[j]);
    }
    printf("\n");
    
    return 0;
}