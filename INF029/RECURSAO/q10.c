#include <stdio.h>
#include <stdlib.h>

int contaNum(int n, int b);

int main(void){
	
	int n, b;
	
	puts("Informe um numero");
	scanf("%d", &n);
    puts("Informe um algarismo a buscar");
	scanf("%d", &b);
    
    printf("%d aparece %d vezes em %d", b, contaNum(n, b), n);
    puts("");
    
    return 0;
}

int contaNum(int n, int b){
    
    if(n/10 == 0){
        
        if(n%10 == b)
            return 1;
        
        return 0;      
    }
    
    if(n%10 == b)
        return contaNum(n/10, b) + 1;
    
    return contaNum(n/10, b);    
}
