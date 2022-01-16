//
// Created by Hugo on 16/01/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include <string.h>



void logtofile(int num_iter,int best ,float mbf){
    FILE *out = fopen("output.txt", "a");

    fprintf(out, "%d\t%d\t%.2f\n",num_iter,best,mbf);
    fclose(out);
}


int* init_dados(char *nome, int *n){
    FILE    *f;
    int     *p;
    int     i, j, lig, lin, col;
    char    str[100];
    f=fopen(nome, "r");
    if(!f){
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }
    while(strcmp(str,"edge")){
        fscanf(f,"%s",str);
    }
    fscanf(f, "%d", n);

    fscanf(f, "%d", &lig);
    p = malloc(sizeof(int)*(*n)*(*n));
    if(!p){
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
    for(i=0; i<*n; i++)
        for(j=0; j<*n; j++)
            *(p+(*n)*i+j)=0;
    for(i=0; i<lig; i++)
    {
        fscanf(f, " e %d %d", &lin, &col);
        *(p+(*n)*(lin-1)+col-1)=1;
        *(p+(*n)*(col-1)+lin-1)=1;
    }
    fclose(f);
    return p;
}


int flip(){
    if ((rand() % 100) < 50)
        return 0;
    else
        return 1;
}

void gera_sol_inicial(int *sol, int v){
    int i;

    for (i = 0; i < v; i++)
        sol[i] = 0;



    for(i=0; i < v; i++)
        sol[i] = flip();

}

void escreve_sol(int *sol, int vert){
    int i;
    printf("\nConjunto: ");
    for (i = 0; i < vert; i++)
        printf("%2d", sol[i]);
}


void substitui(int a[], int b[], int n){
    int i;
    for (i = 0; i < n; i++)
        a[i] = b[i];
}

void init_rand(){
    srand((unsigned)time(NULL));
}

int random_l_h(int min, int max){
    return min + rand() % (max - min + 1);
}

float rand_01(){
    return ((float)rand()) / RAND_MAX;
}

void imprime_matriz(int *grafo, int vert){
    for (int i = 0; i < vert; i++) {
        printf("\n");
        for (int j = 0; j < vert; j++) {
            printf("%d ", grafo[i*vert+j]);
        }
    }
}
