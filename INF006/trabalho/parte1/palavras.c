#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include "palavras.h"


char consoantes[18] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z'};
char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
char *storeWord[CONT];

int duasLetras(int posicao, int wordLength, char word[]){

	int i = 0, aux = 0, tipo = 0;

	tipo = sorteiaTipo();	

	if(tipo == CONSOANTE){

		for( i = 0 ; i < wordLength ; i+=2 ){
	            
	        while(word[i] != 'h' && word[i] != 'j' && word[i] != 'l' && word[i] != 'h' && word[i] != 'p' && word[i] != 'r' && word[i] != 's' && word[i] != 't' && word[i] != 'v')
	            word[i] = getConsoante();
	        
	        switch(word[i]){
	            
	            case 'h':                        
	                word[i+1] = 'a';
	            break;
	            
	            case 'j':
	                word[i+1] = 'a';
	            break;
	            
	            case 'l':
	                while(word[i+1] != 'a' && word[i+1] != 'e' && word[i+1] != 'i')
	                    word[i+1] = getVogal();
	            break;
	            
	            case 'n':
	                while(word[i+1] != 'a' && word[i+1] != 'o' && word[i+1] != 'u')
	                    word[i+1] = getVogal();
	            break;
	            
	            case 'p':
	                while(word[i+1] != 'a' && word[i+1] != 'e' && word[i+1] != 'o')
	                    word[i+1] = getVogal();
	            break;
	            
	            case 'r':
	                while(word[i+1] != 'e' && word[i+1] != 'i')
	                    word[i+1] = getVogal();
	            break;
	            
	            case 's':
	                    word[i+1] = 'o';
	            break;
	            
	            case 't':
	                while(word[i+1] != 'i' && word[i+1] != 'u')
	                    word[i+1] = getVogal();
	            break;
	            
	            case 'v':
	                while(word[i+1] != 'a' && word[i+1] != 'i')
	                    word[i+1] = getVogal();
	            break;
	        }                            	                
	    }

	}else{

		for( i = 0 ; i < wordLength ; i+=2 ){
	            
	        
	        word[i] = getVogal();
	        
	        switch(word[i]){
	            
	            case 'a':                        
	                while(word[i+1] != 'h' && word[i+1] != 'r' && word[i+1] != 's')
	                    word[i+1] = getConsoante();
	            break;
	            
	            case 'e':
	                word[i+1] = 'm';
	            break;
	            
	            case 'i':
	                word[i+1] = 'r';
	            break;
	            
	            case 'o':
	                while(word[i+1] != 'h' && word[i+1] != 's')
	                    word[i+1] = getConsoante();
	            break;
	            
	            case 'u':
	                word[i+1] = 'm';
	            break;
	        }                            	                
	    }	    
	}

    word[wordLength] = '\0';
    
    aux = buscaString(storeWord, word, wordLength);		//printf("aux: %d\n", aux);		if(storeWord[posicao]==NULL)	puts("NULL");          
    	
    if(aux == 0){		//puts(word);
        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
        strcpy(storeWord[posicao], word);		                    
        return SUCESSO;
    }else
        return EXISTING_WORD;
}


char getConsoante(){
    
    int i;
    
    pause();
    
    srand(time(NULL));
    
    i = rand()%18;
    
    return consoantes[i];
}

char getVogal(){
    
    int i;
    
    pause();
    
    srand(time(NULL));
    
    i = rand()%5;
    
    return vogais[i];
}

int buscaString(char *vetorStr[], char str[], int size){
    
    int i = 0, j = 0, count = 0;
    int aux;
    
    for( i = 0 ; i < CONT ; i++ ){		//printf("i: %d\n", i);      
        
        if(vetorStr[i] == NULL){		//printf("vetorStr[%d]: null\n", i);
           continue;
        }else{
            aux = strcmp(vetorStr[i], str);
            if(aux == 0)
                count++;
        }
                                
    }

    //printf("count: %d\n", count);

    return count;    
}

int sorteiaTipo(){

	int tipo, i, tipos[2] = {CONSOANTE, VOGAL};

	pause();
    
    srand(time(NULL));

    i = rand()%2;

    tipo = tipos[i];

    return  tipo;

}

void inicializa(){
    
    int i=0;
    
    for(i=0; i<CONT; i++){
        storeWord[i] = NULL;
    }
}

void finaliza(){
    
    int i=0;

    for(i=0; i<CONT; i++){
        free(storeWord[i]);
    }
}

void pause(){

	//system("sleep 1");

}