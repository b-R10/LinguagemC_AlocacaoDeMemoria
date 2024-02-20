#include <stdio.h>
#include <stdlib.h>

/*
    malloc() versus calloc()
        ambas alocam memória, mas, calloc inicializa todos os BITS do espaço alocado com 0's
*/

int main(){
    int *p, *p1;
    p = malloc(5*sizeof(int));
    p1 = calloc(5, sizeof(int));
    
    printf("malloc \t\t\tcalloc\n");
    for(int i=0; i<5; i++){
        printf("p[%d] = %d\t", i, p[i]);
        printf("p1[%d] = %d \n", i, p1[i]);
    }
    free(p); free(p1);
    return 0;
}