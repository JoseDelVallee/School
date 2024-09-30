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
    // Paso 2
    while (iteracion <= numeroMaximoIteraciones) {

    // Paso 3
    puntoMedio = extremoIzquierdo + (extremoDerecho - extremoIzquierdo) / 2;
    valorEnPuntoMedio = funcionEcuacion(puntoMedio);

    // Paso 4
    if (valorEnPuntoMedio == 0 || (extremoDerecho - extremoIzquierdo) / 2 < tolerancia) {
    // SALIDA(puntoMedio)
    printf("\nLa solucion aproximada es: %lf\n", puntoMedio);
    return;
  }
    // Paso 5
    iteracion++;

    // Paso 6
      if (valorEnExtremoIzquierdo * valorEnPuntoMedio > 0) {
         extremoIzquierdo = puntoMedio;
         valorEnExtremoIzquierdo = valorEnPuntoMedio;
      } else {
         extremoDerecho = puntoMedio;
       }
   }
    // Paso 7
    printf("\nEl metodo fracaso despues de %d iteraciones.\n", numeroMaximoIteraciones);
}
