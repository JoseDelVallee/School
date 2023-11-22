
typedef int element;
#define ERROR -1;

typedef struct NodoL{
    element e;
    struct NodoL* siguiente;
}NodoL;

typedef struct Lista{
    NodoL* head;
    int longitud;
}Lista;

NodoL* CrearNodo(element e);
void DestruirNodo(NodoL* nodo);

Lista* CrearLista();
void DestruirLista(Lista* lista);

void InsertarInicio(Lista* lista, element e);
void InsertarFinal(Lista* lista, element e);
void InsertarDespues(int n, Lista* lista, element e);

void EliminarInicio(Lista* lista);
void EliminarFinal(Lista* lista);
void Eliminarn(int n, Lista* lista);

element Obtener(int n, Lista* lista);
int Longitud(Lista* lista);
int EstaVacia(Lista* lista);
void ShowL(Lista* lista);

#include "listas.c"
