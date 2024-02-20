#include <stdio.h>
#include <stdlib.h>

/*
    Alocação de arrays multidimensionais
        Para alocar um array com mais de uma dimensão, precisamos usar o conceito de ponteiro para ponteiro
*/

/*
    Ponteiro: cria um vetor
        int *p = malloc(5*sizeof(int));
        int* -> permite criar um array de int
    Ponteiro para ponteiro: permite criar uma matriz
        int **m;
        int** -> permite criar um array de int*
    Ponteiro para ponteiro para ponteiro: permite criar uma matriz de 3 dimensões
        int ***d;
*/

void DuasDimensoes()
{
    int **p;        // array de 2 dimensões
    int N = 2;
    p = (int **) malloc(N* sizeof(int*));
        // Aloca espaço para N ponteiros que apontam pro tipo int
        // Nesse caso, cada posição alocada é um ponteiro do tipo int (int*)
        // cada ponteiro aponta para um novo vetor
        // cria as linhas da matriz
        /*
            **p
            |int*|   ------->    |int ||int ||____||____|
            |____|   ------->    |____||____||____||____|
            |____|   ------->    |____||____||____||____|
            |____|   ------->    |____||____||____||____|
            |____|   ------->    |____||____||____||____|
            indice i                    indice j
        */
    for(int i=0; i<N; i++)
    {
        p[i] = (int*) malloc(N*sizeof(int));
            // criar um array de int* e atribuir a posição i do array p
            // cria as colunas da matriz
        for(int j=0; j<N; j++)
        {
            // lê a matriz de inteiros
            scanf("%d", &p[i][j]);
        }
    }
    // O primeiro malloc cria as linhas, o segundo, cria as colunas da matriz 

    // Para liberar a memória:
    for(int i=0; i<N; i++)
        free(p[i]);     // liberar colunas
    free(p);            // libera linhas
}



int main(){
    return 0;
}