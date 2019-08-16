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

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){
    
    int retorno = 0;
    //testar se existe a estrutura auxiliar
    
    if(vetorPrincipal[posicao-1].vetorAuxiliar != NULL)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
   
    else{
        //testar se posição é um valor válido {entre 1 e 10}
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
    }

    return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    int indiceEstruturaAuxiliar;
    
    //testa se a posição é valida    
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{
        //se a estrutura existe
        if(vetorPrincipal[posicao-1].vetorAuxiliar == NULL)
            return SEM_ESTRUTURA_AUXILIAR;
        
        else{
                
            //testa se a estrutura está vazia
            if(vetorPrincipal[posicao-1].preenchido < 1)
                return ESTRUTURA_AUXILIAR_VAZIA;
            
            else{                    
                
                vetorPrincipal[posicao-1].preenchido--;

                return SUCESSO;  
            }
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliarD

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){

    int indiceEstruturaAuxiliar;
    
    //testa se a posição é valida    
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{
        //se a estrutura existe
        if(vetorPrincipal[posicao-1].vetorAuxiliar == NULL)
            return SEM_ESTRUTURA_AUXILIAR;
        
        else{
                
            //testa se a estrutura está vazia
            if(vetorPrincipal[posicao-1].preenchido < 1)
                return ESTRUTURA_AUXILIAR_VAZIA;
            
            else{                    
                
                indiceEstruturaAuxiliar = buscaElemento(valor, posicao);
                
                //testa se o valor informado existe na estrutura auxiliar
                if(indiceEstruturaAuxiliar == NUMERO_INEXISTENTE)
                    return NUMERO_INEXISTENTE;

                else{

                    shiftEsquerda(posicao, indiceEstruturaAuxiliar);
                    
                    vetorPrincipal[posicao-1].preenchido--;

                    return SUCESSO;                
                }
            }
        }
    }
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
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

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho'

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
*/
int modificarTamanhoEstruturaAuxiliar(int tamanho, int posicao){

    //testa se a posicao eh valida
    if(ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{
        //testa se a estrutura auxiliar existe
        if(vetorPrincipal[posicao-1].vetorAuxiliar == NULL)
            return SEM_ESTRUTURA_AUXILIAR;
        else{
            //testa se o tamanho é um numero maior que 0
            if(vetorPrincipal[posicao-1].tamanho + tamanho <= vetorPrincipal[posicao-1].tamanho)
                return NOVO_TAMANHO_INVALIDO;
            else{
                
                //testa se o tamanho da Estrutura Auxiliar não vai ultrapassar o tamanho máximo de posições
                if(vetorPrincipal[posicao-1].tamanho + tamanho > TAM_MAX_ESTRUTURA_AUXILIAR)
                    return SEM_ESPACO_DE_MEMORIA;

                //deu certo, realiza operação
                else{

                    vetorPrincipal[posicao-1].vetorAuxiliar = (int*) realloc(vetorPrincipal[posicao-1].vetorAuxiliar, sizeof(int) * tamanho);

                    vetorPrincipal[posicao-1].tamanho += tamanho; 
                    

                    return SUCESSO;           
                }        
            }
        }
    }

}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
   
    if (posicao > 0 && posicao <=10){
        return SUCESSO;
    }else
        return POSICAO_INVALIDA;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao){
    
    int retorno = 0;
    
    //testa se a posicao é valida
    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;
   
    else{
        
        if (vetorPrincipal[posicao-1].vetorAuxiliar == NULL){      
            //printf("Estrutura auxiliar %d nao implementada\n\n", posicao);
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }else{
            //print    
            printf("Estrutura Auxiliar %d:\n", posicao);
            printf("Tamanho: %d\n", vetorPrincipal[posicao-1].tamanho);
            printf("Posicoes disponiveis: %d\n", vetorPrincipal[posicao-1].tamanho - vetorPrincipal[posicao-1].preenchido);

            if(vetorPrincipal[posicao-1].preenchido != 0){
                puts("Informacoes armazenadas: \n");
        
                for(int i = 0; i < vetorPrincipal[posicao-1].preenchido; i++)
                    printf("Posicao %d: %d\n", i+1, vetorPrincipal[posicao-1].vetorAuxiliar[i]);
            }else
                puts("Sem informações armazenadas");

            puts("");

            retorno = SUCESSO;
        }
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
    for(int i=0; i < TAM; i++){
        
        if(vetorPrincipal[i].vetorAuxiliar!=NULL)
            free(vetorPrincipal[i].vetorAuxiliar);
    }
}

int ordenaVetor(int posicao){

    int i,j,aux;

    //testa se a posicao eh valida
    if(ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{
        
        //testa se a estrutura auxiliar existe
        if(vetorPrincipal[posicao-1].vetorAuxiliar != NULL){
            
            //testa se a estrutura auxiliar está vazia
            if(vetorPrincipal[posicao-1].preenchido > 0){
            
                for(i=1; i < vetorPrincipal[posicao-1].preenchido; i++){

                    aux=vetorPrincipal[posicao-1].vetorAuxiliar[i];

                    for(j=i-1; (vetorPrincipal[posicao-1].vetorAuxiliar[j])>=0 && (vetorPrincipal[posicao-1].vetorAuxiliar[j])>aux; j--){

                        vetorPrincipal[posicao-1].vetorAuxiliar[j+1]=vetorPrincipal[posicao-1].vetorAuxiliar[j];
                    }

                    vetorPrincipal[posicao-1].vetorAuxiliar[j+1]=aux;
                }
        
                return SUCESSO;
            }
            
            else
                return ESTRUTURA_AUXILIAR_VAZIA;
        }
        
        else
            return POSICAO_INVALIDA;
        
    }
}

int buscaElemento(int elemento, int posicao){

    int i, indice;

    for(i=0; i < vetorPrincipal[posicao-1].preenchido; i++){

        if(vetorPrincipal[posicao-1].vetorAuxiliar[i] == elemento){
            return i;
        }
    }

    return NUMERO_INEXISTENTE;
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

void shiftEsquerda(int posicao, int posicaoElemento){

    int i;

    for(i = posicaoElemento; i < (vetorPrincipal[posicao-1].tamanho)-1; i++ )
        vetorPrincipal[posicao-1].vetorAuxiliar[i] = vetorPrincipal[posicao-1].vetorAuxiliar[i+1];

}
