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

int TirarDados(){

    int random_num1,random_num2;

    int num_anterior1 = 0;
    int num_anterior2 = 0;
    int suma = 0;

    while (1) {
        if (kbhit()){
            char ch = getch();
            if (ch == ' ') {
                if (num_anterior1 != 0 && num_anterior2 != 0) {
                        printf("\r");  // Regresar al principio de la línea
                    for (int i = 0; i < 30; i++) {
                        printf(" ");  // Espacios en blanco para borrar la línea anterior
                    }
                    printf("\r");  // Regresar al principio de la línea nuevamente
                }
                random_num1 = rand() % 6 + 1;  // Genera un entero aleatorio entre 1 y 6
                random_num2 = rand() % 6 + 1;  // Genera otro entero aleatorio entre 1 y 6
                printf("%d %d", random_num1, random_num2);
                fflush(stdout);
                num_anterior1 = random_num1;
                num_anterior2 = random_num2;
                suma = random_num1 + random_num2;
            } else {
                break;
            }
        }
    }
    return suma;
}
//Funcion que mueve al jugador en el tablero--------------------------------------------------------

//Funcion que mueve al jugador en el tablero--------------------------------------------------------
void mover(int jugador, int pasos, Lista* tablero, Move e[], Move s[]) {
    int posicionActual = 0;
    int nuevaPosicion = 0;
    int i;

    if (jugador == 1) {
        posicionActual = J1;
        nuevaPosicion = posicionActual + pasos;

        if (nuevaPosicion <= 100) {
            // Verificar si el jugador ha caído en una escalera o serpiente
            for (i = 0; i < 5; i++) {
                if (nuevaPosicion == e[i].ini->e) {
                    printf("\nJugador 1 ha subido por una escalera. Avanzar%c a la posici%cn %d\n", 160, 162, e[i].fin->e);
                    system("pause");
                    nuevaPosicion = e[i].fin->e; // Ajustar la posición a la posición de destino de la escalera
                    break;
                } else if (nuevaPosicion == s[i].ini->e) {
                    printf("Jugador 1 ha caído por una serpiente. Retroceder%c a la posici%cn %d\n",160, 162, s[i].fin->e);
                    system("pause");
                    nuevaPosicion = s[i].fin->e; // Ajustar la posición a la posición de destino de la serpiente
                    break;
                }
            }
            
            J1 = nuevaPosicion; // Actualizar la posición del jugador 1 en el tablero
        }
    } else if (jugador == 2) {
        posicionActual = J2;
        nuevaPosicion = posicionActual + pasos;

        if (nuevaPosicion <= 100) {
            // Verificar si el jugador ha caído en una escalera o serpiente
            for (i = 0; i < 5; i++) {
                if (nuevaPosicion == e[i].ini->e) {
                    printf("\nJugador 2 ha subido por una escalera. Avanzar%c a la posici%cn %d\n", 160, 162, e[i].fin->e);
                    system("pause");
                    nuevaPosicion = e[i].fin->e; // Ajustar la posición a la posición de destino de la escalera
                    break;
                } else if (nuevaPosicion == s[i].ini->e) {
                    printf("\nJugador 2 ha caido por una serpiente. Retroceder%c a la posici%cn %d\n",160, 162, s[i].fin->e);
                    nuevaPosicion = s[i].fin->e; // Ajustar la posición a la posición de destino de la serpiente
                    break;
                }
            }
            
            J2 = nuevaPosicion; // Actualizar la posición del jugador 2 en el tablero
        }
    }
// Mostrar el tablero actualizado
    MostrarTablero(tablero, e, s);
}

void Jugar(Lista* tablero, Move *e, Move *s){
    int i = 1; 
    while(J1<99 && J2<99){
        MostrarTablero(tablero, e, s);
        if(i%2){
            printf("\nTurno de J1\t presione espacio para lanzar el dado\n");
            mover(1, TirarDados(), tablero, e, s);
        }else{
            printf("\nTurno de J2\tresione espacio para lanzar el dado\n");
            mover(2, TirarDados(), tablero, e, s);
        }
        i++;

        if(J1 == 98 && J2 == 98){
            printf("\n\tEmpate :)");
            return;
        }
    }
    system("cls");
    
    JGanadore(J1, J2);

}   
void JGanadore(int J1, int J2){

	if(J1==99){
        printf("\n");
        printf(J1C);
        printf("\t\t                \n");
		printf("\t\t Jugador 1 gana \n");
        printf("\t\t                \n");
        printf("\x1b[0m");
	}
	else{
        printf("\n");
        printf(J2C);
        printf("\t\t                \n");
		printf("\t\t Jugador 2 gana \n");
        printf("\t\t                \n");
        printf("\x1b[0m");
	}	

}

void Inicio(){

    system("cls");

    printf("\033[1;32m");

    printf("\n\n\n\n");

    printf("\t\t\t                                       ##                         ##                                      \n");
    printf("\t\t\t                                                                  ##                                      \n");
    printf("\t\t\t  #####    ####    ######   ######    ###      ####    #####     #####    ####     #####            ##  ##\n");
    printf("\t\t\t ##       ##  ##    ##  ##   ##  ##    ##     ##  ##   ##  ##     ##     ##  ##   ##                ##  ##\n");
    printf("\t\t\t  #####   ######    ##       ##  ##    ##     ######   ##  ##     ##     ######    #####            ##  ##\n");
    printf("\t\t\t      ##  ##        ##       #####     ##     ##       ##  ##     ## ##  ##            ##            #####\n");
    printf("\t\t\t ######    #####   ####      ##       ####     #####   ##  ##      ###    #####   ######                ##\n");
    printf("\t\t\t                            ####                                                                    #####\n");

    printf("\t\t\t\t\t                                      ###\n");
    printf("\t\t\t\t\t                                      ##\n");
    printf("\t\t\t\t\t ####     #####    ####     ####      ##      ####    ######    ####     #####\n");
    printf("\t\t\t\t\t##  ##   ##       ##  ##       ##     ##     ##  ##    ##  ##      ##   ##\n");
    printf("\t\t\t\t\t######    #####   ##        #####     ##     ######    ##       #####    #####\n");
    printf("\t\t\t\t\t##            ##  ##  ##   ##  ##     ##     ##        ##      ##  ##        ##\n");
    printf("\t\t\t\t\t #####   ######    ####     #####    ####     #####   ####      #####   ######\n");





