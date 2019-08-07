#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();

void dobrar(int *x);

int menu(){
    int op;
    printf("Digite a opção desejada\n");
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
                liberaMemoria();
                limpaTela();                
                sair =1;
                break;
            }
            case 1:{
                ret = inserirNumeroEmEstrutura(25, 5);
                if (ret == SUCESSO){
                	limpaTela();
                    puts("Inserido com sucesso");
                }else if (ret == SEM_ESPACO){
                    limpaTela();
                	puts("Sem Espaço");
                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                	limpaTela();
                    puts("Sem estrutura Auxiliar");
                }else if(ret == POSICAO_INVALIDA){
                	limpaTela();
                    puts("Posicao invalida");
                }
                break;
            }

            case 2:{ //excluir
                //TODO
                break;
            }
            
            case 3:{ //listar tudo                        
                limpaTela();
                //cria um laço com a função listaEstruturaAuxiliar
                for(int i=0; i<TAM; i++){
                    if(listaEstruturaAuxiliar(i) != SUCESSO)
                        printf("Estrutura Auxiliar %d nao implementada\n", i);

                    puts("");
                    quebraPagina();
                }

                break;
            }

            case 4:{ //Ordenar e listar
                //TODO
                break;
            }

            case 5:{ //Ordenar e listar tudo
                //TODO
                break;
            }

            case 6:{ //Aumentar tamanho da lista
                //TODO
                break;
            }

            case 7:{//Criar estrutura Auxiliar
                ret = criarEstruturaAuxiliar(3, 5);

                if(ret == SUCESSO){
                    limpaTela();
                    puts("Criado com sucesso");
                }else if(ret == TAMANHO_INVALIDO){
                    limpaTela();
                    puts("Tamanho invalido");
                }else if(ret == SEM_ESPACO_DE_MEMORIA){
                    limpaTela();
                    puts("Estrutura muito grande, sem espaço na memória");
                }else{
                    limpaTela();
                    puts("Posicao invalida");
                }
                break;
            }

            default:{
                printf("opcao inválida\n");
            }

            
        }
        
        
    }
    
    return 0;
    
}
