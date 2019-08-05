#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 10


void printVet(int *v){
	for(int i=0;i<TAM;i++){
		printf("%d ", v[i]);
	}
}

void atribuiVet(int *v){
	for(int i=0;i<TAM;i++){
		v[i]=rand()%TAM;
	}
}

void iSort(int *v){
	int i,j,aux;

	for(i=0;i<TAM;i++){
		aux=v[i];
		for(j=i;j>0&&aux<v[j-1];j--){
			v[j]=v[j-1];
		}
		v[j]=aux;
	}
}
int buscaBin(int *v, int n){

	int inicio,meio,fim;

	inicio=0;
	fim=TAM-1;
	

	while((fim-inicio)>0){
		meio=(fim+inicio)/2;

		if(v[meio]==n)
			return meio;
	
		else if(v[meio]>n)
			fim=meio-1;
		
		else
			inicio=meio+1;
	}

	return -1;
}

int main(){

	int vetor[TAM];
	int n;

	atribuiVet(vetor);

	puts("Vetor desordenado");

	printVet(vetor);

	iSort(vetor);

	puts("\nVetor ordenado");

	printVet(vetor);

	printf("\nDigite o numero a buscar: ");
	scanf("%d", &n);

	buscaBin(vetor, n);

	if(buscaBin(vetor, n)!=-1)
		printf("A posicao do numero eh: %d\n", buscaBin(vetor, n)+1);
	else
		puts("Numero nao encontrado");

	return 0;
}