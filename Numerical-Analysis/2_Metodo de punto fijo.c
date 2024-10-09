#include <stdio.h>
#include <math.h>

// Definir la función h(x)
double h(double x) {
    return sqrt(x + 1);
}
void iteracionPuntoFijo(double puntoInicial, double tolerancia, int numeroMaximoIteraciones) {
    int iteracion;
    double puntoActual;
    // Paso 1
    iteracion = 1;
    // Paso 2
    while (iteracion <= numeroMaximoIteraciones) {
    // Paso 3
      puntoActual = h(puntoInicial);
    // Paso 4
        if (fabs(puntoActual - puntoInicial) < tolerancia) {
            // SALIDA(puntoActual)
            printf("\nLa solucion aproximada es: %lf\n", puntoActual);
            return;
        }
    // Paso 5
        iteracion++;
    // Paso 6
        puntoInicial = puntoActual;
    }
