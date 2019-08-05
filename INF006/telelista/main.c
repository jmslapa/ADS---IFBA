#include<stdio.h>
#include<stdlib.h>

#include "agenda.h"


int main(void){

	lista *empresa = malloc(TAM_LISTA * sizeof(lista));

	FILE *arq;

	char nome[255];
	char n;

	arq = fopen("telelista.txt", "r");

	listarAgenda(arq, empresa);
	
	printf("Informe o nome da empresa:");
	
	fgets(nome, sizeof(nome), stdin);

	system ("clear");

	buscaEmpresa(empresa, nome);

	return 0;
}