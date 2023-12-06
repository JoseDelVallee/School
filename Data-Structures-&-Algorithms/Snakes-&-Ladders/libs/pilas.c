//pilas.c

#include <stdlib.h>
#define ERRORP '*'

//Funciones básicas

Node* CrearNodoP(elementp e){
    Node* nodo = (Node *)malloc(sizeof(Node));
    //Datos
    nodo->e = e;
    nodo -> siguiente = NULL;
    return nodo;
}
