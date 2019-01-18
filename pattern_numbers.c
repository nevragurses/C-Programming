#include <stdio.h>
/*This program prints numbers as pattern.Such:

1 = 1
1 + 2 = 3
1 + 2 + 3 =5 ...

*/
int main()
{
	int i,num,j,k,sum=0;
	printf("Enter a positive integer:");
	scanf("%d",&num);
	for(i=1;i<=num;++i)
	{
	
		for(j=1;j<=i;++j)
		{
			if(j==i)
			{
				printf("%d",j);
			}
			else
			{
			
			printf("%d+",j);
			}
			
			
		
			sum=sum+j;
		
			
			
		
		}
		printf("=%d",sum);
		
		printf("\n");
		sum=0;
	}
	return 0;
}
		
