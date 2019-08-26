#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include "palavras.h"


char consoantes[18] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z'};
char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
char *storeWord[CONT];

int duasLetras(int posicao, int wordLength, char word[]){

	int i = 0, aux = 0, tipo = 0, retorno = 0;

	while(retorno != SUCESSO){

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
	        retorno = SUCESSO;
	    }else
	        retorno = EXISTING_WORD;
    }

    return retorno;
}

int tresLetras(int posicao, int wordLength, char word[]){

	int retorno = 0;

	int modoConstrucao = -1;
	int monossilaba = 0;
	int dissilaba = 1;
	int opcoesConstrucao[2] = {monossilaba, dissilaba};

	modoConstrucao = defineConstrucao(opcoesConstrucao, 2);
	//modoConstrucao = dissilaba;
	if(modoConstrucao == dissilaba){

		int aux, a1, a2;
		int combinacaoTipos[wordLength];
		
		char silaba_1;
		char silaba_2[wordLength-1];

		while(retorno != SUCESSO){		//puts("dissilaba");

			//define silaba 1
			silaba_1 = getVogal();
			//define silaba 2
			formaSilabaDuasLetras((wordLength-1) , silaba_2, combinacaoTipos);
			silaba_2[wordLength-1] = '\0';		//printf("silaba 2: %s\n", silaba_2);

			a1 = combinacaoTipos[0];
			a2 = combinacaoTipos[1];
			//junta as 2 silabas
			word[0] = silaba_1;
			word[1] = '\0';	//puts(word);
			strcat(word, silaba_2);	//puts(word);
			word[wordLength] = '\0';
			//verifica se palavra já existe;
			aux = buscaString(storeWord, word, wordLength);		//printf("aux: %d\n", aux);		if(storeWord[posicao]==NULL)	puts("NULL");

			//puts("passou a atribuicao do aux");          
	    	
		    if(aux == 0){		//puts(word);
		    	//puts("entrou no aux==0");
		    	//printf("a1: %d\n", a1);
		    	//printf("a2: %d\n", a2);
		        if(a1 == CONSOANTE && a2 == VOGAL){
		        	//puts("entrou no C-V");
		        	if(word[1] != 'q'){
		        		storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
				        strcpy(storeWord[posicao], word);		                    
				        retorno = SUCESSO;
				    }else
				    	retorno = PALAVRA_INVALIDA;
		    	}else
		    		retorno PALAVRA_INVALIDA;
		    }else
		        retorno = EXISTING_WORD;

		     //printf("retorno: %d\n", retorno);
		}	

	}else{

		int aux, a1, a2, a3;
		int combinacaoTipos[wordLength];

		while(retorno != SUCESSO){

			formaSilabaTresLetras(wordLength, word, combinacaoTipos);

			word[wordLength] = '\0';

			a1 = combinacaoTipos[0];
			a2 = combinacaoTipos[1];
			a3 = combinacaoTipos[2];
		    
		    aux = buscaString(storeWord, word, wordLength);		//printf("aux: %d\n", aux);		if(storeWord[posicao]==NULL)	puts("NULL");          
		    	
		    if(aux == 0){		//puts(word);

		    	if(a1 == CONSOANTE && a2 == VOGAL && a3 == VOGAL){

		    		if(word[0] == 'q'){
		    			if(word[2] == 'e'){
			    			storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
					        strcpy(storeWord[posicao], word);		                    
					        retorno = SUCESSO;			        
					    }else
					    	retorno = PALAVRA_INVALIDA;			    
		    		}else if(word[0] != 'g' && word[0] != 'h' && word[0] != 'j' && word[0] != 'x' && word[0] != 'z'){
		    			storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
				        strcpy(storeWord[posicao], word);		                    
				        retorno = SUCESSO;
		    		}
		    		else
		    			retorno = PALAVRA_INVALIDA;
		    	}else if(a1 == CONSOANTE && a2 == VOGAL && a3 == CONSOANTE){

		    		if(word[0] != 'h' && word[0] != 'j' && word[0] != 'r' && word[0] != 'c' && word[0] != 'x' && word[0] != 'z'){
		    			
		    			if(word[2] != 'b' && word[2] != 'c' && word[2] != 'd' && word[2] != 'f' && word[2] != 'g' && word[2] != 'h' && word[2] != 'j' && word[2] != 'n' && word[2] != 'p' && word[2] != 't' && word[2] != 'v'){
			    			
			    			storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
					        strcpy(storeWord[posicao], word);		                    
					        retorno = SUCESSO;
				    	}
				    }else
		    			retorno = PALAVRA_INVALIDA;
		    	}else
		    		retorno = PALAVRA_INVALIDA;		   
		    }else
		    	retorno = EXISTING_WORD;
	    }
	}

    return retorno;
}

void formaSilabaDuasLetras(int size, char silaba[], int combinacaoTipos[]){

	int a1, a2, sair, aux;

	srand(time(NULL));

	sair = 0;

	while(!sair){

		composicaoSilaba(size, silaba);

		a1 = silaba[0];
		a2 = silaba[1];

		//printf("silaba_2[0]: %d\n", a1);
		//printf("silaba_2[1]: %d\n", a2);

		if(a1 == CONSOANTE && a2 == VOGAL){

			silaba[0] = getConsoante();
			silaba[1] = getVogal();

			sair = 1;

		}else if(a1 == VOGAL && a2 == CONSOANTE){

			silaba[0] = getVogal();
			silaba[1] = getConsoante();

		}else
			continue;
	}

	combinacaoTipos[0] = a1;
	combinacaoTipos[1] = a2; 
}

void formaSilabaTresLetras(int size, char silaba[], int combinacaoTipos[]){

	int a1, a2, a3, sair, aux;

	srand(time(NULL));

	sair = 0; 

	while(!sair){

		composicaoSilaba(size, silaba);

		a1 = silaba[0];
		a2 = silaba[1];
		a3 = silaba[2];
		
		if(a1 == CONSOANTE && a2 == VOGAL && a3 == VOGAL){		//puts("CVV");
			//define primeira letra
			do{	
				silaba[0] = getConsoante();
			}while(silaba[0] == 'h');		
			//testa se a primeira letra é q ou g
			if(silaba[0] == 'q' || silaba[0] == 'g'){
				//define segunda letra
				silaba[1] = 'u';
				//espera 1 segundo para modificar semente da função rand()
				pause();
				//define teceira letra
				while(silaba[2] != 'a' && silaba[2] != 'e' && silaba[2] != 'i' && silaba[2] != 'o')
					silaba[2] = getVogal();
			}else{
				//define segunda letra
				silaba[1] = getVogal();
				//espera 1 segundo para modificar semente da função rand()
				pause();
				//define teceira letra
				do{	
				silaba[2] = getVogal();
				}while (silaba[2] == silaba[1]);
			}
			sair = 1;

		}else if(a1 == CONSOANTE && a2 == CONSOANTE && a3 == VOGAL){		//puts("CCV");

			//define primeira letra
			while(silaba[0] != 'b' && silaba[0] != 'c' && silaba[0] != 'd' && silaba[0] != 'f' && silaba[0] != 'g' && silaba[0] != 'p' && silaba[0] != 't' && silaba[0] != 'v')
				silaba[0] = getConsoante();
			//define segunda letra
			aux = rand()%2; //printf("aux: %d\n", aux);
			if(aux == 0)
				 silaba[1] = 'r';
			else
				silaba[1] = 'l';
			//define terceira letra
			silaba[2] = getVogal();

			sair = 1;

		}else if(a1 == CONSOANTE && a2 == VOGAL && a3 == CONSOANTE){		//puts("CVC");
			//define primeira letra
			do{	
				silaba[0] = getConsoante();
			}while(silaba[0] == 'q');			
			//define segunda letra
			silaba[1] = getVogal();
			//espera 1 segundo para modificar semente da função rand()
			//pause();
			//define teceira letra
			do{	
				silaba[2] = getConsoante();
			}while (silaba[2] == silaba[0]);

			sair = 1;	

		}else
			continue;
	}
	combinacaoTipos[0] = a1;
	combinacaoTipos[1] = a2;
	combinacaoTipos[2] = a3;
	//puts("formaSilabaTresLetras completa");
}

char getConsoante(){
    
    int i;
    
    srand(time(NULL));
    
    i = rand()%18;
    
    return consoantes[i];
}

char getVogal(){
    
    int i;
    
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

	int tipo, i, tipos[2];

	tipos[0] = CONSOANTE;
	tipos[1] = VOGAL;

	//printf("tipos[0]: %d\n", tipos[0]);
	//printf("tipos[1]: %d\n", tipos[1]);

	pause();
    
    srand(time(NULL));

    i = rand()%2;    

    tipo = tipos[i];		//printf("i: %d\n", i); printf("tipo: %d\n", tipo); puts("sorteiaTipo completa");

    return  tipo;

}

int defineConstrucao(int opcoes[], int size){

	int i, modoConstrucao;

	srand(time(NULL));

	i = rand()%size;

	modoConstrucao = opcoes[i];

	return modoConstrucao;
}

void composicaoSilaba(int size, char silaba[]){

	int tipo;

	for(int i = 0 ; i < size ; i++ ){
		//pause();
		tipo = sorteiaTipo();
		//printf("tipo2: %d\n", tipo);

		if(tipo == CONSOANTE)
			silaba[i] = CONSOANTE;
		else
			silaba[i] = VOGAL;

		//printf("silaba[%d]: %d\n", i, silaba[i]);
	}

	silaba[size] = '\0';

	//puts("composicaoSilaba completa");
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

	system("sleep 1");

}