#include <stdio.h>
#include <stdlib.h>

int soma(int n);

int main(void){
	
	int n, i;
	
	puts("Informe um Numero");
	scanf("%d", &n);

    printf("Soma dos numeros: ");
    printf(" %d", soma(n));
    puts("");
    
    return 0;
}

int soma(int n){
    
    if(n == 0)
        return 0;
    
    return n + soma(n-1);
}
