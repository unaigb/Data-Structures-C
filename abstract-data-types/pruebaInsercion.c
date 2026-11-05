/*
** Fichero: pruebaInsercion.c
** Autor:
** Unai García Blanco
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas/lista.h"
#include "insercion.h"

long int contExt;
long int contInt;

int main(int argc, char *argv[])
{   
	Lista miLista;
	tipoPosicion p, aux;
	double tiempo, tInit, tFinal, t1, t2, tiempoTotal;
	int numElementos, codigoError, i;

	FILE *fichero = fopen("resultados.txt", "w+");
	srand(time(NULL));

	if (argc != 2) {
		printf("\n Uso: ./pruebaInsercion <número de elementos de la lista>\n\n");
		return -1;
	}

	t1=t2=(double)clock();
	numElementos=atoi(argv[1]); 

	printf("Creando lista vacía: %d\n", creaVacia(&miLista));

	printf("Se crea una lista de %d elementos\n", numElementos);
	anula(&miLista);	
	p = primero(&miLista);
	for (i = 0; i < numElementos; i++) { 
		codigoError = inserta(rand()%100000,p,&miLista);
		p = siguiente(p,&miLista);
	}

	printf("\nLista Original: \n");
	imprime(&miLista);

    printf("\nComienza la ordenación: \n");
    if (insercion(&miLista) != 0) {
		printf("Error al ordenar la list. Saliendo...");
		return -1;
	}

	printf("\nLista Ordenada: \n");
    imprime(&miLista);
    
	t2=(double)clock();
	tiempoTotal=(t2-t1)/(double)CLOCKS_PER_SEC;

	printf("\n\nTiempo total en ordenar %d elementos: %g", numElementos, tiempoTotal);
	printf("\n");

	printf("\nAnalisis de tiempo: \n");
	fprintf(fichero,"\nn\t\ttiempo\t\tCont Ext\t\tCont Int\n");

	aux=primero(&miLista);
	for(i=100; i<1000; i=i+100){
		anula(&miLista);
		aux=primero(&miLista);

		for(int j=0; j<i; j++){
			codigoError = inserta(rand()%100000, aux, &miLista);
			aux=siguiente(aux, &miLista);
		}
		
	    tInit = tFinal= (double)clock();

		insercion(&miLista);
		tFinal = (double) clock();

		tiempo=(tFinal-tInit) / (double)CLOCKS_PER_SEC;
		printf("Tiempo ejecucion para n=%d: %g\n", i, tiempo);
		fprintf(fichero,"%d", i);
		fprintf(fichero,"\t\t%8g", tiempo);
		fprintf(fichero,"\t\t%ld\t%ld\n", contExt, contInt);
    }

	fclose(fichero);

    anula(&miLista);
	destruye(&miLista); 

    return 0;
}
