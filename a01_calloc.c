#include<stdio.h>
#include<stdlib.h>
// Função calloc():
    // faz um pedido de memória ao computador e retorna um ponteiro com o endereço do inicio do espaço de memória alocado
    // parâmetro: void* calloc(unsigned int num, unsigned int size);
    // Funcionamento:
        // recebe por parâmetro o número de elementos no array a ser alocado e o tamanho de cada elemento do array
    // Retorno:
        // NULL: erro
        // ponteiro para a primeira posição do array

void CriarArray()
{
    int *v = calloc(50, 4);     // 4 bytes cada
        // 50 posições
    char *c = calloc(200, 1);   // 1 byte cada
        // 200 posições
}

void Utilizando_sizeof()
{
    int *v = calloc(50, sizeof(int));
    char *c = calloc(50, sizeof(char));
}

void VerificaMemoriaSuficiente()
{
    int *p;                                     // p inicia como ponteiro
    p = calloc(5, sizeof(int));
    if (p == NULL){
        printf("Erro.");
        exit(1);
    }
    for(int i=0; i<5; i++){
        printf("Digite p[%d]: ", i);
        scanf("%d", &p[i]);                     // agora, p é um vetor de inteiros
    }
    free(p);                                    // libera a memória alocada com o calloc()
}

int main()
{
    CriarArray();
    Utilizando_sizeof();
    VerificaMemoriaSuficiente();
    return 0;
}