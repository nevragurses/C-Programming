#include <stdio.h>
/*This program draws a shape.*/
int main()
{
	int num,i,j;
	printf("Enter a number:");
	scanf("%d",&num);
	for(i=1;i<num;++i)
	{
		for(j=1;j<=num-i;++j)
		{
			printf(" ");
		}
		for(j=1;j<=(2*i)-1;++j)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=1;i<=num;++i)
	{
		for(j=1;j<=(2*num)-1;++j)
		{
			printf("*");
		}
		printf("\n");
	}
	
	for(i=1;i<num;++i)
	{
		for(j=1;j<=(2*i)-i;++j)
		{
			printf(" ");
		}
		for(j=1;j<(2*num+1)-(2*i+1);++j)
		{
			printf("*");
		}
		printf("\n");
	}
	
	
	
		
	return 0;
}
