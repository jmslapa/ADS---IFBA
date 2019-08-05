#define TAM_LISTA 50

typedef struct{
	char nome[255];
	long int tel;
} lista;

void criaLista();
void listarAgenda();
void iSort();
void buscaEmpresa();
void printTel();
void printNome();
int verificaString();