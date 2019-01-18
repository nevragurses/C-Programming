#include <stdio.h>
#include <math.h>
#define PI 3.14  

/*This program calcultes ;the area of the largest circle that fits inside a rectangle,
the area of the largest square that fits inside the rectangle,
the area of the smallest circle that surrounds the same rectangle,
the area of the smallest square that surrounds the same rectangle with different functions.*/

/*Function prototypes*/
double circle_area(double radius);
double calc_hypotenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);
double calc_area_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_square(int side1, int side2);
double calc_area_of_largest_square(int side1, int side2);
double calc_area_of_square (int side);
void display_results(double largest_cicle,double largest_square,double smallest_circle,double smallest_square);

int main()
{
	int side1,side2;
	double largest_circle,largest_square,smallest_circle,smallest_square;
	
	printf("Please enter first side for rectangle:");
	scanf("%d",&side1);  /*Shows the first side lenght of rectangle on the screen.*/
	printf("Please enter second side for rectangle:");
	scanf("%d",&side2);  /*Shows the second side lenght of rectangle on the screen.*/

	/*assigns functions to double type variables)*/
	largest_circle=calc_area_of_largest_circle(side1,side2);
	largest_square=calc_area_of_largest_square(side1,side2);
	smallest_circle=calc_area_of_smallest_circle(side1,side2);
	smallest_square= calc_area_of_smallest_square(side1,side2);

	display_results(largest_circle,largest_square,smallest_circle,smallest_square);/*Calls function that displays results.*/
	return 0;
}
/*This function calculates a circle's area.*/
double circle_area(double radius)
{
	double area_circle;
	area_circle=PI*pow(radius,2);
	return(area_circle);
}
/*This function calculates a hyponetuse length with using side1 and side2.*/
double calc_hypotenuse(int side1, int side2)
{
	double hypotenuse;
	hypotenuse=sqrt((pow(side1,2))+(pow(side2,2)));
	return(hypotenuse);
}
/*This function calculates the radius of the largest circle that fits inside a rectangle.*/
double calc_radius_of_largest_circle(int side1, int side2)
{
	double radius_of_largest_circle;
	if(side1<=side2)
	{
		radius_of_largest_circle=side1/2.00;/*Radius of the largest circle is found by dividing short side lenght by  double type 2.*/
	}
	else   
	{
		radius_of_largest_circle=side2/2.00;
	}
	return(radius_of_largest_circle);
}
/*This function calculates the area of the largest circle that fits inside a rectangle  by  calling the function named "circle_area".*/
double calc_area_of_largest_circle(int side1, int side2)
{
	double area_of_largest_circle;
	area_of_largest_circle=circle_area(calc_radius_of_largest_circle(side1,side2));
	return(area_of_largest_circle);
}
/*This function calculates the area of the smallest circle that surrounds the same rectangle by calling the function named "circle_area."*/
double calc_area_of_smallest_circle(int side1, int side2)
{
	double area_of_smallest_circle;
	area_of_smallest_circle=circle_area(calc_hypotenuse(side1,side2)/2.00);/*The half of hypotenuse length is radius of smallest circle.*/
	return(area_of_smallest_circle);
}
/*This function calculates the area of the smallest square that surrounds the same rectangle by calling the function named "calc_area_of_square."*/
double calc_area_of_smallest_square(int side1, int side2)
{
	double area_of_smallest_square;
	if(side1>=side2)
	{
		area_of_smallest_square=calc_area_of_square(side1);/*The long side lenght of the rectangle is a side length of smallest square.*/	}
	else 
	{
		area_of_smallest_square=calc_area_of_square(side2);
	}
	return(area_of_smallest_square);
}
/*This function calculates the area of the largest square that fits inside the rectangle by calling the function named "calc_area_of_square."*/
double calc_area_of_largest_square(int side1, int side2)
{
	double area_of_largest_square;
	if(side1<=side2)
	{
		area_of_largest_square=calc_area_of_square(side1);/*The short side length of the rectangle is a side length of the largest square.*/
	}
	else 
	{
		area_of_largest_square=calc_area_of_square(side2);
	}
	return(area_of_largest_square);
}
/*This function calculates area of a square.*/
double calc_area_of_square(int side)
{
	double area_of_square;
	area_of_square=pow(side,2.00);
	return(area_of_square);
}
/*This function displays results on screen .*/
void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square)
{
	/*Prints the values of double type parameters that assigned by functions in Main function.*/
	printf("The area of the largest circle that fits inside a rectangle:%.2lf\n",largest_circle);
	printf("The area of the largest square that fits inside the rectangle:%.2lf\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle:%.2lf\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle:%.2lf\n",smallest_square);
}







