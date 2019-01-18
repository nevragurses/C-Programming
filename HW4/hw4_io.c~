/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** 
*/

#include <stdio.h>
#include "hw4_io.h"
/*This function gets coefficients for degree-3 polynomial from the user.*/
int read_polynomial3(double * a0, double * a1, double * a2, double * a3)
{
	printf("Enter coefficients of a degree-3 polynomial in order x^3,x^2,x,x^0:\n");
	scanf("%lf \n%lf \n%lf \n%lf",&*a0,&*a1,&*a2,&*a3);/*Shows coefficients of degree-3  polynomial  entered by user on the screen.*/

}

/*This function gets coefficients for degree-4 polynomial from the user.*/
int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4)
{
	printf("\nEnter coefficients of a degree-4 polynomial in order x^4,x^3,x^2,x,x^0:\n");
	scanf("%lf \n%lf \n%lf \n%lf \n%lf",&*a0,&*a1,&*a2,&*a3,&*a4);/*Shows coefficients of degree-4 polynomial  entered by user on the sceen.*/
}

/*This function writes degree-3 polynomial.*/		
void write_polynomial3(double a0, double a1, double a2, double a3)
{
	int i;
	double arr[]={a3,a2,a1,a0};/*This array holds the coefficients of degree-3 polynomial function.*/

	/*All operations is made ins this for loop.*/
	for(i=3;i>=0;--i)
	{
			
		if(arr[i]!=0)/*If the coefficient of x is 0,this coefficient and x are not displayed on screen,for another cases the following operations are performed by this if statement.*/
		{
			/*Last coefficient a0 is showed without x^0 because x^0 is 1 by this if statement.*/
			if(i==0)
			{
				/*Signs  of the last coefficient a0 is showed by this if/else statements.*/
				if(arr[i]>0)
				{
					printf("+%.1f",arr[i]);
				}
				else if(arr[i]<0)
				{
					printf("%.1f",arr[i]);
				}
	
			}
			/*This else statement is activeted if exponent of x is different from zero.*/
			else
			{
				/*This if statement activeted when coefficient of x is positive and it is not equal to +1.*/
				if(arr[i]>0 && arr[i]!=1)
				{
					if(i==1)/*If exponent of x is 1,x is showed only x instead of x^1 with its coefficient  by this if statemet.*/
					{
						printf("+%.1fx",arr[i]);
					}
					else/*If exponent of x different from 1 and 0,x is showed with its exponent and its coefficient by this else statement.*/
					{
						printf("+%.1fx^%d",arr[i],i);
					}
				}
				/*This else  statement activeted when coefficient of x is negative and it is not equal to -1.*/
				else if(arr[i]<0 && arr[i]!=-1)
				{
					if(i==1)
					{
						printf("%.1fx",arr[i]);/*If exponent of x is 1,x is showed only x instead of x^1 with its coefficient  by this if statemet.*/
					}
					else
					{
						printf("%.1fx^%d",arr[i],i);/*If exponent of x different from 1 and 0,x is showed with its exponent and its coefficient by this else statement.*/
					}
				}
				/*If coefficient of x is 1,only x and its exponent is showed by this else  statement*/
				else if(arr[i]==1)
				{
					printf("+x^%d",i);
				}
				/*If coefficient of x is -1,ony -x and its exponent  is showed by this else statement.*/
				else if(arr[i]==-1)
				{
					printf("-x^%d",i);
				}
			}
		}
	}
}

/*This function writes degree-4 polynomial.*/
void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
	int i;
	double arr[]={a4,a3,a2,a1,a0};/*This array holds the coefficients of degree-4 polynomial function.*/

	/*All operations is made in this for loop.*/
	for(i=4;i>=0;--i)
	{
		if(arr[i]!=0)/*If the coefficient of x is 0,this coefficient and x are not displayed on screen,for another cases the following operations are performed by this if statement.*/
		{
			/*Last coefficient a0 is showed without x^0 because x^0 is 1 by this if statement.*/
			if(i==0) 
			{
				/*Signs  of the last coefficient a0 is showed by this if/else statements.*/
				if(arr[i]>0)
				{
					printf("+%.1f",arr[i]);
				}
				else if(arr[i]<0)
				{
					printf("%.1f",arr[i]);
				}
	
			}
			/*This else statement is activeted if exponent of x is different from zero.*/
			else
			{
				/*This if statement activeted when coefficient of x is positive and it is not equal to +1.*/
				if(arr[i]>0 && arr[i]!=1)
				{
					
					if(i==1)/*If exponent of x is 1,x is showed only x instead of x^1 with its coefficient  by this if statemet.*/
					{
						printf("+%.1fx",arr[i]);
					}
					else/*If exponent of x different from 1 and 0,x is showed with its exponent and its coefficient by this else statement.*/
					{
						printf("+%.1fx^%d",arr[i],i);
					}
				}
				/*This else  statement activeted when coefficient of x is negative and it is not equal to -1.*/
				else if(arr[i]<0 && arr[i]!=-1)
				{
					if(i==1)
					{
						printf("%.1fx",arr[i]);/*If exponent of x is 1,x is showed only x instead of x^1 with its coefficient  by this if statemet.*/
					}
					else
					{
						printf("%.1fx^%d",arr[i],i);/*If exponent of x different from 1 and 0,x is showed with its exponent and its coefficient by this else statement.*/
					}
				}
				/*If coefficient of x is 1,only x and its exponent is showed by this else  statement*/ 
				else if(arr[i]==1)
				{
					printf("+x^%d",i);
				}
				/*If coefficient of x is -1,ony -x and its exponent  is showed by this else statement.*/
				else if(arr[i]==-1)
				{
					printf("-x^%d",i);
				}
			}
		}
	}
}























	

