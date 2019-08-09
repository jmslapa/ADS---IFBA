#define TAM 10
#define TAM_MAX_ESTRUTURA_AUXILIAR 100

#define SUCESSO 1
#define SEM_ESPACO 2
#define SEM_ESTRUTURA_AUXILIAR 3
#define JA_TEM_ESTRUTURA_AUXILIAR 4
#define POSICAO_INVALIDA 5
#define SEM_ESPACO_DE_MEMORIA 6
#define TAMANHO_INVALIDO 7
#define VALOR_INVALIDO 8

int criarEstruturaAuxiliar(int tamanho, int posicao);
int inserirNumeroEmEstrutura(int valor, int posicao);
int listaEstruturaAuxiliar(int posicao);
void atribuiNULL();
int ehPosicaoValida(int posicao);
void limpaTela();
void quebraPagina();
void liberaMemoria();
int ordenaVetor(int posicao);
void capturaPosicao(int *posicao);
void capturaValor(int *valor);
void capturaTamanho(int *tamanho);
int excluirNumeroEmEstrutura(int valor, int posicao);
int buscaElemento(int elemento, int posicao);
void shiftEsquerda(int posicao, int posicaoElemento);
int aumentarEstruturaAuxiliar(int tamanho, int posicao);