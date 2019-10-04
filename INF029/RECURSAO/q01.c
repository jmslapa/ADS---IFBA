#include <stdio.h>
#include <stdlib.h>

int fat(int n);

int main(void){
    
    int n;
    
    puts("Informe um valor");
    scanf("%d", &n);
    
    printf("Fatorial de %d: %d\n", n, fat(n));
    
    return 0;
}

int fat(int n){
        
    if(n == 1)
        return 1;
    
    return n*fat(n-1);
}

