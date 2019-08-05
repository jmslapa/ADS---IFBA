// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Joao Manuel dos Santos Lapa
//  email: lapeta96@gmail.com
//  Matrícula: 2018116028
//  Semestre: 2019.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>

int ehBissexto();
int qtdDiasMes();
int validaData();
int capturaDia();
int capturaMes();
int capturaAno();

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  if(x==1 || x==0)
	return 1;
  else
	return fatorial(x-1)*x;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){

    int datavalida=1;
    int di=0,mi=0,ai=0;
    int count;

    //captura dia e converte em int
    di=capturaDia(data,&count);
    
    //caputura mes e converte em int
    mi=capturaMes(data,&count);
    
    //captura ano e converte em int
    ai=capturaAno(data,&count);
    
    //valida data
    if(validaData(di,mi,ai)==1)
        return 1;
    else
        return 0;

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    

    int di,mi,ai,df,mf,af;
    int countI,countF;

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias=0, nMeses=0, nAnos=0;


    //quebra a data inicial em dia,mes e ano do tipo inteiro
    di=capturaDia(datainicial,&countI);
    mi=capturaMes(datainicial,&countI);
    ai=capturaAno(datainicial,&countI);

    //quebra a data final em dia,mes e ano do tipo inteiro
    df=capturaDia(datafinal,&countI);
    mf=capturaMes(datafinal,&countI);
    af=capturaAno(datafinal,&countI);

    //verifica validade de data inicial
    if (q1(datainicial) == 0)
        return 2;
    
    //verifica validade de data final    
    if (q1(datafinal) == 0)
        return 3;
    
    //verifica se a data incial é anterior à data final
    if (ai > af)
        return 4;
    else if(ai==af&&mi>mf)
        return 4;
    else if(ai==af&&mi==mf&&di>df)
        return 4;
        
    //calcula intervalo de tempo entre uma data e outra em dias, meses e anos.
    if(q1(datainicial)==1&&q1(datafinal)==1){
        
        if(df-di<0){
            nMeses--;
            nDias=(df-di)+qtdDiasMes(mf-1,af);
        }
        else
            nDias=df-di;

        
        if((mf-mi)+nMeses<0){
            nAnos--;
            nMeses=((mf-mi)+nMeses)+12;
        }
        else
            nMeses=(mf-mi)+nMeses;


        if((af-ai)+nAnos<0){
            nAnos=((af-ai)+nAnos)+1;
        }
        else
            nAnos=(af-ai)+nAnos;
    }

    //aloca o valor de dias, meses e anos no endereço de memória da variável correspondente
    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //retorno correspondente ao calculo correto da diferença de tempo entre as datas.
    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0;

    for(int i=0;texto[i]!='\0';i++){
        if(isCaseSensitive!=1){
            if(texto[i]==c+32||texto[i]==c-32||texto[i]==c)
               qtdOcorrencias++; 
        }
        else
            if(texto[i]==c)
                qtdOcorrencias++;
    }

    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0;
    char intTexto[250];
    char intBusca[50];
    int i=0,z=0,j=0,k=0,l=0,count=0,tamBusca=0;
    int pInicial=0,pFinal=0;
    
    //captura texto sem o -61
    for(i=0;strTexto[i]!='\0';i++){
        if(strTexto[i]!=-61){
            intTexto[j]=strTexto[i];
            j++;
        }
    }
    intTexto[j]='\0';
    j=0;
    
    //captura busca sem o -61
     for(i=0;strBusca[i]!='\0';i++){
        if(strBusca[i]!=-61){
            intBusca[j]=strBusca[i];
            j++;
        }
    }
    tamBusca=j;
    intBusca[j]='\0';
    j=0; 
        
    //busca palavra e posiçõefor(i=0;intTexto[i]!='\0';i++){
    for(i=0,j=0;intTexto[i]!='\0';i++){
        if(intTexto[i]==intBusca[j] || intTexto[i]==(intBusca[j]+32) || intTexto[i]==(intBusca[j]-32)){
            for(k=i,l=0;intBusca[l]!='\0';k++,l++){
                if(intTexto[k]==intBusca[l] || intTexto[k]==(intBusca[l]+32) || intTexto[k]==(intBusca[l]-32)){
                    count++;
                }
            }
            //valida condição para armazenar posicoes e contar ocorrencia
            if(count==tamBusca){
                posicoes[z]=i+1;
                posicoes[z+1]=k;
                z+=2;
                qtdOcorrencias++;
            }
        }
        count=0;
    }
    //retorna quantidade de ocorrencias
    return qtdOcorrencias;
 }

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
	int aux=num,b=1;
    if(num/10>0){
		    	
    	for(b;num>0;num/=10){
    		b*=10;
    	}

    	for(b/=10; aux>0; b/=10){
    		num+=(aux%10)*b;
    		aux/=10;
    	}
    }

    else 
        num=num;

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0, aux=numerobusca, b;
    
    if(numerobase/10>0){
		    	
    	for(b=1;aux>0;aux/=10){
    		b*=10;
    	}

        for(b=b;numerobase>0;numerobase/=10){
            if ((numerobase%b)==numerobusca)
                qtdOcorrencias++;
        }
    }

    else if (numerobase==numerobusca)
        qtdOcorrencias=1;
    else
        qtdOcorrencias=0;

    return qtdOcorrencias;
}





int ehBissexto(int ano){
    if((ano%4==0&&ano%100!=0)||ano%400==0)
        return 1;
    else
        return 0;
}

int qtdDiasMes(int mes, int ano){
    
    if(mes==1)
        return 31;

    else if(mes==2){
        if(ehBissexto(ano)==1)
            return 29;
        else
            return 28;
    }

    else if(mes%2!=0){
        if(mes<8)
            return 31;
        else
            return 30;
    }

    else{
        if(mes<8)
            return 30;
        else
            return 31;
    }
}

int capturaDia(char *data, int *count){
    char dd[3];
    int i;

    for(i=0;data[i]!='/';i++){
        dd[i]=data[i];
    }
    dd[i] = '\0';

    *count=i;

    return atoi(dd);
}

int capturaMes(char *data,int *count){
    char mm[3];
    int i,j=0;

    i=*count+1;

    for(;data[i]!='/';i++,j++){
        mm[j]=data[i];
    }    
    mm[j] = '\0';

    *count=i;

    return atoi(mm);
}

int capturaAno(char *data,int* count){
    char ano[5];
    int i,j=0;
    int ai;
    i=*count+1;

    for(;data[i]!='\0';i++,j++){
        ano[j]=data[i];
    }    
    ano[j] = '\0';

    *count=i;

    ai=atoi(ano);

    if(ai<20)
        ai+=2000;

    return ai;
}



int validaData(int di, int mi, int ai){
    
    //valida data
    if(ai<19&&ai<2000)
        return 0;

    else if(mi<1||mi>12)
        return 0;

    else if(mi==1){
        if(di>0&&di<=31)
            return 1;
        else
            return 0;
    }

    else if(mi==2){

        if(di==29){
            if (ehBissexto(ai)==1)
                return 1;
            else
                return 0;
        }
        else if(di>0&&di<29)
            return 1;
        else
            return 0;
    }
    
    else if(mi%2==0){
        if(mi<8){
            if(di>0&&di<31)
                return 1;
            else
                return 0;
        }
        else{
            if(di>0&&di<=31)
                return 1;
            else
                return 0;
        }
    }
    else if(mi%2!=0){
        if(mi<8){
            if(di>0&&di<=31)
                return 1;
            else
                return 0;
        }
        else{
            if(di>0&&di<31)
                return 1;
            else
                return 0;
        }
    }
    else
        return 0;
}
