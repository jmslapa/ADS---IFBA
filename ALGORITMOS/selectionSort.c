#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void selectionSort(int *v, int tam);

void preencheVetor(int *v, int tam);

void imprimeVetor(int *v, int tam);




int main(void){

	int vetor[TAM];

	preencheVetor(vetor, TAM);

	imprimeVetor(vetor, TAM);

	selectionSort(vetor, TAM);

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

void selectionSort(int *v, int tam){

	int i, j, aux, min;

	for(i=0; i<tam-1; i++){

		min=i;
		aux=v[i];

		for(j=i+1; j<tam; j++){

			if(v[j]<v[min])
				min=j;
		}
		
		v[i]=v[min];
		v[min]=aux;

	}
}