#include <stdio.h>
#include <stdlib.h> 
#include <windows.h> 

void tempo(int segundos) {
        Sleep(segundos * 1000); 
}

int main() {
    int numero, intervalo;

    printf("Digite o numero inicial para a contagem: ");
    scanf("%d", &numero);

    printf("Digite o intervalo entre a contagem (em segundos): ");
    scanf("%d", &intervalo);

    printf("\nIniciando contagem regressiva...\n");

    
    for (int i = numero; i >= 0; i--) {
        printf("%d...\n", i);
        
        if (i > 0) {
            tempo(intervalo);
        }
    }

    printf("\nFIM DA CONTAGEM!\n");

    return 0;
}