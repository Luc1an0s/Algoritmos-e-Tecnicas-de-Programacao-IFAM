#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <windows.h>
#endif

#define TAM_TEXTO 50

typedef struct {
    char nome[TAM_TEXTO];
    char rua[TAM_TEXTO];
    int numero;
    char bairro[TAM_TEXTO];
    char complemento[TAM_TEXTO];
    char cidade[TAM_TEXTO];
    char UF[TAM_TEXTO];
    int telefone1;
    int telefone2;
    int telefone3;
} endereco;

void lerString(char* destino){
    scanf(" %[^\n]", destino);
}

void lerInt(int* destino){
    scanf("%d", destino);
}

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    endereco meu_endereco;

    printf("=== Cadastro de Endereço (Usando scanf) ===\n");
    
    printf("Nome: ");
    lerString(meu_endereco.nome);

    printf("Rua: ");
    lerString(meu_endereco.rua);

    printf("Número: ");
    lerInt(&meu_endereco.numero);

    printf("Bairro: ");
    lerString(meu_endereco.bairro);

    printf("Telefone 1 (Apenas números): ");
    lerInt(&meu_endereco.telefone1);

    printf("Telefone 2 (Apenas números): ");
    lerInt(&meu_endereco.telefone2);
    
    printf("Telefone 3 (Apenas números): ");
    lerInt(&meu_endereco.telefone3);

    printf("\n=== Resumo dos Dados Cadastrados ===\n");
    printf("Nome: %s\n", meu_endereco.nome);
    printf("Endereço: %s, Nº %d - Bairro: %s\n", meu_endereco.rua, meu_endereco.numero, meu_endereco.bairro);
    printf("Telefone: %d\n", meu_endereco.telefone1);

    return 0;
}