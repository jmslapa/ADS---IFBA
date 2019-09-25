#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int soma_vet(int *vet, int tam);

int main(void){
    
    srand(time(NULL));
    
    int vet[TAM], i;
    
    for(i = 0 ; i < TAM ; i++)
        vet[i] = rand()%TAM;
    
    system("clear");
    
    printf("Vetor:");
    
    for(i = 0 ; i < TAM ; i++)
        printf(" %d", vet[i]);
    
    puts("");
    
    printf("Soma dos elementos do vetor: %d\n", soma_vet(vet, TAM));
    
    return 0;
}

int soma_vet(int *vet, int tam){
        
    if(tam == 1)
        return vet[0];
    
    return vet[tam-1] + soma_vet(vet, tam-1);
}
