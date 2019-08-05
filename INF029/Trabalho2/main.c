#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();

void dobrar(int *x);

int menu(){
    int op;
    printf("Digite as opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar Tudo\n");
    printf("4 - Ordenar e listar\n");
    printf("5 - Ordenar e listar tudo\n");
    printf("6 - Aumentar tamanho da lista\n");
    printf("7 - Criar estrutura Auxiliar\n");
    scanf("%d", &op);
    return op;
}

int main(){
    
    int op;
    int sair = 0;
    int ret;

    atribuiNULL();

    while (!sair){
        op = menu();
        switch (op){
            case 0:{
                sair =1;
                break;
            }
            case 1:{
                ret = inserirNumeroEmEstrutura(25, 0);
                if (ret == SUCESSO){
                	printf("Inserido com sucesso");
                }else if (ret == SEM_ESPACO){
                	printf("Sem Espaço");
                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                	printf("Sem estrutura Auxiliar");	
                }else if(ret == POSICAO_INVALIDA){
                	printf("Posicao invalida");
                }
                break;
            }

            case 2:{ //excluir
                //TODO
                break;
            }
            
            case 3:{ //dobrar
                //ler um numero
                int valor;
                scanf("%i", &valor);
                
                dobrar(&valor);
                
                //passar para um funcao (void dobrar(...)) que recebe o numero e dobra (EstruturaVetores.c)
                
                printf("%i", valor);
                
                break;
            }
            default:{
                printf("opcao inválida\n");
            }

            
        }
        
        
    }
    
    return 0;
    
}
