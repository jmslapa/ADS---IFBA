#include <stdio.h>
#include <stdlib.h>

#define TAM 100

void mvet(int* vet);
void printv(int* vet);
void invertv(int* vet, int index);

int main(void){
	
	int vet[TAM];
    
	mvet(vet);    
    invertv(vet, TAM-1);
    printv(vet);
    
    return 0;
}

void invertv(int* vet, int index){
    
    if(index > TAM/2){
        
        int tmp = vet[index];
        int mirror = TAM - index - 1;
        
        vet[index] = vet[mirror];
        vet[mirror] = tmp;
        
        invertv(vet, index-1);
    }
}

void mvet(int* vet){
    
    for(int i = 0 ; i < TAM ; i++)
        vet[i] = i+1;
}

void printv(int* vet){
    
    printf("Vetor: ");
    
    for(int i = 0 ; i < TAM ; i++)
        printf(" %d", vet[i]);
    
    puts("");
}


