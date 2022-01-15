//
// Created by mferreira on 1/12/22.
//

#include "../headers/utils.h"

// Inicializa o gerador de numeros aleatorios
void initRand() {
    srand((unsigned) time(NULL));
}

// Gera um valor inteiro aleatorio entre min e max
// Parametros de entrada: Valor inferior do intervalo, min, Valor superior do intervalo, max
// Parametros de saida: Valor aleatorio entre min e max
int randomMinMax(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Gera um valor inteiro aleatorio entre 0 e 1
// Parametros de saida: Valor aleatorio entre 0 e 1
float rand01() {
    return ((float) rand()) / RAND_MAX;
}

// Copia vector b para a (tamanho n)
// Parametros de entrada: Solucao que sera substituida, a, Solucao que ira substituir, b
//                        Numero de vertices, n
void substitui(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

// Leitura do ficheiro de input
// Recebe: nome do ficheiro, numero de vertices (vertices)
// Retorna a matriz de adjacencias
int *inicializarDados(char *nomeFicheiro, int *vertices) {
    FILE *file;
    int *matriz;
    int x, y;
    char *line;
    char delim[] = " ";
    size_t len = 0;


    file = fopen(nomeFicheiro, "r");

    if (!file) {
        printf("\nErro ao abrir o ficheiro\n");
        exit(1);
    }

    while ((getline(&line, &len, file)) != EOF) {
        char *ptr = strtok(line, delim);

        if (ptr) {
            if (ptr[0] == 'p') {
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);

                if (ptr) {
                    *vertices = atoi(ptr);

                    matriz = malloc(sizeof(int) * (*vertices) * (*vertices));

                    if (matriz == NULL) {
                        printf("Erro na alocação de memória da matriz!");
                        exit(1);
                    }

                    memset(matriz, 0, sizeof(int) * (*vertices) * (*vertices));
                }
            } else if (ptr[0] == 'e') {

                x = atoi(ptr = strtok(NULL, delim));
                y = atoi(ptr = strtok(NULL, delim));

                matriz[(x - 1) * (*vertices) + (y - 1)] = 1;
                matriz[(y - 1) * (*vertices) + (x - 1)] = 1;
            }
        }
    }

    return matriz;
}

void mostrarMatriz(int *matriz, int vertices) {
    int k = 0;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            printf("%d", matriz[k++]);
        }
        putchar('\n');
    }
}

// Gera a solucaoo inicial
// Parametros de entrada: Solucao, Numero de vertices
void gerarSolucaoInicial(int *solucao, int vertices) {
    int rnd;

    for (int i = 0; i < vertices; i++) {
        solucao[i] = 0;
    }

    for (int i = 0; i < vertices / 2; i++) {
        do {
            rnd = randomMinMax(0, vertices - 1);
        } while (solucao[rnd] != 0);

        solucao[rnd] = 1;
    }
}

// Escreve solucao no ecra
// Parametros de entrada: Solucao, Numero de vertices
void escreveSolucao(int *solucao, int vertices) {
    printf("\nConjunto A: ");
    for (int i = 0; i < vertices; i++) {
        if (solucao[i] == 0) {
            printf("%2d  ", i);
        }
    }

    printf("\nConjunto B: ");
    for (int i = 0; i < vertices; i++) {
        if (solucao[i] == 1) {
            printf("%2d  ", i);
        }
    }

    printf("\n");
}

float rand_01()
{
    return ((float)rand()) / RAND_MAX;
}
