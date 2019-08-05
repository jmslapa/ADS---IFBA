#include <stdio.h> 
#include <stdlib.h>
#define TAM 10


#include "EstruturaVetores.h"

typedef struct{
    int tamanho;
    int ocupado;
    int *elemento;
}lista;

int *vetorPrincipal[10];


void atribuiNULL(){
    for(int i=0; i<TAM; i++)
        vetorPrincipal[i] = NULL;
}


int criarEstruturaAuxiliar(int tamanho, int posicao){
    
    int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    // se posição é um valor válido {entre 1 e 10}
    retorno = POSICAO_INVALIDA;
    // o tamanho ser muito grande
    retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    retorno = SUCESSO;

    return retorno;

}

int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;

        //testar se a posicao eh valida
        if (ehPosicaoValida(posicao)==POSICAO_INVALIDA)
            retorno = POSICAO_INVALIDA;
        else{
            // testar se existe a estrutura auxiliar
            if (vetorPrincipal[posicao-1]!=NULL){
                //testar se tem espaço
                if (vetorPrincipal[posicao-1].ocupado < vetorPrincipal[posicao-1].tamanho){
                  //insere
                  vetorPrincipal[posicao-1].elemento[vetorPrincipal[posicao-1].ocupado] = valor;
                  retorno = SUCESSO;  
                }else{
                  retorno = SEM_ESPACO;
                }
            }else{
                retorno = SEM_ESTRUTURA_AUXILIAR;
            }
        }  

    else
        retorno = VALOR_INVALIDO;


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

    if (ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }else{
        //print
        retorno = SUCESSO;
    }   

    return retorno;

}

int temEspaco(posicao){
    
}

