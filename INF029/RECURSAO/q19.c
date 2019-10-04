#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hiperFat(int n);

int main(void){
    
    int n;
    
    puts("Informe um valor");
    scanf("%d", &n);
    
    printf("Hiper fatorial de %d: %d\n", n, hiperFat(n));
    
    return 0;
}

int hiperFat(int n){
        
    if(n == 1)
        return 1;
    
    return pow(n,n) * hiperFat(n-1);
}

