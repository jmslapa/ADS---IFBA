#include <stdio.h>
#include <stdlib.h>

int pot(int n, int p);

int main(void){
	
	int n, p;
	
	puts("Informe um número");
	scanf("%d", &n);
    puts("Informe a potência a qual quer elevá-lo");
	scanf("%d", &p);

    printf("%d^%d: ", n, p);
    printf(" %d", pot(n, p));
    puts("");
    
    return 0;
}

int pot(int n, int p){
    
    if(p == 0)
        return 1;
    
    return pot(n, p-1) * n;
}
