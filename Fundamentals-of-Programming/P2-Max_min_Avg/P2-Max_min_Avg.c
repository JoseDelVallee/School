#P2-Max_min_Avg
#include <stdio.h>
#include <math.h>

int main()
{
system("color F3");
  
int n, suma,menor,mayor,promedioo,contador;
float promedio;
  
printf("Ingrese un valor numerico: ");
scanf("%d", &n);
  
suma = 0;
mayor = 0;
contador = 0;
menor = n;
	while( n >= 0 )	
	{	
	if ( n > mayor){
		mayor=n;  
	}
	if( n < menor ) {
		menor = n;		
	}
	suma = suma + n; 
	contador++;
	promedio = suma/(float)contador;
	printf("Ingrese el siguiente valor: ");
	scanf("%d", &n);
	
	}
	printf("La suma es: %d\n", suma);
	printf("El promedio de los valores es: %.2f\n",promedio);
	printf("El valor mayor es: %d\n", mayor);
	printf("El valor menor es: %d\n", menor);

return 0;

}

