#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "agenda.h"

/*#define TAM_LISTA 50

typedef struct{
	char nome[255];
	long int tel;
} lista;*/



void listarAgenda(FILE *arq, lista *v){
	

	int c;
	char nome[255];
	char numero[255];
	int count = 0;
	int i=0;




	if(arq){

		do{

			while((c=fgetc(arq))!= ';'){
				nome[count]=c;
				count++;
			}
			nome[count]='\0';
			count=0;

			while((c=fgetc(arq))!= ';'){
				numero[count]=c;
				count++;
			}
			numero[count]='\0';
			count=0;


			strcpy(v[i].nome, nome);
			v[i].tel=atol(numero);
			i++;

		}while((fgetc(arq)!=EOF));

		fclose(arq);
	}
	else
		printf("Erro ao abrir arquivo\n");
}

void iSort(lista *v){
	long int i,j;
	lista aux;

	for(i=0;i<TAM_LISTA;i++){
		aux=v[i];
		for(j = i ; j > 0 && aux.tel < v[j-1].tel ; j--){
			v[j]=v[j-1];
		}
		v[j]=aux;
	}
}

void buscaEmpresa(lista *v, char *busca){
	int cont=0;

	for(int i=0;i<TAM_LISTA;i++){
		if(verificaString(v[i].nome, busca)>0){
			printf("%s: %li\n", v[i].nome, v[i].tel);
			cont++;
		}
	}
	if(cont==0)
		puts("Nenhuma referencia encontrada");

	puts("");
}

void printTel(lista *v){
	for(int i=0;i<TAM_LISTA;i++)
		printf("empresa[%d].tel: %li\n", i, v[i].tel);
}

void printNome(lista *v){
	for(int i=0;i<TAM_LISTA;i++)
		printf("empresa[%d].nome: %s\n", i, v[i].nome);
}

int verificaString(char *str, char *busca){

	int i=0,j=0,k=0,l=0,cont=0;
	int qtdOcorrencias=0;

	for(i=0;str[i]!='\0';i++){
		if(str[i]==busca[j]||str[i]==busca[j]+32||str[i]==busca[j]-32){
			for(k=i,l=j;busca[l]!='\0';k++,l++){
				if(busca[l]==str[k]||busca[l]==str[k]+32||busca[l]==str[k]-32){
					cont++;
				}
			}
			if(cont==strlen(busca)-1){
				qtdOcorrencias++;
			}
			cont =0;
		}		
	}

	return qtdOcorrencias;
}