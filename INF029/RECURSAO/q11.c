#include <stdio.h>
#include <stdlib.h>

int mult(int n, int m);

int main(void){
	
	int n, m;
	
	puts("Informe um número");
	scanf("%d", &n);
    puts("Informe o numero ao qual quer multiplicá-lo");
	scanf("%d", &m);

    printf("%d*%d =", n, m);
    printf(" %d", mult(n, m));
    puts("");
    
    return 0;
}

int mult(int n, int m){
    
    if(m == 0)
        return 0;
    
    return mult(n, m-1) + n;
}
