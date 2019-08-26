#define CONT 10

#define SUCESSO -1
#define EXISTING_WORD -2
#define CONSOANTE -3
#define VOGAL -4

void inicializa();
void finaliza();
void pause();
char getConsoante();
char getVogal();
int sorteiaTipo();
int duasLetras(int posicao, int wordLength, char word[]);
int buscaString(char *vetorStr[], char str[], int size);