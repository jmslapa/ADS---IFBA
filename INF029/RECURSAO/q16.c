#include <stdio.h>
#include <stdlib.h>

int fatDuplo(int n);

int main(void){
    
    int n;
    
    puts("Informe um valor");
    scanf("%d", &n);
    
    printf("%d!! = %d\n", n, fatDuplo(n));
    
    return 0;
}

int fatDuplo(int n){
        
    if(n == 1)
        return 1;
    
    if(n%2 != 0)
        return n*fatDuplo(n-1);
    
    return fatDuplo(n-1);
}

