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

int excluirNumeroEmEstrutura(int valor, int posicao){

    int indiceEstruturaAuxiliar;
    //testar se existe estrutura auxiliar
    if(ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{

        //ordena o vetor auxiliar
        ordenaVetor(posicao);

        //testa se o valor informado existe na estrutura auxiliar
        indiceEstruturaAuxiliar = buscaElemento(valor, posicao);

        if(indiceEstruturaAuxiliar == VALOR_INVALIDO)
            return VALOR_INVALIDO;
        else{

            if(indiceEstruturaAuxiliar == (vetorPrincipal[posicao-1].tamanho) - 1){
                
                vetorPrincipal[posicao-1].tamanho--;
                vetorPrincipal[posicao-1].preenchido--;

                return SUCESSO;

            }else if(indiceEstruturaAuxiliar == (vetorPrincipal[posicao-1].preenchido) - 1){

                vetorPrincipal[posicao-1].tamanho--;
                vetorPrincipal[posicao-1].preenchido--;

                return SUCESSO;

            }else{

                shiftEsquerda(posicao, indiceEstruturaAuxiliar);
                vetorPrincipal[posicao-1].tamanho--;
                vetorPrincipal[posicao-1].preenchido--;

                return SUCESSO;                
            }

        }

    }
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
        printf("Estrutura Auxiliar %d nao implementada\n", posicao);

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

int ordenaVetor(int posicao){

    int i,j,aux;


    if(ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    else{
        
        if(vetorPrincipal[posicao-1].vetorAuxiliar != NULL){
        
            for(i=1; i < vetorPrincipal[posicao-1].tamanho; i++){
        
                aux = vetorPrincipal[posicao-1].vetorAuxiliar[i];
        
                for(j=i-1; j >= 0 && vetorPrincipal[posicao-1].vetorAuxiliar[j] > aux; j--){
        
                    vetorPrincipal[posicao-1].vetorAuxiliar[j+1] = vetorPrincipal[posicao-1].vetorAuxiliar[j];
                }
        
                vetorPrincipal[posicao-1].vetorAuxiliar[j+1]=aux;
            }
    
            return SUCESSO;
        }

        else
            return SEM_ESTRUTURA_AUXILIAR;
    }
}

int buscaElemento(int elemento, int posicao){

    int inicio, meio, fim;

    inicio = 0;
    fim = (vetorPrincipal[posicao-1].tamanho) - 1;

    while(inicio <= fim){

        meio = (inicio + fim)/2;

        if(vetorPrincipal[posicao-1].vetorAuxiliar[meio] == elemento)
            return meio;

        else if(vetorPrincipal[posicao-1].vetorAuxiliar[meio] < meio)
            fim=meio-1;
        
        else
            inicio=meio+1;
    }

    return VALOR_INVALIDO;

}





void capturaValor(int *valor){

    int n;

    puts("Informe o valor");
    scanf("%d", &n);

    *valor=n;
               
}

void capturaPosicao(int *posicao){

    int n;

    puts("Informe qual a Estrutura Auxiliar");
    scanf("%d", &n);

    *posicao=n;
}

void capturaTamanho(int *tamanho){

    int n;

    puts("Informe o tamanho da Estrutura Auxiliar");
    scanf("%d", &n);

    *tamanho=n;
}

void shiftEsquerda(int posicao, int posicaoElemento){

    int i;

    for(i = posicaoElemento; i < (vetorPrincipal[posicao-1].tamanho)-1; i++ )
        vetorPrincipal[posicao-1].vetorAuxiliar[i] = vetorPrincipal[posicao-1].vetorAuxiliar[i+1];

}