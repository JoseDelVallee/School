#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   system("color F3");
   int a;
   int b;
   printf("\Teorema de euclicez.\n\n");
   printf("Introduzca el valor de (a) que sea entero:\n ");
   scanf (" %d", &a);

   printf(" Introduzca el valor de (b) que sea entero:\n ");
   scanf (" %d", &b);

   int Resto = a%b;
   
    if(Resto == 0){
       printf("El MCD es %d", b);
       }
       while(!Resto == 0)
    {
   a = b;
     b = Resto;
     Resto = a%b;
   
    }

   
}
