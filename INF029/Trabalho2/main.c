#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();


int menu(){
    int op;
    printf("Digite a opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar Tudo\n");
    printf("4 - Ordenar e listar\n");
    printf("5 - Ordenar e listar tudo\n");
    printf("6 - Aumentar tamanho da Estrutura Auxiliar\n");
    printf("7 - Criar Estrutura Auxiliar\n");
    scanf("%d", &op);
    return op;
}

int main(){
    
    int op;
    int sair = 0;
    int ret, valor=0, posicao=0, tamanho=0;

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
            	//recebe valor e posicao
            	capturaValor(&valor);
            	capturaPosicao(&posicao);

                ret = inserirNumeroEmEstrutura(valor, posicao);

                if (ret == SUCESSO){
                	limpaTela();
                    puts("Inserido com sucesso");
                }else if (ret == SEM_ESPACO){
                    limpaTela();
                	puts("Sem Espaço");
                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                	limpaTela();
                    puts("Sem estrutura Auxiliar");
                }else{
                	limpaTela();
                    puts("Posicao invalida");
                }
                break;
            }

            case 2:{ //excluir
            	//recebe valor e posicao
            	capturaValor(&valor);
            	capturaPosicao(&posicao);

            	//define retorno
            	ret = excluirNumeroEmEstrutura(valor, posicao);

            	//chama função de excluir
            	if(ret == SUCESSO){
            		limpaTela();
            		puts("Excluido com sucesso");
                    listaEstruturaAuxiliar(posicao);
                }else if(ret == VALOR_INVALIDO){
                	limpaTela();
            		puts("Valor Invalido");
                }else{
                	limpaTela();
                    puts("Posicao invalida");
                }

                break;
            }
            
            case 3:{ //listar tudo                        
                limpaTela();

                //cria um laço com a função listaEstruturaAuxiliar
                for(int i=1; i<=TAM; i++){
                    
                    listaEstruturaAuxiliar(i);
                }

                break;
            }

            case 4:{ //Ordenar e listar
            	//recebe a posicao
            	capturaPosicao(&posicao);

                ret = ordenaVetor(posicao);

                if(ret==SUCESSO){
                	
                	puts("Ordenado com Sucesso");
                	
                	listaEstruturaAuxiliar(posicao);
                }

                else if(ret==POSICAO_INVALIDA)
                	puts("Posicao Invalida");

                else
                	puts("A estrutura auxiliar nao foi implementada");
                
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

            	capturaTamanho(&tamanho);
            	capturaPosicao(&posicao);

                ret = criarEstruturaAuxiliar(tamanho, posicao);

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
