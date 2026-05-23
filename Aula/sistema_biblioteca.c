#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//definição de constantes
#define MAX_LIVROS 200
#define MAX_USUARIOS 100
#define TAM_TITULO 120
#define TAM_AUTOR 80
#define TAM_ISBN 20
#define TAM_NOME 80
#define TAM_CPF 15

//definição de cores
#define VERDE "\x1b[32m"
#define VERMELHO "\x1b[31m"
#define AMARELO "\x1b[33m"
#define CIANO "\x1b[35m"
#define RESET "\x1b[0m"

//Categoria dos livros
typedef enum {
    FICCAO = 1,
    NAOFICCAO,
    CIENCIA,
    HISTORIA,
    TECNOLOGIA,
    ARTE
} CategoriaLivro;

//Situação dos livros
typedef enum {
    DISPONIVEL = 1,
    EMPRESTADO,
    RESERVADO
} SituacaoLivro;

//Struct para dados do autor
typedef struct {
    char nome[TAM_AUTOR];
    char nacionalidade[50];
    int anoNascimento;
} DadosAutor;


int main() {}