#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif
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
int lerInteiro(char []);
const char* categoriaParaTexto(CategoriaLivro);
const char* situacaoParaTexto(SituacaoLivro);
int encontrarLivroPorId(Livro [], int, int);
int encontrarUsuarioPorId(Usuario [], int, int);
void pausarTela();
void cadastrarLivro(Livro [], int *, int*);
void listarLivros(Livro [], int);
void listarLivrosDisponiveis(Livro [], int);
void buscarLivroPorTitulo(Livro [], int);
void buscarLivroPorCategoria(Livro [], int);
void atualizarLivro(Livro [], int);
void removerLivro(Livro [], int);
void cadastrarUsuario(Usuario [], int *, int*);
void listarUsuarios(Usuario [], int *);
void buscarUsuarioPorNome(Usuario [], int);
void atualizarUsuario(Usuario [], int);
void removerUsuario(Usuario [], int);
void registrarDevolucao(Livro [], int, Usuario [], int);
void registrarEmprestimo(Livro [], int, Usuario [], int);
void listarEmprestimos(Livro [], int, Usuario [], int);
void menuLivros(Livro [], int *, int *);
void menuUsuarios(Usuario [], int *, int *);
void menuEmprestimos(Livro [], int, Usuario [], int);
void limparTela();
void removerQuebraLinha(char []);
void configurarConsole();

int main() {
    configurarConsole();

    Livro acervo[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];

    int totalLivros = 0, proximoIdLivro = 1;
    int totalUsuarios = 0, proximoIdUsuario = 1;
    int op;

    do {
        limparTela();
        printf("\n%s=== SISTEMA DE BIBLIOTECA ===%s\n", CIANO, RESET);
        printf("1. Módulo de Livros\n2. Módulo de Usuários\n3. Módulo de Empréstimos\n0. Sair\n");
        op = lerInteiro("Opção: ");

        switch (op) {
            case 1: menuLivros(acervo, &totalLivros, &proximoIdLivro); break;
            case 2: menuUsuarios(usuarios, &totalUsuarios, &proximoIdUsuario); break;
            case 3: menuEmprestimos(acervo, totalLivros, usuarios, totalUsuarios); break;
            case 0: printf("%sSistema encerrado.%s\n", VERDE, RESET); break;
            default:
                printf("%sOpção inválida!%s\n", VERMELHO, RESET);
                pausarTela();
                break;
        }
    } while (op != 0);

    return 0;
}

void configurarConsole() {
    setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
//funçao auxiliar para ler texto
void lerTexto(char *texto, int tam) {
    fgets(texto, tam, stdin);
    removerQuebraLinha(texto);
}

//funçao para ler inteiro
int lerInteiro(char mensagem[]) {
    int valor;
    printf("%s%s%s", mensagem, RESET);
    scanf("%d", &valor);
    getchar();

    return valor;
}

void pausarTela() {
    printf("\n%sPressione ENTER para continuar...%s",AMARELO, RESET);
    getchar();
}

void removerQuebraLinha(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}

const char* categoriaParaTexto(CategoriaLivro cat) {
    switch (cat) {
        case FICCAO: return "Ficção";
        case NAOFICCAO: return "Não-Ficção";
        case CIENCIA: return "Ciência";
        case HISTORIA: return "História";
        case TECNOLOGIA: return "Tecnologia";
        case ARTE: return "Arte";
        default: return "Desconhecida";
    }
}

const char* situacaoParaTexto(SituacaoLivro sit) {
    switch (sit) {
        case DISPONIVEL: return "DISPONIVEL";
        case EMPRESTADO: return "EMPRESTADO";
        case RESERVADO : return "RESERVADO";
        default: return "Desconhecida";
    }
}

CategoriaLivro escolherCategoriaLivro() {
    int opcao;
    printf("%s%s%s", AMARELO, RESET);
    printf("\n%s1 - Ficção\n%s2 - Não-Ficção\n%s3 - Ciência%s\n", VERDE, VERDE, VERDE, RESET);
    printf("%s4 - História\n%s5 - Tecnologia\n%s6 - Arte%s\n", VERDE, VERDE, VERDE, RESET);

    do {
        opcao = lerInteiro("Escolha a categoria (1-6): ");
        if (opcao < 1 || opcao > 6) {
            printf("%sOpção inválida. Tente novamente.%s\n", VERMELHO, RESET);
        }
    } while (opcao < 1 || opcao > 6);

    return (CategoriaLivro) opcao;
    }

int encontrarLivroPorId(Livro acervo[], int tam, int id) {
    for (int i = 0; i < tam; i++) {
        if (acervo[i].id == id && acervo[i].ativo == 1) {
            return i;
        }
    }
    return -1;
}

int encontrarUsuarioPorId(Usuario usuarios[], int tam, int id) {
    for (int i = 0; i < tam; i++) {
        if (usuarios[i].id == id && usuarios[i].ativo == 1) {
            return i;
        }
    }
    return -1;
}

void cadastrarLivro(Livro acervo[], int *tam, int *proximoId) {
    Livro novo;
    novo.id = (*proximoId)++;
    novo.ativo = 1;
    novo.situacao = DISPONIVEL;

    printf("\n%s--- Cadastrar Livro ---%s\n", CIANO, RESET);

    printf("Título: ");
    lerTexto(novo.titulo, TAM_TITULO);

    printf("ISBN: ");
    lerTexto(novo.isbn, TAM_ISBN);

    novo.anoPublicacao = lerInteiro("Ano de Publicação: ");

    printf("Nome do Autor: ");
    lerTexto(novo.autor.nome, TAM_AUTOR);

    printf("Nacionalidade do Autor: ");
    lerTexto(novo.autor.nacionalidade, 50);

    novo.autor.anoNascimento = lerInteiro("Ano de Nascimento do Autor: ");
    novo.categoria = escolherCategoriaLivro();

    acervo[*tam] = novo;
    (*tam)++;

    printf("%sLivro cadastrado com sucesso! ID: %d%s\n", VERDE, novo.id, RESET);
}

void listarLivros(Livro acervo[], int tam) {
    int encontrou = 0;
    printf("\n%s--- Acervo Completo ---%s\n", CIANO, RESET);
    for (int i = 0; i < tam; i++) {
        if (acervo[i].ativo == 1) {
            printf("ID: %d | Título: %s | Autor: %s | Categoria: %s | Situação: %s\n",
                   acervo[i].id, acervo[i].titulo, acervo[i].autor.nome,
                   categoriaParaTexto(acervo[i].categoria), situacaoParaTexto(acervo[i].situacao));
            encontrou = 1;
        }
    }
    if (!encontrou) printf("%sNenhum livro cadastrado.%s\n", VERMELHO, RESET);
}

void listarLivrosDisponiveis(Livro acervo[], int tam) {
    int encontrou = 0;
    printf("\n%s--- Livros Disponíveis ---%s\n", CIANO, RESET);
    for (int i = 0; i < tam; i++) {
        if (acervo[i].ativo == 1 && acervo[i].situacao == DISPONIVEL) {
            printf("ID: %d | Título: %s | Autor: %s\n", acervo[i].id, acervo[i].titulo, acervo[i].autor.nome);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("%sNenhum livro disponível.%s\n", VERMELHO, RESET);
}

void buscarLivroPorTitulo(Livro acervo[], int tam) {
    char busca[TAM_TITULO];
    int encontrou = 0;
    printf("\nDigite parte do título: ");
    lerTexto(busca, TAM_TITULO);

    printf("\n%s--- Resultados da Busca ---%s\n", CIANO, RESET);
    for (int i = 0; i < tam; i++) {
        if (acervo[i].ativo == 1 && strstr(acervo[i].titulo, busca) != NULL) {
            printf("ID: %d | Título: %s | Situação: %s\n", acervo[i].id, acervo[i].titulo, situacaoParaTexto(acervo[i].situacao));
            encontrou = 1;
        }
    }
    if (!encontrou) printf("%sLivro não encontrado.%s\n", VERMELHO, RESET);
}

void buscarLivroPorCategoria(Livro acervo[], int tam) {
    CategoriaLivro cat = escolherCategoriaLivro();
    int encontrou = 0;
    printf("\n%s--- Livros na Categoria ---%s\n", CIANO, RESET);
    for (int i = 0; i < tam; i++) {
        if (acervo[i].ativo == 1 && acervo[i].categoria == cat) {
            printf("ID: %d | Título: %s | Autor: %s\n", acervo[i].id, acervo[i].titulo, acervo[i].autor.nome);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("%sNenhum livro nesta categoria.%s\n", VERMELHO, RESET);
}

void atualizarLivro(Livro acervo[], int tam) {
    int id = lerInteiro("Digite o ID do livro para atualizar: ");
    int idx = encontrarLivroPorId(acervo, tam, id);
    if (idx == -1) {
        printf("%sLivro não encontrado.%s\n", VERMELHO, RESET);
        return;
    }
    printf("Novo Título (Atual: %s): ", acervo[idx].titulo);
    lerTexto(acervo[idx].titulo, TAM_TITULO);
    printf("%sLivro atualizado.%s\n", VERDE, RESET);
}

void removerLivro(Livro acervo[], int tam) {
    int id = lerInteiro("Digite o ID do livro a ser removido: ");
    int j = encontrarLivroPorId(acervo, tam, id);
    if (j == -1) {
        printf("%sLivro não encontrado.%s\n", VERMELHO, RESET);
        return;
    }
    if (acervo[j].situacao == EMPRESTADO) {
        printf("%sNão é possível remover livro emprestado.%s\n", VERMELHO, RESET);
        return;
    }
    acervo[j].ativo = 0;
    printf("%sLivro removido (logicamente).%s\n", VERDE, RESET);
}

void menuLivros(Livro acervo[], int *tam, int *proximoId) {
    int op;
    do {
        limparTela();
        printf("\n%s=== MÓDULO DE LIVROS ===%s\n", CIANO, RESET);
        printf("1. Cadastrar Livro\n2. Listar Livros\n3. Listar Disponíveis\n");
        printf("4. Buscar por Título\n5. Buscar por Categoria\n");
        printf("6. Atualizar Livro\n7. Remover Livro\n0. Voltar\n");
        op = lerInteiro("Opção: ");

        switch(op) {
            case 1: cadastrarLivro(acervo, tam, proximoId); break;
            case 2: listarLivros(acervo, *tam); break;
            case 3: listarLivrosDisponiveis(acervo, *tam); break;
            case 4: buscarLivroPorTitulo(acervo, *tam); break;
            case 5: buscarLivroPorCategoria(acervo, *tam); break;
            case 6: atualizarLivro(acervo, *tam); break;
            case 7: removerLivro(acervo, *tam); break;
            case 0: break;
            default: printf("%sOpção inválida.%s\n", VERMELHO, RESET);
        }
        if (op != 0) pausarTela();
    } while (op != 0);
}

void cadastrarUsuario(Usuario usuarios[], int *tam, int *proximoId) {
    Usuario novo;
    novo.id = (*proximoId)++;
    novo.ativo = 1;
    novo.livroEmprestadoId = 0;

    printf("\nNome: ");
    lerTexto(novo.nome, TAM_NOME);
    printf("CPF: ");
    lerTexto(novo.cpf, TAM_CPF);
    printf("E-mail: ");
    lerTexto(novo.email, TAM_EMAIL);

    usuarios[*tam] = novo;
    (*tam)++;
    printf("%sUsuário cadastrado com sucesso! ID: %d%s\n", VERDE, novo.id, RESET);
}

void listarUsuarios(Usuario usuarios[], int *tam) {
    int encontrou = 0;
    printf("\n%s--- Lista de Usuários ---%s\n", CIANO, RESET);
    for (int i = 0; i < tam; i++) {
        if (usuarios[i].ativo == 1) {
            printf("ID: %d | Nome: %s | Empréstimo Ativo: %d\n",
                   usuarios[i].id, usuarios[i].nome, usuarios[i].livroEmprestadoId);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("%sUsuário não encontrado.%s\n", VERMELHO, RESET);
}

void buscarUsuarioPorNome(Usuario usuarios[], int tam) {
    char busca[TAM_NOME];
    int encontrou = 0;
    printf("\nDigite parte do nome: ");
    lerTexto(busca, TAM_NOME);

    for (int i = 0; i < tam; i++) {
        if (usuarios[i].ativo && strstr(usuarios[i].nome, busca) != NULL) {
            printf("ID: %d | Nome: %s | Email: %s\n", usuarios[i].id, usuarios[i].nome, usuarios[i].email);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("%sUsuário não encontrado.%s\n", VERMELHO, RESET);
}

void atualizarUsuario(Usuario usuarios[], int tam) {
    int id = lerInteiro("Digite o ID do usuário para atualizar: ");
    int idx = encontrarUsuarioPorId(usuarios, tam, id);
    if (idx == -1) {
        printf("%sUsuário não encontrado.%s\n", VERMELHO, RESET);
        return;
    }
    printf("Novo Nome (Atual: %s): ", usuarios[idx].nome);
    lerTexto(usuarios[idx].nome, TAM_NOME);
    printf("%sUsuário atualizado.%s\n", VERDE, RESET);
}

void removerUsuario(Usuario usuarios[], int tam) {
    int id = lerInteiro("Digite o ID do usuário a ser removido: ");
    int idx = encontrarUsuarioPorId(usuarios, tam, id);
    if (idx == -1) {
        printf("%sUsuário não encontrado.%s\n", VERMELHO, RESET);
        return;
    }
    if (usuarios[idx].livroEmprestadoId != 0) {
        printf("%sO usuário possui empréstimo pendente.%s\n", VERMELHO, RESET);
        return;
    }
    usuarios[idx].ativo = 0;
    printf("%sUsuário removido.%s\n", VERDE, RESET);
}

void menuUsuarios(Usuario usuarios[], int *tam, int *proximoId) {
    int op;
    do {
        limparTela();
        printf("\n%s=== MÓDULO DE USUÁRIOS ===%s\n", CIANO, RESET);
        printf("1. Cadastrar Usuário\n2. Listar Usuários\n3. Buscar Usuário\n");
        printf("4. Atualizar Usuário\n5. Remover Usuário\n0. Voltar\n");
        op = lerInteiro("Opção: ");

        switch(op) {
            case 1: cadastrarUsuario(usuarios, tam, proximoId); break;
            case 2: listarUsuarios(usuarios, *tam); break;
            case 3: buscarUsuarioPorNome(usuarios, *tam); break;
            case 4: atualizarUsuario(usuarios, *tam); break;
            case 5: removerUsuario(usuarios, *tam); break;
            case 0: break;
            default: printf("%sOpção inválida.%s\n", VERMELHO, RESET);
        }
        if (op != 0) pausarTela();
    } while (op != 0);
}

void registrarEmprestimo(Livro acervo[], int tLivros, Usuario usuarios[], int tUsuarios) {
    int idUser = lerInteiro("ID do Usuário: ");
    int idxUser = encontrarUsuarioPorId(usuarios, tUsuarios, idUser);
    if (idxUser == -1) {
        printf("%sUsuário não encontrado.%s\n", VERMELHO, RESET);
        return;
    }
    if (usuarios[idxUser].livroEmprestadoId != 0) {
        printf("%sUsuário já possui um empréstimo ativo.%s\n", VERMELHO, RESET);
        return;
    }

    int idLivro = lerInteiro("ID do Livro: ");
    int idxLivro = encontrarLivroPorId(acervo, tLivros, idLivro);
    if (idxLivro == -1 || acervo[idxLivro].situacao != DISPONIVEL) {
        printf("%sLivro indisponível ou não encontrado.%s\n", VERMELHO, RESET);
        return;
    }

    usuarios[idxUser].livroEmprestadoId = acervo[idxLivro].id;
    acervo[idxLivro].situacao = EMPRESTADO;
    printf("%sEmpréstimo realizado com sucesso!%s\n", VERDE, RESET);
}

void registrarDevolucao(Livro acervo[], int tLivros, Usuario usuarios[], int tUsuarios) {
    int idUser = lerInteiro("ID do Usuário devolvendo o livro: ");
    int idxUser = encontrarUsuarioPorId(usuarios, tUsuarios, idUser);

    if (idxUser == -1 || usuarios[idxUser].livroEmprestadoId == 0) {
        printf("%sUsuário não encontrado ou sem empréstimos.%s\n", VERMELHO, RESET);
        return;
    }

    int idxLivro = encontrarLivroPorId(acervo, tLivros, usuarios[idxUser].livroEmprestadoId);

    usuarios[idxUser].livroEmprestadoId = 0;
    if (idxLivro != -1) {
        acervo[idxLivro].situacao = DISPONIVEL;
    }
    printf("%sDevolução concluída.%s\n", VERDE, RESET);
}

void listarEmprestimos(Livro acervo[], int tLivros, Usuario usuarios[], int tUsuarios) {
    int encontrou = 0;
    printf("\n%s--- Empréstimos Ativos ---%s\n", CIANO, RESET);
    for (int i = 0; i < tUsuarios; i++) {
        if (usuarios[i].ativo && usuarios[i].livroEmprestadoId != 0) {
            int idxLivro = encontrarLivroPorId(acervo, tLivros, usuarios[i].livroEmprestadoId);
            if (idxLivro != -1) {
                printf("Usuário: %s | Livro: %s\n", usuarios[i].nome, acervo[idxLivro].titulo);
                encontrou = 1;
            }
        }
    }
    if (!encontrou) printf("%sNenhum empréstimo ativo.%s\n", VERMELHO, RESET);
}

void menuEmprestimos(Livro acervo[], int tLivros, Usuario usuarios[], int tUsuarios) {
    int op;
    do {
        limparTela();
        printf("\n%s=== MÓDULO DE EMPRÉSTIMOS ===%s\n", CIANO, RESET);
        printf("1. Registrar Empréstimo\n2. Registrar Devolução\n3. Listar Empréstimos\n0. Voltar\n");
        op = lerInteiro("Opção: ");

        switch(op) {
            case 1: registrarEmprestimo(acervo, tLivros, usuarios, tUsuarios); break;
            case 2: registrarDevolucao(acervo, tLivros, usuarios, tUsuarios); break;
            case 3: listarEmprestimos(acervo, tLivros, usuarios, tUsuarios); break;
            case 0: break;
            default: printf("%sOpção inválida.%s\n", VERMELHO, RESET);
        }
        if (op != 0) pausarTela();
    } while (op != 0);
}