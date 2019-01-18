/*This program calculates body mass index.*/
#include <stdio.h>
#include <math.h>
void welcome();
int getHeight();
double getInputDouble();
double calculateBMI(int height,double weight);
void printBMICategory(double BMI);
void printInfo(int height,double weight);
int main()
{
	int height;
	double weight;
	height=getHeight();
	weight=getInputDouble();
	printInfo(height,weight);
	return 0;
}
void welcome()
{
	printf("BMI CALCULATOR");
	printf("Body mass index tells someone");
	printf("whether his/her healthy weight.");
}
int getHeight()
{
	int height;
	printf("Enter height:");
	scanf("%d",&height);
	return height;
}
double getInputDouble()
{
	double weight;
	printf("Enter weight:");
	scanf("%lf",&weight);
	return weight;
}
double calculateBMI(int height,double weight)
{
	double BMI;
	/*printf("Body mass index can be calculated using:\n");*/
	BMI=(weight)/pow(height/100.0,2);
	return BMI;
}
void printBMICategory(double BMI)
{
	if(0<=BMI && BMI<=18.49){
		printf("Category:Underweight");
	}
	else if(18.5 <=BMI && BMI<=24.49)
	{
		printf("Category:Normal");
	}
	else if(24.5<=BMI && BMI<=29.99){
		printf("Category:Overweight");
	}
	else if(30<=BMI && BMI>=30){
		printf("Category:Obesity");
	}
}
void printInfo(int height,double weight)
{
	double BMI=calculateBMI(height,weight);

	printf("Height:%d\nWeight=%.2lf\nBMI=%.2lf\n",height,weight,BMI);
	printBMICategory(BMI);
}

	


































	

	
