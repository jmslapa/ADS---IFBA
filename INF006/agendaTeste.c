#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void listarAgenda();



struct lista{
	char nome[50];
	int tel;
};


void main(){

	FILE *arq;
	lista empresa[100]; 



	arq = fopen("telelista.txt", "r");

	listarAgenda(arq, empresa);
}

void listarAgenda(FILE *arq, lista *empresa){

	char c;
	int count = 0;

	if(arq){
		while(!feof(arq)&&(c = fgetc(arq))!=';'){
			c = fgetc(arq);
			empresa.nome[count] = c;
			count++;
		}

		fclose(arq);
	}
	else
		printf("Erro ao abrir arquivo\n");

}