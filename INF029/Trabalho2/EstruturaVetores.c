#include <stdio.h> 
#include <stdlib.h>


#include "EstruturaVetores.h"

typedef struct{
    int tamanho;
    int preenchido;
    int *vetorAuxiliar;
}lista;

lista vetorPrincipal[TAM];


void atribuiNULL(){

    int i;

    for(i=0; i<TAM; i++){

            vetorPrincipal[i].vetorAuxiliar = NULL;
            vetorPrincipal[i].tamanho = 0;
            vetorPrincipal[i].preenchido = 0;
    }
}


int criarEstruturaAuxiliar(int tamanho, int posicao){
    
    int retorno = 0;
    //testar se existe a estrutura auxiliar
    

    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    // se posição é um valor válido {entre 1 e 10}
    if (ehPosicaoValida(posicao)==POSICAO_INVALIDA)
            retorno = POSICAO_INVALIDA;
    else{
        //testar se o tamanho informado é menor que o limite
        if(tamanho>TAM_MAX_ESTRUTURA_AUXILIAR)
            retorno = SEM_ESPACO_DE_MEMORIA;
        else{
            //testar se o tamanho não é menor que 1
            if(tamanho<1)
                retorno = TAMANHO_INVALIDO;
            else{
                // deu tudo certo, crie
                vetorPrincipal[posicao-1].vetorAuxiliar = (int*) malloc(tamanho * sizeof(int));
                vetorPrincipal[posicao-1].tamanho = tamanho;
                
                retorno = SUCESSO;
            }
        }
    }

    return retorno;

}

int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;

        //testar se a posicao eh valida
        if (ehPosicaoValida(posicao)==POSICAO_INVALIDA)
            retorno = POSICAO_INVALIDA;
        else{
            // testar se existe a estrutura auxiliar
            if (vetorPrincipal[posicao-1].vetorAuxiliar!=NULL){
                //testar se tem espaço
                if (vetorPrincipal[posicao-1].preenchido < vetorPrincipal[posicao-1].tamanho){
                  //insere
                  vetorPrincipal[posicao-1].vetorAuxiliar[vetorPrincipal[posicao-1].preenchido] = valor;
                  //incrementa a quantidade de posições preenchidas
                  vetorPrincipal[posicao-1].preenchido++;
                  //define o retorno como sucesso
                  retorno = SUCESSO;
                }else{
                  retorno = SEM_ESPACO;
                }
            }else{
                retorno = SEM_ESTRUTURA_AUXILIAR;
            }
        }


    return retorno;

}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;

}

int listaEstruturaAuxiliar(int posicao){
    
    int retorno = 0;

    if (vetorPrincipal[posicao-1].vetorAuxiliar == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        //print    
        printf("Estrutura Auxiliar %d:\n", posicao);
        printf("Tamanho: %d\n", vetorPrincipal[posicao-1].tamanho);
        printf("Posicoes disponiveis: %d\n", vetorPrincipal[posicao-1].tamanho - vetorPrincipal[posicao-1].preenchido);
        puts("Informacoes armazenadas: \n");

        for(int i = 0; i < vetorPrincipal[posicao-1].preenchido; i++)
            printf("Posicao %d: %d\n", i+1, vetorPrincipal[posicao-1].vetorAuxiliar[i]);

        retorno = SUCESSO;
    }   

    return retorno;

}

void limpaTela(){
    system("clear");
}

void quebraPagina(){
    printf("*\n*\n");
}

void liberaMemoria(){
    for(int i=0; i < TAM; i++)
        free(vetorPrincipal[i].vetorAuxiliar);
}
