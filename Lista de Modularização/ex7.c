#include <stdio.h>
#include <math.h>

int arredondamento(double num){
	int parteinteira = (int)num;
	double partedecimal = num - parteinteira;
	
	if(partedecimal != 0.5){
		return (int)round(num);
	}
	
	if(parteinteira % 2 == 0){
		return parteinteira;
	} else {
		return parteinteira + 1;
	}
}

int main(){
	double num;
	
	printf("Digite o numero que deseja arredondar");
	scanf("%lf", &num);
	
	int resultado = arredondamento(num);
	
	printf("o valor arredondado eh: %d", resultado);
	
	return 0;
}