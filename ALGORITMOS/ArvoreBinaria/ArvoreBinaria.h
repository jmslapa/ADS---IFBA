//cria estrutura 'node'
typedef struct arvore{
    
    int info;
    struct arvore* esq;
    struct arvore* dir;
}node;

typedef struct rt{
    
    node* inicio;
}root;

//funções:
root* montarArvore();
int inserirNode(root* raiz, int valor);
int destruirArvore(root* raiz);
void liberarNode(node* no);
int saberAltura(root* raiz);
int altura_daArvore(node* no);
int saberQtd(root* raiz);
int totalNodes(node* no);
void exibir_emOrdem(root* raiz);
void emOrdem(node* no);
