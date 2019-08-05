#include <stdio.h> 
#include <stdlib.h>
#define TAM 10

typedef struct{
	int tamanho;
	int *elemento;
}lista;

int *vetorPrincipal[TAM];


void atribuiNULL(){
    for(int i=0; i<TAM; i++)
        vetorPrincipal[i] = NULL;
}


int main(){

	int i;

	atribuiNULL();
	
	for(i=0; i<TAM; i++)
		printf("vetorPrincipal[%d]: %ls\n", i, vetorPrincipal[i]);
}