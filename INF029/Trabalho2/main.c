#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();


int menu(){
    int op;


    printf("Digite a opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir no fim da estrutura\n");
    printf("3 - Excluir numero especifico na estrutura\n");
    printf("4 - Listar\n");
    printf("5 - Listar Tudo\n");
    printf("6 - Ordenar e listar\n");
    printf("7 - Ordenar e listar tudo\n");
    printf("8 - Aumentar tamanho da Estrutura Auxiliar\n");
    printf("9 - Criar Estrutura Auxiliar\n");
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
            
             case 2:{ //excluir numero do fim da estrutura
            	//recebe posicao
            	capturaPosicao(&posicao);

            	//define retorno
            	ret = excluirNumeroDoFinaldaEstrutura(posicao);

            	//chama função de excluir
            	if(ret == SUCESSO){
            		limpaTela();
            		puts("Excluido com sucesso\n");
                    getDadosEstruturaAuxiliar(posicao);
                }else if(ret == ESTRUTURA_AUXILIAR_VAZIA){
                	limpaTela();
            		puts("Estrutura auxiliar vazia\n");
                }else if(ret == POSICAO_INVALIDA){
                	limpaTela();
                    puts("Posicao invalida\n");
                }else{
                	limpaTela();
                    printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                }

                break;
            }            
            
            case 3:{ //excluir numero especifico
            	//recebe valor e posicao
            	capturaValor(&valor);
            	capturaPosicao(&posicao);

            	//define retorno
            	ret = excluirNumeroEspecificoDeEstrutura(valor, posicao);

            	//chama função de excluir
            	if(ret == SUCESSO){
            		limpaTela();
            		puts("Excluido com sucesso\n");
                    getDadosEstruturaAuxiliar(posicao);
                }else if(ret == NUMERO_INEXISTENTE){
                	limpaTela();
            		puts("Numero Inexistente\n");
                }else if(ret == POSICAO_INVALIDA){
                	limpaTela();
                    puts("Posicao invalida\n");
                }else if(ret == ESTRUTURA_AUXILIAR_VAZIA){
                    limpaTela();
                    puts("Estrutura auxiliar vazia\n");
                }else{
                	limpaTela();
                    printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                }

                break;
            }            

            case 4:{ //listar
            	//recebe posicao
            	capturaPosicao(&posicao);
                
                //define retorno
                ret = getDadosEstruturaAuxiliar(posicao);
                
                if(ret == SUCESSO){
                    limpaTela();
                    getDadosEstruturaAuxiliar(posicao);                    
                    
                }else if(ret == POSICAO_INVALIDA){
                    limpaTela();
                    printf("Posicao Invalida\n\n", posicao);                                        
                }else{
                    limpaTela();
                    printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                }
                    
                
                break;
            }
            
            case 5:{ //listar tudo                        
                
                //cria um laço com a função getDadosEstruturaAuxiliar
                for(posicao=1; posicao<=TAM; posicao++){
                    //define retorno
                    ret = getDadosEstruturaAuxiliar(posicao);
                    
                    if(ret == SUCESSO){
                        //limpaTela();
                        getDadosEstruturaAuxiliar(posicao);                    
                        
                    }else if(ret == POSICAO_INVALIDA){
                        //limpaTela();
                        printf("Posicao Invalida\n\n", posicao);                                        
                    }else{
                        //limpaTela();
                        printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                    }
                }

                break;
            }

            case 6:{ //Ordenar e listar
            	//recebe a posicao
            	capturaPosicao(&posicao);

                ret = ordenaVetor(posicao);

                limpaTela();

                if(ret==SUCESSO){
                	
                	puts("Ordenado com Sucesso\n");                	
                	getDadosEstruturaAuxiliar(posicao);
                }

                else if(ret==POSICAO_INVALIDA)
                	puts("Posicao Invalida\n");
                
                else if(ret == ESTRUTURA_AUXILIAR_VAZIA)
                    puts("Estrutura auxiliar vazia\n");

                else
                	printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                
                break;
            }

            case 7:{ //Ordenar e listar tudo
                
                limpaTela();                

                for(posicao=1; posicao <= TAM; posicao++){
                
                    ret = ordenaVetor(posicao);
    
                    if(ret==SUCESSO){
                        
                        puts("Ordenado com Sucesso\n");
                        
                        getDadosEstruturaAuxiliar(posicao);
                    }
    
                    else if(ret==POSICAO_INVALIDA)
                        puts("Posicao Invalida\n");
    
                    else
                        printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                }        
                        
                break;
            }

            case 8:{ //Aumentar tamanho da lista
                //recebe tamanho e posicao da Estrutura Auxiliar
                capturaTamanho(&tamanho);
                capturaPosicao(&posicao);

                ret = modificarTamanhoEstruturaAuxiliar(tamanho, posicao);

                if(ret == SUCESSO){
                    limpaTela();
                    puts("Aumentado com sucesso\n");
                }else if(ret == SEM_ESTRUTURA_AUXILIAR){
                    limpaTela();
                    printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
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

            case 9:{//Criar estrutura Auxiliar

            	capturaTamanho(&tamanho);
            	capturaPosicao(&posicao);

                ret = criarEstruturaAuxiliar(tamanho, posicao);

                printf("ret: %d\n", ret);

                if(ret == SUCESSO){
                    limpaTela();
                    puts("Criado com sucesso\n");
                }else if(ret == NOVO_TAMANHO_INVALIDO){
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
