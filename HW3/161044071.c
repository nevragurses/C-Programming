#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void menu();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
void horseRacingGame();
void countOccurrence();
void triangleOfSequences();
int main()
{
	srand(time(NULL));/*It is used for taking different random numbers.*/
	menu();
	return 0;
}
/*Function that shows menü on screen until user choose 0 in menü.*/
void menu()
{
	int choice,condition=1;
	do
	{
		printf("------MENU---------\n");
		printf("1.Horse Racing Game\n");
		printf("2.Occurrence Counter\n");
		printf("3.Triangle of Sequences\n");
		printf("0.Exit\n");
		printf("\nMake your choice:");
		scanf("%d",&choice);/*Shows selection on the screen.*/
		/*This switch-case statements calls the functions in Cases  to be processed according to the user's choice.*/
		printf("\n");
		switch(choice)
		{
		case 1:
			horseRacingGame();
			break;
		case 2:
			countOccurrence();
			break;
		case 3:
			triangleOfSequences();
			break;
				
		case 0:
			condition=0;/*If user enter 0 then loop stops.*/
			break;
		default:
			condition=1;/*Allows the menu to be shown again on the screen when different selections are entered.*/
		}
		
	}
	while(condition!=0);
}
/*This function asks the user to enter a number until user enters the number  within a certain minimum and maximum range.*/
int getInt(int mini, int maxi)
{
	int num;
	scanf("%d",&num);
	while(num<mini || num>maxi)/*This loop warns the user and asks new number when user enters number that is not range.*/
	{
		printf("It is not within the %d and %d!Enter new number:",mini,maxi);
		scanf("%d",&num);
		
	}
	return num;
}
/*This function generates a random number until the random number is between minimum and maximum range.*/
int numberGeneratorBetweenRange(int min, int max)
{

	int number;
	number=rand()%(max+1);
	while(number<min)/*This loop provides getting a new random number when random number is not in range.*/
	{
		number=rand()%(max+1);
	}
	return number;
}
/*This function game of horse.*/
void horseRacingGame()	
{
	int num_of_horse,your_horse,time,i,k;
	int time_max=30,index,index2;
	int count=0;
	num_of_horse=numberGeneratorBetweenRange(3,5);/*It generates random number of horses by using numberGeneratorBetweenRange function.*/
	printf("Number of Horse:%d\n",num_of_horse);
	printf("Horse number:");
	your_horse=getInt(1,num_of_horse);/*It gets horse number for user by calling getInt function.*/
	printf("Racing starts..\n");
	for(i=1;i<=num_of_horse;++i)
	{
		time=numberGeneratorBetweenRange(10,20);/*It provide getting random time for horses.*/
		printf("Horse %d  ",i);
		/*This if statements provide to determine the fastest horse.*/
		if(time<time_max)
		{
			time_max=time;
			index=i;
		}
		if(time==time_max)
		{
			count++;
			index2=i;
		}
		
		for(k=1;k<=time;++k)/*This for loop prints "-" for random times.*/
		{
			printf("-");
		}
		
		
		printf("\n");
	}
	if(count!=0 && index!=index2)/*This if statement prints no winner if there are two winners at the same speed.*/
	{
		printf("NO WİNNER!\n\n");
	}
	
	else if(your_horse==index)/*This else statement prints "you win" when speed of user's horse is fastest.*/
	{
		printf("\nYOU WIN!Winner is horse %d\n\n",index);
	}
	else /*This else statement prints "no win" for another cases.*/
	{
		printf("\nYOU LOSE!Winner is Horse:%d\n\n",index);
	}
}
/*This function finds searching number within the number that user entered.*/
void countOccurrence()
{
	int big,search,mod,count=0;
	int i,remainder,counter=0,power;
	printf("\nBig number:");
	big=getInt(1,2147483647);/*That provides  big number is  an positive  integer value by calling getInt function. */
	printf("Search number:");
	search=getInt(1,2147483647);/*That provides searching number is an positive integer value by calling getInt function.*/
	for(i=search;i>0;i/=10)
	{
		remainder=search%10;/*That finds number of search number's digits.*/
		counter ++;
	}
	power=pow(10,counter);
	for(i=big;i>0;i/=10)
	{
		mod=i%power;
		if(search==mod)/*This if statement finds out how many are in big number of the seaching number by holding the counter.*/
		{
			count++;
			
		}
	}
	printf("Occurrence:%d\n\n",count);
}
/*This function generates a special triangle that is random row length.*/
void triangleOfSequences()
{
	int i,j;
	int value;
	value=numberGeneratorBetweenRange(2,10);/*That generates random value within 2-10 by calling numberGeneratorBetweenRange function.*/
	for(i=1;i<=value;++i)
	{
		for(j=1;j<=i;++j)
		{
			printf("%d ",i*j);
		}
		printf("\n");
	}
	printf("\n");
}
