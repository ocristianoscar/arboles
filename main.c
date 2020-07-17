#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arboles.h"



int main()
{
    printf("Demostración de la librería de árboles binarios\n");

    srand(time(NULL));

    nodoArbol * arbol = inicArbol();

    nodoArbol * nodo = crearNodoArbol(5);

    //mostrarNodoArbol(nodo);

    printf("\n");

    arbol = inicArbol();

    for (int i = 0; i < 10; i++)
    {
        arbol = insertar(arbol, datoRandomArbol());
    }

    mostrarInOrden(arbol);

    printf("\n\n");

    //estas tres lineas siguientes irán en la función para balancear arbol. Son de prueba.

    /*int* array = arbolToArray(arbol);
    int validos = cantNodos(arbol);

    mostrarArrayArbol(array, validos);

    printf("\n");

    printf("\nla cantidad de niveles del arbol es de %i", cantNiveles(arbol));
    printf("\nla cantidad de nodos del arbol es de %i", cantNodos(arbol));
    printf("\nla cantidad de hojas del arbol es de %i", cantHojas(arbol));*/

    printf("\n");

    printf("\n\ncual desea borrar? ");
    fflush(stdin);
    int op;
    scanf("%i", &op);

    borrar(arbol, op);

    mostrarInOrden(arbol);

    printf("\n");

    return 0;
}


