#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fatExp(int n);

int main(void){
    
    int n;
    
    puts("Informe um valor");
    scanf("%d", &n);
    
    printf("Fatorial de %d: %d\n", n, fatExp(n));
    
    return 0;
}

int fatExp(int n){
        
    if(n == 1)
        return 1;
    
    return pow(n, fatExp(n-1));
}

