/*Finds a number is whether even or odd.*/
#include <stdio.h>
int main()
{
	int num;
	printf("Write a number:");
	scanf("%d",&num);

		if(num%2==0 && num>=0){
			printf("Your number is even.");
		}
		else if(num%2!=0){
			printf("Your number is odd.");
		}
		else if(num<0){
		printf("This number couldn't be even or odd.");
		}
		
	return 0;
}
