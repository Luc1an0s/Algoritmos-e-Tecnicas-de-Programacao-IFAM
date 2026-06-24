#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <windows.h>
#endif

#define TAM_TEXTO 50
#define TAM_VETOR 2

typedef struct {
    char rua[TAM_TEXTO];
    int numero;
    char bairro[TAM_TEXTO];
    char complemento[TAM_TEXTO];
    char cidade[TAM_TEXTO];
    char UF[TAM_TEXTO];
} endereco;

typedef struct {
    char nome[TAM_TEXTO];
    endereco end;
    int telefone;
} pessoa;

void lerString(char* destino){
    scanf(" %[^\n]", destino);
}

void lerInt(int* destino){
    scanf("%d", destino);
}

int main(){
    pessoa pessoas[TAM_VETOR];

    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    printf("=== Cadastro de Pessoas ===\n");
    for(int i = 0; i < TAM_VETOR; i++){
        printf("\nCadastro da Pessoa %d:\n", i + 1);
        printf("Nome: ");
        lerString(pessoas[i].nome);
        printf("Rua: ");
        lerString(pessoas[i].end.rua);
        printf("Número: ");
        lerInt(&pessoas[i].end.numero);
        printf("Bairro: ");
        lerString(pessoas[i].end.bairro);
        printf("Complemento: ");
        lerString(pessoas[i].end.complemento);
        printf("Cidade: ");
        lerString(pessoas[i].end.cidade);
        printf("UF: ");
        lerString(pessoas[i].end.UF);
        printf("Telefone: ");
        lerInt(&pessoas[i].telefone);
    }
    
    printf("\n=== Resumo dos Cadastros ===\n");
    for(int i = 0; i < TAM_VETOR; i++){
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Endereço: %s, Nº %d - Bairro: %s, Complemento: %s, Cidade: %s, UF: %s\n",
               pessoas[i].end.rua, pessoas[i].end.numero, pessoas[i].end.bairro,
               pessoas[i].end.complemento, pessoas[i].end.cidade, pessoas[i].end.UF);
        printf("Telefone: %d\n", pessoas[i].telefone);
    }

    return 0;
}