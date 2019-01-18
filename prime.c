#include <stdio.h>
#define SIZE 10
/*This program calculates whether a number prime or not.*/
int main()
{
	int arr[SIZE],i,j;
	int flag;
	printf("Enter 10 numbers betwen 0 and 1000");
	for (i=0;i<SIZE;++i)
	{
		scanf("%d",&arr[i]);
	}
	for (i=0;i<SIZE;++i)
	{
		flag=1;
		for(j=2;j<arr[i]/2;++j)
		{
			if(arr[i]%j==0);
			flag=1;
		}
		if(flag==1)
		{
			printf("%d not prime:",arr[i]);
		}
		else
		{
			printf("%d prime:",arr[i]);
		}
	}
	return 0;
}

	
