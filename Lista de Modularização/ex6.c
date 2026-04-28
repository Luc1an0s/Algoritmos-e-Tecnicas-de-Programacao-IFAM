#include <stdio.h>
#include <stdlib.h>

void verificarDivisibilidade(int a, int b){
	if (b == 0){
		printf("Nao existe divisão com divisor igual a zero");
	} else if ((a/b)* b == a){
		printf("O numero %d e divisivel pelo numero %d", a, b);
	} else {
		printf("Nao e divisivel");
	}
}

int main (){
	int num1, num2;
	
	printf("divite o dividendo:\n");
	scanf("%d", &num1);
	printf("divite o divisor:\n");
	scanf("%d", &num2);
	
	verificarDivisibilidade(num1, num2);
	
	return 0;
}