#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "utils.h"
#include "funcao.h"

#define DEFAULT_RUNS 30

int main(int argc, char *argv[])
{
    char    nome_fich[100];
    int     vert,  num_iter = 5000, k, runs, custo, best_custo;
    int     *grafo, *sol, *best;
    float   mbf = 0.0;



        printf("Nome do Ficheiro: ");
        gets(nome_fich);

        printf("Número de runs: ");
        scanf("%d", &runs);

    if (runs <= 0)
        return 0;
    init_rand();
    grafo = init_dados(nome_fich, &vert);


    imprime_matriz(grafo, vert);

    sol = malloc(sizeof(int)*vert);
    best = malloc(sizeof(int)*vert);
    if(sol == NULL || best == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    for(k=0; k<runs; k++)
    {
        gera_sol_inicial(sol, vert);
        puts("\n");
        printf("\nSolucao Inicial %d:", k);
        escreve_sol(sol, vert);


        custo = trepa_colinas_probabilistico(sol, grafo, vert, num_iter);

        printf("\nRepeticao %d:", k);
        escreve_sol(sol, vert);
        printf("\nCusto final: %2d\n", custo);
        mbf += custo;
        if(k==0 || best_custo <= custo)
        {
            best_custo = custo;
            substitui(best, sol, vert);
        }
    }
    printf("\n\nMBF: %f\n", mbf/k);
    printf("\nMelhor solucao encontrada: ");
    escreve_sol(best, vert);
    printf("\nCusto final: %2d\n", best_custo);
    puts("\n");
    logtofile(num_iter,best_custo,mbf/k);

    free(grafo);
    free(sol);
    free(best);
    return 0;
}
