/* Unai García Blanco */

/* PA1 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 5                // capacidad del cubo
#define CUBOS 20           // Número de cubos en el area prima
#define CUBOSDESBORDE  4   // Número de cubos area de desborde

typedef struct {
	char dni[9];
	char nombre[19];
	char ape1[19];
	char ape2[19];
	char provincia[11];
} tipoAlumno;


typedef struct {
	tipoAlumno reg[C];
	int cuboDES;      // De momento no la vamos a utilizar
	int numRegAsignados;
} tipoCubo;

// Funciones
void creaHvacio(char *fichHash);
int leeHash(char *fichHash);
int creaHash(char *fichEntrada,char *fichHash);
tipoAlumno * busquedaHash(FILE *f, char *dni, int *nCubo, int *ncuboDes, int *posReg, int *error);
int modificarReg(char *fichero, char *dni, char *provincia);
int desborde(FILE * fHash, tipoAlumno reg, int cubos, int cubosDesborde);



