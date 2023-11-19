//pilas.h

#include <stdio.h>
//--------------------------------------------------------
//Definición de constantes y estructuras
typedef int elementp;

typedef struct Node {
    elementp e;
    struct Node* siguiente;
} Node;

typedef struct Pila{
    Node* head;
    int longitud;
} Pila;

//--------------------------------------------------------
//Encabezados de las funciones de la librería

Node* CrearNodoP(elementp e);
void DestruirNodoP(Node* nodo);

Pila* CrearPila();
void DestruirPila(Pila* pila);

void Push(Pila* pila, elementp e);
void Desapilar(Pila* pila);
elementp Cima(Pila* pila, Node* ref);
elementp Pop(Pila* pila, Node* ref);

void ShowP(Pila* pila);
int Longitudp(Pila* pila);

Pila* InvertirPila(Pila* pila);
void Suma(Pila* sumando1, Pila* sumando2, Pila* result);
int verificar_balance(char *formula);
int Buscar(Pila* pila, elementp buscado);



#include "pilas.c"
