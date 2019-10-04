#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y);

int main(void){
	
	int x, y;
	
	puts("Informe dois Numeros");
	scanf("%d %d", &x, &y);

    printf("mdc(%d,%d): ", x, y);
    printf(" %d", mdc(x,y));
    puts("");
    
    return 0;
}

int mdc(int x, int y){
    
    if(y == 0)
        return x;
    
    return mdc(y, x%y);
}
