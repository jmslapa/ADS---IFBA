#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_LISTA 50

void listarAgenda();
void iSort();
int buscaPosicaoTel();
void printTel();
void printNome();

typedef struct{
	char nome[255];
	long int tel;
} lista;

void main(){

	long int tel;

	FILE *arq;
	lista *empresa = malloc(TAM_LISTA * sizeof(lista)); 

	arq = fopen("telelista.txt", "r");

	listarAgenda(arq, empresa);

	fclose(arq);

	iSort(empresa);

	printTel(empresa);
	printNome(empresa);
	
	printf("Informe o telefone desejado, para saber o nome da empresa:");
	scanf("%li",&tel);

	if(buscaPosicaoTel(empresa, tel)==-1)
			puts("Telefone nao encontrado");
	else
		printf("O nome da empresa eh: %s\n", empresa[buscaPosicaoTel(empresa, tel)].nome);
	
	
}

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

			puts(v[i].nome);
			printf("%li\n",v[i].tel);
			i++;

		}while((fgetc(arq)!=EOF));
		
		puts("Sucesso");
	}
	else
		printf("Erro ao abrir arquivo\n");
}

void iSort(lista *v){
	long int i,j,aux;

	for(i=0;i<TAM_LISTA;i++){
		aux=v[i].tel;
		for(j = i ; j > 0 && aux < v[j-1].tel ; j--){
			v[j].tel=v[j-1].tel;
		}
		v[j].tel=aux;
	}
}

int buscaPosicaoTel(lista *v, long int tel){

	int inicio,meio,fim;

	inicio=0;
	fim=TAM_LISTA-1;
	

	while((fim-inicio)>0){
		meio=(fim+inicio)/2;

		if(v[meio].tel==tel)
			return meio;
	
		else if(v[meio].tel>tel)
			fim=meio-1;
		
		else
			inicio=meio+1;
	}

	return -1;
}

void printTel(lista *v){
	for(int i=0;i<TAM_LISTA;i++)
		printf("empresa[%d].tel: %li\n", i, v[i].tel);
}

void printNome(lista *v){
	for(int i=0;i<TAM_LISTA;i++)
		printf("empresa[%d].nome: %s\n", i, v[i].nome);
}