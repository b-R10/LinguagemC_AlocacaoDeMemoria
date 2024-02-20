#include <stdio.h>
#include <stdlib.h>

struct ponto{
    int x, y;
};

// Função sizeof()
    // a função retorna o tamanho em bytes do dado fornecido.
void Funcao_sizeof(){
    printf("char: %lld\n", sizeof(char)); 
    printf("int: %lld\n", sizeof(int)); 
    printf("float: %lld\n", sizeof(float)); 
    printf("double: %lld\n", sizeof(double));
    printf("struct ponto: %lld\n", sizeof(struct ponto)); 
}

// Função malloc()
    // faz um pedido de memória ao computador e retorna um ponteiro com o endereço do início de espaço de memória alocado
    // protótipo: void malloc(unsigned int num);
    // funcionamento:
        // recebe por parâmetro a quantidade de bytes a ser alocada.
        // retorna um ponteiro para o início da área alocada ou NULL se não houver memória disponível.
void Funcao_malloc(){
    int *v = malloc(200);       // cria array de 50 inteiros (200 bytes)
        // a partir desse momento, se trabalha com v[0], v[1], ..., v[49]
    char *c = malloc(200);      // cria array de 200 caracteres (200 bytes)
}

void Utilizando_sizeof(){
    // int *v = (int*) malloc(200);        // (int*) ->  cast para informar que estamos trabalhando com int*
                                            // malloc retorna um ponteiro genérico, mas precisa ser 
                                            // convertido para o tipo correto
    // int *c = (char*) malloc(50);

    // Solução mais inteligente:
    int *v = (int*)malloc(50*sizeof(int));   // multiplicação é uma forma mais segura de indicarmos o tamanho correto
    int *c = (char*)malloc(50*sizeof(char));   // multiplicação é uma forma de indicarmos que queremos 50 chars
}

// Se não houver memória suficiente para alocar, a função malloc() retorna NULL
void VerificaMemoriaSuficiente(){
    int *p;
    p = malloc(5*sizeof(int));
    if(p == NULL){
        printf("Erro: Sem memória!\n");
        exit(1);    // termina o programa se dentro do int main()
    }
    for(int i=0; i<5; i++){
        printf("Digite p[%d]:", i);
        scanf("%d, &p[i]");
    }
    free(p);   // libera a memória ocupada por p[]
}



int main(){
    Funcao_sizeof();
    Funcao_malloc();
    Utilizando_sizeof();
    VerificaMemoriaSuficiente();
    return 0;
}