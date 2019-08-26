#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "palavras.h"

void limpaTela();

int main(void){
    
    int posicao = 0, wordLength, retorno;
    
    limpaTela();
    
    inicializa();   
        
    
    for( posicao = 0 ; posicao < CONT ; posicao++ ){
        
        pause();
        
        srand(time(NULL));

        /*
        while(wordLength < 2){
            
            wordLength = rand()%5;
        }
        */
        
        wordLength = 2;
        
        char word[wordLength+1];       
        
        switch(wordLength){
            
            case 2:{//palavra com 2 letras

                    retorno = duasLetras(posicao, wordLength, word);        //printf("retorno: %d\n", retorno);

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

void limpaTela(){
    system("clear");
}
