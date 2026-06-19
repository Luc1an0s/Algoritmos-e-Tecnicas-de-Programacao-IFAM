#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO_ESTOQUE "estoque.txt"

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;

} Produto;

void adicionarProduto();
int buscarPorId();
void removerProduto();
void salvarArquivo();
void carregarArquivo();
void imprimirRelatorio();

void carregarArquivo(void) {
    FILE *fp = fopen(ARQUIVO_ESTOQUE, "w");

    if (fp == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fclose(fp);

    printf("Arquivo inicial criado com sucesso.\n");
}

void adicionarProduto(void) {
    FILE *fp = fopen(ARQUIVO_ESTOQUE, "a");
    Produto produto;

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para adicionar dados.\n");
        return;
    }
    printf("Digite o Id:\n");
    scanf("%d", &produto.id);

    getchar();

    printf("Digite a descricao do produto:\n");
    fgets(produto.nome, sizeof(produto.nome), stdin);

    produto.nome[strcspn(produto.nome, "\n")] = '\0';

    printf("Digite a quantidade:\n");
    scanf("%d", &produto.quantidade);

    printf("Digite o preco:\n");
    scanf("%f", &produto.preco);

    getchar();

    fprintf(fp, "%d;%s;%d;%.2f\n", produto.id, produto.nome, produto.quantidade, produto.preco);

    fclose(fp);

    printf("Produto adicionado com sucesso.\n");
}

void imprimirRelatorio(void) {
    FILE *fp = fopen(ARQUIVO_ESTOQUE, "r");
    Produto produto;

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura formatada.\n");
        return;
    }

    printf("\n\t\t=== RELATORIO DE ESTOQUE ===\n");
    printf("\n----------------------------------------------------------\n");
    printf("\nID \t Nome \t\t\t\ Qtd \t Preco \t Total\n");
    while (fscanf(fp, "%d;%49[^;];%d;%f;%f\n", &produto.id, produto.nome, &produto.quantidade, &produto.preco) == 4) {
        printf("%d \t %s \t\t\t %d \t %.2f \t %.2f\n",
               produto.id,
               produto.nome,
               produto.quantidade,
               produto.preco,
               produto.quantidade*produto.preco);
    }
    printf("\n----------------------------------------------------------\n");

    fclose(fp);
}

void menu(void) {
    printf(" --- MENU ---\n");
    printf("1. Adicionar produto\n");
    printf("2. Buscar produto por ID\n");
    printf("3. Remover produto por ID\n");
    printf("4. Exibir relatorio de estoque\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

int main(){
      int opcao;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;

            case 2:
                printf("Ainda em desenvolvimento.\n");
                break;

            case 3:
                printf("Ainda em desenvolvimento.\n");
                break;

            case 4:
                imprimirRelatorio();
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 0);


    return 0;
}
