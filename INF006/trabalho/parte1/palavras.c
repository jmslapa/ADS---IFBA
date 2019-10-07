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
	//modoConstrucao = monossilaba;
	if(modoConstrucao == dissilaba){

		int aux, a1, a2;
		int combinacaoTipos[wordLength];
		
		char silaba_1;
		char silaba_2[3];

		while(retorno != SUCESSO){		//puts("dissilaba");

			//define silaba 1
			silaba_1 = getVogal();
			//define silaba 2
			formaSilabaDuasLetras(silaba_2, combinacaoTipos);
			silaba_2[2] = '\0';		//printf("silaba 2: %s\n", silaba_2);

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
                    if(word[0] == 'a'){
                        if(word[2] == 'a'){
                            if(word[1] == 'n' || word[1] == 'b' || word[1] == 'j' || word[1] == 'l' || word[1] == 'm' || word[1] == 'r' || word[1] == 's' || word[1] == 't'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'e'){
                            if(word[1] == 'g' || word[1] == 'm' || word[1] == 'r' || word[1] == 't' || word[1] == 'v'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'i'){
                            if(word[1] == 'g' || word[1] == 'l'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'o'){
                            if(word[1] == 'j' || word[1] == 'm' || word[1] == 'n' || word[1] == 'r' || word[1] == 't'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }
                    }else if(word[0] == 'e'){
                        if(word[2] == 'a'){
                            if(word[1] == 'm' || word[1] == 'v' || word[1] == 'l' || word[1] == 'r'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'o'){
                            if(word[1] == 'c' || word[1] == 'g' || word[1] == 'l'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'e'){
                            if(word[1] == 'l'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }
                    }else if(word[0] == 'i'){
                        if(word[2] == 'a'){
                            if(word[1] == 'r' || word[1] == 'd'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'e'){
                            if(word[1] == 'd'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'o'){
                            if(word[1] == 'd'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }
                    }else if(word[0] == 'o'){
                        if(word[2] == 'a'){
                            if(word[1] == 'b' || word[1] == 'c' || word[1] == 'p' || word[1] == 'r'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'e'){
                            if(word[1] == 'r'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'o'){
                            if(word[1] == 'c' || word[1] == 'r'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }
                    }else if(word[0] == 'u'){
                        if(word[2] == 'a'){
                            if(word[1] == 'm' || word[1] == 'n' || word[1] == 's' || word[1] == 'v'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'e'){
                            if(word[1] == 's' || word[1] == 'n'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'i'){
                            if(word[1] == 'n'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }else if(word[2] == 'o'){
                            if(word[1] == 'n'){
                                storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                strcpy(storeWord[posicao], word);		                    
                                retorno = SUCESSO;
                            }
                        }
                    }
		    	}else
		    		retorno PALAVRA_INVALIDA;
		    }else
		        retorno = EXISTING_WORD;
		}	

    }else{

		int aux, a1, a2, a3;
		int combinacaoTipos[wordLength];

		while(retorno != SUCESSO){

			formaSilabaTresLetras(word, combinacaoTipos);

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
int quatroLetras(int posicao, int wordLength, char word[]){

	int retorno = 0;

	int modoConstrucao = -1;
	int monossilaba = 0;
	int dissilaba_1_3 = 1;
    int dissilaba_2_2 = 2;
	int opcoesConstrucao[3] = {monossilaba, dissilaba_1_3, dissilaba_2_2};

	modoConstrucao = defineConstrucao(opcoesConstrucao, 4);
	//modoConstrucao = dissilaba_2_2;
	if(modoConstrucao == dissilaba_1_3){

		int aux, a1, a2, a3;
		int combinacaoTipos[wordLength];
		
		char silaba_1;
		char silaba_2[wordLength];

		while(retorno != SUCESSO){		//puts("dissilaba");

			//define silaba 1
			silaba_1 = getVogal();
			//define silaba 2
			formaSilabaTresLetras(silaba_2, combinacaoTipos);
			silaba_2[wordLength-1] = '\0';		//printf("silaba 2: %s\n", silaba_2);

			a1 = combinacaoTipos[0];
			a2 = combinacaoTipos[1];
            a3 = combinacaoTipos[2];
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
		        if(a1 == CONSOANTE && a2 == CONSOANTE && a3 == VOGAL){
		        	storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                    strcpy(storeWord[posicao], word);		                    
                    retorno = SUCESSO;
				    
		    	}else if(a1 == CONSOANTE && a2 == VOGAL && a3 == VOGAL){
		        	storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                    strcpy(storeWord[posicao], word);		                    
                    retorno = SUCESSO;
				    
		    	}else if(a1 == CONSOANTE && a2 == VOGAL && a3 == CONSOANTE){
		        	storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                    strcpy(storeWord[posicao], word);		                    
                    retorno = SUCESSO;
				    
		    	}else 
		    		retorno PALAVRA_INVALIDA;
		    }else
		        retorno = EXISTING_WORD;

		     //printf("retorno: %d\n", retorno);
		}	

    }else if(modoConstrucao == dissilaba_2_2){

		int aux, a1, a2, a3, a4;
		int combinacaoTipos[wordLength];
		
		char silaba_1[wordLength-1];
		char silaba_2[wordLength-1];

		while(retorno != SUCESSO){		//puts("dissilaba");

			//define silaba 1
			formaSilabaDuasLetras(silaba_1, combinacaoTipos);
			silaba_1[2] = '\0';		//printf("silaba 2: %s\n", silaba_2);

			a1 = combinacaoTipos[0];
			a2 = combinacaoTipos[1];
            
			//define silaba 2
			formaSilabaDuasLetras(silaba_2, combinacaoTipos);
			silaba_2[2] = '\0';		//printf("silaba 2: %s\n", silaba_2);

			a3 = combinacaoTipos[0];
			a4 = combinacaoTipos[1];
            
			//junta as 2 silabas
			word[0] = silaba_1[0];
            word[1] = silaba_1[1];
			word[2] = silaba_2[0];
            word[3] = silaba_2[1];
            word[4] = '\0';
			//verifica se palavra já existe;
			aux = buscaString(storeWord, word, wordLength);		//printf("aux: %d\n", aux);		if(storeWord[posicao]==NULL)	puts("NULL");

			//puts("passou a atribuicao do aux");          
	    	
		    if(aux == 0){		//puts(word);
		    	//puts("entrou no aux==0");
		    	//printf("a1: %d\n", a1);
		    	//printf("a2: %d\n", a2);
		        if(a2 == VOGAL && a3 == CONSOANTE){
		        	storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                    strcpy(storeWord[posicao], word);		                    
                    retorno = SUCESSO;
				    
		    	}else if(a2 == CONSOANTE && a3 == VOGAL){
		        	storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                    strcpy(storeWord[posicao], word);		                    
                    retorno = SUCESSO;
				    
		    	}else 
		    		retorno PALAVRA_INVALIDA;
		    }else
		        retorno = EXISTING_WORD;

		     //printf("retorno: %d\n", retorno);
		}	

    }else{

		int aux, a1, a2, a3, a4;
		int combinacaoTipos[wordLength];

		while(retorno != SUCESSO){

			formaSilabaQuatroLetras(word, combinacaoTipos);

			word[wordLength] = '\0'; 

			a1 = combinacaoTipos[0];
			a2 = combinacaoTipos[1];
			a3 = combinacaoTipos[2];
            a4 = combinacaoTipos[3];
		    
		    aux = buscaString(storeWord, word, wordLength);		//printf("aux: %d\n", aux);		if(storeWord[posicao]==NULL)	puts("NULL");          
		    	
		    if(aux == 0){		//puts(word);
		    	
                if(a1 == CONSOANTE && a2 == VOGAL && a3 == VOGAL && a4 == CONSOANTE){
                    
                    if(word[0] == 'q' || word[0] == 'g')
                        retorno = PALAVRA_INVALIDA;
                    else{
                        
                        if(word[1] != 'e' && word[1] != 'a' && word[1] != 'o')
                            retorno = PALAVRA_INVALIDA;
                        else{
                            
                            if(word[2] == 'i'){
                                
                                if(word[1] == 'a'){ 
                                    if(word[0] == 'c' || word[0] == 'd' || word[0] == 'm' || word[0] == 'p' || word[0] == 's' || word[0] == 't' || word[0] == 'v'){
                                        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                        strcpy(storeWord[posicao], word);		                    
                                        retorno = SUCESSO;
                                    }
                                }else if(word[1] == 'e'){ 
                                    if(word[0] == 'd' || word[0] == 'l' || word[0] == 'r' || word[0] == 's'){
                                        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                        strcpy(storeWord[posicao], word);		                    
                                        retorno = SUCESSO;
                                    }
                                }else if(word[1] == 'o'){
                                    if(word[0] == 'b' || word[0] == 'd' || word[0] == 'p' || word[0] == 's'){
                                        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                        strcpy(storeWord[posicao], word);		                    
                                        retorno = SUCESSO;
                                    }
                                }else
                                    retorno = PALAVRA_INVALIDA; 
                                
                            }else if(word[2] == 'u'){
                                
                                if(word[1] == 'a'){
                                    if(word[0] == 'p' || word[0] == 'm'){
                                        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                        strcpy(storeWord[posicao], word);		                    
                                        retorno = SUCESSO;
                                    }
                                }else if(word[1] == 'e'){
                                    if(word[0] == 'd' || word[0] == 'm' || word[0] == 's' || word[0] == 't'){
                                        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                        strcpy(storeWord[posicao], word);		                    
                                        retorno = SUCESSO;
                                    }
                                }else
                                    retorno = PALAVRA_INVALIDA;
                            }
                        }
                    }                    
                }else if(a1 == CONSOANTE && a2 == VOGAL && a3 == VOGAL && a4 == VOGAL){
                    
                    if(word[0] == 'c' || word[0] == 'd' || word[0] == 'f' || word[0] == 'g' || word[0] == 'm' || word[0] == 'p' || word[0] == 'r' || word[0] == 's' || word[0] == 'r'){
                       
                        if(word[0] == 'c' || word[0] == 'f' || word[0] == 'g' || word[0] == 'm' || word[0] == 'p' || word[0] == 's' || word[0] == 'v'){
                            
                            if(word[0] == 's'){
                                if(word[1] == 'o'|| word[1] == 'u'){
                                    storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                    strcpy(storeWord[posicao], word);		                    
                                    retorno = SUCESSO;
                                }
                            }else if(word[0] == 'm'){
                                if(word[1] == 'i' || word[1] == 'o'){
                                    if(word[1] == 'o'){
                                        if(word[2] != 'o'){
                                            storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                            strcpy(storeWord[posicao], word);		                    
                                            retorno = SUCESSO;
                                        }
                                    }else{
                                        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                        strcpy(storeWord[posicao], word);		                    
                                        retorno = SUCESSO;
                                    }
                                }                                
                            }else if(word[0] == 'd' || word[0] == 'r'){
                                if(word[1] == 'o'){
                                    if(word[0] == 'r' && word[2] != 'o'){
                                        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                        strcpy(storeWord[posicao], word);		                    
                                        retorno = SUCESSO; 
                                    }else{
                                        storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                        strcpy(storeWord[posicao], word);		                    
                                        retorno = SUCESSO;
                                    }
                                }
                            }else if(word[0] == 'c' || word[0] == 'g'){
                                if(word[1] == 'e'){
                                    storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                    strcpy(storeWord[posicao], word);		                    
                                    retorno = SUCESSO;
                                }
                            }else if(word[0] == 'f' || word[0] == 'p'){
                                if(word[1] == 'i'){
                                    storeWord[posicao] = (char*) malloc( (wordLength + 1) * sizeof(char) );
                                    strcpy(storeWord[posicao], word);		                    
                                    retorno = SUCESSO;
                                }
                            }else
                                retorno = PALAVRA_INVALIDA;
                            
                        }else
                            retorno = PALAVRA_INVALIDA;
                        
                    }else
                        retorno = PALAVRA_INVALIDA;
                    
                }else
                    retorno = EXISTING_WORD;
            }
        }
    }

    return retorno;
}

void formaSilabaDuasLetras(char silaba[], int combinacaoTipos[]){

	int a1, a2, sair, aux;

	srand(time(NULL));

	sair = 0;

	while(!sair){

		composicaoSilaba(2, silaba);

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

void formaSilabaTresLetras(char silaba[], int combinacaoTipos[]){

	int a1, a2, a3, sair, aux;

	srand(time(NULL));

	sair = 0; 

	while(!sair){

		composicaoSilaba(3, silaba);

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
// 				pause();
				//define teceira letra
				while(silaba[2] != 'a' && silaba[2] != 'e' && silaba[2] != 'i' && silaba[2] != 'o')
					silaba[2] = getVogal();
			}else{
				//define segunda letra
				silaba[1] = getVogal();
				//espera 1 segundo para modificar semente da função rand()
// 				pause();
				//define teceira letra
				do{	
				silaba[2] = getVogal();
				}while (silaba[2] == silaba[1]);
			}
			sair = 1;

		}else if(a1 == CONSOANTE && a2 == CONSOANTE && a3 == VOGAL){		//puts("CCV");

			//define primeira letra
			do{
				silaba[0] = getConsoante();
            }while(silaba[0] != 'c' && silaba[0] != 'b' && silaba[0] != 'f' && silaba[0] != 'g' && silaba[0] != 'p' && silaba[0] != 'd' && silaba[0] != 't' && silaba[0] != 'n');
            
			//define segunda letra
            if(silaba[0] == 'c')
                do{
                    silaba[1] = getConsoante();
                }while(silaba[1] != 'r' && silaba[1] != 'l' && silaba [1] != 'h');
			else if(silaba[0] == 'b' || silaba[0] == 'f' || silaba[0] == 'g' || silaba[0] == 'p')
				 do{
                    silaba[1] = getConsoante();
                 }while(silaba[1] != 'r' && silaba[1] != 'l' );
			else if(silaba[0] == 'd' || silaba[0] == 't')
                silaba[1] = 'r';
            else if(silaba[0] == 'n')
                silaba[1] = 'h';
			//define terceira letra
			silaba[2] = getVogal();

			sair = 1;

		}else if(a1 == CONSOANTE && a2 == VOGAL && a3 == CONSOANTE){		//puts("CVC");
			//define primeira letra
			do{	
				silaba[0] = getConsoante();
			}while(silaba[0] == 'q' && silaba[0] == 'h');
			//define segunda letra
			silaba[1] = getVogal();
			//espera 1 segundo para modificar semente da função rand()
			//pause();
			//define teceira letra
			do{	
				silaba[2] = getConsoante();
			}while (silaba[2] == silaba[0] && silaba[2] != 'c' && silaba[2] != 'l' && silaba[2] != 'm' && silaba[2] != 'n' && silaba[2] != 's');

			sair = 1;	

		}else
			continue;
	}
	combinacaoTipos[0] = a1;
	combinacaoTipos[1] = a2;
	combinacaoTipos[2] = a3;
	//puts("formaSilabaTresLetras completa");
}

void formaSilabaQuatroLetras(char silaba[], int combinacaoTipos[]){

	int a1, a2, a3, a4, sair, aux;

	srand(time(NULL));

	sair = 0; 

	while(!sair){

		composicaoSilaba(4, silaba);

		a1 = silaba[0];
		a2 = silaba[1];
		a3 = silaba[2];
        a4 = silaba[3];
		
		if(a1 == CONSOANTE && a2 == VOGAL && a3 == VOGAL && a4 == CONSOANTE){		//puts("CVVC");
			//define primeira letra				
			do{
                silaba[0] = getConsoante();
            }while(silaba[0] == 'h' || silaba[0] == 'j' || silaba[0] == 'x' || silaba[0] == 'z'); //printf("%c\n", silaba[0]);
			//testa se a primeira letra é q ou g
			if(silaba[0] == 'q' || silaba[0] == 'g'){
				
                //define segunda letra
				silaba[1] = 'u'; //printf("%c\n", silaba[1]);
				
				//define teceira letra
				while(silaba[2] != 'a' && silaba[2] != 'e' && silaba[2] != 'i')
					silaba[2] = getVogal();
                
                //define quarta letra
                if(silaba[0] == 'g' && silaba[2] == 'a'){
                    do{	
                        silaba[3] = getConsoante();
                    }while(silaba[3] != 'l' && silaba[3] != 'm' && silaba[3] != 'n' && silaba[3] != 'r'); //printf("%c\n", silaba[3]);
                }else if(silaba[0] == 'g' && silaba[2] == 'e'){
                    do{	
                        silaba[3] = getConsoante();
                    }while(silaba[3] != 'l' && silaba[3] != 'n' && silaba[3] != 'r' && silaba[3] != 's' && silaba[3] != 'z'); //printf("%c\n", silaba[3]);
                }else if(silaba[0] == 'g' && silaba[2] == 'i'){
                    do{	
                        silaba[3] = getConsoante();
                    }while(silaba[3] != 'm' && silaba[3] != 'n' && silaba[3] != 'r' && silaba[3] != 's'); //printf("%c\n", silaba[3]);
                }else if(silaba[0] == 'q' && silaba[2] == 'a'){
                    do{	
                        silaba[3] = getConsoante();
                    }while(silaba[3] != 'l' && silaba[3] != 'n' && silaba[3] != 'r' && silaba[3] != 's'); //printf("%c\n", silaba[3]);
                }else if(silaba[0] == 'q' && silaba[2] == 'e'){
                    do{	
                        silaba[3] = getConsoante();
                    }while(silaba[3] != 'l' && silaba[3] != 'n' && silaba[3] != 'r' && silaba[3] != 's'); //printf("%c\n", silaba[3]);
                }else if(silaba[0] == 'q' && silaba[2] == 'i'){
                    do{	
                        silaba[3] = getConsoante();
                    }while(silaba[3] != 'm' && silaba[3] != 'n' && silaba[3] != 'r' && silaba[3] != 's'); //printf("%c\n", silaba[3]);
                }
                    
			}else{
				//define segunda letra
				do{	
                    silaba[1] = getVogal(); 
				}while (silaba[1] != 'a' && silaba[1] != 'e' && silaba[1] != 'o'); //printf("%c\n", silaba[1]);
				
                //define teceira letra
				do{	
                    silaba[2] = getVogal();
				}while (silaba[2] != 'i' && silaba[2] != 'u'); //printf("%c\n", silaba[2]);
                
                //define quarta letra
                silaba[3] = 's'; //printf("%c\n", silaba[3]);
			}
			
			sair = 1;

		}else if(a1 == CONSOANTE && a2 == VOGAL && a3 == VOGAL && a4 == VOGAL){		//puts("CVVV");
            
            //define a primeira letra
            do{	
                silaba[0] = getConsoante();
            }while(silaba[0] != 'c' && silaba[0] != 'd' && silaba[0] != 'f' && silaba[0] != 'g' && silaba[0] != 'm' && silaba[0] != 'p' && silaba[0] != 'q' && silaba[0] != 'r' && silaba[0] != 's');
            
			
			if(silaba[0] == 'g' || silaba[0] == 'q'){
            
                //define segunda letra
                silaba[1] = 'u';
                
                //define terceira letra
                if(silaba[0] == 'q'){
                    
                    silaba[2] = 'e';
                    
                    //define quarta letrguea
                    silaba[3] = 'i';
                }else{
                    
                    do{	
                        silaba[2] = getVogal();
                    }while (silaba[2] != 'a' && silaba[2] != 'e' && silaba[2] != 'o');
                    
                    //define quarta letra
                    if(silaba[2] == 'o')
                        silaba[3] = 'u';
                    else
                        silaba[3] = 'i';
                }
                
            }else{
                
                //define a segunda letra
                do{
                    silaba[1] = getVogal();
                }while(silaba[1] == 'a');
                
                //define a terceira letra
                do{
                    silaba[2] = getVogal();
                }while(silaba[2] == 'i' || silaba[2] == 'u');
                
                //define a quarta letra
                if(silaba[2] == 'o'){
                    silaba[3] = 'u';
                }else if(silaba[2] == 'a'){
                    if(silaba[0] == 'm'){
                        do{
                            silaba[3] = getVogal();
                        }while(silaba[3] != 'i' && silaba[3] != 'u');
                    }else
                        silaba[3] = 'i';
                    
                }else if(silaba[2] == 'e'){
                    if(silaba[0] == 'd'){
                        silaba[3] = 'u';
                    }else if(silaba[0] == 'r' || silaba[0] == 'm'){
                        do{
                            silaba[3] = getVogal();
                        }while(silaba[3] != 'i' && silaba[3] != 'u');
                    }else{
                        silaba[3] = 'i';
                    }              
                }
            }
            
            sair = 1;
            
        }else if(a1 == CONSOANTE && a2 == CONSOANTE && a3 == VOGAL && a4 == CONSOANTE){
                
            //define a primeira letra
            do{	
                silaba[0] = getConsoante();
            }while(silaba[0] == 'h' || silaba[0] == 'j' || silaba[0] == 'm' || silaba[0] == 'q' || silaba[0] == 'r' || silaba[0] == 's' || silaba[0] == 'x' || silaba[0] == 'z');
            
            if(silaba[0] == 'v'){
                strcpy(silaba, "vrar");                    
            }else{
                
                //define a segunda letra
                if(silaba[0] == 'c'){
                    do{	
                        silaba[1] = getConsoante();
                    }while(silaba[1] != 'h' && silaba[1] != 'l' && silaba[1] != 'r');
                }else if(silaba[0] == 'l' || silaba[0] == 'n'){
                    silaba[1] = 'h';
                }else{
                    do{	
                        silaba[1] = getConsoante();
                    }while(silaba[1] != 'l' && silaba[1] != 'r');
                }
                
                //define a terceira letra                                  
                silaba[2] = getVogal();
                
                //define qa quarta letra
                do{	
                    silaba[3] = getConsoante();
                }while(silaba[3] == 'l' && silaba[3] != 'm' && silaba[3] != 'n' && silaba[3] != 'r' && silaba[3] != 's' && silaba[3] != 'z'); 
            }

			sair = 1;

		}else if(a1 == CONSOANTE && a2 == CONSOANTE && a3 == VOGAL && a4 == VOGAL){
            
			//define a primeira letra
            do{	
                silaba[0] = getConsoante();
            }while(silaba[0] == 'h' || silaba[0] == 'j' || silaba[0] == 'm' || silaba[0] == 'q' || silaba[0] == 'r' || silaba[0] == 's' || silaba[0] == 'x' || silaba[0] == 'z');
                           
            //define a segunda letra
            if(silaba[0] == 'c'){
                do{	
                    silaba[1] = getConsoante();
                }while(silaba[1] != 'h' && silaba[1] != 'r');
            }else if(silaba[0] == 'l' || silaba[0] == 'n'){
                silaba[1] = 'h';
            }else
                silaba[1] = 'r';                
            
            //define a terceira letra
            do{	
                silaba[2] = getVogal();
            }while (silaba[2] == 'i' || silaba[2] == 'u');
            
            //define a quarta letra
            do{	
                silaba[3] = getVogal();
            }while (silaba[3] != 'i' && silaba[3] != 'u');
            
            sair = 1;

		}else if(a1 == CONSOANTE && a2 == VOGAL && a3 == CONSOANTE && a4 == CONSOANTE){
            
            //define a primeira letra
            do{	
                silaba[0] = getConsoante();
            }while(silaba[0] == 'h' || silaba[0] == 'j' || silaba[0] == 'q' || silaba[0] == 'r' || silaba[0] == 's' || silaba[0] == 'x' || silaba[0] == 'z');
            
            //define a segunda letra
            silaba[1] = getVogal();
            
            //define a terceira letra
            silaba[2] = 'n';
            
            //define a quarta letra
            silaba[3] = 's';
            
            sair = 1;
            
        }else
			continue;
	}
	combinacaoTipos[0] = a1;
	combinacaoTipos[1] = a2;
	combinacaoTipos[2] = a3;
    combinacaoTipos[3] = a4;
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

// 	pause();
    
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

int comparaWord(char *word, int size){
    
    FILE* arq;
    char str[55];
    int res, count = 0;
    
    if(size == 2){
        arq = fopen("2letras.txt", "r");
        
        if(arq == NULL)
            return 0;
        
        while(!feof(arq)){
            fgets(str, sizeof(str), arq);
            str[2] = '\0';
            
            res = strncmp(word, str, sizeof(word));
            if(res == 0)
                count++;
        }
        
        fgets(str, sizeof(str), arq);
            str[2] = '\0';
            
            res = strncmp(word, str, sizeof(word));
            if(res == 0)
                count++;
    }else if(size == 3){
        arq = fopen("3letras.txt", "r");
        
        if(arq == NULL)
            return 0;
        
        while(!feof(arq)){
            fgets(str, sizeof(str), arq);
            str[3] = '\0';
            
            res = strncmp(word, str, sizeof(word));
            if(res == 0)
                count++;
        }
        
        fgets(str, sizeof(str), arq);
            str[3] = '\0';
            
            res = strncmp(word, str, sizeof(word));
            if(res == 0)
                count++;
    }else if(size == 4){
        arq = fopen("4letras.txt", "r");
        
        if(arq == NULL)
            return 0;
        
        while(!feof(arq)){
            fgets(str, sizeof(str), arq);
            str[4] = '\0';
            
            res = strncmp(word, str, sizeof(word));
            if(res == 0)
                count++;
        }
        
        fgets(str, sizeof(str), arq);
            str[4] = '\0';
            
            res = strncmp(word, str, sizeof(word));
            if(res == 0)
                count++;
    }else
        return 0;
    
    return count;
}
