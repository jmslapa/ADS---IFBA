#include <stdio.h>
#include <stdlib.h>

int tetra(int n);

int main(void){
	
	int n, i;
	
	puts("Informe um Numero");
	scanf("%d", &n);

	printf("%dº termo da sequencia Tretranacci:", n);    
   
    printf(" %d\n", tetra(n)); 
    
    return 0;
}

int tetra(int n){
    
    if(n == 1 || n == 2 || n == 3)
        return 0;
    
    if(n == 4)
        return 1;
    
    return tetra(n-1) + tetra(n-2) + tetra(n-3) + tetra(n-4);        
}
