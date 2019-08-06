#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void insertionSort(int *v, int tam);

void preencheVetor(int *v, int tam);

void imprimeVetor(int *v, int tam);




int main(void){

	int vetor[TAM];

	preencheVetor(vetor, TAM);

	imprimeVetor(vetor, TAM);

	insertionSort(vetor, TAM);

	imprimeVetor(vetor, TAM);

	return 0;
}




void preencheVetor(int *v, int tam){
	
	int i;

	for(i=0; i<TAM; i++)
		v[i]=rand()%10;
}

void imprimeVetor(int *v, int tam){

	int i;

	for(i=0; i<tam; i++)
		printf("%d ", v[i]);
	
	puts("");
}

void insertionSort(int *v, int tam){

	int i, j, aux;

	for(i=1; i<tam; i++){

		aux=v[i];

		for(j=i-1; j>=0 && v[j]>aux; j--){

			v[j+1]=v[j];
		}

		v[j+1]=aux;
	}
}