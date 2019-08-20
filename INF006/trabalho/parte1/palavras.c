#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CONT 10


int tamanhoSilaba(void);
char geraVogal(void);
char geraConsoante(void);


int main(void){

	char *silaba_1;
	char *silaba_2;
	int sizeof_silaba;


	for(int i=0; i<CONT; i++){		
		
        system("sleep 1");
        
        srand(i);
        
        sizeof_silaba = tamanhoSilaba();       
        
		switch(sizeof_silaba){
            
			case 2:{//silaba com 2 letras
                silaba_1 = (char*) malloc (sizeof_silaba * sizeof(char));
                silaba_1[0] = geraConsoante;
                puts("Consoante foi");
                silaba_1[1] = geraVogal;
                puts("Vogal foi");
                puts(silaba_1);
                break;    
			}
			
            default:
                puts("ERROR:");
		}
	}
    
	return 0;
}


int tamanhoSilaba(void){

	int tam=1;	
	
	while(tam<=1){
		tam = rand()%3;
	}

	return tam;
}

char geraVogal(void){

	char vogal=0;
	int sair=0;

	while(!sair){

		vogal = rand()%123;
        
        
		switch(vogal){
			
			case 97:
				sair=1;
				break;
			case 101:
				sair=1;
				break;
			case 105:
				sair=1;
				break;
			case 111:
				sair=1;
				break;
			case 117:
				sair=1;
                break;
            default:
				sair=0;
		}		
	}
	
	return vogal;
}

char geraConsoante(void){

	char consoante=98;
	int sair=0;

	while(consoante > 96 && consoante != 97 && consoante != 101 && consoante != 105 && consoante != 111 && consoante != 117 && consoante != 97-32 && consoante != 101-32 && consoante != 105-32 && consoante != 111-32 && consoante != 117-32){

		consoante = rand()%123;
        
	}
	
	return consoante;
}
