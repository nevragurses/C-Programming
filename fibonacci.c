#include <stdio.h>
/*This program writes fibonacci series and finds bigger one.*/
void Fiboancci(int number,int *sira,int *last);
int main()
{
	int number;
	int sira,last;
	printf("Enter number:");
	scanf("%d",&number);
	Fiboancci(number,&sira,&last);
	printf("\n");
	printf("Number of an integer and the biggest number in Fibonacci Series:%d %d",sira,last);
	return 0;
}
void Fiboancci(int number,int *sira,int *last)
{
	int count=0;
	int t1=0,t2=1,temp=0;
	while(t1<number)
	{
		printf("%d",t1);
		++count;
		temp=t1+t2;
		t1=t2;
		t2=temp;
		
	}
	*last=temp-t1;
	*sira=count;
}
	
