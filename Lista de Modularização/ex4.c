#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void aleatorio(int quantidade, int faixa) {
    printf("Sorteando %d numeros entre 1 e %d:\n", quantidade, faixa);
    
    for (int i = 0; i < quantidade; i++) {
        int numeroSorteado = (rand() % faixa) + 1;
        printf("Numero %d: %d\n", i + 1, numeroSorteado);
    }
}

int main() {
    int qtd, limite;

    srand(time(NULL));

    printf("Quantos numeros voce deseja sortear? ");
    scanf("%d", &qtd);

    printf("Qual o valor maximo (faixa)? ");
    scanf("%d", &limite);

    aleatorio(qtd, limite);

    return 0;
}