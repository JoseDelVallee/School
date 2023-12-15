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
void Desapilar(Pila* pila){
    if(pila->head!=NULL){
        Node* eliminar = pila->head;
        pila->head = pila->head->siguiente;
        DestruirNodoP(eliminar);
        pila->longitud--;
    }
}
//Funciones propias de las pilas

void Push(Pila* pila, elementp e){
    Node* nodo = CrearNodoP(e);
    nodo->siguiente = pila->head;
    pila->head = nodo;
    pila->longitud++;
}
elementp Pop(Pila* pila, Node* ref){
    if(ref==NULL){;
        return ERRORP;
    }else{
        return ref->e;
    }
}
//Funciones adicionales para pilas

elementp Cima(Pila* pila, Node* ref){
    if(ref==NULL){
        return ERRORP;
    }else{
        return ref->e;
    }
}
void Desapilar(Pila* pila){
    if(pila->head!=NULL){
        Node* eliminar = pila->head;
        pila->head = pila->head->siguiente;
        DestruirNodoP(eliminar);
        pila->longitud--;
    }
}
elementp Pop(Pila* pila, Node* ref){
    if(ref==NULL){;
        return ERRORP;
    }else{
        return ref->e;
    }
}
void ShowP(Pila* pila){

    if(pila->head == NULL){
        return;
    }else{
        Node* puntero = pila->head;
        while(puntero!=NULL){

            printf("| %d |", puntero->e);
            puntero = puntero->siguiente;
            
        }
        printf("\n");
        return;
    }

}
