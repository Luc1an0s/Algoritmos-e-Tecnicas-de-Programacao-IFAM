#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mediaAnimais(){
	
	char especie, sexo, continuar;
	int contBovFem= 0, contBovMas= 0, contOvinFem= 0, contOvinMas= 0, contCapFem= 0, contCapMas= 0;
	float peso, pesoBovFem= 0, pesoBovMas= 0, pesoOvinFem= 0, pesoOvinMas= 0, pesoCapFem= 0, pesoCapMas= 0;
	
	do {
        printf("Selecione a especie do animal\n");

		printf("B - BOVINOS\n");
		printf("O - OVINOS\n");
		printf("C - CAPRINOS\n");
		scanf(" %c", &especie);
		
        especie = toupper(especie); 
        
        printf("Selecione o sexo do animal\n");
		printf("F - FEMININO\n");
		printf("M - MASCULINO\n");
		scanf(" %c", &sexo);
		
        sexo = toupper(sexo); 
        
        printf("Insira o peso do animal:\n");
        scanf("%f", &peso);
        
        switch (especie){
            case 'B': 
                if (sexo == 'F'){
                    contBovFem++;
                    pesoBovFem += peso;
                } else if(sexo == 'M'){
                    contBovMas++;
                    pesoBovMas += peso;
                }
                break;
            
            case 'O': 
                if (sexo == 'F'){
                    contOvinFem++;
                    pesoOvinFem += peso;
                } else if(sexo == 'M'){
                    contOvinMas++;
                    pesoOvinMas += peso;
                }
                break;
            
            case 'C': 
                if (sexo == 'F'){
                    contCapFem++;
                    pesoCapFem += peso;
                } else if(sexo == 'M'){
                    contCapMas++;
                    pesoCapMas += peso;
                }
                break;
            default: 
                printf("\nOpcao invalida!\n");
        }

        printf("Deseja inserir mais um animal? (S/N)\n");
        scanf(" %c", &continuar);
        
    } while (toupper(continuar) == 'S');
    
    printf("\n--- RESULTADOS (MEDIAS DE PESO) ---");
    printf("\nBovinos  - F: %.2f | M: %.2f", (contBovFem > 0) ? pesoBovFem/contBovFem : 0, (contBovMas > 0) ? pesoBovMas/contBovMas : 0);
    printf("\nOvinos   - F: %.2f | M: %.2f", (contOvinFem > 0) ? pesoOvinFem/contOvinFem : 0, (contOvinMas > 0) ? pesoOvinMas/contOvinMas : 0);
    printf("\nCaprinos - F: %.2f | M: %.2f\n", (contCapFem > 0) ? pesoCapFem/contCapFem : 0, (contCapMas > 0) ? pesoCapMas/contCapMas : 0);
}
   

int main(){
	mediaAnimais();
	return 0;
}