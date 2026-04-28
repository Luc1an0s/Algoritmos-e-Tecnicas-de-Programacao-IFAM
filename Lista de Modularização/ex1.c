#include <stdio.h>

void volumeEsfera(double raio){
	double pi = 3.14;
	
	double volume = (4.0/3.0)*pi*(raio*raio);
	
	printf("O volume da esfera eh: %.4lf\n", volume);
}

int main(){
	double raio;
	
	printf("Digite o valor do raio:\n");
	scanf("%lf", &raio);
	
	volumeEsfera(raio);
	
	return 0;
}