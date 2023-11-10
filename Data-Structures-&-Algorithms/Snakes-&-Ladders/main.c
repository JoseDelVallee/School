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

//Definicion de las funciones utilizadas -----------------------------------------------------------

void MostrarTablero(Lista* tablero, Move *e, Move *s){

    system("cls");
    printf("\n\n");
    for(int fila = 1; fila<=tamtab; fila++){
        printf("\n\n\t\t\t\t\t");
        if(fila%2){
            for(int columna = tamtab-1; columna >= 0; columna--){   

                int celda = Obtener(pow(tamtab, 2)-(fila*tamtab)+columna, tablero);

                if(celda == J1 && celda == J2){
                    printf(J1C);
                    printf("[J1");
                    printf(J2C);
                    printf("J2]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(celda == J1){
                    printf(J1C);
                    printf("[ J1 ]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(celda == J2){
                    printf(J2C);
                    printf("[ J2 ]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(
                    celda == e[0].ini->e ||
                    celda == e[1].ini->e ||
                    celda == e[2].ini->e ||
                    celda == e[3].ini->e ||
                    celda == e[4].ini->e 
                    
                ){

                    for(int i = 0; i < 5; i++){
                        if(celda == e[i].ini->e){
                        printf("\x1b[32m");
                        printf("[ e%d ]", i);
                        printf("\x1b[0m");
                        printf("  ");
                        }else{
                            continue;
                        }
                    }

                }else if(
                    celda == e[0].fin->e ||
                    celda == e[1].fin->e ||
                    celda == e[2].fin->e ||
                    celda == e[3].fin->e ||
                    celda == e[4].fin->e 
                ){

                    for(int i = 0; i < 5; i++){
                        if(celda == e[i].fin->e){
                        printf("\x1b[32m");
                        printf("[ e%df]", i);
                        printf("\x1b[0m");
                        printf("  ");
                        }else{
                            continue;
                        }
                    }

                }else if(
                    celda == s[0].ini->e ||
                    celda == s[1].ini->e ||
                    celda == s[2].ini->e ||
                    celda == s[3].ini->e ||
                    celda == s[4].ini->e 
                ){
                    for(int i = 0; i < 5; i++){
                        if(celda == s[i].ini->e){
                        printf("\x1b[31m");
                        printf("[ s%d ]", i);
                        printf("\x1b[0m");
                        printf("  ");
                        }else{
                            continue;
                        }
                    }
                }else if(
                    celda == s[0].fin->e ||
                    celda == s[1].fin->e ||
                    celda == s[2].fin->e ||
                    celda == s[3].fin->e ||
                    celda == s[4].fin->e
                ){
                    for(int i = 0; i < 5; i++){
                        if(celda == s[i].fin->e){
                        printf("\x1b[31m");
                        printf("[ s%df]", i);
                        printf("\x1b[0m");
                        printf("  ");
                        }else{
                            continue;
                        }
                    }
                
                }else{
                    printf("\033[0m");
                    if(celda / 10 < 1){
                        printf("[ 0%d ]  ", celda);
                    }else{
                        printf("[ %d ]  ", celda);
                    }
                }
            
            }
            printf("\n");
        }else{
            for(int columna = 0; columna < tamtab; columna++){

                int celda = Obtener(pow(tamtab, 2)-(fila*tamtab)+columna, tablero);

                if(celda == J1 && celda == J2){
                    printf(J1C);
                    printf("[J1");
                    printf(J2C);
                    printf("J2]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(celda == J1){
                    printf(J1C);
                    printf("[ J1 ]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(celda == J2){
                    printf(J2C);
                    printf("[ J2 ]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(
                    celda == e[0].ini->e ||
                    celda == e[1].ini->e ||
                    celda == e[2].ini->e ||
                    celda == e[3].ini->e ||
                    celda == e[4].ini->e
                ){
                    for(int i = 0; i < 5; i++){
                        if(celda == e[i].ini->e){
                        printf("\x1b[32m");
                        printf("[ e%d ]", i);
                        printf("\x1b[0m");
                        printf("  ");
                        }else{
                            continue;
                        }
                    }
                }else if(
                    celda == e[0].fin->e ||
                    celda == e[1].fin->e ||
                    celda == e[2].fin->e ||
                    celda == e[3].fin->e ||
                    celda == e[4].fin->e 
                ){
                    for(int i = 0; i < 5; i++){
                        if(celda == e[i].fin->e){
                        printf("\x1b[32m");
                        printf("[ e%d ]", i);
                        printf("\x1b[0m");
                        printf("  ");
                        }else{
                            continue;
                        }
                    }
                }else if(
                    celda == s[0].ini->e ||
                    celda == s[1].ini->e ||
                    celda == s[2].ini->e ||
                    celda == s[3].ini->e ||
                    celda == s[4].ini->e 
                ){
                    for(int i = 0; i < 5; i++){
                        if(celda == s[i].ini->e){
                        printf("\x1b[31m");
                        printf("[ s%d ]", i);
                        printf("\x1b[0m");
                        printf("  ");
                        }else{
                            continue;
                        }
                    }
                }else if(
                    celda == s[0].fin->e ||
                    celda == s[1].fin->e ||
                    celda == s[2].fin->e ||
                    celda == s[3].fin->e ||
                    celda == s[4].fin->e 
                ){
                    for(int i = 0; i < 5; i++){
                        if(celda == s[i].fin->e){
                        printf("\x1b[31m");
                        printf("[ s%df]", i);
                        printf("\x1b[0m");
                        printf("  ");
                        }else{
                            continue;
                        }
                    }
                }else{
                    printf("\033[0m");
                    if(celda / 10 < 1){
                        printf("[ 0%d ]  ", celda);
                    }else{
                        printf("[ %d ]  ", celda);
                    }
                }
            }
            printf("\n");
        }
    }
    printf("\n\n");
    printf("\033[0m");
}
