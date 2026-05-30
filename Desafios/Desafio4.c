#include <stdio.h>

int *buscaBinaria(int *arr, int n, int alvo) {
    int *inicio = arr;
    int *fim = arr + n - 1;
    int *meio;

    while (inicio <= fim) {
        meio = inicio + ((fim - inicio) / 2);

        if (*meio == alvo) {
            return meio;
        }
        if (*meio < alvo) {
            inicio = meio + 1;
        }
        if (*meio > alvo) {
            fim = meio - 1;
        }
    }
    return NULL;
}

int main() {
    int vetor[] = {20, 30, 40, 50, 80, 90, 100};
    int n = 7;
    int *resultado;
    int numero_buscado; 
    
    printf("Digite o numero que deseja buscar no vetor: ");
    scanf("%d", &numero_buscado);

    resultado = buscaBinaria(vetor, n, numero_buscado);

    if (resultado == NULL) {
        printf("Nao achou o numero\n");
    } else {
        printf("Achou o numero: %d\n", *resultado);
    }

    return 0;
}
