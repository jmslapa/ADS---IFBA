#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *arq;
    int vet[3];
    int num;
    int sair, option, i, j;
    
    sair = 0;
    
    while(!sair){
        
        puts("Informe a opcao desejada: ");
        puts("0 - Sair");
        puts("1 - Escrever arquivo Bin");
        puts("2 - Ler arquivo Bin");
        puts("3 - Ler bin do Trabalho3");
        scanf("%d", &option);
        
        switch(option){
            
            case 0:{
                sair = 1;
                system("clear");
            break;}
            
            case 1: {
                
                arq = fopen("data.bin", "wb");
                
                system("clear");
                puts("Preencha o vetor : ");
                for(i = 0 ; i < 3 ; i++){
                    scanf("%d", &vet[i]);
                }
                
                fwrite(&vet[0], sizeof(vet), 1, arq);
                    
                fclose(arq);
                
            break;}
            
            case 2:{/*
                
                arq = fopen("data.bin", "rb");
                
                system("clear");
                i = 0;
                j = 0;
                while(fread(&num, sizeof(int), 1, arq)){
                    
                    if(i >= 2){
                        vetAux[j] = num;
                        j++;
                    }
                    i++;          
                }
                
                for(i = 0 ; i < j ; i++)
                    printf("%d ", vetAux[i]);
                
                puts("");
                
                fclose(arq);*/
            break;}
            
            case 3:{
                
                int n;
                
                arq = fopen("data.bin", "rb");
                
                system("clear");
                
                                   
                while(fread(&n, sizeof(n), 1, arq)){
                    
                    printf("%d ", n);
                    
                }
                    
                puts("");
                
                
                
                fclose(arq);
            break;}
            
            default:
                puts("Opção Inválida");
        }
        
    }
    
    return 0;
}


//backup leitura txt
for(i = 0 ; i < TAM ; i++){
                
    //verifica se a estrutura auxiliar existe
    for(c = fgetc(arq), j = 0 ; c != ' ' && c != '\n' && c != EOF ; c = fgetc(arq), j++)
        tamanho[j] = c;
    
    tamanho[j] = '\0';
    n = atoi(tamanho);
    
    if(n != 0){ //se a estrutura existir
        
        //cria a estrutura auxiliar
        ret = criarEstruturaAuxiliar(n, i+1);
        
        if(ret != SUCESSO)
            return ret;
        
        else{ //estrutura criada com sucesso
            
                                    
            //verifica se a estrutura auxiliar está vazia
            for(c = fgetc(arq), j = 0 ; c != ' ' && c != '\n' && c != EOF ; c = fgetc(arq), j++)
                preenchido[j] = c;
        
            preenchido[j] = '\0';
            n = atoi(preenchido);
            
            if(n != 0){ //se a estrutura não estiver vazia
                                        
                //lê os elementos da estrutura auxiliar e os atribui
                for(k = 0 ; k < n ; k++){
                    
                    for(c = fgetc(arq), j = 0 ; c != ' ' && c != '\n' && c != EOF ; c = fgetc(arq), j++)
                        elemento[j] = c;
                    
                    elemento[j] = '\0';
                    m = atoi(elemento);
                                                    
                    //atribui o elemento da estrutura auxiliar
                    ret = inserirNumeroEmEstrutura(m, i+1);
                    if(ret != SUCESSO)
                        return ret;
                }
            }
        }
    }
}
