#define TAM 10

#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11


//definindo elementos da lista encadeada
typedef struct reg {
    int conteudo;
  struct reg *prox;
} No;


//voids principais
void inicializar();
void finalizar();
//voids secundárias
void shiftEsquerda(int posicao, int posicaoElemento);
void insertionSort(int *v, int tam);
//ints principais
int criarEstruturaAuxiliar(int tamanho, int posicao);
int inserirNumeroEmEstrutura(int valor, int posicao);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
int getQuantidadeTotalElementos(void);
int gravarDados(FILE *arq);
//ints secundárias
int ehPosicaoValida(int posicao);
int buscaElemento(int elemento, int posicao);
//funções de lista encadeada
No* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No* inicio);
//funcções secundárias de lista encadeada
No* criarElementoEncadeado(int valor);
void inserirFimListaEncadeada(No *inicio, int valor);
