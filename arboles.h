#ifndef ARBOLES_2020_H_INCLUDED
#define ARBOLES_2020_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>



//----------------estructura principal

typedef struct nodoArbol{
    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
}nodoArbol;



//----------------prototipados de funciones

//                                             DONE
//funciones de manipulación del arbol
nodoArbol * inicArbol();                        //
nodoArbol * insertar(nodoArbol*, int);          //
nodoArbol * buscar(nodoArbol*, int);            //
nodoArbol * borrar(nodoArbol*, int);            //
nodoArbol * balancearArbol(nodoArbol*);
nodoArbol * crearNodoArbol(int);                //
int datoRandomArbol();                          //
int * arbolToArray(nodoArbol*);                 //
void nodoToArray(nodoArbol*, int*, int*);       //

//funciones de muestra del arbol
void mostrarNodoArbol(nodoArbol*);              //
void mostrarPreOrden(nodoArbol*);               //
void mostrarInOrden(nodoArbol*);                //
void mostrarPostOrden(nodoArbol*);              //
void mostrarArbol(nodoArbol*);

//funciones de información del arbol
int cantNiveles(nodoArbol*);                    //
int cantNodos(nodoArbol*);                      //
int cantHojas(nodoArbol*);                      //
nodoArbol * nodoExtremoDerecho(nodoArbol*);     //
nodoArbol * nodoExtremoIzquierdo(nodoArbol*);   //
void mostrarArrayArbol(int*, int);



#endif // ARBOLES_2020_H_INCLUDED
