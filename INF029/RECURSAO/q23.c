#include <stdio.h>
#include <stdlib.h>

int padovan(int n);

int main(void){
	
	int n, i;
	
	puts("Informe um Numero");
	scanf("%d", &n);

	printf("%dº termo da sequencia Padovan:", n);    
   
    printf(" %d\n", padovan(n)); 
    
    return 0;
}

int padovan(int n){
    
    if(n == 1 || n == 2 || n == 3)
        return 1;
    
    return padovan(n-2) + padovan(n-3);        
}
