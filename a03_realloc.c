#include <stdio.h>
#include <stdlib.h>

/*
    FUNÇÃO realloc()
    Funcionamento:
        recebe, por parâmetro, um ponteiro para um bloco de memória já alocado e a quantidade de bytes a ser alocada
    Retorno:
        NULL
        ponteiro com o endereço do inicio do espaço de memoria alocado
    procedimento: void* realloc(void* ponteiro, unsigned int tamanho);
*/

void Funcao_realloc(){
    // 50 inteiros 
    int *v = (int*) malloc(200);
    // aumenta para 100 inteiros
    v = realloc(v, 400);    //Redimensiona a memória para que possa armazenar mais elementos
}

void Utilizando_sizeof(){
    int *v = malloc(50*sizeof(int));
    v = realloc(v, 100*sizeof(int));
}

// Se o ponteiro para o bloco de memória previamente alocado for NULL, a função realloc() irá alocar a memória da mesma forma
// que a função malloc()
void caso1(){
    int *p;
    p = realloc(NULL, 50*sizeof(int));
    free(p);        // é equivalente a: p = realloc(p, 0)
}

void VerificarRealocacaoSemPerderOAnterior(){
    int *p = malloc(5*sizeof(int));
    int *p1 = realloc(p, 15*sizeof(int));
        // caso o realloc falhe, usasse p1, para não perder p
        // 
    if(p1 != NULL){
        p = p1;
    }
    free(p); free(p1);
}

void VerificarRealocao(){
    int *p = malloc(5*sizeof(int));
    p = realloc(p, 15*sizeof(int));
    if(p == NULL){
        printf("Erro: Sem memória.");
        exit(1);
    }
    free(p);
}

int main(){
    Funcao_realloc();
    Utilizando_sizeof();
    caso1();
    VerificarRealocacaoSemPerderOAnterior();
    return 0;
}