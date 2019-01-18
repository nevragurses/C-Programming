#include <stdio.h>
//This pprogram reverse an array with function that takes array as parameter.
void insert(int a[],int b[],int sizea);
int main()
{
	int i,sizea=4;
	int a[]={1,2,3,4};
	int b[sizea];
	for(i=0;i<sizea;++i)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	
	insert(a,b,sizea);
	
	for(i=0;i<sizea;++i)
	{
		printf("%d",b[i]);
	}
	return 0;
}
void insert(int a[],int b[],int sizea)
{
	int i;
	for(i=0;i<sizea;++i)
	{
		b[sizea-i-1]=a[i];
	}
}
	
	
	
