#include <stdio.h>
//This program takes numbers from user and finds max.If number is 0,program terminates.
int main()
{
	int num;
	int max=0;

	printf("Write a number:");
	scanf("%d",&num);
	while(num!=0){
		if(num<0){
		printf("Write number:");
		scanf("%d",&num);
		}
		else if(num>0){
			if(num>max){
				max=num;
				printf("Write number:");
				scanf("%d",&num);
			}
		}
	}
	printf("Max number >>%d",max);
	return 0;
}
