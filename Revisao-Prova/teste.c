#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
void lerInt(int *p) {
    printf("Digite um número inteiro: \n");
    scanf("%d", p);
    
}
int main (){
    int *array = (int *) malloc(SIZE * sizeof(int));
    if (array == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return 1; 
    }

    for (int i = 0; i < SIZE; i++) {
        lerInt(&array[i]);
    }

    free(array);
    return 0;
}