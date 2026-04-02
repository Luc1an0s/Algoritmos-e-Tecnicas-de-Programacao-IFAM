#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "");

    float nota1, nota2, peso1, peso2, media;

    printf("Digite a primeira nota: \n");
    scanf("%f", &nota1);
    printf("Digite o peso da primeira nota: \n");
    scanf("%f", &peso1);
    printf("Digite a segunda nota: \n");
    scanf("%f", &nota2);
    printf("Digite o peso da segunda nota: \n");
    scanf("%f", &peso2);
    media = (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
    printf("A média ponderada das notas é: %.2f\n", media);
    return 0;
}