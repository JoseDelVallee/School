#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <limits.h>

//gravedades
#define Pi 3.14159265358979323846264338327950288L
#define gt 9.81L
#define gt20 9.80665215960352001615613098482965812L
#define luna 1.635L
#define Io 1.796L
#define Europa 1.314L
#define Ganimedes 1.428L
#define Fobos 0.0057L
#define Deimos 0.003L
#define Titan 1.352L
#define Rea 0.127L



double rad(double a);                    //Funcion grados a radianes
double VoX(double Vo, double a);
double VoY(double Vo, double a);
double distance(double VoX, double tv);
double h(double VoY, double t);
double h2(double VoY, double t);
void hss(double VoY, double t);
double errorAbs(double p, double Ppri);
double errorRel(double p, double Ppri);

int main(){
	system("color F3");
    int n,i;
    double Vo,a,arad,x,y,T,dH,dV,dV2;
    T = 0.1;

    printf("Ingrese la Vo:\n");
    scanf("%lf",&Vo);

    printf("Ingrese el valor del angulo:\n");
    scanf("%lf",&a);

    //Conversion a radianes
    arad = rad(a);

    //VoX
    x = VoX(Vo,arad);
    printf("VoX: %lf\n",x);

    //VoY
    y = VoY(Vo,arad);
    printf("VoY: %lf\n",y);

    printf("Cuantas veces desea hacer la operacion? El tiempo va a variar de 0.1 a 0.01 en 0.001 consecutivamente\n");
    scanf("%d",&n);

    for(i =0; i<n;i++){
        printf("No test:%d\n",i+1);
        
        dH = distance(x,T);
        printf("Distancia Horizontal: %34f\n",dH);

        printf("Usando 2 valores significativos\n");
        dV = h(y,T);
        printf("Distancia Vertical: %34f\n",dV);
        printf("----------------------------------------------------------------------------------------------\n");

        printf("Usando 20 valores significativos\n");
        dV2 = h2(y,T);
        printf("Distancia vertcial: %34f\n",dV2);
        printf("----------------------------------------------------------------------------------------------\n");

        printf("Distancia vertical en la luna y de otros satelites en diferentes planetas\n");
        hss(y,T);
        printf("----------------------------------------------------------------------------------------------\n");
        T=T/10;
    }
    return 0;
}

double rad(double a){
    double Rad;
    int int_part;
    int exponent;
    double mantissa;
    Rad = a*Pi/180;

    int_part = (int)Rad;

    //First, the integer part of the number is checked.
    if(int_part > INT_MAX || int_part < INT_MIN){
    	printf("Overflow en la parte integral): \n");
 		    }

    //Then the floating and exponential part of the number is checked.
    mantissa = frexp(Rad, &exponent);

    if(mantissa < -DBL_MAX || mantissa > DBL_MAX){
         	printf("Overflow en el matissa ): \n");
    }

    if(exponent < -DBL_MAX || exponent > DBL_MAX){
         printf("Overflow en el exponente ): \n");
    }

    return Rad;
}

// Initial velocity in X
double VoX(double Vo, double a) {
  double vox;
  int int_part;
  int exponent;
  double mantissa;

  vox = Vo * cos(a);

  // Extract the integer part of a number
  int_part = (int)vox;

  // Check the integer part of the number
  if (int_part > INT_MAX || int_part < INT_MIN) {
  	printf("Overflow en la parte integral): \n");
  }

  // Check the floating-point and exponential parts of the number

  mantissa = frexp(vox, &exponent);

  // Check the mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
    	printf("Overflow en el matissa ): \n");
  }

  // Check the exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
        printf("Overflow en el exponente ): \n");
  }

  return vox;
}

// Initial velocity in Y
double VoY(double Vo, double a) {
  double voy;
  int int_part;
  int exponent;
  double mantissa;

  // Convert degrees to radians
  voy = Vo * sin(a);

  // Extract the integer part of a number
  int_part = (int)voy;

  if (int_part > INT_MAX || int_part < INT_MIN) {
 	printf("Overflow en la parte integral): \n");
  }

  mantissa = frexp(voy, &exponent);
  // mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
 	printf("Overflow en el matissa ): \n");
  }

  // Check the exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
        printf("Overflow en el exponente ): \n");
  }

  return voy;
}

// Calcular la distancia horizontal (Vox * tv)
double distance(double VoX, double tv) {
  double dHori;
  int int_part;
  int exponent;
  double mantissa;

  dHori = VoX * tv;

  int_part = (int)dHori;

  if (int_part > INT_MAX || int_part < INT_MIN) {
 	printf("Overflow en la parte integral): \n");
  }

  mantissa = frexp(dHori, &exponent);
  // mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
 	printf("Overflow en el matissa ): \n");
  }
  // exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
        printf("Overflow en el exponente ): \n");
  }
  return dHori;
}
// Calcular la distancia vertical((VoY * t)-1/2*(g*t)^2)
double h(double VoY, double t) {
  double height;
  int int_part;
  int exponent;
  double mantissa;

  // Calcular la altura
  height = VoY * t - 0.5 * gt * pow(t, 2);

  int_part = (int)height;

  if (int_part > INT_MAX || int_part < INT_MIN) {
 	printf("Overflow en la parte integral): \n");
  }

  mantissa = frexp(height, &exponent);
  // mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
    printf("Overflow en el matissa ): \n");
  }

  // exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
    printf("Overflow en el exponente ): \n");
  }

  return height;
}

// Calcular la distancia vertical
double h2(double VoY, double t) {
  double height;
  int int_part;
  int exponent;
  double mantissa;
 
  height = VoY * t - 0.5 * gt20 * pow(t, 2);

  int_part = (int)height;

  if (int_part > INT_MAX || int_part < INT_MIN) {
    printf("Overflow en la parte integral): \n");
  }
  
  mantissa = frexp(height, &exponent);
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
    printf("Overflow en el matissa ): \n");
  }
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
    printf("Overflow en el exponente ): \n");
  }

  return height;
}
//Calcula la distancia vertical de la luna y los diferentes satélites de los planetas del sistema solar
void hss(double VoY, double t){
    double moon,io,eur,gan,fob,dei,tit,rea;
    moon= VoY*t-(0.5)*luna*pow(t,2);
    io = VoY*t-(0.5)*Io*pow(t,2);
    eur = VoY*t-(0.5)*Europa*pow(t,2);
    gan = VoY*t-(0.5)*Ganimedes*pow(t,2);
    fob = VoY*t-(0.5)*Fobos*pow(t,2);
    dei = VoY*t-(0.5)*Deimos*pow(t,2);
    tit = VoY*t-(0.5)*Titan*pow(t,2);
    rea = VoY*t-(0.5)*Rea*pow(t,2);
    printf("Usando la gravendad de la luna: %20f\n",moon);
    printf("**********************\n");
    printf("Usando la gravendad de IO: %20f\n",io);
    printf("**********************\n");
    printf("Usando la gravedad Eur: %20f\n",eur);
    printf("**********************\n");
    printf("Usando la gravedad de Gan: %20f\n",gan);
    printf("**********************\n");
    printf("Usando la gravedad de Fobo: %20f\n",fob);
    printf("**********************\n");
    printf("Usando la gravedad de Dei: %20f\n",dei);
    printf("**********************\n");
    printf("Usando la gravedad de Tita: %20f\n",tit);
    printf("**********************\n");
    printf("Usando la gravedad de Rea: %20f\n",rea);
    printf("**********************\n");
}
