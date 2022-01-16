//
// Created by Hugo on 16/01/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define PROB 0.01
#define TMAX 0.99
#define TMIN 0.0001


void gera_vizinho(int a[], int b[], int n){
    int i, p1, p2;


    for(i = 0; i < n; i++)
        b[i] = a[i];


    p1 = random_l_h(0, n-1);
    b[p1] = !b[p1];
}

void gera_vizinho2(int a[], int b[], int n){
    int i, p1, p2, p3, p4;

    for(i = 0; i < n; i++)
        b[i] = a[i];

    p1 = random_l_h(0, n-1);
    do{
        p2 = random_l_h(0, n-1);
    }
    while(p1 == p2);
    b[p1] = !b[p1];
    b[p2] = !b[p2];
}



int trepa_colinas_probabilistico(int sol[], int *mat, int vert, int num_iter)
{
    int *nova_sol, custo, custo_viz, i;

    nova_sol = malloc(sizeof(int)*vert);
    if (nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    custo = calcula_fit(sol, mat, vert);
    for(i = 0; i < num_iter; i++)
    {
        //gera_vizinho(sol, nova_sol, vert);
        gera_vizinho2(sol, nova_sol, vert);
        custo_viz = calcula_fit(nova_sol, mat, vert);
        if (custo_viz >= custo)
        {
            substitui(sol, nova_sol, vert);
            custo = custo_viz;
        }
        else
        {
            if (rand_01() < PROB)
            {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
    }

    free(nova_sol);
    return custo;
}


