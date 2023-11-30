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

//Funciones propias de las listas

void InsertarInicio(Lista* lista, element e){
    NodoL* nodo = CrearNodo(e);
    nodo->siguiente = lista->head;
    lista->head = nodo;
    lista->longitud++;
}

void InsertarFinal(Lista* lista, element e){
    NodoL* nodo = CrearNodo(e);
    
    if(lista->head == NULL){
        lista->head = nodo;
        lista->longitud++;
    }else{
        NodoL* puntero = lista->head;
        while(puntero->siguiente){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
}

void InsertarDespues(int n, Lista* lista, element e){
    NodoL* nodo = CrearNodo(e);

    if(lista->head == NULL){
        lista->head = nodo;
        lista->longitud++;
    }else{
        NodoL* puntero = lista->head;
        int posicion = 0;

        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
        lista->longitud++;
    }
}

void EliminarInicio(Lista* lista){

    if(lista->head){
        NodoL* eliminar = lista->head;
        lista->head = lista->head->siguiente;
        DestruirNodo(eliminar);
        lista->longitud--;
    }else{
        printf("Underflow");
    }


}

void EliminarFinal(Lista* lista){

    if(lista->head){

        if(lista->head->siguiente){
            NodoL* puntero = lista->head;
            while(puntero->siguiente->siguiente){
                puntero = puntero->siguiente;
            }

            NodoL* eliminar = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminar);
            lista->longitud--;
        }else{
            NodoL* eliminar = lista->head;
            lista->head = NULL;
            DestruirNodo(eliminar);
            lista->longitud--;
        }

    }

}
void Eliminarn(int n, Lista* lista){
    if(lista->head){

        if(n == 0){
            EliminarInicio(lista);
        }else if(n < lista->longitud){
            NodoL* puntero = lista->head;
            int posicion = 0;
            while(posicion < (n-1)){
                puntero = puntero->siguiente;
                posicion++;
            }
            NodoL* eliminar = puntero->siguiente;
            puntero->siguiente = eliminar->siguiente;
            DestruirNodo(eliminar);
            lista->longitud--;
        }
    }
}
//Funciones adicionales

element Obtener(int n, Lista* lista){
    if(lista->head == NULL){
        printf("La lista esta vacia");
        return ERROR;
    }else{
        NodoL* puntero = lista->head;
        int posicion = 0;
        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion ++;
        }

        if(posicion != n){
            printf("ERROR, %d no encontrado", n);
            return ERROR;
        }else
            return puntero->e;
    }
}
int Longitud(Lista* lista){
    return lista->longitud;
}

