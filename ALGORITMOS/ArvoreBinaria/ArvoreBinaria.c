#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int inserirNode(root* raiz, int valor){
    
    //se a arvore nao tiver sido criada
    if(raiz == NULL){
        return 0;
    }
    
    //cria o novo node
    node* novo = (node*) malloc(sizeof(node));    
    
    //se o novo node nao tiver sido criado
    if(novo == NULL)
        return 0;
    
    //atribui o conteudo de node
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    
    //se o conteudo de raiz for nulo
    if(raiz->inicio == NULL)
        raiz->inicio = novo;
    
    else{
        
        //cria apontadores para node atual e node anterior
        node* atual = raiz->inicio;
        node* anterior = NULL;
        
        //enquanto o node atual não for nulo
        while(atual != NULL){
            
            //armazena o node atual em node anterior
            anterior = atual;
            
            //se o valor já existir em algum node da arvore
            if(valor == atual->info){                
                free(novo);
                return 0;
            }
            
            //se o valor for menor que o valor contido em atual
            if(valor < atual->info)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        
        //se o valor for menor que o valor contido em node anterior
        if(valor < anterior->info)
            anterior->esq = novo;
        else
            anterior->dir = novo;
    }
    
    return 1;
}

int excluirNode(root* raiz, int valor){
    
    //verifica se a arvore existe
    if(raiz == NULL)
        return 0;
   
    node* atual = raiz->inicio;
    node* anterior = NULL;
    
    while(atual != NULL){
        
        if(valor == atual->info){
            
            if(atual == raiz->inicio){
                raiz->inicio = removeAtual(atual);
                return 1;
            }else{
                
                if(anterior->esq == atual){
                    anterior->esq = removeAtual(atual);
                    return 1;
                }else{
                    anterior->dir = removeAtual(atual);
                    return 1;
                }
            }
        }
        
        anterior = atual;
        
        if(valor < atual->info)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    
    return 0;
}

node* removeAtual(node* atual){
    
    node* tmp;
    node* aux;
    
    //verifica se o atual tem filho a esquerda
    if(atual->esq == NULL){
        
        tmp = atual->dir;
        free(atual);
        atual = tmp;
        
        return atual;
    }
    
    tmp = atual->esq;
    
    while(tmp->dir != NULL){        
        aux = tmp;
        tmp = tmp->dir;
    }
    
    if(tmp != atual){
        aux->dir = tmp->esq;
        tmp->esq = atual->esq;
    }
    
    tmp->dir = atual->dir;
    free(atual);
    atual = tmp;
    
    return atual;
}

root* montarArvore(){
    
    //aloca memoria para o indicador da raiz da arvore
    root* raiz = (root*) malloc(sizeof(root));
    
    if(raiz!=NULL)
        raiz->inicio = NULL;
    
    //retorna raiz
    return raiz;
}

void liberarNode(node* no){
    
    //se o node for nulo, sai da funçao
    if(no == NULL)
        return;
    
    //se o node não for nulo, chama a funçao recursivamente passando o node filho da esquerda
    liberarNode(no->esq);
    //depois de liberar o nó da esquerda chama a funçao recursivamente passando o node filho da direita
    liberarNode(no->dir);
    //após liberar o node da esquerda e da direita, libera o próprio node
    free(no);
    
    //atribui NULL ao node;
    no = NULL;
}

int destruirArvore(root* raiz){
    
    //se arvore não tiver sido criada
    if(raiz == NULL)
        return 0;
    
    //chama a função para liberar todos os nós descendentes de raiz
    liberarNode(raiz->inicio);
    
    //libera a raiz
    free(raiz);
    
    return 1;
}

int saberAltura(root* raiz){
    
    //se a arvore nao foi criada
    if(raiz == NULL)
        return 0;
    
    int ret;
    
    node* atual = raiz->inicio;
    
    ret = altura_daArvore(atual);
    
    return ret;
}

int altura_daArvore(node* no){
    
    int alt_esq;
    int alt_dir;
    
    //se o no for nulo
    if(no == NULL)
        return 0;
    
    //chama a função recursivamente para calcular a altura da árvore à esquerda
    alt_esq = altura_daArvore(no->esq);
    
    //chama a função recursivamente para calcular a altura da árvore à direita
    alt_dir = altura_daArvore(no->dir);
    
    //se a altura da esquerda for maior que a da direita, altura = altura da esquerda + 1
    if(alt_esq > alt_dir)
        return alt_esq + 1;
    else
        return alt_dir + 1;   
}

int saberQtd(root* raiz){
    
    //se a arvore nao foi criada
    if(raiz == NULL)
        return 0;
    
    int ret;
    
    node* atual = raiz->inicio;
    
    ret = totalNodes(atual);
    
    return ret;
}

int totalNodes(node* no){
    
    int total_esq;
    int total_dir;
    
    //se o no for nulo
    if(no == NULL)
        return 0;
    
    //chama a função recursivamente para calcular o total de nodes à esquerda
    total_esq = totalNodes(no->esq);
    
    //chama a função recursivamente para calcular o total de nodes à direita
    total_dir = totalNodes(no->dir);
    
    //a quantidade de nós da arvore é o total à esquerda + o total à direita + 1
    return(total_esq + total_dir + 1);   
}

void exibir_emOrdem(root* raiz){
    
    //se a arvore nao foi criada
    if(raiz == NULL)
        return;
    
    node* atual = raiz->inicio;
    
    emOrdem(atual);
}

void emOrdem(node* no){
    
    //se o no for nulo
    if(no == NULL)
        return;
    
    //imprime esquerda
    emOrdem(no->esq);
    //imprime raiz
    printf(" %d", no->info);
    //imprime direita
    emOrdem(no->dir);
}















