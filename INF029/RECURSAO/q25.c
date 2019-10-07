#include <stdio.h>
#include <stdlib.h>

int cata(int n);

int main(void){
	
	int n, i;
	
	puts("Informe um Numero");
	scanf("%d", &n);

	printf("%dº termo da sequencia Catalan:", n);   
   
    printf(" %d\n", cata(n-1)); 
    
    return 0;
}

int cata(int n){
    
    if(n <= 1)
        return 1;
    
    int res = 0;
        
    for (int i = 0; i < n; i++) 
        res += cata(i) * cata(n - i - 1); 
    
    return res;
}
