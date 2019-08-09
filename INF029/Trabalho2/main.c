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
                    puts("Inserido com sucesso\n");
                }else if (ret == SEM_ESPACO){
                    limpaTela();
                	puts("Sem Espaço\n");
                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                	limpaTela();
                    printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                }else{
                	limpaTela();
                    puts("Posicao invalida\n");
                }
                break;
            }

            case 2:{ //excluir
            	//recebe valor e posicao
            	capturaValor(&valor);
            	capturaPosicao(&posicao);

                printf("tamanho informado: %d\n", tamanho);
                printf("posicao informada: %d\n", posicao);

            	//define retorno
            	ret = excluirNumeroEmEstrutura(valor, posicao);

            	//chama função de excluir
            	if(ret == SUCESSO){
            		limpaTela();
            		puts("Excluido com sucesso\n");
                    listaEstruturaAuxiliar(posicao);
                }else if(ret == VALOR_INVALIDO){
                	limpaTela();
            		puts("Valor Invalido\n");
                }else{
                	limpaTela();
                    puts("Posicao invalida\n");
                }

                break;
            }
            
            case 3:{ //listar tudo                        
                limpaTela();

                //cria um laço com a função listaEstruturaAuxiliar
                for(posicao=1; posicao<=TAM; posicao++){
                    
                    listaEstruturaAuxiliar(posicao);
                }

                break;
            }

            case 4:{ //Ordenar e listar
            	//recebe a posicao
            	capturaPosicao(&posicao);

                ret = ordenaVetor(posicao);

                limpaTela();

                if(ret==SUCESSO){
                	
                	puts("Ordenado com Sucesso\n");
                	
                	listaEstruturaAuxiliar(posicao);
                }

                else if(ret==POSICAO_INVALIDA)
                	puts("Posicao Invalida\n");

                else
                	printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                
                break;
            }

            case 5:{ //Ordenar e listar tudo
                
                limpaTela();                

                for(posicao=1; posicao <= TAM; posicao++){
                
                    ret = ordenaVetor(posicao);
    
                    if(ret==SUCESSO){
                        
                        puts("Ordenado com Sucesso\n");
                        
                        listaEstruturaAuxiliar(posicao);
                    }
    
                    else if(ret==POSICAO_INVALIDA)
                        puts("Posicao Invalida\n");
    
                    else
                        printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                }        
                        
                break;
            }

            case 6:{ //Aumentar tamanho da lista
                //recebe tamanho e posicao da Estrutura Auxiliar
                capturaTamanho(&tamanho);
                capturaPosicao(&posicao);

                ret = aumentarEstruturaAuxiliar(tamanho, posicao);

                if(ret == SUCESSO){
                    limpaTela();
                    puts("Aumentado com sucesso\n");
                }else if(ret == TAMANHO_INVALIDO){
                    limpaTela();
                    puts("Quantidade de posicoes menor que 1\n");
                }else if(ret == SEM_ESPACO_DE_MEMORIA){
                    limpaTela();
                    puts("O tamanho da Estrutura Auxiliar ultrapassou o maximo permitido\n");
                }else{
                    limpaTela();
                    puts("Posicao invalida\n");
                }

                break;
            }

            case 7:{//Criar estrutura Auxiliar

            	capturaTamanho(&tamanho);
            	capturaPosicao(&posicao);

                ret = criarEstruturaAuxiliar(tamanho, posicao);

                printf("ret: %d\n", ret);

                if(ret == SUCESSO){
                    limpaTela();
                    puts("Criado com sucesso\n");
                }else if(ret == TAMANHO_INVALIDO){
                    limpaTela();
                    puts("Quantidade de posicoes menor que 1\n");
                }else if(ret == SEM_ESPACO_DE_MEMORIA){
                    limpaTela();
                    puts("O tamanho da Estrutura Auxiliar ultrapassou o maximo permitido\n");
                }else if(ret == JA_TEM_ESTRUTURA_AUXILIAR){
                    limpaTela();
                    printf("A Estrutura auxiliar %d ja existe\n\n", posicao);
                }else{
                    limpaTela();
                    puts("Posicao invalida\n");
                }
                break;
            }

            default:{
                limpaTela();
                puts("Opcao inválida\n");
            }

            
        }
        
        
    }
    
    return 0;
    
}