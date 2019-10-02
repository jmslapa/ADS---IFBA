#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

arv* montarArvoreAVL(arv* inicio){
    //verifica se arvore já foi criada
    if(inicio != NULL)
        return NULL;
    //aloca memoria para inicio
    inicio = (arv*) malloc(sizeof(arv));
    //se alocaçao for bem sucedida
    if(inicio != NULL){
        inicio->esq = NULL;
        inicio->dir = NULL;
        inicio->prox = NULL;
    }
    
    return inicio;
}

void rotacaoLL(arv* raiz){
    
    arv* tmp;
    
    tmp = raiz->esq;
    raiz->esq = tmp->dir;
    tmp->dir = raiz;
    
    raiz = tmp;    
}

void rotacaoRR(arv* raiz){
    
    arv* tmp;
    
    tmp = raiz->dir;
    raiz->dir = tmp->esq;
    tmp->esq = raiz;
    
    raiz = tmp;
}

void rotacaoLR(arv* raiz){
    
    rotacaoRR(raiz->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(arv* raz){
    
    rotacaoLL(raiz->dir);
    rotacaoRR(raiz);
}

int fatorBalanceamento(arv* raiz){
    
    return alturaArvore(raiz->esq) - alturaArvore(raiz->dir);
}

int alturaArvore(arv* raiz){
    
    int altEsq;
    int altDir;
    
    if(raiz == NULL)
        return 0;
    
    altEsq = alturaArvore(raiz->esq);
    altDir = alturaArvore(raiz->dir);
    
    if(altEsq > altDir)
        return altEsq + 1;
    else
        return altDir + 1;    
}

int maiorValor(int a, int b){
    
    if(a > b)
        return a;
    else
        return b;
}






