//
// Created by Hugo on 16/01/2022.
//
#define _CRT_SECURE_NO_WARNINGS 1
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"
#define PROB 0.01
#define GENERATIONS_TC  100
#define PROBGERAVIZ     1.0


float eval_individual(int sol[], struct info d, int *mat, int *v){
    int total = 0;
    int i, j;
    int zeros=0;

    for (i = 0; i < d.numGenes; i++){
        if (sol[i] == 0)
        {
            for (j = 0; j < d.numGenes; j++)
                if (sol[j] == 0 && *(mat+i*d.numGenes+j) == 1)
                    total++;
        }
    }
    if(total == 0){
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


float eval_individual_reparado2(int sol[], struct info d, int mat[][2], int *v)
        {

}


void evaluate(pchrom pop, struct info d, int *mat)
{
    int i;

    for (i=0; i<d.popsize; i++)
        pop[i].fitness = eval_individual(pop[i].p, d, mat, &pop[i].valido);
}

void gera_vizinho(int sol[], int solViz[], int *mat, int nGenes)
{
    int i, menorCustoIn, maiorCustoOut, p1, p2;

    for (i=0; i < nGenes; i++)
        solViz[i] = sol[i];
    if (rand_01() < PROBGERAVIZ)
    {
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
            else
            {
                if(rand_01() < PROB)
                {
                    pop[i] = vizinho;
                }
            }
        }
    }
}

