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

Lista* CrearLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->head = NULL;
    lista->longitud = 0;
    return lista;
}

void DestruirLista(Lista* lista){
    NodoL* puntero = lista->head;
    while(puntero != NULL){
        lista->head = puntero->siguiente;
        DestruirNodo(puntero);
        puntero = puntero->siguiente;
    }
    free(lista);
}
