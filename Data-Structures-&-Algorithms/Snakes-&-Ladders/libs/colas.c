//#include "colas.h"

#include<stdio.h>
#include<stdlib.h>

//Funciones básicas
NodoC* CrearNodoC(elementc e){
    NodoC* nodo = (NodoC*)malloc(sizeof(NodoC));
    nodo->e = e;
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodoC(NodoC* nodo){
    free(nodo);
}

Cola* CrearCola(){
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->head = cola->tail = NULL;
    return cola;
}

void DestruirCola(Cola* cola){
    
    
    while(cola->head){
        Eliminar(cola);
    }
    free(cola);
}

//Funciones propias de las colas

void Encolar(Cola* cola, elementc e){
    
    NodoC* nodo = CrearNodoC(e);

    if(cola->head == NULL){
        cola->head = nodo;
        cola->tail = nodo;
    }else{
        cola->tail->siguiente = nodo;
        cola->tail = nodo;
    }
    cola->longitud++;
}

elementc Procesar(Cola* cola){
    if(cola->head == NULL){
        printf("Underflow");
        return ERRORC;
    }else{
        elementc e;
        e = cola->head->e;
        Eliminar(cola);
        return e;
    }
}

//Funciones adicionales para colas

void Eliminar(Cola* cola){
    if(cola->head){
        NodoC* eliminado = cola->head;
        cola->head = cola->head->siguiente;
        DestruirNodoC(eliminado);
        
        if(cola->head == NULL)
            cola->tail = NULL;

    }
}

elementc Consultar(Cola* cola){
    if(cola->head)
        return cola->head->e;
    else
        return ERRORC;
}

int Longitudc(Cola* cola){
    return cola->longitud;
}

int EstaVaciaC(Cola* cola){
    return cola->head == NULL;
}

void ShowC(Cola* cola){

    NodoC* puntero = cola->head;

    while(puntero){

        if((puntero->e/10) >= 1){
            printf("| %d |", puntero->e);
        }else{
            printf("| 0%d |", puntero->e);
        }

        puntero = puntero->siguiente;
    
    }
    printf("\n");

}
