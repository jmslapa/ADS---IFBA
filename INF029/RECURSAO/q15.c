#include <stdio.h>
#include <stdlib.h>

void printDec(int n);

int main(void){
    
    int n;
    
    puts("Informe um valor");
    scanf("%d", &n);  
    
    printDec(n);
    puts("");
    
    return 0;
}

void printDec(int n){
        
    if(n < 2)
        return;
    
    if(n%2 == 0)
        printf("%d ", n);
    
    printDec(n-1);      
}

