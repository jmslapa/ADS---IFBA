#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "palavras.h"

void limpaTela();
int tamanhoPalavra();

int main(void){
    
    int posicao = 0, wordLength = 0, retorno;
    
    limpaTela();
    
    inicializa();   
        
    
    for( posicao = 0 ; posicao < CONT ; posicao++ ){

        wordLength = tamanhoPalavra();
        
        char word[wordLength+1];

        //printf("wordLength: %d\n", wordLength);       
        
        switch(wordLength){
            
            case 2:{//palavra com 2 letras

                    retorno = duasLetras(posicao, wordLength, word);        //printf("retorno: %d\n", retorno);

                    if(retorno != SUCESSO)
                        posicao--;
                    else
                        puts(word);                        

                break;
            }

            case 3:{//palavra com 3 letras 

                    retorno = tresLetras(posicao, wordLength, word);        //printf("retorno: %d\n", retorno);

                    if(retorno != SUCESSO)
                        posicao--;
                    else
                        puts(word);                        

                break;
            }

            
        }
        
    }
    
    finaliza();

    return 0;      
}

int tamanhoPalavra(){

    int size = 0;

    while(size < 2){

        srand(time(NULL));
    
        pause();
    
        size = rand()%4;
    }

    return size;
}

void limpaTela(){
    system("clear");
}
