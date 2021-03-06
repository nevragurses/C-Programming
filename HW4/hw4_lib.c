/*
** hw4_lib.c:
**
** The source file implementing library functions.
**

** 
*/
#include <stdio.h>
#include "hw4_lib.h"
/*This function makes numeric calculation of the integral of the function f within the range [xs,xe].*/
double integral(double f(double x), double xs, double xe, double delta)
{
	/*to find integral of a function, lim n -->infinity delta*(summation notation from i=1 i=n f((xs+i*delta))) formula is used and delta is (xe-xs)/n.This formula is called RİEMAN SUMS*/
	double n=(xe-xs)/delta;/*variable n is upper bound of summation notation.*/
	double summation_notation=0;
	int i;
	for(i=1;i<=n;++i)
	{
		summation_notation+=delta*f(xs+(i*delta));/*summation notation from 1 to n that is upper bound is made using f function that  is wanted finding integral by using integration formula*/
	}
	printf("%.2f",summation_notation);
	return summation_notation;
	
}	




/*This function makes numeric calculation of the integral of a two input function within the given range [xs,xe] and [ys,ye].*/
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta)
{
	
	/*to find double integral of a function,double summation notation is made.Midpoint Rule is used.*/
	double n_out=(xe-xs)/delta;/*This n_out variable is upper bound of summation notation that is out.*/
	double n_in=(ye-ys)/delta;/*This n_in variable is upper bound of summation notation that is in.*/ 
	double sum_all=0;
	int i,j;
	/*By using nested for loop, double summation notation is made and applied the double integration formula to find integral of f function by using f function.
	Integration is made as y firsty and then x.*/
	for(i=1;i<=n_out;++i)
	{
		for(j=1;j<=n_in;++j)
		{
			sum_all+=delta*delta*f(xs+i*delta,ys+j*delta);
		}
	}
	printf("%.2f",sum_all);
	
	return sum_all;
}


/*This function makes numeric calculation of first (d1) and second (d2) derivative of a given function.*/
int derivatives(double f(double a), double x, double eps, double * d1, double * d2)
{
	
	*d1=(f(x+eps)-f(x-eps))/(2*eps);/*By using  first derivative formula first derivative of f function is found.*/
	*d2=(f(x+eps)-2*f(x)+f(x-eps))/(eps*eps);/*By using second derivative formula second derivative of f function is found.*/

	/*This if /else statements provide returning different values as epsilon.*/
	if(eps==0)
	{
		return -1;
	}
	else
		return 1;
	
}



/*This function tests the error in numeric calculation of derivatives vs. actual derivatives given by functions d1 and d2.*/
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2)
{
	double drv1,drv2;
	double actual_d1,actual_d2;
	double numeric_d1,numeric_d2;
	double difference_1,difference_2;
	
	
	

	derivatives(f,x,eps,&drv1,&drv2);/*Numeric first and second derivatives of f function is found by using function named derivatives.*/
	numeric_d1=drv1;
	numeric_d2=drv2;	
	actual_d1=d1(x);/*actual first derivative is found by using d1 function.*/
	actual_d2=d2(x);/*actual second derivative is found b using d2 dunction.*/
	
	/*The absolute difference is found by using actual and numeric derivatives.*/
	difference_1=(actual_d1)-(numeric_d1);
	difference_2=(actual_d2)-(numeric_d2);
	if(difference_1<0)
	{
		*e1=-1*difference_1;
	}
	else
	{
		*e1=difference_1;
	}
	if(difference_2>=0)
	{
		*e2=difference_2;
	}
	else
	{
		*e2=-1*difference_2;
	}
	
	return (*e1);
	
}
/*This function finds "one" root of a function by using SECANT METOD*/

int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4)
{

	double x_zero=0.001,x_start=3,x_new,error=0.0,tolerance=0.00001;
	do
	{
		
		x_new=(x_start-((x_start-x_zero)*f(x_start))/(f(x_start)-f(x_zero)));/*used secant formula to find approximate root.*/
		error=x_start-x_zero;/*the difference between the two approximate roots is updated.*/
		/*Absolute value of error is taken by using if/else statement.*/
		if(error<0)
		{
			error=-1*error;
		}
		else
		{
			error=+error;
		}
		/*new approximate roots are updating by this assignments.*/
		x_zero=x_start;
		x_start=x_new;
		
		/*printf("Approximate root:%f error:%f\n",x_new,error);*/
	}
	while(error>=tolerance);/*This loop continues while the difference between the two approximate roots is  bigger than tolerance.*/
	*x1=x_new;
	*x2=0.0;
	*x3=0.0;
	*x4=0.0;
	return x_new;
}
	


	












































