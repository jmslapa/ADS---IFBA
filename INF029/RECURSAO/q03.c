#include <stdio.h>
#include <stdlib.h>

void inverte(int n);

int main(void){
	
	int n, i;
	
	puts("Informe um Numero");
	scanf("%d", &n);

    printf("Numero invertido: ");
    inverte(n);
    puts("");
    
    return 0;
}

void inverte(int n){
    
    if(n == 0)
        return;
       
    printf("%d", n%10);
    
    inverte(n/10);
}
