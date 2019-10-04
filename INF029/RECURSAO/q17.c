#include <stdio.h>
#include <stdlib.h>

int fat(int n);

int fatQuad(int n);

int main(void){
    
    int n;
    
    puts("Informe um valor");
    scanf("%d", &n);
    
    printf("%d!!!! = %d\n", n, fatQuad(n));
    
    return 0;
}

int fatQuad(int n){
     
    return fat(n*2)/fat(n);
}

int fat(int n){
        
    if(n == 1)
        return 1;
    
    return n*fat(n-1);
}
