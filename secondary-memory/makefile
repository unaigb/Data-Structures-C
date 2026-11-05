
ejercicio1y2: prueba.c indice.o dispersion.o dispersion.h
	gcc -g prueba.c indice.o dispersion.o -o ejercicio1y2
	rm *.o
	
dispersion.o: dispersion.c indice.h dispersion.h
	gcc -g -c dispersion.c
indice.o: indice.c indice.h
	gcc -g -c indice.c

indice:
	rm *.idx
hash:
	rm *.hash
ejecutable:
	rm ejercicio*
