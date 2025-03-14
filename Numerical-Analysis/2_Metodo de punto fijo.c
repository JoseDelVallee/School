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
    // Paso 7
    printf("\nEl método fracaso despues de %d iteraciones.\n", numeroMaximoIteraciones);
}

int main() {
	system("Color F3");
    double puntoInicial, tolerancia;
    int numeroMaximoIteraciones;

    // Entrada de datos
    printf("\nIngrese la aproximacion inicial: ");
    scanf("%lf", &puntoInicial);
    printf("\nIngrese la tolerancia TOL: ");
    scanf("%lf", &tolerancia);
    printf("\nIngrese el numero maximo de iteraciones: ");
    scanf("%d", &numeroMaximoIteraciones);
    // Llamada al método de iteración de punto fijo
    iteracionPuntoFijo(puntoInicial, tolerancia, numeroMaximoIteraciones);

    return 0;
}
