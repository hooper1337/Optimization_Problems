//
// Created by Hugo on 16/01/2022.
//

#ifndef EVOLUTIVO_ALGORITMO_H
#define EVOLUTIVO_ALGORITMO_H
#define MAX_OBJ 500		// Numero maximo de objectos

// EStrutura para armazenar parametros
struct info
{

    int     popsize;
    float   pm;
    float   pr;
    int     tsize;
    int     numGenes;
    int     numGenerations;
};

// Individuo (solu��o)
typedef struct individual chrom, *pchrom;

struct individual
{
    // Solu��o (objetos que est�o dentro da mochila)
    int     p[MAX_OBJ];
    // Valor da qualidade da solu��o
    float   fitness;
    // 1 se for uma solu��o v�lida e 0 se n�o for
    int     valido;
};

void tournament(pchrom, struct info, pchrom);

void tournament_geral(pchrom, struct info, pchrom);

void genetic_operators(pchrom, struct info, pchrom);

void crossover(pchrom, struct info, pchrom);

void mutation(pchrom, struct info);

void mutacao_por_troca(pchrom, struct info);

#endif //EVOLUTIVO_ALGORITMO_H
