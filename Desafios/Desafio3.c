#include <stdio.h>

int lerInteiro(char mensagem[]);
float lerNumDecimal(char mensagem[]);
void soma();
void subtracao();
void multiplicacao();
void divisao();

int main(){
    void (*menu[4])()= {soma, subtracao, multiplicacao, divisao};
    int escolha;


    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("Qualquer outra tecla para sair");
    escolha = lerInteiro("Escolha a operacao que deseja realizar:\n");

    if (escolha >= 1 && escolha <= 4)
        menu[escolha - 1]();

    return 0;
}


int lerInteiro(char mensagem[]){
    int valor;
    printf("%s", mensagem);
    scanf("%d", &valor);
    getchar();

    return valor;
}

float lerNumDecimal(char mensagem[]){
    float valor;
    printf("%s", mensagem);
    scanf("%f", &valor);
    getchar();

    return valor;
}

void soma(){
    int resultado;
    int x, y;
    x = lerInteiro("Digite o primeiro valor:\n");
    y = lerInteiro("Digite o segundo valor:\n");

    resultado = x + y;

    printf("a soma desses numero e %d", resultado);
}

void subtracao(){
    int resultado;
    int x, y;
    x = lerInteiro("Digite o primeiro valor:\n");
    y = lerInteiro("Digite o segundo valor:\n");

    resultado = x - y;

    printf("a subtracao desses numero e %d", resultado);
}

void multiplicacao(){
    int resultado;
    int x, y;
    x = lerInteiro("Digite o primeiro valor:\n");
    y = lerInteiro("Digite o segundo valor:\n");

    resultado = x * y;

    printf("a multiplicacao desses numero e %d", resultado);
}

void divisao(){
    float resultado;
    float x, y;
    x = lerNumDecimal("Digite o primeiro valor:\n");
    y = lerNumDecimal("Digite o segundo valor:\n");
    if (y == 0)
        printf("nao existe divisao por 0");
    else{
       resultado = x/ y;

    printf("a divisao desses numero e %.2f", resultado);
    }
}
