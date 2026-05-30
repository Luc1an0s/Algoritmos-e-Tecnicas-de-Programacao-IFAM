#include <stdio.h>
#define TAM 50
size_t meu_strlen(const char *s);

size_t meu_strlen(const char *s) {
    const char *cont = s;
    while (*s != '\0') {
        s++;
    }
    return s - cont;
}

int main(){
    int i;
    char palavra[TAM];

    printf("Digite a palavra:\n");
    fgets(palavra, TAM, stdin);
    palavra[strcspn(palavra,"\n")]='\0';

    i = meu_strlen(palavra);
    printf("contador: %d", i);

    return 0;
}
