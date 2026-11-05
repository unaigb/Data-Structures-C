/*
** Fichero: insercion.c
** Autor:
** Unai García Blanco
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas/lista.h"
#include "insercion.h"

int insercion(Lista *lista) {
    if (lista == NULL) {
        return -1; 
    }

    Lista listaDesord;
    tipoPosicion head, i;
    
    
    // Inicializar las listas
    if (creaVacia(&listaDesord) != 0) {
        return -2;
    }


    // Dividir la lista en lOrdenada y listaDesord
    head = primero(lista);
    
    if (dividirLista(lista, head, &listaDesord) != 0) {
        return -3;
    }
    /*printf("Lista Ordenada:\n");
    imprime(lista);
    printf("Lista Desordenada:\n");
    imprime(&listaDesord);*/

    head = primero(&listaDesord);

    while (!vacia(&listaDesord)) {
        contExt++;

        tipoElemento actual = recupera(head, &listaDesord);
        tipoElemento ultimo = recuperaUltimo(lista);

        //Comprobamos si se puede insertar al final
        if (actual >= ultimo) {
            if (traspasarNodo(head, &listaDesord, fin(lista), lista) != 0) {
                return -4;
            }
        } 
        else {
            tipoPosicion q = primero(lista);
            while (q != fin(lista) && actual > recupera(q, lista)) {
                contInt++;
                q = siguiente(q, lista);
            }
            if (traspasarNodo(head, &listaDesord, q, lista) != 0) {
                return -5;
            }
        }
    }
    destruye(&listaDesord);
    
    return 0; 
}