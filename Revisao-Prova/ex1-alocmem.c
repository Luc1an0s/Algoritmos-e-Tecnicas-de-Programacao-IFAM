#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *vetor; 

    printf("Quantos números você quer guardar? ");
    scanf("%d", &n);

    vetor = malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return 1; 
    }
    
    for(i = 0; i < n; i++) {
        vetor[i] = (i + 1) * 10;
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    free(vetor);

    return 0;
}