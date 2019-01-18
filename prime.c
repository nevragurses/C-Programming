#include <stdio.h>
#define SIZE 10
/*This program prints prime numbers between 0-1000.*/
int main()
{
	int arr[SIZE],i,j;
	int flag;
	printf("Enter 10 numbers betwen 0 and 1000:\n");
	for (i=0;i<SIZE;++i)
	{
		scanf("%d",&arr[i]);
	}
	printf("Prime numbers:");
	for (i=0;i<SIZE;++i)
	{
		flag=0;
		for(j=2;j<arr[i];++j)
		{
			if(arr[i]%j==0)
			{
			flag=1;
			}
		}
		if(flag==0)
		{
			printf("%d ",arr[i]);
		}
	}

	return 0;
}

