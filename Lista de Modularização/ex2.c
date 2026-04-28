#include <stdio.h>

void conversaoTemp (float f){
	float c;
	c = (5.0/9.0)*(f - 32);
	
	printf("A temperatura em celsius e: %.2f", c);
}

int main(){
	float fahrenheit;
	
	printf("Digite em fahrenheit a temperatura que deseja converter para celsius:\n");
	scanf("%f", &fahrenheit);
	
	conversaoTemp(fahrenheit);
	
	return 0;
}