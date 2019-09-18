#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();
void limpaTela();
void capturaPosicao(int *posicao);
void capturaValor(int *valor);
void capturaTamanho(int *tamanho);
void captura_novoTamanho(int *novoTamanho);
void imprimeEstruturaAuxiliar(int posicao, int *vetor, int tamanho);
void imprimeEstruturaPrincipal(int *vetor, int tamanho);


int main(){
    
    int op;
    int sair = 0;
    int ret, valor=0, posicao=0, tamanho=0, novoTamanho=0;

    No *inicio = NULL;

    inicializar();

    while (!sair){
        op = menu();
        switch (op){
            case 0:{
                destruirListaEncadeadaComCabecote(inicio);
                finalizar();
                limpaTela();                
                sair =1;
                break;
            }
            case 1:{//inserir numero em estrutura
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
                
                int size = getQuantidadeElementosEstruturaAuxiliar(posicao);
                
                
                if(size == POSICAO_INVALIDA){
                    limpaTela();
                    puts("Posicao invalida\n");        
                }else if(size == ESTRUTURA_AUXILIAR_VAZIA){                
                    limpaTela();
                    puts("Estrutura auxiliar vazia\n");
                }else if(size == SEM_ESTRUTURA_AUXILIAR){                
                    limpaTela();
                    printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                }else{                    
                    int vetAux[size];
                    //define retorno
                    ret = getDadosEstruturaAuxiliar(posicao, vetAux);
                    
                    if(ret == SUCESSO){
                        limpaTela();                   
                        imprimeEstruturaAuxiliar(posicao, vetAux, size);                 
                        
                    }else if(ret == POSICAO_INVALIDA){
                       // limpaTela();
                        printf("Posicao Invalida: getdados\n\n");                                        
                    }else if(ret == ESTRUTURA_AUXILIAR_VAZIA){
                        limpaTela();
                        puts("Estrutura auxiliar vazia\n");
                    }else{
                        limpaTela();
                        printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                    }
                    
                }
                

                break;
            }
            
            case 5:{ //listar tudo                         
                
                int size = getQuantidadeTotalElementos();
                
                
                                   
                int vetAux[size];
                //define retorno
                ret = getDadosDeTodasEstruturasAuxiliares(vetAux);
                
                if(ret == SUCESSO){
                    limpaTela();                   
                    imprimeEstruturaPrincipal(vetAux, size);                 
                    
                }else{
                    limpaTela();
                    printf("Nenhuma informação armazenada\n\n");
                }
                    

                break;
            }

            case 6:{ //Ordenar e listar
            	//recebe posicao
            	capturaPosicao(&posicao);  
                
                int size = getQuantidadeElementosEstruturaAuxiliar(posicao);
                
                
                if(size == POSICAO_INVALIDA){
                    limpaTela();
                    puts("Posicao invalida\n");        
                }else if(size == ESTRUTURA_AUXILIAR_VAZIA){                
                    limpaTela();
                    puts("Estrutura auxiliar vazia\n");
                }else if(size == SEM_ESTRUTURA_AUXILIAR){                
                    limpaTela();
                    printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                }else{                    
                    int vetAux[size];
                    //define retorno
                    ret = getDadosOrdenadosEstruturaAuxiliar(posicao, vetAux);
                    
                    if(ret == SUCESSO){
                        limpaTela();                   
                        imprimeEstruturaAuxiliar(posicao, vetAux, size);                       
                    }else if(ret == POSICAO_INVALIDA){
                       // limpaTela();
                        printf("Posicao Invalida: getdados\n\n");                                        
                    }else if(ret == ESTRUTURA_AUXILIAR_VAZIA){
                        limpaTela();
                        puts("Estrutura auxiliar vazia\n");
                    }else{
                        limpaTela();
                        printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
                    }
                    
                }
                

                break;
            }

            case 7:{ //Ordenar e listar tudo
                
               int size = getQuantidadeTotalElementos();
                
                
                                   
                int vetAux[size];
                //define retorno
                ret = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetAux);
                
                if(ret == SUCESSO){
                    limpaTela();                   
                    imprimeEstruturaPrincipal(vetAux, size);                 
                    
                }else{
                    limpaTela();
                    printf("Nenhuma informação armazenada\n\n");
                }
                    

                break;
            }

            case 8:{ //Aumentar tamanho da lista
                //recebe tamanho e posicao da Estrutura Auxiliar                
                capturaPosicao(&posicao);
                captura_novoTamanho(&novoTamanho);

                ret = modificarTamanhoEstruturaAuxiliar(posicao, novoTamanho);

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

                if(ret == SUCESSO){
                    limpaTela();
                    puts("Criado com sucesso\n");
                }else if(ret == NOVO_TAMANHO_INVALIDO){
                    limpaTela();
                    puts("Quantidade de posicoes menor que 1\n");
                }else if(ret == SEM_ESPACO_DE_MEMORIA){
                    limpaTela();
                    puts("Sem espaço suficiente na memória\n");
                }else if(ret == JA_TEM_ESTRUTURA_AUXILIAR){
                    limpaTela();
                    printf("A Estrutura auxiliar %d ja existe\n\n", posicao);
                }else{
                    limpaTela();
                    puts("Posicao invalida\n");
                }
                break;
            }

            case 10:{//Criar Lista Encadeada

                inicio = montarListaEncadeadaComCabecote();

                if(inicio == NULL){
                    limpaTela();
                    puts("Nenhuma informação armazenada\n");
                }else{
                    limpaTela();                    
                    puts("Criado com sucesso\n");
                }
                break;
            }

            case 11:{//EXIBIR LISTA ENCADEADA

                int size = getQuantidadeTotalElementos();              
                
                                   
                int vetAux[size];
                //define retorno
                if(inicio != NULL){
                    getDadosListaEncadeadaComCabecote(inicio, vetAux);
                    limpaTela();                
                    imprimeEstruturaPrincipal(vetAux, size);
                }else{
                    limpaTela();
                    puts("Lista Encadeada nao existente\n");
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

int menu(){
    int op;


    printf("Digite a opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir numero em estrutura\n");
    printf("2 - Excluir no fim da estrutura\n");
    printf("3 - Excluir numero especifico na estrutura\n");
    printf("4 - Listar\n");
    printf("5 - Listar Tudo\n");
    printf("6 - Ordenar e listar\n");
    printf("7 - Ordenar e listar tudo\n");
    printf("8 - Modificar tamanho da Estrutura Auxiliar\n");
    printf("9 - Criar Estrutura Auxiliar\n");
    printf("10 - Criar Lista Encadeada\n");
    printf("11 - Exibir Lista Encadeada\n");
    scanf("%d", &op);
    return op;
}

void limpaTela(){
    system("clear");
}

void capturaValor(int *valor){

    int n;

    puts("Informe o valor");
    scanf("%d", &n);

    *valor=n;
               
}

void capturaPosicao(int *posicao){

    int n;

    puts("Informe qual a posicao da Estrutura Auxiliar");
    scanf("%d", &n);

    *posicao=n;
}

void capturaTamanho(int *tamanho){

    int n;

    puts("Informe a quantidade de posicoes na Estrutura Auxiliar");
    scanf("%d", &n);

    *tamanho=n;
}

void captura_novoTamanho(int *novoTamanho){

    int n;

    puts("Informe o numero de posições a ser somado à estrutura auxiliar");
    scanf("%d", &n);

    *novoTamanho=n;
}

void imprimeEstruturaAuxiliar(int posicao, int *vetor, int tamanho){

    printf("Estrutura Auxiliar %d:\n", posicao);

   
    puts("Informacoes armazenadas: \n");
    for(int i = 0 ; i < tamanho ; i++)
        printf("Posicao %d: %d\n", i+1, vetor[i]); 

    puts("");
}

void imprimeEstruturaPrincipal(int *vetor, int tamanho){

    puts("Informacoes armazenadas: \n");
    for(int i = 0 ; i < tamanho ; i++)
        printf("Posicao %d: %d\n", i+1, vetor[i]); 

    puts("");
}
