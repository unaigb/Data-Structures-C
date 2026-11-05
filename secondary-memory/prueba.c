/* Unai García Blanco */

/* PA1 */

#include "indice.h"

int main(void){
	char opcion;
	
	//Variables Ejer 1
	tipoAlumno *encontrado;
	int nCubo, ncuboDes, posReg, valor, error, control=0;
	FILE *fp;
	
	//Variables Ejer 2
	FILE *indice;
	tipoAlumno *alumno;
	tipoIndice indi;
	tipoAlumno *reg;
	
	int numMat = 256418;
	char dni[9];
	
	/* Presentación */

	printf("============================================================\n");
	printf("                     MEMORIA SECUNDARIA                     \n");
	printf("============================================================\n");
	printf("\n");
	printf("        a) Ejercicio 1. Organizacion Directa. Dispersion    \n");
	printf("        b) Ejercicio 2. Busqueda binaria.                   \n");
	printf("        s) Salir                                            \n");
	printf("\n");
	printf("Opción?: "); scanf("%c", &opcion);
	printf("\n\n");
	
	/* Switch del menú */
	switch (opcion) {
		case 'a': 
		case 'A': 
			printf("Deseas reiniciar el fichero \"alumnos.hash\"??\n1) Si\nOtra cosa) No\n");
		    	scanf("%d", &control);
		    	if(control)
		    		creaHash("alumnos.dat","alumnos.hash");
		    	//Una vez creado busco por el hash correspondiente
		    	leeHash("alumnos.hash");
		    	if(NULL == (fp = fopen("alumnos.hash", "rb"))){
		    		printf("Error al abrir el fichero alumnos.hash\n");
		    		return -1;
		    	}
		    	encontrado = busquedaHash(fp, "12312389", &nCubo, &ncuboDes, &posReg, &error);
		    	fclose(fp);
		    	if(error == 0){
		   		printf("[*] Registro:");
		    		printf("\t %s %s %s %s %s\n\n",encontrado->dni,encontrado->nombre,encontrado->ape1,encontrado->ape2,encontrado->provincia);
		    		printf("[->] El numero de cubo es: %d\n", nCubo);
		    		printf("[->] El numero de cubo de desborde es: %d\n", ncuboDes);
		    		printf("[->] La posicion del registro es (empezando en 0): %d\n", posReg);
		    	}else if(error == -1){
		    		printf("No existe el registro\n");
		    	}else{
		    		printf("Error en la funcon: Cod. error [%d]\n", error);
		    	}
		    	control = modificarReg("alumnos.hash", "12312389", "ZAMORA");
		    	if(control == 0){
		    		printf("Modificado!!!\n");
		    	}
		break;

		case 'b': 
		case 'B': 
			if (NULL == (indice = fopen("numMat.idx", "rb"))) {
				printf("Error al abrir el fichero numMat.idx\n");
		    		return -1;
			}
			valor = busquedaBinariaIndice(numMat, dni, indice);
			if (valor == 0) {
				printf("El DNI asociado a la matricula %d es: %s\n", numMat, dni);
			} else if (valor == -1) {
				printf("No existe el registro asociado\n");
			} else {
				printf("Error en la funcion: Cod.error [%d]\n", valor);
			}
			fclose(indice);
			alumno = busqueda(numMat, "alumnos.hash", "numMat.idx", &error);
			if (error == 0) {
				printf("[*] Registro:");
		    		printf("\t %s %s %s %s %s\n",alumno->dni,alumno->nombre,alumno->ape1,alumno->ape2,alumno->provincia);
			} else if (error == -1) {
				printf("No existe el registro asociado\n");
			} else {
				printf("Error en la funcion: Cod.error [%d]\n", error);
			}
		break;

		case 's': 
		case 'S': 
		  /* Si el usuario teclea la letra s se sale sin hacer nada */
		break;

		default: 
		printf("Opción %c incorrecta\n", opcion);

	}
	
	printf("\n\n");
 	return 0;
}
