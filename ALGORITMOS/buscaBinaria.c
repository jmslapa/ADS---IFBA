#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void insertionSort(int *v, int tam);

void preencheVetor(int *v, int tam);

void imprimeVetor(int *v, int tam);

int buscaBinaria(int *v, int tam, int valor);



int main(void){

	int vetor[TAM], n;

	srand(time(NULL));

	preencheVetor(vetor, TAM);

	insertionSort(vetor, TAM);

	imprimeVetor(vetor, TAM);

	puts("Digite um valor");

	scanf("%d", &n);

	if(buscaBinaria(vetor, TAM, n) == 0)
		puts("Valor nao encontrado");
	
	else
		printf("O valor está na posicao %d\n", buscaBinaria(vetor, TAM, n)+1);

	return 0;
}




void preencheVetor(int *v, int tam){
	
	int i;

	for(i=0; i<TAM; i++)
		v[i]=rand()%100;
}

void imprimeVetor(int *v, int tam){

	int i;

	for(i=0; i<tam; i++)
		printf("%d ", v[i]);
	
	puts("");
}

int buscaBinaria(int *v, int tam, int valor){

	int inicio = 0, fim = tam-1, meio;

	while(inicio <= fim){

		meio = (inicio + fim)/2;

		printf("meio: %d\n", meio);

		printf("valor: %d\n", valor);

		printf("v[meio]: %d\n", v[meio]);

		if(valor > v[meio])
			inicio = meio+1;

		else if(valor < v[meio])
			fim = meio-1;

		else
			return meio;
	}
	
	return 0;
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