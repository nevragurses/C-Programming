/*
** main.c:
**
** The test program for the homework.
*/


#include <stdio.h>
#include "hw4_io.h"
#include "hw4_lib.h"

double f(double x) { return x*x; }
double d1(double x) { return 2.0*x; }
double d2(double x) { return 2.0; }
double f2(double x,double y) { return (x*x)+(4*y) ;} 
double f3(double x) { return ((x-2)*(x-2)*(x-2)*(x-2));}

/*
**Testing polynomial functions...
**
*/
void test_polynomial(){
	double a0,a1,a2,a3,a4;
	read_polynomial3(&a0,&a1,&a2,&a3);
	write_polynomial3(a0,a1,a2,a3);	
	read_polynomial4(&a0,&a1,&a2,&a3,&a4);
	write_polynomial4(a0,a1,a2,a3,a4);
}
	
	

/*
** Testing derivative calculations..
**
*/
void test_compare_derivatives() {
	double e1, e2;
	int res = compare_derivatives(f, d1, d2, 1.0, 0.0001, &e1, &e2);
	printf("%f %f\n",e1,e2);
}
/*
** Testing integration calculations..
**
*/
void test_integral(){
	integral(f,2,5,0.0001);	
}
/*
** Testing double integration calculations..
**
*/
void test_double_integral(){
	integral2(f2,0,1,0,1,0.001);
}

/*
**Testing derivative..
**
*/
void test_derivative(){
	double d1,d2;
	derivatives(f,3,0.0001,&d1,&d2);
	printf("%f %f\n",d1,d2);
}
/*
**Testing find root calculations..
**
*/
void test_find_root(){
	double x1,x2,x3,x4;
	find_roots(f3,&x1,&x2,&x3,&x4);
	printf("Roots:%f %f %f %f",x1,x2,x3,x4);
}

/*
** main function for testing the functions...
**
*/
int main(void)
{
		printf("3-DEGREE AND 4-DEGREE POLINOMIALS\n");
		test_polynomial();
		printf("\n\nINTEGRAL\n");
		test_integral();
		printf("\n\nDOUBLE INTEGRAL\n");
		test_double_integral();
		printf("\n\nDERİVATIVES\n");
		test_derivative();
		printf("\nCOMPARE DERIVATIVES\n");
		test_compare_derivatives();
		printf("\nFINDING ROOTS\n");
		test_find_root();
		return (0);
		
}
	
	
	

