#include <stdio.h>
#include <stdlib.h>

#include "arboles.h"

int main()
{
    printf("Demostración de la librería de árboles binarios\n");

    nodoArbol * arbol = inicArbol();

    nodoArbol * nodo = crearNodoArbol(5);

    mostrarNodoArbol(nodo);

    printf("\n");

    return 0;
}
