#include <stdio.h> 
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

void clearBuf(void);
int validFormat(const char*, void*);
int validar=1;

int main(){
	
	int i,j;
	char nombre[50];
	float notas[4][5];
	float promedios,media1,media2,aux;
	
	for(i=0;i<5;i++){
		
		printf("\nIngrese el nombre del alumno %i \n",i+1);
		scanf("%s",nombre);
		
		for(j=0;j<4;j++){
			
			verificacion: //marca un punto en el programa para poder retornar a el
				
		do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
					
		printf("\nIngrese la nota %i del alumno %i \n",j+1,i+1);			
					
		if(validFormat("%f",&notas[j][i])) continue; //validformat nos sirve para ingresar los datos y validarlos
			
		validar=notas[j][i]<=-1;//valida la opcion y si es menor saltara un error
			
		if(validar){//if que sirve para imprimir en pantalla el error
				
			printf("\n\nIngreso un numero invalido\n");
			printf("No se aceptan numeros menores o iguales 0\n\n"); //imprime en pantalla el error
			
		}
		}while(validar); //que retorna despues de mostrar el error
			
		if(notas[j][i]>20 or notas[j][i]>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
			printf("\n\nIngreso un numero demasiado alto o invalido\n");
			printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
			goto verificacion; //da la orden para que el programa vaya a un punto de este
				
		}
			
		
			
		}
		
	}
	
	for(i=0;i<5;i++){
		printf("\neste es el promedio de el alumno %i\n\n",i);
		for(j=0;j<4;j++){
		
			promedios=notas[j][i]+notas[j+1][i];
			aux=promedios/4;
			
		printf("\n\neste es el promedio de el alumno %i %f\n",i,aux);	
			
		}
	
	}

getch();	
}
int validFormat(const char* formato, void* variable){ /* Esto es para verificar variables */
	
	validar=1;//reseteamos la comprobacion de la opcion
    /* si se retorna 0 fue porque ocurrio un error*/
    
    if(!scanf(formato, variable) || (getchar() != '\n'))
    {
        
        clearBuf();/* Se utiliza para limpiar el buffer */
        
        printf("\n\n\tError\n\n");
        printf("\n\tUsted Ingreso una opcion no valida\n"); /* Se imprime en pantalla el error */
        printf("\n\tPor favor ingrese una opcion valida\n");
        system("pause");
		
        return 1;
    }
    
    return 0;
}

void clearBuf()
{
    int ch;
    /* Se utiliza para limpiar el buffer */
    while((ch = getchar()) != '\n' && ch != EOF);
}

