#define ERRORC '*'

typedef int elementc;

typedef struct NodoC{
    elementc e;
    struct NodoC* siguiente;
}NodoC;

typedef struct Cola{
    NodoC* head;
    NodoC* tail;
    int longitud;
}Cola;

NodoC* CrearNodoC(elementc e);
void DestruirNodoC(NodoC* nodo);

Cola* CrearCola();
void DestruirCola(Cola* cola);

void Encolar(Cola* cola, elementc e);
elementc Procesar(Cola* cola);

void Eliminar(Cola* cola);
elementc Consultar(Cola* cola);
int Longitudc(Cola* cola);
int EstaVaciaC(Cola* cola);
void ShowC(Cola* cola);

#include "colas.c"
