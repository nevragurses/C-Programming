#include <stdio.h>
/*This program sorts characters.*/
void alpabeticalSort(char *arr,int size);
int main()
{
	int i;
	char arr[]={'m','e','r','h','a','A','i'};
	alpabeticalSort(arr,7);
	for(i=0;i<7;++i)
	{
		printf("%c",arr[i]);
	}
	printf("\n");
	return 0;
}
void alpabeticalSort(char *arr,int size)
{
	int i,j,temp;
	for(j=0;j<size;++j)
	{
		for(i=j+1;i<size;++i){
			if(arr[j]>arr[i])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
}
