#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void digitarValores(int v[]) {
    printf("\n--- Digitacao dos Valores ---\n");
    for (int i = 0; i < TAM; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &v[i]);
    }
}

void imprimirSomatorio(int v[]) {
    int soma = 0;
    for (int i = 0; i < TAM; i++) {
        soma += v[i];
    }
    printf("\nSomatorio dos itens: %d\n", soma);
}

void imprimirMedia(int v[]) {
    int soma = 0;
    for (int i = 0; i < TAM; i++) {
        soma += v[i];
    }
    float media = (float)soma / TAM;
    printf("\nMedia dos valores: %.2f\n", media);
}

void zerarNegativos(int v[]) {
    for (int i = 0; i < TAM; i++) {
        if (v[i] < 0) {
            v[i] = 0;
        }
    }
    printf("\nValores negativos substituidos por zero!\n");
}

void zerarRepetidos(int v[]) {
    for (int i = 0; i < TAM; i++) {
        if (v[i] > 0) {
            for (int j = i + 1; j < TAM; j++) {
                if (v[i] == v[j]) {
                    v[j] = 0; 
                }
            }
        }
    }
    printf("\nValores repetidos (maiores que zero) substituidos por zero!\n");
}



int main() {
    int vetor[TAM] = {0}; 
    int opcao;

    do {
        printf("\n========= MENU =========");
        printf("\n1 - Digitar valores");
        printf("\n2 - Ver Somatorio");
        printf("\n3 - Ver Media");
        printf("\n4 - Zerar Negativos");
        printf("\n5 - Zerar Repetidos");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: digitarValores(vetor); break;
            case 2: imprimirSomatorio(vetor); break;
            case 3: imprimirMedia(vetor); break;
            case 4: zerarNegativos(vetor); break;
            case 5: zerarRepetidos(vetor); break;
            case 0: printf("\nSaindo...\n"); break;
            default: printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}