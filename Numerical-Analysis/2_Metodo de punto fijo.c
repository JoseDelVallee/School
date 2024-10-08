#include <stdio.h>
#include <math.h>

// Definir la función h(x)
double h(double x) {
    return sqrt(x + 1);
}
void iteracionPuntoFijo(double puntoInicial, double tolerancia, int numeroMaximoIteraciones) {
    int iteracion;
    double puntoActual;
