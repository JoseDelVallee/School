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

void MostrarTablero(Lista* tablero, Move e[], Move s[]);
int TirarDados();
void mover(int jugador, int pasos, Lista* tablero, Move e[], Move s[]);
void Jugar(Lista* tablero, Move *e, Move *s);
void JGanadore(int J1, int J2);
void Inicio();

//Programa Principal -------------------------------------------------------------------------------

int main(){

    srand(time(NULL));

    Lista* camino = CrearLista();
    Move s[5];
    Move e[5];

    for (int i = 0; i < 100; i++){
        InsertarFinal(camino, i);
    }

    //Creacion de escaleras
    for(int i = 0; i < 5; i++){;
        int ini = 18*i+6;
        int fin = ini + 12;
    
        NodoL* puntero_ini = camino->head; 
    
        for(int i = 1; i <= ini; i++){
            puntero_ini = puntero_ini->siguiente;
        }
    
        e[i].ini = puntero_ini;

        if(puntero_ini == NULL){
            printf("Fallo en el puntero");
            system("pause");
        }    
        NodoL* puntero_fin = puntero_ini;

        for(int i = 1; i <= fin-ini; i++){
            puntero_fin = puntero_fin->siguiente;
        }

        e[i].fin = puntero_fin;
        
        
    }
    //Creación de serpientes
    for(int i = 0; i < 5; i++){
        int fin = 15*i+4;
        int ini = fin + 7;
    
        NodoL* puntero_fin = camino->head; 
    
        for(int i = 1; i <= fin; i++){
            puntero_fin = puntero_fin->siguiente;
        }
    
        s[i].fin = puntero_fin;
    
        NodoL* puntero_ini = camino->head;

        for(int i = 1; i <= ini; i++){
            puntero_ini = puntero_ini->siguiente;
        }

        s[i].ini = puntero_ini;
        puntero_fin = puntero_ini = NULL;
        
    }

    Inicio();
    Jugar(camino, e, s);

    free(camino);

    return 0;
}
