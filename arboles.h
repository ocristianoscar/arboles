#ifndef ARBOLES_2020_H_INCLUDED
#define ARBOLES_2020_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>



//----------------estructura principal

typedef struct{
    int dato;                   //este dato se puede cambiar por el que se necesite
    struct nodoArbol * izq;
    struct nodoArbol * der;
}nodoArbol;



//----------------prototipados de funciones

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int);
nodoArbol * insertar(nodoArbol*, int);
void mostrarNodoArbol(nodoArbol*);



#endif // ARBOLES_2020_H_INCLUDED
