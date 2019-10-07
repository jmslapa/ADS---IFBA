#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "palavras.h"

void limpaTela();
int tamanhoPalavra();

int main(void){
    
    int posicao = 0, wordLength = 0, retorno, count = 0;
    
    limpaTela();
    inicializa();   
        
    //wordLength = tamanhoPalavra();
    puts("Informe o tamanho da palavra");
    scanf("%d", &wordLength);
    
    for( posicao = 0 ; posicao < CONT ; posicao++ ){
        
        char word[wordLength+1];

        //printf("wordLength: %d\n", wordLength);       
        
        switch(wordLength){
            
            case 2:{//palavra com 2 letras

                    retorno = duasLetras(posicao, wordLength, word);        //printf("retorno: %d\n", retorno);
                  
                    if(retorno != SUCESSO){
                        posicao--;
                    }else{
                        puts(word);
                        
                        count = count + comparaWord(word, 2);                        
                    }
                    

                break;
            }

            case 3:{//palavra com 3 letras 

                    retorno = tresLetras(posicao, wordLength, word);        //printf("retorno: %d\n", retorno);

                    if(retorno != SUCESSO)
                        posicao--;
                    else{
                        puts(word);
                        
                        count = count + comparaWord(word, 3);
                    }                       

                break;
            }

            case 4:{//palavra com 4 letras 

                    retorno = quatroLetras(posicao, wordLength, word);        //printf("retorno: %d\n", retorno);

                    if(retorno != SUCESSO)
                        posicao--;
                    else{
                        puts(word);
                        
                        count = count + comparaWord(word, 4);
                    }                      

                break;
            }
        }
        
    }  
    
    printf("Margem de acerto: %d/%d\n", count, CONT);
    
    finaliza();

    return 0;      
}

int tamanhoPalavra(){

    int size = 0;

    while(size < 2){

        srand(time(NULL));
    
//         pause();
    
        size = rand()%4;
    }

    return size;
}

void limpaTela(){
    system("clear");
}
