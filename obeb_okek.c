#include <stdio.h>
/*This program calculates greatest lower bound and least upper bound.*/
void LCMGCD(int num1,int num2,int *obeb,int *okek);
int main()
{
	int obeb,okek,num1,num2;
	scanf("%d",&num1);
	scanf("%d",&num2);
	LCMGCD(num1,num2,&obeb,&okek);
	printf("LGMGCD(%d,%d)=%d,%d",num1,num2,obeb,okek);
	return 0;
}
	


void LCMGCD(int num1,int num2,int *obeb,int *okek)
{
	int small,i,find_obeb;
	if(num1<num2)
	{
		small=num1;
	}
	else if(num1>num2)
	{
		small=num2;
	}
	for(i=1;i<=small;++i)
	{
		if(num1%i==0 && num2%i==0)
		{
			find_obeb=i;
		}
	}
	*obeb=find_obeb;
	*okek=(num1*num2)/(*obeb);


}
