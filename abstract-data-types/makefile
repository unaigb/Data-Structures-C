# Proyecto para entrega Tipos Abstractos de Datos 2023
#
# ( Añadir las reglas necesarias para la correcta compilación de todas las implementaciones que se piden)


pruebaInsercion: pruebaInsercion.o listas/lista.o insercion.o
	gcc -g pruebaInsercion.o insercion.o listas/lista.o -o pruebaInsercion
	
pruebaInsercion.o: pruebaInsercion.c insercion.h listas/lista.h 
	gcc -g -c pruebaInsercion.c 

insercion.o: insercion.c insercion.h listas/lista.h 
	gcc -g -c insercion.c 

listas/lista.o: listas/lista.c listas/lista.h 
	gcc -g -c listas/lista.c -o listas/lista.o 
	
limpiar:
	rm *.o listas/lista.o	
	
