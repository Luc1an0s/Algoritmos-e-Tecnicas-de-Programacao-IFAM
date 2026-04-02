#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "");

    float num1, num2, subtracao;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    subtracao = num1 - num2;
    printf("A subtração dos números são: %.2f\n", subtracao);
    return 0;
}