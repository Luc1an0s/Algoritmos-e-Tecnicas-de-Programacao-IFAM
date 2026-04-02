#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "");
int num1, num2, soma;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    soma = num1 + num2;
    printf("A soma dos números são: %d\n", soma);
    return 0;

}