#P4 Matrix-addition
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	system("color F3");
	int a[2][2] = {{8,7},{2,1}};
	int b[2][2] = {{2,3},{9,4}};
	int r[2][2] = {0};
	int i,j;
	
	for(i=0; i<2; i++){
		for (j=0; j<2;j++)
			r[i][j] = a [i][j] + b[i][j];
	}
	for (i=0; i<2; i++)
		for(j=0; j<2; j++)
		printf("\n [%i] + [%i] = [%i]\n", a[i][j], b[i][j], r[i][j]);
	
}
