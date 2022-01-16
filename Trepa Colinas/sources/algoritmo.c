//
// Created by mferreira on 1/12/22.
//

#include "../headers/algoritmo.h"
#define TMAX 100
#define TMIN 5
// Gera um vizinho com distancia 1 (troca um vertice de cada grupo)
// Parametros de entrada: Solucao actual, Solucao vizinha, Numero de vertices
void geraVizinho(const int solucao[], int solucaoVizinha[], int vertices) {
    int vertice1, vertice2;

    // Copia a solucao atual para a solucao vizinha
    for (int i = 0; i < vertices; i++) {
        solucaoVizinha[i] = solucao[i];
    }

    // Encontra aleatoriamente a posicao de um vertice com valor 0
    do {
        vertice1 = randomMinMax(0, vertices - 1);
    } while (solucaoVizinha[vertice1] != 0);

    // Encontra aleatoriamente a posicao de um vertice com valor 1
    do {
        vertice2 = randomMinMax(0, vertices - 1);
    } while (solucaoVizinha[vertice2] != 1);

    // Troca os valores dos vertices encontrados
    solucaoVizinha[vertice1] = 1;
    solucaoVizinha[vertice2] = 0;
}

// Gera um vizinho com distancia 2 (troca dois vertices de cada grupo)
// Parametros de entrada: Solucao actual, Solucao vizinha, Numero de vertices
void geraVizinho2(int solucao[], int solucaoVizinha[], int vertices) {
    int vertice1, vertice2, vertice3, vertice4;

    // Copia solucao solu��o atual para solucao solu��o vizinha
    for (int i = 0; i < vertices; i++)
        solucaoVizinha[i] = solucao[i];
    // Encontra aleatoriamente solucao posi��o de um v�rtice com valor 0
    do
        vertice1 = randomMinMax(0, vertices - 1);
    while (solucaoVizinha[vertice1] != 0);
    // Encontra aleatoriamente solucao posi��o de um v�rtice com valor 1
    do
        vertice2 = randomMinMax(0, vertices - 1);
    while (solucaoVizinha[vertice2] != 1);
    // Troca os valores dos v�rtices das posi��es encontradas
    solucaoVizinha[vertice1] = 1;
    solucaoVizinha[vertice2] = 0;
    // Encontra aleatoriamente solucao posi��o de um v�rtice, que vertices�o seja igual solucao p2, com valor 0
    do
        vertice3 = randomMinMax(0, vertices - 1);
    while (solucaoVizinha[vertice3] != 0 || vertice3 == vertice2);
    // Encontra aleatoriamente solucao posi��o de um v�rtice, que vertices�o seja igual solucao p1, com valor 1
    do
        vertice4 = randomMinMax(0, vertices - 1);
    while (solucaoVizinha[vertice4] != 1 || vertice4 == vertice1);
    // Troca os valores dos v�rtices das posi��es encontradas
    solucaoVizinha[vertice3] = 1;
    solucaoVizinha[vertice4] = 0;
}

// Trepa colinas first-choice
// Parametros de entrada: Solucao, Matriz de adjacencias, Numero de vertices, Numero de iteracoes
// Retorna custo da melhor solucao encontrada
int trepaColinas(int solucao[], int *matriz, int vertices, int iteracoes) {
    int *novaSolucao, *novaSolucao2, custo, custoVizinho, custoVizinho2;

    // Alocacao de memoria para guardar as novas solucoes
    novaSolucao = malloc(sizeof(int) * vertices);
    novaSolucao2 = malloc(sizeof(int) * vertices);

    if (novaSolucao == NULL || novaSolucao2 == NULL) {
        printf("Erro na alocação de memória das soluções!");
        exit(1);
    }

    // Avalia solucao inicial
    custo = calculaFitness(solucao, matriz, vertices);

    for (int i = 0; i < iteracoes; ++i)
    {
        repara_sol(novaSolucao, matriz, vertices);
        geraVizinho(solucao, novaSolucao, vertices);
        //geraVizinho2(solucao, novaSolucao2, vertices);
        custoVizinho = calculaFitness(novaSolucao, matriz, vertices);
        //custoVizinho2 = calculaFitness(novaSolucao2, matriz, iteracoes);

        if (custoVizinho > custo)
        {
            substitui(solucao, novaSolucao, vertices);
            custo = custoVizinho;
        }

        /*if (custoVizinho > custoVizinho2)
        {
            if (custoVizinho > custo)
            {
                substitui(solucao, novaSolucao, vertices);
                custo = custoVizinho;
            }
        } else {
            if (custoVizinho2 > custo)
            {
                substitui(solucao, novaSolucao2, vertices);
                custo = custoVizinho2;
            }
        }*/
    }

    free(novaSolucao);
    free(novaSolucao2);

    return custo;
}

int recristalizacao_simulada(int sol[], int *mat, int vert, int num_iter)
{
    int     *nova_sol, custo, custo_viz, i, best_custo, *best_sol;
    float   t = TMAX, decrementoT;

    // Calculo da decrementa��o de T para ir de TMAX a TMIN en num_iter
    decrementoT = (TMAX - TMIN) / num_iter;
    // Aloca espa�o em mem�ria para guardar a nova solu��o e a melhor solu��o
    nova_sol = malloc(sizeof(int)*vert);
    best_sol = malloc(sizeof(int)*vert);
    // Caso n�o consiga fazer a aloca��o, envia aviso e termina o programa
    if(nova_sol == NULL || best_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    // Avalia solucao inicial
    custo = calculaFitness(sol, mat, vert);
    // Guarda essa solu��o inicial como a melhor
    best_custo = custo;
    substitui(best_sol, sol, vert);
    for(i=0; i < num_iter; i++)
    {
        // Gera solu��o vizinha
        geraVizinho(sol, nova_sol, vert);
        // Avalia solu��o vizinha
        custo_viz = calculaFitness(nova_sol, mat, vert);
        // Se a solu��o vizinha for melhor que a solu��o atual, guarda-a como a melhor solu��o
        if(custo_viz > best_custo)
        {
            best_custo = custo_viz;
            substitui(best_sol, nova_sol, vert);
        }
        // Fica com a solu��o vizinha se o custo n�o aumentar (problema de minimiza��o) em rela��o � solu��o atual
        if(custo_viz >= custo)
        {
            substitui(sol, nova_sol, vert);
            custo = custo_viz;
        }
        else
        {
            // Fica com a solu��o vizinha, apesar de pior, se o valor aleat�rio gerado for abaixo da probabilidade que se vai ajustando
            if (rand01() < exp((custo - custo_viz) / t))
            {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
        t = t - decrementoT;
    }
    // Retorna a melhor solu��o encontrada
    substitui(sol, best_sol, vert);
    // Liberta a mem�ria usada para guardar a nova solu��o e a melhor solu��o
    free(nova_sol);
    free(best_sol);
    // Devolve o custo da melhor solu��o encontrada
    return best_custo;
}
