#include <stdio.h>
#include <stdlib.h>

int tribo(int n);

int main(void){
	
	int n, i;
	
	puts("Informe um Numero");
	scanf("%d", &n);

	printf("%dº termo da sequencia Tribonacci:", n);    
   
    printf(" %d\n", tribo(n)); 
    
    return 0;
}

int tribo(int n){
    
    if(n == 1 || n == 2)
        return 0;
    
    if(n == 3)
        return 1;
    
    return tribo(n-1) + tribo(n-2) + tribo(n-3);        
}
