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
#define TAM_EMAIL 50

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

//struct para dados do livro
typedef struct {
    int id;
    char titulo[TAM_TITULO];
    DadosAutor autor;
    char isbn[TAM_ISBN];
    int anoPublicacao;
    CategoriaLivro categoria;
    SituacaoLivro situacao;
    int ativo;
} Livro;

//struct para dados do usuario
typedef struct {
    int id;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char email[TAM_EMAIL];
    int livroEmprestadoId;
    int ativo;
} Usuario;

//prototipo das funções
void lerTexto(char *, int);
void lerInteiro(int *);
const char* categoriaParaTexto(CategoriaLivro);
const char* situacaoParaTexto(SituacaoLivro);
int encontrarLivroPorId(int, Livro [], int);
int encontrarUsuarioPorId(int, Usuario [], int);
void pausarTela();
void cadastrarLivro(Livro [], int *, int*);
void listarLivros(Livro [], int);
void listarLivrosDisponiveis(Livro [], int);
void buscarLivroPorTitulo(Livro [], int);
void buscarLivroPorCategoria(Livro [], int);
void atualizarLivro(Livro [], int);
void removerLivro(Livro [], int);
void cadastrarUsuario(Usuario [], int *, int*);
void listarUsuarios(Usuario [], int);
void buscarUsuarioPorNome(Usuario [], int);
void atualizarUsuario(Usuario [], int);
void removerUsuario(Usuario [], int);
void registrarDevolucao(Livro [], int, Usuario [], int);
void registrarEmprestimo(Livro [], int, Usuario [], int);
void listarEmprestimos(Livro [], int, Usuario [], int);
void menuLivros(Livro [], int *, int *);
void menuUsuarios(Usuario [], int *, int *);
void menuEmprestimos(Livro [], int, Usuario [], int);


int main() {}