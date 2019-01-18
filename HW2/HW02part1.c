#include <stdio.h>
#include <stdlib.h>
void find_letter_grade(int grade);
int main()
{
	int student,i,selection,grade,r,count=0;
	int counter1=0,counter2=0,counter3=0,counter4=0,counter5=0;
	int max=0,min=100;
	int index_max,index_min;
	int condition=0;
	double sum=0.0;
	
	printf("Enter student count:");
	scanf("%d",&student);/*Prints the number of student count.*/
	srand(40);/*Calls the function that creates random grades.*/
	
	/*This loop prints warning if student count less than 2 or more than 50 and prints a new student count.*/
	while(student<=2 || student>50)
	{
		printf("\nNot in range!\n");
		printf("Enter student count:");
		scanf("%d",&student);
		
	}
	printf("\n");
	/*All calculations are done in this for loop.*/
	for(i=1;i<=student;++i)
	{
		
			r=rand()%101;/*Takes random scores that are between 0 and 100,up to the count of students and assigns them a variable named 'r'.*/
			printf("%d ",r);
			count++;/*increase counter for each received score.*/

			/*This if statement allows 10 student score to be displayed on one line in the terminal.*/
			if(count>=10)
			{
				printf("\n");
				count=0;/*After getting 10 score, the counters will be zero.*/
			}
			
			/*This if statement finds the maximum score and the index.*/
			if(r>max)/*Gives the condition that if the new score is higher than the previous score.*/
			{
				max=r;
				index_max=i;/*assigns the number of 'i' in the for loop where the maximum number is found to variable named index_max.*/

			}
			/*This if statement finds the minimum score and the index.*/
			if(r<min)/*Gives the condition that is if the new score is less than the previous score.*/
			{
				min=r;
				index_min=i;/*assigns the number of 'i' in the for loop where the minimum score is found. to variable named index_min.*/
			}
			/*Each letter grade's numbers is calculated with this if/else statements by increasing counter.*/
			
			if(r>=90 && r<=100)
			{
				counter1++;
			}
			else if(r>=80 && r<=89)
			{
				counter2++;	
			}	
			else if(r>=70 && r<=79)
			{
				counter3++;
			}
			else if(r>=60 && r<=69)
			{
				counter4++;
			}
			else if(r>=0 && r<=59)
			{
				counter5++;
			}
			sum+=r;/*Finds the sum of all the scores.*/
	
	}
		

	while(condition!=-1)/*This is the loop that allows the menu to be displayed as long as -1 is not entered.*/
	{
		/*The options in the menu are printed on the screen.*/
		printf("\n---------------------------------------------------");
		printf("\n\nStudent Score Calculator Menü For %d Student\n",student);
		printf("1)Most Successful Student\n");
		printf("2)Most Unsuccessful Student\n");
		printf("3)Letter Grade Statistics\n");
		printf("4)Calculate Avarage\n");
		printf("5)Show All\n");
		printf("\t\t\t\tMake selection:");
		scanf("%d",&selection);/*Shows the selection on the screen*/
		/*This switch statement shows the operations according to the selection made in the menu.*/

		switch(selection)
		{

		case 1:/*Prints maximum score,it's index and it's letter grade.*/

			printf("\nMost Successful Student:\n");
	      	 	printf("Index:%d\n",index_max);
	      	 	printf("Score:%d\n",max);
	      		grade=max;
	      		find_letter_grade(grade);/*Finds the letter grade of maximum score by calling the finding letter grade function.*/
	     		break;

		case 2:/*Prints minimum score,it's index and it's letter grade.*/

			printf("\nMost Unsuccessful Student:\n");
	     		printf("Index:%d\n",index_min);
	      		printf("Score:%d\n",min);
         		grade=min;
	      		find_letter_grade(grade);/*Finds the letter grade of minimum score by calling the finding letter grade function.*/
	      	 	break;

		case 3:/*Shows that how many points are in which letter grade.*/

			printf("\nLetter Grade Statistics:\n");
	      	 	printf("%d student got grade 'A'\n",counter1);
	      		printf("%d student got grade 'B'\n",counter2);
	      		printf("%d student got grade 'C'\n",counter3);
	      		printf("%d student got grade 'D'\n",counter4);
           		printf("%d student got grade 'F'\n",counter5);
	      		break;

		case 4:/*Calculates the avarage score of students.*/

			printf("\nCalculate Avarage:\n");
	      	 	printf("The average score of %d students is:%.2lf\n",student,sum/student);
	     		break;
	
		case 5:/*It shows everything done in the previous 4 cases on the screen.*/

			printf("\nShow All:\n");
	     		printf("\nMost Successful Student:\n");
	       	 	printf("Index:%d\n",index_max);
	       	 	printf("Score:%d\n",max);
	        	grade=max;
	        	find_letter_grade(grade);

	        	printf("\nMost Unsuccessful Student:\n");
	       	 	printf("Index:%d\n",index_min);
	        	printf("Score:%d\n",min);
                	grade=min;
	        	find_letter_grade(grade);
		
	       	 	printf("\nLetter Grade Statistics:\n");
	        	printf("%d student got grade 'A'\n",counter1);
	        	printf("%d student got grade 'B'\n",counter2);
	        	printf("%d student got grade 'C'\n",counter3);
	        	printf("%d student got grade 'D'\n",counter4);
            		printf("%d student got grade 'F'\n",counter5);
	      
			printf("\nCalculate Avarage:");
	        	printf("The average score of %d students is:%.2lf\n",student,sum/student);
	        	break;

		case -1:/*Ends the program.*/

			condition=-1;
	        	break;

		default:/*Notifies when an out of menu selection is made.*/

			printf("\nFalse Selection!!\n");
		}
	}
	return 0;
}

/*This function finds out which letter grade  the score is in by if/else statements.*/
void find_letter_grade(int grade)
{
	if(grade>=90 && grade<=100)
	{
		printf("Letter Grade:A\n");
	}
	else if(grade>=80 && grade<=89)
	{
		printf("Letter Grade:B\n");
	}
	else if(grade>=70 && grade<=79)
	{
		printf("Letter Grade:C\n");
	}
	else if(grade>=60 && grade<=69)
	{
		printf("Letter Grade:D\n");
	}
	else if(grade>=0 && grade<=59)
	{
		printf("Letter Grade:F\n");
	}
	
}
