//
// Created by mferreira on 1/12/22.
//

#ifndef TESTE_UTILS_H
#define TESTE_UTILS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "funcao.h"

void initRand();

int randomMinMax(int min, int max);

float rand01();

void substitui(int a[], int b[], int n);

int *inicializarDados(char *nomeFicheiro, int *vertices);

void mostrarMatriz(int *matriz, int vertices);

void gerarSolucaoInicial(int *solucao, int vertices);

void escreveSolucao(int *solucao, int vertices);

#endif //TESTE_UTILS_H
