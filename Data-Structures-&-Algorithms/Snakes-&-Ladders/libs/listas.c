#include<stdlib.h>

//Funciones básicas

NodoL* CrearNodo(element e){
    NodoL* nodo = (NodoL*)malloc(sizeof(NodoL));
    nodo->e = e;
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(NodoL* nodo){
    free(nodo);
}

