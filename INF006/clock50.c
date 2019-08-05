#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void down();
void end();
void printV();
void randV();
void bubbleSort();
void selectionSort();
void insertionSort();

void main(){
	int vetor[MAX];

	clock_t tempo;

	end();
	//CLOCK BUBBLE
	printf("Vetor desordenado: ");
	randV(vetor,MAX);
	printV(vetor, MAX);
	down();

	printf("Vetor ordenado: ");
	tempo=clock();
	bubbleSort(vetor, MAX);
	tempo=clock()-tempo;
	printV(vetor, MAX);
	down();
	
	printf("Clock do BubbleSort: %f segundos\n", (float)tempo/CLOCKS_PER_SEC);
	end();

	//CLOCK SELECTION
	printf("Vetor desordenado: ");
	randV(vetor,MAX);
	printV(vetor, MAX);
	down();

	printf("Vetor ordenado: ");
	tempo=clock();
	selectionSort(vetor, MAX);
	tempo=clock()-tempo;
	printV(vetor, MAX);
	down();

	printf("Clock do SelectionSort: %f segundos\n", (float)tempo/CLOCKS_PER_SEC);
	end();

	//CLOCK INSERTION
	printf("Vetor desordenado: ");
	randV(vetor,MAX);
	printV(vetor, MAX);
	down();

	printf("Vetor ordenado: ");
	tempo=clock();
	insertionSort(vetor, MAX);
	tempo=clock()-tempo;
	printV(vetor, MAX);
	down();

	printf("Clock do InsertionSort: %f segundos\n", (float)tempo/CLOCKS_PER_SEC);
	end();
}




void down(){
	printf("\n");
}

void end(){
	for(int i=0;i<5;i++){
		printf("					*\n");
	}
}

void printV(int *v, int tam){
	for(int i=0;i<tam;i++){
		printf("%d ", v[i]);
	}
}

void randV(int *v,int tam){
	for(int i=0;i<tam;i++){
		v[i]=rand()%((tam-1)*11);
	}
}

void bubbleSort(int *V  , int N){

    int i, j, aux;

	for(i = 0; i < N; i++){
		
	    for(j = i+1; j < N; j++){
	    	
	        if (V[i] > V[j]){
	            aux = V[i];
	            V[i] = V[j];
	            V[j] = aux;
	        }   
	    }		
	}

}

void selectionSort(int *V, int N){
	
    int i, j, menor, troca;
    
	for(i = 0; i < N-1; i++){
        menor = i;
        
		for(j = i+1; j < N; j++){
            if(V[j] < V[menor])
                menor = j;
        }
        
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

void insertionSort(int *V, int N){
	
	int i, j, aux;
	
	for(i = 1; i < N; i++){
		
		aux = V[i];
		
		for(j = i ; ( j > 0 ) && (aux < V[j-1]) ; j--){
			
			V[j] = V[j-1];
		}
		
		V[j] = aux;
	}
	
}



