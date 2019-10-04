#include <stdio.h>
#include <stdlib.h>

int fat(int n);

int superFat(int n);

int main(void){
    
    int n;
    
    puts("Informe um valor");
    scanf("%d", &n);
    
    printf("Super fatorial de %d: %d\n", n, superFat(n));
    
    return 0;
}

int superFat(int n){
    
    if(n == 1)
        return 1;
    
    return fat(n) + superFat(n-1);
}

int fat(int n){
        
    if(n == 1)
        return 1;
    
    return n*fat(n-1);
}
