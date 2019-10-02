#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int mainMenu();

int main(){
    
    int op, sair, ret, valor;
    
    root* raiz = montarArvore();
    
    sair = 0;
    
    while(!sair){
        
        op = mainMenu();
        
        switch(op){
            
            case 0:{
                
                destruirArvore(raiz);
                
                sair = 1;
                
                break;
            }
            
            case 1:{
                    
                puts("Informe o valor a ser inserido");
                scanf("%d", &valor);
                
                ret = inserirNode(raiz, valor);
                
                if(ret)
                    puts("Node inserido com sucesso.");
                else
                    puts("ERRO: Processo de inserção falhou.");
                    
                break;                
            }
            
            case 2:{
                
                printf("Em Ordem:");
                exibir_emOrdem(raiz);
                puts("");
                
                break;                
            }
            
            case 3:{
                    
                puts("Informe o valor a ser excluido");
                scanf("%d", &valor);
                
                ret = excluirNode(raiz, valor);
                
                if(ret)
                    puts("Node excluido com sucesso.");
                else
                    puts("ERRO: Processo de exclusão falhou.");
                    
                break;                
            }
            
             case 4:{
                    
                puts("Informe o valor do nó a ser buscado");
                scanf("%d", &valor);
                
                ret = buscar_naArvore(raiz, valor);
                
                if(ret)
                    puts("O nó existe na árvore.");
                else
                    puts("ERRO: Nó não encontrado.");
                    
                break;                
            }
            
            default:
                puts("Opção inválida");
        }
    }
}

int mainMenu(){
    
    int op;
    
    puts("Informe a opção desejada:");    
    
    puts("Opção 0: Sair");
    puts("Opção 1: Inserir novo nó na Árvore");
    puts("Opção 2: Exibir nós em ordem");
    puts("Opção 3: Excluir nó da Árvore");
    puts("Opção 4: Buscar nó na Árvore");
    
    scanf("%d", &op);
    
    return op;
}
