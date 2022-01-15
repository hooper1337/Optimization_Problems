//
// Created by mferreira on 1/12/22.
//

#include "../headers/funcao.h"

// Calcula a qualidade de uma solucao
// Parametros de entrada: Solucao actual, Matriz de adjacencias, N�mero de vertices
// Retorna o custo(total) - Neste caso, o numero de ligacoes que existem entre os vertices dos dois grupos
int calculaFitness(int solucaoAtual[], int *matriz, int vertices) {
    int total = 0;

    for (int i = 0; i < vertices; i++) {
        if (solucaoAtual[i] == 0) {
            for (int j = 0; j < vertices; j++) {
                if (solucaoAtual[j] == 1 && *(matriz + i * vertices + j) == 1) {
                    total++;
                }
            }
        }
    }

    return total;
}

void repara_sol(int solucaoAtual[], int *matriz, int vertices){

    for(int i = 0; i < vertices; i++){
        if(solucaoAtual[i] == 0){
            for(int j=0; j<vertices; j++){
                if(solucaoAtual[j] == 1 && *(matriz + i * vertices + j) == 1){
                    solucaoAtual[j] = 0;
                }
            }
        }
    }
}
