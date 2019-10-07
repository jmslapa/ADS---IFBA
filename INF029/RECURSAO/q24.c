#include <stdio.h>
#include <stdlib.h>

int pell(int n);

int main(void){
	
	int n, i;
	
	puts("Informe um Numero");
	scanf("%d", &n);

	printf("%dº termo da sequencia Pell:", n);   
   
    printf(" %d\n", pell(n)); 
    
    return 0;
}

int pell(int n){
    
    if(n == 1)
        return 0;
    
    if(n == 2)
        return 1;
    
    return (2 * pell(n-1)) + pell(n-2);
}
