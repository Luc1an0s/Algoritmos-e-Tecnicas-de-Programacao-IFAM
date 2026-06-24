#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <windows.h>
#endif

typedef struct {
    int x;
    int y;
} Ponto;

void verificaPosicao(Ponto p, Ponto v1, Ponto v2){
    if(p.x >= v1.x && p.x <= v2.x && p.y >= v1.y && p.y <= v2.y){
        printf("O ponto está dentro do retângulo.\n");
    } else {
        printf("O ponto está fora do retângulo.\n");
    }
}

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    Ponto v1 = {2, 2};
    Ponto v2 = {8, 6};

    Ponto p_dentro = {5, 4};
    Ponto p_fora = {10, 5};
    Ponto p_borda = {2, 6};

    printf("=== Retangulo Definido ===\n");
    printf("Inferior Esquerdo v1(%d, %d) | Superior Direito v2(%d, %d)\n\n", v1.x, v1.y, v2.x, v2.y);
    
    printf("=== Teste dos Pontos ===\n");
    verificaPosicao(p_dentro, v1, v2);
    verificaPosicao(p_fora, v1, v2);
    verificaPosicao(p_borda, v1, v2);
    
    return 0;
}