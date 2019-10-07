#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fibo(int n);

int main(void){
	
	int n;
	
	puts("Informe um Numero");
	scanf("%d", &n);

	printf("%dª palavra da sequencia fidbonacci:", n);   
    
    fibo(n);
    
    puts("");
    
    return 0;
}

void fibo(int n){    
    
    if(n == 1){
        printf("b");
        return;
    }
    if(n == 2){
        printf("a");
        return;
    }
    
    fibo(n-1);
    fibo(n-2);   
}
