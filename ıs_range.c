/*This program is find whether a number is in given range or not.*/
#include <stdio.h>
int isInRange(int up,int low,int num);
int main()
{
	int up,low,sayi;
	printf("Write up value:");
	scanf("%d",&up);
	printf("write low value:");
	scanf("%d",&low);
	printf("Write a number:");
	scanf("%d",&sayi);
	while(sayi!=-1){
		isInRange(up,low,sayi);
		
		if(isInRange(up,low,sayi)==1){
			printf("Your number is that range.");
		}
		else if(isInRange(up,low,sayi)==0){
			printf("Your number is not that range");
		}
		
		printf("\Write a number:");
		scanf("%d",&sayi);
	}
	return 0;
}
	
int isInRange(int up,int low,int num)
{
	if(num>=low && num<=up)
	{
		return 1;
	}
	else{
		return 0;
	}
}


