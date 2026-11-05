/*
** Fichero: lista.c
** Autor:
** Unai García Blanco
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"

int creaVacia(Lista *l)
{
    if (l == NULL) 
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda)))) 
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}

int vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posicion: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la lista\n",posicion-1);
    }
}

tipoPosicion anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}


tipoPosicion primero(Lista *l)
{
    if (l == NULL || l->raiz == NULL) return NULL;
    else return l->raiz;
}



tipoPosicion fin(Lista *l)
{
    if (l == NULL) 
    {
        return NULL;
    }
    else if (l->ultimo == NULL)
    {
        return NULL;
    }
    else
        return l->ultimo;
}


int inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
    tipoCelda *nuevo;
    
    if (l == NULL || l->raiz == NULL || p == NULL) 
    {
        return -1;
    }
    else if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))) 
    {
        return -2;
    }
    else 
    {
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == l->ultimo)
            l->ultimo = nuevo;
        return 0;
    }
}

int suprime (tipoPosicion p, Lista *l)
{
    tipoPosicion aBorrar;
    if (vacia(l) != 0 || p == NULL) return -1;
    else {
        aBorrar = p->sig;
        if(aBorrar == NULL) return -2;
        p->sig = aBorrar->sig;
        free(aBorrar);
        l->ultimo = fin(l);
        return 0;
    }
}


tipoPosicion siguiente(tipoPosicion p,Lista *l)
{
    tipoPosicion posicion;
    if (vacia(l) != 0 || p == NULL) return NULL;
    else {
        if(p == fin(l)) return p;
        return p->sig;
    }
}

tipoPosicion localiza (tipoElemento x, Lista *l)
{
    tipoPosicion posicion;
    if (vacia(l) != 0) return NULL;
	else{
        posicion = l->raiz;
        while (posicion->sig != NULL)
        {
            if (posicion->sig->elemento == x) return posicion;
            posicion = posicion->sig;
        } return posicion; //Esto es un fin(l)
    }
}

tipoElemento recupera(tipoPosicion p, Lista *l)
{
    if (l == NULL || l->raiz == NULL || p == NULL) return -1;
    else {
        if(p == fin(l)) return -2;
        return p->sig->elemento;
    }
}

int anula(Lista *l)
{
    if (l == NULL || l->raiz == NULL|| vacia(l)) {
        return -1;
    }
    else
    {
        tipoPosicion aux = primero(l) , aborrar ;
        aux=aux->sig;
        while(aux != fin(l)){
            aborrar = aux;
            aux = aux->sig;
            free(aborrar);
        }
        l->raiz->sig=NULL;
        l->ultimo = l->raiz;
        free(aux);
        
        return 0;
    }
}

tipoElemento recuperaUltimo(Lista *l)
{
    if (vacia(l) != 0) {
        return -1;
    } else {
        tipoPosicion ultimo = fin(l);
        return ultimo->elemento;
    }
}

int dividirLista(Lista *lOrigen, tipoPosicion p, Lista *lNueva)
{
    tipoPosicion i = p;

    if (lOrigen == NULL || lOrigen->raiz == NULL || p == NULL || lNueva == NULL || lNueva->raiz == NULL) {
        return -1;
    } 
    
    while ( i->sig != fin(lOrigen)) {
        i = siguiente(p, lOrigen);
        traspasarNodo(i, lOrigen, fin(lNueva), lNueva);
    }

    tipoPosicion ultimoOrigen = lOrigen->ultimo;
    ultimoOrigen->sig = NULL;
    fin(lNueva)->sig = NULL;
    
    return 0;
}

int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb) 
{
    tipoElemento elmt;

	if (la == NULL || la->raiz == NULL || lb == NULL || lb->raiz == NULL)
		return -1;
	else
	{
		elmt = recupera(p, la);
        inserta(elmt, q, lb);
        suprime(p, la);

        return 0;
    }
}
