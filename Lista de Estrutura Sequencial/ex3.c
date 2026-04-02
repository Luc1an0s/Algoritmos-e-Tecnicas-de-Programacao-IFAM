#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "");

    int num1, num2;
    float divisao;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    if (num2 != 0) {
        divisao = (float)num1 / num2;  // não sei se pode fazer conversão forçada, mas é necessário para obter o resultado com casas decimais!!
        printf("A divisão dos números é: %.2f\n", divisao);
    } else {
        printf("Erro: Divisão por zero não é permitida.\n");
    }
    return 0;
}