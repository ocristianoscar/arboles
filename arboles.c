#include "arboles.h"




//----------FUNCIONES DE MANIPULACIÓN DEL ARBOL

//inicia un arbol binario con el valor NULL
nodoArbol * inicArbol()
{
    return NULL;
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

//busca un dato en el arbol y si lo encuentra devuelve un puntero al nodo
//si no lo encuentra, devuelve NULL
nodoArbol * buscar(nodoArbol* arbol, int dato)
{
    nodoArbol * encontrado = NULL;

    if(arbol != NULL)
    {
        if(arbol->dato == dato)
            encontrado = arbol;
        else
        {
            if(dato > arbol->dato)
                encontrado = buscar(arbol->der, dato);
            else
                encontrado = buscar(arbol->izq, dato);
        }
    }

    return encontrado;
}

//busca un dato en el arbol y si existe, lo borra
nodoArbol * borrar(nodoArbol* arbol, int dato)
{
    if (arbol != NULL)
    {
        if (dato == arbol->dato)    //si la raiz del arbol es el dato a borrar, lo reemplaza por el proximo
        {                           //mas grande, si existe
            if (arbol->der != NULL)
            {
                nodoArbol * nodoMasIzq = nodoExtremoIzquierdo(arbol->der);
                arbol->dato = nodoMasIzq->dato;
                arbol->der = borrar(arbol->der, nodoMasIzq->dato);
            }
            else    //de lo contrario, lo reemplaza por el próximo más chico, si existe
            {       //si tampoco existe, significa que es nodo que reemplazó el nodo borrado
                if (arbol->izq != NULL)                     //por lo tanto lo elimina
                {
                    nodoArbol * nodoMasDer = nodoExtremoDerecho(arbol->izq);
                    arbol->dato = nodoMasDer->dato;
                    arbol->izq = borrar(arbol->izq, nodoMasDer->dato);
                }
                else
                {
                    nodoArbol * aux = arbol;
                    free(aux);
                    arbol = NULL;
                }
            }
        }
        else    //si la raiz del arbol no es el dato a borrar, sigue buscando en el arbol
        {
            if (dato > arbol->dato)
                arbol->der = borrar(arbol->der, dato);
            else
                arbol->izq = borrar(arbol->izq, dato);
        }
    }

    return arbol;
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

//devuelve un int random entre 0 y 100
int datoRandomArbol(){
    int dato = rand()%100;
    return dato;
}









//----------FUNCIONES DE BALANCEO DEL ARBOL

//balancea un arbol binario.
nodoArbol * balancearArbol(nodoArbol * arbol)
{
        int* arrayArbol = arbolToArray(arbol);
        int validos = cantNodos(arbol);
        //mostrarArrayArbol(array, validos);

        int * arrayBalanceado = NULL;
        int * arrayIzq = NULL;
        int * arrayDer = NULL;
        int * valBan = NULL;

        arrayArbolToPreOrden(arrayArbol, validos, arrayBalanceado, valBan,
                            arrayIzq, INIC_BAL, arrayDer, INIC_BAL);

        nodoArbol * arbolBalanceado = NULL;

        arrayPreOrdenToArbolBalanceado(arbolBalanceado, arrayBalanceado);

        return arbolBalanceado;
}

//crea un arreglo de enteros con tamaño justo para almacenar todos los elementos del arbol en orden
//se vale de la función nodoToArray() para completar el arreglo, y lo devuelve
int * arbolToArray(nodoArbol * arbol)
{
    int * arbolArray = (int*)malloc(sizeof(cantNodos(arbol)));
    int validos = 0;

    if(arbol != NULL)
    {
        nodoToArray(arbol, arbolArray, &validos);
    }

    return arbolArray;
}

//función recursiva que completa un arreglo con los elementos en orden del arbol
//el arreglo es devuelto por la función arbolToArray()
void nodoToArray(nodoArbol * arbol, int * array, int * validos)
{
    if (arbol != NULL)
    {
        nodoToArray(arbol->izq, array, validos);

        array[*validos] = arbol->dato;
        (*validos)++;

        nodoToArray(arbol->der, array, validos);
    }
}

//recibe un array con los elementos del arbol en orden, y lo devuelve en PreOrden.
//También recibe, además del array, su numero de elementos (validos del array),
//un puntero al array donde se van a grabar los elementos en PreOrden (el array balanceado), un puntero
//a un int que va a ir creciendo a medida que se van grabando los elementos, y dos punteros a los sub-arrays
//que representan las ramas izquierda y derecha, con sus válidos. Para el inicio de la funcion, los validos
//se inicializan con el valor INIC_VAL
void arrayArbolToPreOrden(int * arrayArbol, int validos, int * arrayBalanceado, int * valBan,
                        int * arrayIzq, int valIzq, int * arrayDer, int valDer)
{
    /*
    *-----------FUNCIÓN ACTUALMENTE EN PROCESO - 19 DE JULIO DE 2020

     **estoy creando un algoritmo en papel

     *cortar el arreglo a la mitad. El numero de la mitad será la raiz del arbol
     **si los elementos son impares, la parte entera de elementos/2 da el índice del arreglo correspondiente
     **a la nueva raiz
     **si los elementos son pares, (elementos/2) + 1 es el índice del arreglo correspondiente a la nueva raiz
     *poner la raiz como primer elemento de un nuevo arreglo.
     **al final, este arreglo representa un arbol mostrado en pre-orden
     *volver a hacer esta operación con cada una de las mitades hasta que solo quede 1 elemento
     *se ingresan los elementos del arreglo en orden a un nuevo arbol
     **de esta forma entra primero la raiz, luego los hijos, y estos a su vez son nuevos sub-arboles
     *de esta forma queda un arbol balanceado
    */
}

void arrayPreOrdenToArbolBalanceado(nodoArbol * arbolBalanceado, int * arrayBalanceado)
{

}








//----------FUNCIONES DE MUESTRA DEL ARBOL

//muestra información sobre el nodoArbol enviado por referencia
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

//muestra los elementos de un arbol en pre orden (raiz - nodo izquierdo - nodo derecho)
void mostrarPreOrden(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        printf("%i ", arbol->dato);
        mostrarPreOrden(arbol->izq);
        mostrarPreOrden(arbol->der);
    }
}

//muestra los elementos de un arbol en orden (nodo izquierdo - raiz - nodo derecho)
void mostrarInOrden(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        mostrarInOrden(arbol->izq);
        printf("%i ", arbol->dato);
        mostrarInOrden(arbol->der);
    }
}

//muestra los elementos de un arbol en post orden (nodo izquierdo - nodo derecho - raiz)
void mostrarPostOrden(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        mostrarPostOrden(arbol->izq);
        mostrarPostOrden(arbol->der);
        printf("%i ", arbol->dato);
    }
}








//--------FUNCIONES DE INFORMACIÓN DEL ARBOL

//devuelve la cantidad de niveles del arbol
int cantNiveles(nodoArbol * arbol)
{
    int izq, der, niveles = 0;

    if (arbol != NULL)
    {
        izq = 1 + cantNiveles(arbol->izq);
        der = 1 + cantNiveles(arbol->der);

        if (izq > der)
            niveles = izq;
        else
            niveles = der;
    }

    return niveles;
}

//devuelve la cantidad de nodos de un arbol
int cantNodos(nodoArbol * arbol)
{
    int nodos = 0;

    if (arbol != NULL)
    {
        nodos++;
        nodos += cantNodos(arbol->izq);
        nodos += cantNodos(arbol->der);
    }

    return nodos;
}

//devuelve la cantidad de hojas de un arbol
int cantHojas(nodoArbol * arbol)
{
    int hojas = 0;

    if (arbol != NULL)
    {
        if ((arbol->der == NULL) && (arbol->izq == NULL))
        {
            hojas++;
        }
        else
        {
            hojas += cantHojas(arbol->izq);
            hojas += cantHojas(arbol->der);
        }
    }
    return hojas;
}

//devuelve un puntero al nodo más a la derecha de un arbol pasado por referencia
nodoArbol * nodoExtremoDerecho(nodoArbol * arbol)
{
    nodoArbol * nodoExtDer = arbol;
    if (arbol->der != NULL)
        nodoExtDer = nodoExtremoDerecho(arbol->der);
    return nodoExtDer;
}

//devuelve un puntero al nodo más a la izquierda de un arbol pasado por referencia
nodoArbol * nodoExtremoIzquierdo(nodoArbol * arbol)
{
    nodoArbol * nodoExtIzq = arbol;
    if (arbol->izq != NULL)
        nodoExtIzq = nodoExtremoIzquierdo(arbol->izq);
    return nodoExtIzq;
}

//muestra un arreglo de enteros pasado por referencia
void mostrarArrayArbol(int * array, int validos)
{
    printf("|");

    for (int i = 0; i < validos; i++)
        printf(" %i |", array[i]);
}

//asd
