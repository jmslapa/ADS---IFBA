//copia o conteudo do arquivo tmp.txt em tmpCopy.txt, com alteracoes
#include<stdio.h>
#include<stdlib.h>

void main(){          

  char c;

  FILE *ent;

  ent = fopen("teste.txt", "r");
   
  if(ent){
   	                
    while(!feof(ent)){

        c=fgetc(ent);
      	printf("%c", c);   		                        
    }
      
    fclose( ent );
              
  }

  else
    	printf ("Erro na abertura do arquivo\n");
}

