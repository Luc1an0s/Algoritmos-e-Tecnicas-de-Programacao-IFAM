#include <stdio.h>

enum semana{Domingo = 10, Segunda, Terca, Quarta, Quinta, Sexta, Sabado};

int main(){
    enum semana s1, s2, s3;

    s1=Segunda;
    s2=Terca;

    s3=s1+s2;

    printf("Domingo = %d\n", Domingo);
    printf("Segunda = %d\n", Segunda);
    printf("Terca = %d\n", Terca);#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

#define MAX_CONTATOS 100
#define TAM_NOME 80
#define TAM_TELEFONE 20
#define TAM_EMAIL 80
#define TAM_TEXTO 100

//Cores ANSI para deixar a interface mais amigável

#define RESET "\033[0m"
#define VERDE "\033[32m"
#define VERMELHO "\033[31m"
#define AMARELO "\033[33m"
#define AZUL "\033[34m"
#define CIANO "\033[36m"
#define BRANCO "\033[37m"
#define NEGRITO "\033[1m"

//enm usado para representar o tipo de contato
typedef enum{
    PESSOAL =1,
    TRABALHO,
    FAMILIA
}TipoContato;

//struct aninhada - será usada dentro da struct Contato

typedef struct{
    char rua[TAM_TEXTO];
    int numero;
    char bairro[TAM_TEXTO];
    char cidade[TAM_TEXTO];
}Endereco;

typedef struct{
    int id;
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
    Endereco endereco;
    TipoContato tipo;
    int favorito; //0= não favorito, 1 = favorito
    int ativo; //0= removido, 1 = ativo
}Contato;

//Prototipo das funções
void configurarConsole();
void limparTela();
void pausar();
void removerQuebraLinha(char texto[]);
void lerTexto(char mensagem[], char destino[], int tamanho);
int lerInteiro(char mensagem[]);
void exibirMenu();
void cadastrarContato(Contato agenda[], int *total, int *proximoId);
void listarContatos(Contato agenda[], int total);
void buscarContatoPorNome(Contato agenda[], int total);
void atualizarContato(Contato agenda[], int total);
void removerContato(Contato agenda[], int total);
void alterarContato(Contato agenda[], int total);
void listarFavoritos(Contato agenda[], int total);
 
int encontrarIndicePorId(Contato agenda[], int total);
const char* tipoParaTexto(TipoContato tipo);
TipoContato escolherTipoContato();
void imprimirContato(Contato contato);

//configurar a acentuação e UTF-8 no terminal

void configurarConsole(){
    setlocale(LC_ALL,"Portuguese_Brazil.UTF-8");
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif // _WIN32
}

//LIMPA A TELA DE ACORDO COM O SISTEMA OPERACIONAL

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//pausa a execucao
void pausar(){
    printf("\n%sPressione ENTER...%s", AMARELO, RESET);
    getchar();
}

void removerQuebraLinha(char texto[]){
    texto[strcspn(texto,"\n")]='\0';
}

void lerTexto(char mensagem[], char destino[], int tamanho){
    printf("%s%s%s", CIANO, mensagem, RESET);
    fgets(destino, tamanho, stdin);
    removerQuebraLinha(destino);
}

int lerInteiro(char mensagem[]){
    int valor;
    printf("%s%s%s", CIANO, mensagem, RESET);
    scanf("%d", &valor);
    getchar();

    return valor;
}

void exibirMenu(){
    printf("%s", NEGRITO);
    printf("\n================================\n");
    printf("      AGENDA DE CONTATOS\n");
    printf("\n================================\n");
    printf("%s", RESET);
    printf("%s1.%s Cadastrar Contato\n", VERDE, RESET);
    printf("%s2.%s Listar Contatos\n", VERDE, RESET);
    printf("%s3.%s Buscar Contato\n", VERDE, RESET);
    printf("%s4.%s Atualizar Contato\n", VERDE, RESET);
    printf("%s5.%s Remover Contato\n", VERDE, RESET);
    printf("%s6.%s Listar Favoritos\n", VERDE, RESET);
    printf("%s7.%s Marcar/Desmarcar Favorito\n", VERDE, RESET);
    printf("%s0.%s Sair\n", VERMELHO, RESET);
}

const char* tipoParaTexto(TipoContato tipo){
    switch(tipo){
        case PESSOAL:return "Pessoal";
        case TRABALHO:return "Trabalho";
        case FAMILIA:return "Desconhecido";
        default:return "Desconhecido";
    }
}

TipoContato escolherTipoContato(){
    int opcao;

    printf("\n%sTipo de contato:%s\n", VERMELHO, RESET);
    printf("1 - Pessoal\n");
    printf("2 - Trabalho\n");
    printf("1 - Familia\n");

    do{
        opcao = lerInteiro("Escolha um Tipo:");
        if(opcao < 1 || opcao > 3){
            printf("%sOpção inválida. Tente .%s\n", VERMELHO, RESET);
        }
    } while (opcao < 1 || opcao > 3);

    return (TipoContato)opcao;
}

void imprimirContato(Contato contato){
    printf("\n%s------------------------------%s\n", AZUL, RESET);
    printf("\n%sID: %s %d", NEGRITO, RESET, contato.id);
    printf("\n%Nome: %s %s", NEGRITO, RESET, contato.nome);
    printf("\n%sTelefone: %s %s", NEGRITO, RESET, contato.telefone);
    printf("\n%E-mail: %s %s", NEGRITO, RESET, contato.email);
    printf("%sFavorito:%s %s\n",
           NEGRITO,
           RESET,
           contato.favorito ? "Sim" : "Não");
    printf("\n%s------------------------------%s\n", AZUL, RESET);
}

void listarContatos(Contato agenda[], int total){
    int encontrou = 0;
    
    printf("\n%s=== Lista de Contatos ====%s\n", NEGRITO, RESET);
    
    for(int = 0; i < total; i++){
        if(agenda[i].ativo == 1){
            imprimirContato(agenda[i]);
            encontrou =1;
        }
    }
    if(!encontrou){
        printf("\n%sNenhum contato cadastrado.%s\n", VERMELHO, RESET);
    }    
}

void buscarContatoPorNome(Contato agenda[], int total){
    char busca[TAM_NOME];
    int encontrou = 0;
    
    printf("\n%s==== Buscar Contato ====%s\n", NEGRITO, RESET);
    lerTexto("Digite parte do nome: ", busca, TAM_NOME)
    for(int = 0; i < total; i++){
        if(agenda[i].ativo == 1 && strstr(agenda[i].nome, busca) != NULL){
            imprimirContato(agenda[i]);
            encontrou =1;
        }
    }
    if(!encontrou){
        printf("\n%sNenhum contato encontrado.%s\n", VERMELHO, RESET);
    } 
}

int encontrarIndicePorId(Contato agenda[], int total){
    int busca;
    
    printf("\n%s==== Buscar Contato ====%s\n", NEGRITO, RESET);
    busca = lerInteiro("Digite o id");
    
    for(int = 0; i < total; i++){
        if(agenda[i].ativo == 1 && agenda[i].id == busca) {
            return i;
        }
    }
    return -1; 
}

void atualizarContato(Contato agenda[], int total){
    int id;
    int indice;
    
    printf("\n%s===== Atualizar Contato =====%s\n", NEGRITO, RESET);
    listarContatos(agenda, total);
    
    id = lerInteiro("\nDigite o id do contato que deseja atualizar ");
    indice = encontrarIndicePorId(agenda, total, id);
    
    if(indice == -1){
        printf("%sContato não encontrado%s\n", VERMELHO, RESET);
        return;
    } 
    printf("\n%sDigite os novos dados do contato%s\n", AMARELO, RESET);
    lerTexto(,TAM_NOME);
    lerTexto(,TAM_TELEFONE);
    lerTexto(,TAM_EMAIL);
    lerTexto(,TAM_TEXTO);
    lerTexto(,TAM_TEXTO);
    lerTexto(,TAM_TEXTO);
}

void listarFavoritos(Contato agenda[], int total){
    int encontrou = 0;
    
    printf("\n%s==== Contatos Fvoritos ====%s\n", NEGRITO, RESET)        ;
    
    for(int i =0; i< total; i++){
        if(agenda[i].ativo == 1 && agenda[i].favorito = 1){
            imprimirContato(agenda[i]);
            encontrou = 1;
        }            
    }
    if(!encontrou){
        printf("\n%sNenhum contato favoritado.%s\n", VERMELHO, RESET);
    } 
}
int main (){

    return 0;
}
    printf("Quarta = %d\n", Quarta);
    printf("Quinta = %d\n", Quinta);
    printf("Sexta = %d\n", Sexta);
    printf("Sabado = %d\n", Sabado);
    printf("s1 = %d\n", s1);
    printf("s2 = %d\n", s2);
    printf("s3 = %d\n", s3);

    return 0;
}
