#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define CONT 10


char getConsoante(char *vog);
char getVogal(char *con);
int buscaString(char *str1[], char *str2, int size);
void inicializa(char *vetor[]);


int main(void){
    
    char consoantes[18] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z'};
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
    char *storeWord[CONT];
    int i = 0, wordLength = 0, z = 0, k = 0 , aux;
    
    system("clear");
    
    inicializa(storeWord);    
        
    
    for( z = 0 ; z < CONT ; z++ ){
        
        system("sleep 1");
        
        srand(time(NULL));
        /*
        while(wordLength < 2){
            
            wordLength = rand()%5;
        }
        */
        
        wordLength = 2;
        
        char word[wordLength+1];
        
        storeWord[z] = (char*) malloc( (wordLength+1) * sizeof(char) );
        
        
        switch(wordLength){
            
            case 2:{//palavra com 2 letras
                
                for( i = 0 ; i < wordLength ; i+=2 ){
                    
                    while(word[i] != 'h' && word[i] != 'j' && word[i] != 'l' && word[i] != 'h' && word[i] != 'p' && word[i] != 'r' && word[i] != 's' && word[i] != 't' && word[i] != 'v')
                        word[i] = getConsoante(consoantes);
                    
                    switch(word[i]){
                        
                        case 'h':                        
                            word[i+1] = 'a';
                        break;
                        
                        case 'j':
                            word[i+1] = 'a';
                        break;
                        
                        case 'l':
                            while(word[i+1] != 'a' && word[i+1] != 'e' && word[i+1] != 'i')
                                word[i+1] = getVogal(vogais);
                        break;
                        
                        case 'n':
                            while(word[i+1] != 'a' && word[i+1] != 'o' && word[i+1] != 'u')
                                word[i+1] = getVogal(vogais);
                        break;
                        
                        case 'p':
                            while(word[i+1] != 'a' && word[i+1] != 'e' && word[i+1] != 'o')
                                word[i+1] = getVogal(vogais);
                        break;
                        
                        case 'r':
                            while(word[i+1] != 'e' && word[i+1] != 'i')
                                word[i+1] = getVogal(vogais);
                        break;
                        
                        case 's':
                                word[i+1] = 'o';
                        break;
                        
                        case 't':
                            while(word[i+1] != 'i' && word[i+1] != 'u')
                                word[i+1] = getVogal(vogais);
                        break;
                        
                        case 'v':
                            while(word[i+1] != 'a' && word[i+1] != 'i')
                                word[i+1] = getVogal(vogais);
                        break;
                    }                                    
                            
                }
                word[wordLength] = '\0';
                
                aux = buscaString(storeWord, word, 2);                
                
                if(aux == 0){
                    strcpy( storeWord[z], word );
                    puts(storeWord[z]);
                }else
                    z--;
                
                break;
            }
            
        }
        
    }
    
    //free(storeWord);
    
    return 0;      
}


char getConsoante(char *con){
    
    int i;
    
    system("sleep 1");
    
    srand(time(NULL));
    
    i = rand()%18;
    
    return con[i];
}

char getVogal(char *vog){
    
    int i;
    
    system("sleep 1");
    
    srand(time(NULL));
    
    i = rand()%5;
    
    return vog[i];
}

int buscaString(char *vetorStr[], char *str, int size){
    
    int i = 0, j = 0, count = 0;
    int aux;
    
    for( i = 0 ; i < CONT ; i++ ){        
        
        if(vetorStr[i] == NULL){
           continue;
        }else{
            aux = strcmp(vetorStr[i], str);
            if(aux == 0)
                count++;
        }
                                
    }
    return count;    
}

void inicializa(char *vetor[]){
    
    int i=0;
    
    for(i=0; i<CONT; i++){
        vetor[i] = NULL;
    }
}
