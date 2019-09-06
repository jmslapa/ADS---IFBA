#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

	int elemento;

	struct lista *prox;

} node;


node* criarElemento(int valor){

	node *novo = (node*) malloc(sizeof(node));

	if(novo == NULL)
		return NULL;
	else{

		novo->elemento = valor;

		novo->prox = NULL;
	}

	return novo;
}

void inserirFim(node *inicio, int valor){

	node *tmp;
	node *novo = criarElemento(valor);

	if(inicio->prox == NULL)
		inicio->prox = novo;
	else{

		tmp = inicio->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void listarElementos(node *inicio){

	node *atual;

	puts("Lista Encadeada:");

	for(atual = inicio->prox ; atual != NULL ; atual = atual->prox){

		printf("%d\n", atual->elemento);

	}

}

void liberarLista(node *inicio){

	node *atual = inicio;
	node *tmp;

	while(atual != NULL){

		tmp = atual->prox;
		free(atual);
		atual = tmp;

	}

}

int main_menu(){
	int option;


    printf("Digite a opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir Numero\n");
    printf("2 - Listar Elementos\n");   
    scanf("%d", &option);

    return option;
}

int main(void){

	int option;
	int exit = 0;
	int value;

	node *inicio = (node*) malloc(sizeof(node));
	
	if(inicio == NULL)
		puts("Sem espaço em memória");

	else{

		inicio->prox = NULL;

		while(!exit){

			option = main_menu();

			switch(option){

				case 0:{

					liberarLista(inicio);

					exit = 1;

					break;
				}

				case 1:{

					puts("Digite o valor");
					scanf("%d", &value);

					inserirFim(inicio, value);

					break;
				}

				case 2:{

					listarElementos(inicio);

					break;
				}

				default:{

					puts("Opção Inválida");

				}

			}
		}
	}

	return 0;
}