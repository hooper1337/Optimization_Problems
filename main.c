#include "headers/utils.h"
#include "headers/algoritmo.h"

#define EXECUCOES_PADRAO 30

int main() {

    //Inicializa a geração dos números aleatórios
    initRand();

    char nomeFicheiro[100];
    int opcao, vertices, iteracoes, custo, melhorCusto = 0;
    int *matriz;
    int *solucao, *melhorSolucao;
    float mbf = 0.0;

    printf("Nome do ficheiro: ");
    fgets(nomeFicheiro, sizeof(nomeFicheiro) - 1, stdin);
    nomeFicheiro[strlen(nomeFicheiro) - 1] = '\0';

    matriz = inicializarDados(nomeFicheiro, &vertices);

    mostrarMatriz(matriz, vertices);

    // Menu
    printf("1- Trepa Colinas\n");
    printf("2- Algoritmo Evolutivo\n");
    printf("3- Algoritmo Hibrido\n");

    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        // Aloca espa�o em mem�ria para guardar as solucoes
        solucao = malloc(sizeof(int) * vertices);
        melhorSolucao = malloc(sizeof(int) * vertices);

        if (solucao == NULL || melhorSolucao == NULL) {
            printf("Erro na alocacao de memoria das solucoes!");
            exit(1);
        }

        printf("Numero de iteracoes: ");
        scanf("%d", &iteracoes);

        for (int i = 0; i < EXECUCOES_PADRAO; ++i) {
            gerarSolucaoInicial(solucao, vertices);

            escreveSolucao(solucao, vertices);

            custo = trepaColinas(solucao, matriz, vertices, iteracoes);

            printf("\nRepeticao %d:", i);

            escreveSolucao(solucao, vertices);

            printf("Custo final: %2d\n", custo);

            mbf += custo;

            // Guarda a melhor solu��o encontrada
            if (i == 0 || melhorCusto > custo) {
                melhorCusto = custo;
                substitui(melhorSolucao, solucao, vertices);
            }
        }

        // Calcula e mostra a m�dia dos custos de todas as melhores solu��es encontradas
        printf("\n\nMBF: %f\n", mbf / EXECUCOES_PADRAO - 1);

        // Mostra a melhor solu��o encontrada e o seu respectivo custo
        printf("\nMelhor solucao encontrada");

        escreveSolucao(melhorSolucao, vertices);

        printf("Custo final: %2d\n", melhorCusto);

        // Liberta a mem�ria usada
        free(matriz);
        free(solucao);
        free(melhorSolucao);
    }

    return 0;
}
