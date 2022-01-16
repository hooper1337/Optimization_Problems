//
// Created by Hugo on 16/01/2022.
//
#define _CRT_SECURE_NO_WARNINGS 1
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define GENERATIONS_TC  100
#define PROBGERAVIZ     1.0

// Calcula a qualidade de uma soluï¿½ï¿½o
// Parï¿½metros de entrada: soluï¿½ï¿½o (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parï¿½metros de saï¿½da: qualidade da soluï¿½ï¿½o (se a capacidade for excedida devolve 0)
float eval_individual(int sol[], struct info d, int *mat, int *v){
    int total = 0;
    int i, j;
    int zeros=0;

    for (i = 0; i < d.numGenes; i++){
        if (sol[i] == 0)
        {
            for (j = 0; j < d.numGenes; j++)
                if (sol[j] == 0 && *(mat+i*d.numGenes+j) == 1)
                    total++; //total Ã© o numero de ligaÃ§oes entre os membros dos grupos de 0's
        }
    }
    if(total == 0){
        //conta os zeros
        //ciclo for para contar os zeros
        for(i=0;i<d.numGenes;i++){
            if(sol[i] == 0){
                zeros++;
            }
        }
        *v = 1;
        return zeros;//numero de zeros;
    }
    else{
        *v = 0;
        return -total;
    }

}

// Calcula a qualidade de uma soluï¿½ï¿½o com penalizaï¿½ï¿½o
// Parï¿½metros de entrada: soluï¿½ï¿½o (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parï¿½metros de saï¿½da: qualidade da soluï¿½ï¿½o (se a capacidade for excedida devolve 0)

/*
float eval_individual_penalizado(int sol[], struct info d, int mat[][2], int *v){
	int     i;
	float   sum_weight, sum_profit;

	sum_weight = sum_profit = 0;
	// Percorre todos os objectos
	for (i=0; i < d.numGenes; i++)
	{
        // Verifica se o objecto i esta na mochila
		if (sol[i] == 1)
		{
            // Actualiza o peso total
			sum_weight += mat[i][0];
            // Actualiza o lucro total
			sum_profit += mat[i][1];
            // Obtem o melhor ro
            if (d.ro < (float)mat[i][1]/mat[i][0])
                d.ro = (float)mat[i][1]/mat[i][0];
		}
	}
	if (sum_weight > d.capacity)
	{
        // Soluï¿½ï¿½o invï¿½lida
		*v = 0;
		return sum_profit-(sum_weight-d.capacity)*d.ro; // Solucao com penalizaï¿½ï¿½o
	}
	else
	{
        // Soluï¿½ï¿½o vï¿½lida
		*v = 1;
		return sum_profit;
	}
}
*/
// Calcula a qualidade de uma soluï¿½ï¿½o com reparaï¿½ï¿½o aleatï¿½ria
// Parï¿½metros de entrada: soluï¿½ï¿½o (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parï¿½metros de saï¿½da: qualidade da soluï¿½ï¿½o (se a capacidade for excedida devolve 0)
float eval_individual_reparado1(int sol[], struct info d, int * mat, int *v){int total = 0;
    int i, j;
    int zeros=0;



    for (i = 0; i < d.numGenes; i++){
        if (sol[i] == 0)
        {
            for (j = 0; j < d.numGenes; j++)
                if (sol[j] == 0 && * (mat+i*d.numGenes+j) == 1) {
                    total++; //total é o numero de ligaçoes entre os membros dos grupos de 0's
                }
        }
    }
    if(total == 0){
        //conta os zeros
        //ciclo for para contar os zeros
        for(i=0;i<d.numGenes;i++){
            if(sol[i] == 0){
                zeros++;
            }
        }
        *v = 1;
        return zeros;//numero de zeros;
    }
    else{
        while (total != 0) {


            do{
                i = random_l_h(0, d.numGenes-1);
            }
            while(sol[i] != 0);


            sol[i] = 1;

            total = 0;

            for (i = 0; i < d.numGenes; i++){

                if (sol[i] == 0)
                {
                    for (j = 0; j < d.numGenes; j++)
                        if (sol[j] == 0 && * (mat+i*d.numGenes+j) == 1) {
                            total++; //total é o numero de ligaçoes entre os membros dos grupos de 0's
                        }
                }
            }
        }
        zeros = 0;
        for(i=0;i<d.numGenes;i++){
            if(sol[i] == 0){
                zeros++;
            }
        }
        *v = 1;
        return zeros;
    }
}

// Calcula a qualidade de uma soluï¿½ï¿½o com reparaï¿½ï¿½o de acordo com uma heirï¿½stica sofrega
// Parï¿½metros de entrada: soluï¿½ï¿½o (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parï¿½metros de saï¿½da: qualidade da soluï¿½ï¿½o (se a capacidade for excedida devolve 0)
float eval_individual_reparado2(int sol[], struct info d, int mat[][2], int *v){
/*
	int     i, mv, pos;
	float   sum_weight, sum_profit;

	sum_weight = sum_profit = 0;
	// Percorre todos os objectos
	for (i=0; i < d.numGenes; i++)
	{
        // Verifica se o objecto i esta na mochila
		if (sol[i] == 1)
		{
            // Actualiza o peso total
			sum_weight += mat[i][0];
            // Actualiza o lucro total
			sum_profit += mat[i][1];
		}
	}
	// Processo de reparacao 2
    while (sum_weight > d.capacity)
    {
        pos = -1;
        for (i=0; i < d.numGenes; i++)
        {
            if (sol[i] == 1)
            {
                if  (pos == -1 || mv > mat[i][1])
                {
                    mv = mat[i][1];
                    pos = i;
                }
            }
        }
        sol[pos] = 0;
        sum_weight -= mat[pos][0];
        sum_profit -= mat[pos][1];
    }
    *v = 1;
	return sum_profit;
	*/
}

// Avaliacao da populaï¿½ï¿½o
// Parï¿½metros de entrada: populacao (pop), estrutura com parametros (d) e matriz com dados do problema (mat)
// Parï¿½metros de saï¿½da: Preenche pop com os valores de fitness e de validade para cada soluï¿½ï¿½o
void evaluate(pchrom pop, struct info d, int *mat)
{
    int i;

    for (i=0; i<d.popsize; i++)
        pop[i].fitness = eval_individual(pop[i].p, d, mat, &pop[i].valido);
    // Exercï¿½cio 4.2(b)
    //pop[i].fitness = eval_individual_reparado1(pop[i].p, d, mat, &pop[i].valido);
}

void gera_vizinho(int sol[], int solViz[], int *mat, int nGenes)
{
    int i, menorCustoIn, maiorCustoOut, p1, p2;

    // Copia a soluï¿½ï¿½o para a soluï¿½ï¿½o vizinha
    for (i=0; i < nGenes; i++)
        solViz[i] = sol[i];
    if (rand_01() < PROBGERAVIZ)
    {
        // escolhe um objeto aleatoriamente
        i = random_l_h(0, nGenes-1);
        solViz[i] = !solViz[i];
    }
    else
    {
        menorCustoIn = MAX_OBJ;
        maiorCustoOut = 0;
        for (i=0; i < nGenes; i++)
        {
            if (sol[i] == 1 && menorCustoIn > *mat)
            {
                menorCustoIn = *mat;
                p1 = i;
            }
            if (sol[i] == 0 && maiorCustoOut < *mat)
            {
                maiorCustoOut = *mat;
                p2 = i;
            }
        }
        solViz[p1] = 0;
        solViz[p2] = 1;
    }
}

void trepa_colinas(pchrom pop, struct info d, int *mat)
{
    int     i, j;
    chrom   vizinho;

    for (i=0; i<d.popsize; i++)
    {
        for (j=0; j<GENERATIONS_TC; j++)
        {
            gera_vizinho(pop[i].p, vizinho.p, mat, d.numGenes);
            vizinho.fitness = eval_individual(vizinho.p, d, mat, &vizinho.valido);
            if (vizinho.fitness >= pop[i].fitness)
                pop[i] = vizinho;
        }
    }
}

