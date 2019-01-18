#include <stdio.h>
/*This program calculates square root*/
int main(){

	int i;
	double num,x;

	printf("Print a number:");
	scanf("%lf",&sayi);
 
	x=1;
	for(i=0;i<1000;i++){
 		x=0.5*(x+(num/x));
	}
 	printf("\nresult:%f\n",x);
 	return 0;

}
