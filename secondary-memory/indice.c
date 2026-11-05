/* Unai García Blanco */

/* PA1 */


#include "indice.h"

int busquedaBinariaIndice(int numMat, char *dni, FILE *f) {
	int inicio = 0;
	int fin = ftell(f)/sizeof(tipoIndice);
	tipoIndice indice;
	
	while (inicio <= fin) {
		fseek (f, (fin+inicio)/2, SEEK_SET);
		fread(&indice, sizeof(tipoIndice), 1, f);
		if (indice.numMat == numMat) {
			strcpy(dni, indice.dni);
			return 0;
		} else {
			if (indice.numMat > numMat) {
				fin = (fin + inicio)/2 - 1;
			}
			else {
				inicio = (fin + inicio)/2 + 1;
			}
		}
	}
	return -1;
}

tipoAlumno * busqueda(int numMat, char *ficheroDatos, char *ficheroIndice, int *error) {
	FILE *fp;
	FILE *indice;
	tipoAlumno *reg = malloc(sizeof(tipoAlumno));
	tipoIndice indi;
	int nCubo, ncuboDes, posReg, perror;
	
	if (NULL == (fp = fopen(ficheroDatos, "rb"))) {
		*error = -2;
	}
	if (NULL == (indice = fopen(ficheroIndice, "rb"))) {
		*error = -3;
	}
	
	busquedaBinariaIndice(numMat, indi.dni, indice);
	reg = busquedaHash(fp, indi.dni, &nCubo, &ncuboDes, &posReg, &perror);
	
	fclose(indice);
	fclose(fp);
	
	*error = 0;
	return reg;
}
