//
// Created by Hugo on 16/01/2022.
//

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmo.h"
#include "utils.h"
#include <string.h>




void logtofile(chrom b, struct  info x,float mbf){
    FILE *out = fopen("output.txt", "a");


    fprintf(out, "%4.1f\t%.2f\t%d\t%.3f\t%.4f\t%d\t%d\t%d\n",b.fitness,mbf, x.popsize,	x.pr,	x.pm,	x.tsize,	x.numGenerations,x.numGenes);
    fclose(out);
}


void imprime_matriz(int *grafo, int vert)
{
    for (int i = 0; i < vert; i++)
    {
        printf("\n");
        for (int j = 0; j < vert; j++)
        {
            printf("%d ", grafo[i*vert+j]);
        }
    }
}

// Inicialização do geradores de números aleatórios
void init_rand(){
    srand((unsigned)time(NULL));
}

// Leitura dos paremetros e dos dados do problema.
// Par�metros de sa�da: Devolve a estrutura com os par�metros
void init_data(char *filename, int *mat, struct  info *x ){

    FILE    *f;
    char    str[100];
    int     i, j, lin, col;
    int     nrligacoes;

    // Leitura dos parametros do problema


    f=fopen(filename, "r");
    if(!f){
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }
    while(strcmp(str,"edge"))
        fscanf(f,"%s",str);
    // Numero de vertices
    fscanf(f, "%d", &x->numGenes);
    if (x->numGenes > MAX_OBJ)
    {
        printf("Number of itens is superior to MAX_OBJ\n");
        exit(1);
    }

    // Numero de ligações
    fscanf(f, "%d", &nrligacoes);
    // Preenchimento da matriz
    for(i=0; i<x->numGenes; i++)
        for(j=0; j<x->numGenes; j++)
            *(mat+(x->numGenes)*i+j)=0;
    for(i=0; i<nrligacoes; i++)
    {
        fscanf(f, " e %d %d", &lin, &col);
        *(mat+x->numGenes*(lin-1)+col-1)=1;
        *(mat+x->numGenes*(col-1)+lin-1)=1;
    }
    fclose(f);

    // Devolução da estrutura
    //return x;
}

// Simula o lan�amento de uma moeda, retornando o valor 0 ou 1
int flip(){
    if ((((float)rand()) / RAND_MAX) < 0.5)
        return 0;
    else
        return 1;
}

// Criacao da populacao inicial. O vector e alocado dinamicamente
// Par�metro de entrada: Estrutura com par�metros do problema
// Par�metro de sa�da: Preenche da estrutura da popula��o apenas o vector bin�rio com os elementos que est�o dentro ou fora da mochila
pchrom init_pop(struct info d){
    int     i, j;
    pchrom  indiv;

    indiv = malloc(sizeof(chrom)*d.popsize);
    if (indiv==NULL)
    {
        printf("Erro na alocacao de memoriaaa\n");
        exit(1);
    }
    for (i=0; i<d.popsize; i++)
    {
        for (j=0; j<d.numGenes; j++)
            indiv[i].p[j] = flip();
    }

/*	for (i=0; i<d.popsize; i++)
	{
		for (j=0; j<d.numGenes; j++)
			printf("%d", indiv[i].p[j]); //imprime pop
		printf("\n");
	}*/



    return indiv;
}

// Actualiza a melhor solu��o encontrada
// Par�metro de entrada: populacao actual (pop), estrutura com par�metros (d) e a melhor solucao encontrada at� a gera��oo imediatamente anterior (best)
// Par�metro de sa�da: a melhor solucao encontrada at� a gera��o actual
chrom get_best(pchrom pop, struct info d, chrom best){
    int i;

    for (i=0; i<d.popsize; i++)
    {
        if (best.fitness < pop[i].fitness)
            best=pop[i];
    }
    return best;
}

// Devolve um valor inteiro distribuido uniformemente entre min e max
int random_l_h(int min, int max){
    return min + rand() % (max-min+1);
}

// Devolve um valor real distribuido uniformemente entre 0 e 1
float rand_01(){
    return ((float)rand())/RAND_MAX;
}

// Escreve uma solu��o na consola
// Par�metro de entrada: populacao actual (pop) e estrutura com par�metros (d)
void write_best(chrom x, struct info d){
    int i;

    printf("\nBest individual: %4.1f\n", x.fitness);
    for (i=0; i<d.numGenes; i++)
        printf("%d", x.p[i]);
    putchar('\n');
}
