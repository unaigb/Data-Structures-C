/*
** Fichero: cola.c
** Autor:
** Unai García Blanco
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"

int colaCreaVacia(Cola *c)
{
    c->frente=NULL;
	c->fondo=NULL;
 	return 0;
}

int colaVacia(Cola *c)
{
    if(c->frente==NULL && c->fondo==NULL)
    {
    	return 1;
	}
	
	return 0;
}

int colaInserta(Cola *c, tipoElemento elemento)
{
    tipoCelda *nuevo = (tipoCelda *) malloc(sizeof (tipoCelda));
    
    if(nuevo == NULL)
    {
    	return -1;
	}
	
	nuevo->sig=NULL;
	nuevo->elemento= elemento;
	
	if(colaVacia(c))
	{
		c->frente=nuevo;
		c->fondo=nuevo;
	}
	else
	{
		(c->fondo)->sig=nuevo;
		c->fondo=nuevo;
	}
	return 0; 
}

tipoElemento colaSuprime(Cola *c)
{
    tipoElemento element;
    
	tipoCelda *aux = c->frente;

	if(colaVacia(c))
	{
		exit(-1);
	}
	
	element = (c->frente)->elemento;

	if(c->frente == c->fondo)
	{
		c->fondo = NULL;
		free(c->frente);
		c->frente = NULL;
	} 
	else
	{
		c->frente = aux->sig;
		free(aux);
		aux = NULL;	
	}	
	return element;
}
