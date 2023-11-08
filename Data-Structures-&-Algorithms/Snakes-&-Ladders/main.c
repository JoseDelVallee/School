/*
    Programa que simula el juego "Serpientes y Escaleras"
    para dos jugadores
    Algoritmos y Estructuras de Datos
    Piña Del Valle José 
*/

#include <math.h>

#include "libs/colas.h"
#include "libs/pilas.h"
#include "libs/listas.h"
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>

//Definición de constantes y variables globales ----------------------------------------------------

typedef struct Move{
    NodoL* ini;
    NodoL* fin;
}Move;


#define tamtab 10   //El tablero será cuadrado
#define J1C "\x1b[46m" //Color CYAN
#define J2C "\x1b[44m" //Color AZUL

int J1 = 0, J2 = 0; 

//Encabezados de las funciones utilizadas ----------------------------------------------------------
