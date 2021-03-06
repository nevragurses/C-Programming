#include <stdio.h>
/*C program to find all digits of a number which is entered from the keyboard (the
number must be between 23 and 98760).*/
int main()
{
	int first,second,third,fourth,fifth;
	int number;
	printf("Enter the number between 23 and 98760:");
	scanf("%d",&number);/*Shows the number that user enters*/
	/*This if statement prints the digits of a two-digit number between 23 and 99 on the screen by finding the numbers in digits.*/
	if(number>=23 && number<=99)
	{
		second=(number-(number%10))/10;
		printf("\nThe second digit is:%d\n",second);
		first=number%10;
		printf("The first digit is:%d\n",first);
	}
	/*This else statement prints the digits of a three-digit number on the screen by finding the numbers in digits.*/
	else if(number>=100 && number <=999)
	{
		third=number/100;
		printf("\nThe third digit is:%d\n",third);
		second=((number%100)-(number%10))/10;
		printf("The second digit is:%d\n",second);
		first=number%10;
		printf("The first digit is:%d\n",first);
	}
	/*This else statement prints the digits of a four-digit number on the screen by finding the numbers in digits.*/
	else if(number>=1000 && number<=9999)
	{
		fourth=number/1000;
		printf("\nThe fourth digit is:%d\n",fourth);
		third=((number%1000)-(number%100))/100;
		printf("The third digit is:%d\n",third);
		second=((number%100)-(number%10))/10;
		printf("The second digit is:%d\n",second);
		first=number%10;
		printf("The first digit is:%d\n",first);
	}
	/*This else statement prints the digits of a five-digit number between 10000 and 98760 on the screen by finding the numbers in digits. */
	else if(number>=10000 && number<=98760)
	{
		fifth=number/10000;
		printf("\nThe fifth digit is:%d\n",fifth);
		fourth=((number%10000)-(number%1000))/1000;
		printf("The fourth digit is:%d\n",fourth);
		third=((number%1000)-(number%100))/100;
		printf("The third digit is:%d\n",third);
		second=((number%100)-(number%10))/10;	
		printf("The second digit is:%d\n",second);
		first=number%10;
		printf("The first digit is:%d\n",first);
	}
	/*This else statement prints the warning message is on the screen  when an out-of-range number is entered.*/
	else
	{
		printf("The number is not between 23 and 98760!\n");
	}
	return 0;
}

