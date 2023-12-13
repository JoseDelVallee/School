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
void DestruirNodoP(Node* nodo){
    nodo->siguiente = NULL;
    free(nodo);
}

Pila* CrearPila(){
  Pila* pila = (Pila *)malloc(sizeof(Pila));
  pila -> head = NULL;
  pila->longitud = 0;
  return pila;
}
void DestruirPila(Pila* pila){
    while(pila->head!=NULL){
        Desapilar(pila);
    }
    free(pila);
}

//Funciones propias de las pilas

void Push(Pila* pila, elementp e){
    Node* nodo = CrearNodoP(e);
    nodo->siguiente = pila->head;
    pila->head = nodo;
    pila->longitud++;
}
