/*This program find sinus,power and factorial without using math library.*/

#include <stdio.h>
int factorial(int n);
double power(double x,int n);
double sin(double x);
int main()
{
	double x,result;
	printf("Please enter the degree to be calculated:");
	scanf("%lf",&x);
	result=sin(x);  /*In this part I called the sin(x) function. */
	printf("result:%f \n",result); /*I printed the result on the screen.*/
	return 0;
}
	
	int factorial(int n)
	{
		int i;
		int fact=1;
		
		for(i=1;i<=n;++i)
		{
			fact=fact*i;/*I created a cycle that would calculate the factorial operation.*/
		}
		return fact;
	}
	double power(double x,int n)
	{
		int count=1;
		double multiplication=1;
		if(x!=0 || n!=0)
		{

			while(count<=n)
			{
				multiplication=multiplication*x;/*I create a cycle that would calculate exponential operation.*/
				++count;
			}
		}

		else if(x==0 && n==0)/*I gave a condition that  x and n are equal to 0.*/
		{
			return -1;
		}
		return multiplication;
	}
double sin(double x)
{
	double radian;
	const double pi=3.14159;/*I fixed the value of pi.*/
	radian=(pi*x)/180;/*I wrote the transformation that translate the degree into radian.*/
	double result=0;
	int i,term; 
	printf("Please enter the term that you are wanted:");
	scanf("%d",&term);
	
	for(i=1;i<=term;i++)/*I created a cycle that would calculate the Taylor expantion of sinüs.*/
	{
		result+=power(-1,i-1)*(power(radian,2*i-1)/factorial(2*i-1));/*In this section I performed the Taylor expantion of sinüs.*/
	}
	return result;
}

		
		
		
		
			

	
