#include <stdio.h>
void bubbleSort(int *arr, int n) {
    int i, j, copia;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) { 
            if (*(arr + j) > *(arr + j + 1)) {
                copia = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = copia;
            }
        }
    }
}

int main() {
    int vetor[] = {50, 40, 30, 80, 10, 20, 55};
    int n = 7; 
    int i;

    bubbleSort(vetor, n);
    
    printf("Vetor ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("\n");

    return 0; 
}
