#include "arboles.h"

//inicia un arbol binario con el valor NULL
nodoArbol * inicArbol()
{
    return NULL;
}

//devuelve un puntero a un nodoArbol con el valor entero ingresado por parámetro como dato
nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

//ingresa un dato al arbol
nodoArbol * insertar(nodoArbol* arbol, int dato)
{
    if(arbol == NULL)
        arbol = crearNodoArbol(dato);
    else
    {
        if(arbol->dato >= dato)
            arbol->izq = insertar(arbol->izq, dato);
        else
            arbol->der = insertar(arbol->der, dato);
    }
    return arbol;
}

//muestra un nodoArbol enviado por puntero
void mostrarNodoArbol(nodoArbol * nodo){
    if(nodo != NULL)
    {
        printf("\ndato: %i\n", nodo->dato);
        
        if(nodo->izq == NULL)
            printf("no ");
        printf("posee nodo hijo izquierdo\n");

        if(nodo->der == NULL)
            printf("no ");
        printf("posee nodo hijo derecho\n");
    }
    else
        printf("\nel nodo es nulo");
}

//asd
