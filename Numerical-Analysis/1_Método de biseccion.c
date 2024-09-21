#include <stdio.h>
#include <math.h>

double funcionEcuacion(double x) {
    return x * x - 4;
}

void metodoBiseccion(double extremoIzquierdo, double extremoDerecho, double tolerancia, int numeroMaximoIteraciones) {
    int iteracion;
    double puntoMedio, valorEnExtremoIzquierdo, valorEnPuntoMedio;

    // Paso 1
    iteracion = 1;
    valorEnExtremoIzquierdo = funcionEcuacion(extremoIzquierdo);
