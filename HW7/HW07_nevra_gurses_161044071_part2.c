#include <stdio.h>
typedef enum 
		{monday,tuesday,wednesday,thursday,friday,saturday,sunday}
		days;
void print_day(int s_day,int s_month,int s_year,int e_day,int e_month,int e_year);
void find_day(int day,int month,int year);
void convert_date();
int find_leap_year(int year);
int main()
{
	int start_day,start_month,start_year,end_day,end_month,end_year;
	char slash;
	printf("Enter a start date that is dd/MM/yyyy format:");/*Start date takes from user*/
	scanf("%d %c %d %c %d",&start_day,&slash,&start_month,&slash,&start_year);
	printf("Enter a end date that is dd/MM/yyyy format:");/*End date takes from user*/
	scanf("%d %c %d %c %d",&end_day,&slash,&end_month,&slash,&end_year);
	
	print_day(start_day,start_month,start_year,end_day,end_month,end_year);
	convert_date();
	return 0;
}
/*This funciton generate all dates (day by day) between two dates.And writes them input_date.txt file.*/
void print_day(int s_day,int s_month,int s_year,int e_day,int e_month,int e_year)
{
	int year,month,day,flag=0;
	FILE *date;
	date=fopen("input_date.txt","a+");/*The file is opening to write.*/
	for(year=s_year;year<=e_year;year++){/*Loop is started from start year up to end year.*/
		if(year==e_year && s_year!=e_year){/*If start year is not equal to end year so end year bigger than start year and year that is in loop is end year this statement is prosessed.*/
			for(month=1;month<=12;month++){
				if(month!=e_month && flag!=1){/*If there are month so end month doesn't came,every month start from day 1.*/
					if(month==1||month==3 ||month==5 ||month==7 || month==8 ||month==10 ||month==12){/*If month that is in loop is 31 day.*/
						for(day=1;day<=31;day++){
							/*This if/else statements provide to print single digit to double digit.(for example :07/06/1998)*/
							if(day<10&&month<10){
								fprintf(date,"0%d/0%d/%d\n",day,month,year);
								printf("0%d/0%d/%d\n",day,month,year);
							}
							else if(day<10&&month>=10){
								fprintf(date,"0%d/%d/%d\n",day,month,year);
								printf("0%d/%d/%d\n",day,month,year);
							}
							else if(day>=10&&month<10){
								fprintf(date,"%d/0%d/%d\n",day,month,year);
								printf("%d/0%d/%d\n",day,month,year);
							}
							else{
								fprintf(date,"%d/%d/%d\n",day,month,year);
								printf("%d/%d/%d\n",day,month,year);
							}
						}
					}
					else if(month==2){/*If month that is in loop is 28 or 29 day.*/
						if(find_leap_year(year)==1){/*If year is a leap found*/
							for(day=1;day<=29;day++){
								/*All days prints 1 to 29*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}		
							}
						}
						else if(find_leap_year(year)==0){/*If year is not leap year*/
							for(day=1;day<=28;day++){
								/*All days prints 1 to 28*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
					}
					else if(month==4 || month==6 || month==9 ||month==11){/*If month that is in loop is 31 day.*/
						for(day=1;day<=30;day++){
							/*All days prints 1 to 28*/
							if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
						}
					}
				}
				else if(month==e_month){/*If end month and end year cames in loop.*/
					for(day=1;day<=e_day;day++){
						/*All days prints 1 to end day.*/
						if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
						flag=1;/*Flag changes to exit the loop*/
					}
				}
			}
		}
		else if(s_year==e_year){/*If start year is equal to end year*/
			for(month=s_month;month<=12;month++){
				if(month!=e_month && flag!=1){/*If there are month so end month doesn't came,every month start from day 1 except start month.*/
					if(month==1||month==3 ||month==5 ||month==7 || month==8 ||month==10 ||month==12){/*If month that is in loop is 31 day.*/
						if(month==s_month){/*If month that is in loop is equal to start month*/
							for(day=s_day;day<=31;day++){/*Days prints from start day up to 31.*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{/*If month that is in loop is not equal to start month*/
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
						else{/*If month that is in loop is not equal to start month*/	
							for(day=1;day<=31;day++){/*Days prints from 1 up to 31.*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
					}
					else if(month==2){/*If month that is in loop is 31 day.*/
						if(find_leap_year(year)==1){/*If month that is in loop is leap year.*/
							if(month==s_month){/*If month that is in loop is equal to start month*/
								for(day=s_day;day<=29;day++){/*Days prints from start day up to 29.*/
									if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
								}
							}
							else{/*If month that is in loop is not equal to start month*/
								for(day=1;day<=29;day++){/*Days prints from 1 up to 31.*/
									if(day<10&&month<10){
										fprintf(date,"0%d/0%d/%d\n",day,month,year);
										printf("0%d/0%d/%d\n",day,month,year);
									}
									else if(day<10&&month>=10){
										fprintf(date,"0%d/%d/%d\n",day,month,year);
										printf("0%d/%d/%d\n",day,month,year);
									}
									else if(day>=10&&month<10){
										fprintf(date,"%d/0%d/%d\n",day,month,year);
										printf("%d/0%d/%d\n",day,month,year);
									}
									else{
										fprintf(date,"%d/%d/%d\n",day,month,year);
										printf("%d/%d/%d\n",day,month,year);
									}
								}
							}
						}
						else if(find_leap_year(year)==0){/*If month that is in loop is not leap year.*/
							if(month==s_month){{/*If month that is in loop is equal to start month*/
								for(day=s_day;day<=28;day++){/*Days prints from start day up to 28.*/
									if(day<10&&month<10){
										fprintf(date,"0%d/0%d/%d\n",day,month,year);
										printf("0%d/0%d/%d\n",day,month,year);
									}
									else if(day<10&&month>=10){
										fprintf(date,"0%d/%d/%d\n",day,month,year);
										printf("0%d/%d/%d\n",day,month,year);
									}
									else if(day>=10&&month<10){
										fprintf(date,"%d/0%d/%d\n",day,month,year);
										printf("%d/0%d/%d\n",day,month,year);
									}
									else{
										fprintf(date,"%d/%d/%d\n",day,month,year);
										printf("%d/%d/%d\n",day,month,year);
									}
								}
								}
							}
							else{/*If month that is in loop is not equal to start month*/
								for(day=1;day<=28;day++){/*Days prints from 1 up to 28.*/
									if(day<10&&month<10){
										fprintf(date,"0%d/0%d/%d\n",day,month,year);
										printf("0%d/0%d/%d\n",day,month,year);
									}
									else if(day<10&&month>=10){
										fprintf(date,"0%d/%d/%d\n",day,month,year);
										printf("0%d/%d/%d\n",day,month,year);
									}
									else if(day>=10&&month<10){
										fprintf(date,"%d/0%d/%d\n",day,month,year);
										printf("%d/0%d/%d\n",day,month,year);
									}
									else{
										fprintf(date,"%d/%d/%d\n",day,month,year);
										printf("%d/%d/%d\n",day,month,year);
									}
								}
							}
						}	
					}
					else if(month==4 || month==6 || month==9 ||month==11){/*If month that is in loop is 30 day.*/
						if(month==s_month){/*If month that is in loop is equal to start month*/
							for(day=s_day;day<=30;day++){/*Days prints from start day up to 30.*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
						else{/*If month that is in loop is not equal to start month*/	
							for(day=1;day<=30;day++){/*Days prints from 1 up to 30.*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
					}
				}
				else if(month==e_month && s_month!=e_month){/*If month is end month and it is not equal to start month*/
					for(day=1;day<=e_day;day++){/*Days print from 1 to end day.*/
						if(day<10&&month<10){
							fprintf(date,"0%d/0%d/%d\n",day,month,year);
							printf("0%d/0%d/%d\n",day,month,year);
						}
						else if(day<10&&month>=10){
							fprintf(date,"0%d/%d/%d\n",day,month,year);
							printf("0%d/%d/%d\n",day,month,year);
						}
						else if(day>=10&&month<10){
							fprintf(date,"%d/0%d/%d\n",day,month,year);
							printf("%d/0%d/%d\n",day,month,year);
						}
						else{
							fprintf(date,"%d/%d/%d\n",day,month,year);
							printf("%d/%d/%d\n",day,month,year);
						}
						flag=1;/*Flag increases to exit loop.*/
					}
				}
				else if(month==e_month && s_month==e_month){/*If month is end month and it is equal to start month*/
					for(day=s_day;day<=e_day;day++){/*Days print from start day to end day.*/
						if(day<10&&month<10){
							fprintf(date,"0%d/0%d/%d\n",day,month,year);
							printf("0%d/0%d/%d\n",day,month,year);
						}
						else if(day<10&&month>=10){
							fprintf(date,"0%d/%d/%d\n",day,month,year);
							printf("0%d/%d/%d\n",day,month,year);
						}
						else if(day>=10&&month<10){
							fprintf(date,"%d/0%d/%d\n",day,month,year);
							printf("%d/0%d/%d\n",day,month,year);
						}
						else{
							fprintf(date,"%d/%d/%d\n",day,month,year);
							printf("%d/%d/%d\n",day,month,year);
						}
						flag=1;/*Flag increases to exit loop.*/
					}
				}
			}
		}
		else if(year<e_year && year==s_year){/*If year that is in loop is smaller than end year end it is start year*/
			for(month=s_month;month<=12;month++){
				if(month==1||month==3 ||month==5 ||month==7 || month==8 ||month==10 ||month==12){/*If month that is in loop is 31 day.*/
					if(month==s_month){/*If month that is in loop is start month*/
						for(day=s_day;day<=31;day++){/*Days print from start day to 31*/
							if(day<10&&month<10){
								fprintf(date,"0%d/0%d/%d\n",day,month,year);
								printf("0%d/0%d/%d\n",day,month,year);
							}
							else if(day<10&&month>=10){
								fprintf(date,"0%d/%d/%d\n",day,month,year);
								printf("0%d/%d/%d\n",day,month,year);
							}
							else if(day>=10&&month<10){
								fprintf(date,"%d/0%d/%d\n",day,month,year);
								printf("%d/0%d/%d\n",day,month,year);
							}
							else{
								fprintf(date,"%d/%d/%d\n",day,month,year);
								printf("%d/%d/%d\n",day,month,year);
							}
						}
					}
					else{/*If month that is in loop is not start month*/	
						for(day=1;day<=31;day++){/*Days print from 1 to 31.*/
							if(day<10&&month<10){
								fprintf(date,"0%d/0%d/%d\n",day,month,year);
								printf("0%d/0%d/%d\n",day,month,year);
							}
							else if(day<10&&month>=10){
								fprintf(date,"0%d/%d/%d\n",day,month,year);
								printf("0%d/%d/%d\n",day,month,year);
							}
							else if(day>=10&&month<10){
								fprintf(date,"%d/0%d/%d\n",day,month,year);
								printf("%d/0%d/%d\n",day,month,year);
							}
							else{
								fprintf(date,"%d/%d/%d\n",day,month,year);
								printf("%d/%d/%d\n",day,month,year);
							}
						}
					}
				}
				else if(month==2){
					if(find_leap_year(year)==1){/*If month that is in loop is a leap year.*/
						if(month==s_month){/*If month that is in loop is start month*/
							for(day=s_day;day<=29;day++){/*Days print from start day to 29.*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
						else{/*If month that is in loop is not start month*/
							for(day=1;day<=29;day++){/*Days print from 1 to 29.*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
					}
					else if(find_leap_year(year)==0){/*If month that is in loop is not a leap year.*/
						if(month==s_month){/*If month that is in loop is start month*/
							for(day=s_day;day<=28;day++){/*Days print from start day to 28.*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
						else{/*If month that is in loop is not start month*/
							for(day=1;day<=28;day++){/*Days print from 1 to 28.*/
								if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
							}
						}
					}	
				}
				else if(month==4 || month==6 || month==9 ||month==11){/*If month that is in loop is 30 day.*/
					if(month==s_month){/*If month that is in loop is start month*/
						for(day=s_day;day<=30;day++){/*Days print from start day to 30.*/
							if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
						}
					}
					else{/*If month that is in loop is not start month*/	
						for(day=1;day<=30;day++){/*Days print from 1 to 30.*/
							if(day<10&&month<10){
									fprintf(date,"0%d/0%d/%d\n",day,month,year);
									printf("0%d/0%d/%d\n",day,month,year);
								}
								else if(day<10&&month>=10){
									fprintf(date,"0%d/%d/%d\n",day,month,year);
									printf("0%d/%d/%d\n",day,month,year);
								}
								else if(day>=10&&month<10){
									fprintf(date,"%d/0%d/%d\n",day,month,year);
									printf("%d/0%d/%d\n",day,month,year);
								}
								else{
									fprintf(date,"%d/%d/%d\n",day,month,year);
									printf("%d/%d/%d\n",day,month,year);
								}
						}
					}
				}
			}
		}
		else if(year<e_year && year!=s_year && year!=e_year){/*If year that is in loop is smaller than end year end it is not start year*/
			for(month=1;month<=12;month++){
				if(month==1||month==3 ||month==5 ||month==7 || month==8 ||month==10 ||month==12){/*If month that is in loop is 31 day.*/
					for(day=1;day<=31;day++){/*Days print from 1 to 31.*/
						if(day<10&&month<10){
							fprintf(date,"0%d/0%d/%d\n",day,month,year);
							printf("0%d/0%d/%d\n",day,month,year);
						}
						else if(day<10&&month>=10){
							fprintf(date,"0%d/%d/%d\n",day,month,year);
							printf("0%d/%d/%d\n",day,month,year);
						}
						else if(day>=10&&month<10){
							fprintf(date,"%d/0%d/%d\n",day,month,year);
							printf("%d/0%d/%d\n",day,month,year);
						}
						else{
							fprintf(date,"%d/%d/%d\n",day,month,year);
							printf("%d/%d/%d\n",day,month,year);
						}
					}
				}
				else if(month==2){
					if(find_leap_year(year)==1){/*If month that is in loop is a leap year.*/
						for(day=1;day<=29;day++){/*Days print from 1 to 29.*/
							if(day<10&&month<10){
								fprintf(date,"0%d/0%d/%d\n",day,month,year);
								printf("0%d/0%d/%d\n",day,month,year);
							}
							else if(day<10&&month>=10){
								fprintf(date,"0%d/%d/%d\n",day,month,year);
								printf("0%d/%d/%d\n",day,month,year);
							}
							else if(day>=10&&month<10){
								fprintf(date,"%d/0%d/%d\n",day,month,year);
								printf("%d/0%d/%d\n",day,month,year);
							}
							else{
								fprintf(date,"%d/%d/%d\n",day,month,year);
								printf("%d/%d/%d\n",day,month,year);
							}
						}
					}
					else if(find_leap_year(year)==0){/*If month that is in loop is not a leap year.*/
						for(day=1;day<=28;day++){/*Days print from 1 to 28.*/
							if(day<10&&month<10){
								fprintf(date,"0%d/0%d/%d\n",day,month,year);
								printf("0%d/0%d/%d\n",day,month,year);
							}
							else if(day<10&&month>=10){
								fprintf(date,"0%d/%d/%d\n",day,month,year);
								printf("0%d/%d/%d\n",day,month,year);
							}
							else if(day>=10&&month<10){
								fprintf(date,"%d/0%d/%d\n",day,month,year);
								printf("%d/0%d/%d\n",day,month,year);
							}
							else{
								fprintf(date,"%d/%d/%d\n",day,month,year);
								printf("%d/%d/%d\n",day,month,year);
							}
						}
					}
				}
				else if(month==4 || month==6 || month==9 ||month==11){/*If month that is in loop is 30 day.*/	
					for(day=1;day<=30;day++){/*Days print from 1 to 30.*/
						if(day<10&&month<10){
							fprintf(date,"0%d/0%d/%d\n",day,month,year);
							printf("0%d/0%d/%d\n",day,month,year);
						}
						else if(day<10&&month>=10){
							fprintf(date,"0%d/%d/%d\n",day,month,year);
							printf("0%d/%d/%d\n",day,month,year);
						}
						else if(day>=10&&month<10){
							fprintf(date,"%d/0%d/%d\n",day,month,year);
							printf("%d/0%d/%d\n",day,month,year);
						}
						else{
							fprintf(date,"%d/%d/%d\n",day,month,year);
							printf("%d/%d/%d\n",day,month,year);
						}
					}
				}
			}
		}
	}
	fclose(date);/*Fıle is closing.*/
}
/*This function finds a day of a date and convert date.For example 21/04/2018 (dd/MM/yyyy) converts Saturday, April 21, 2018 (dddd, MMMM dd, yyyy) and write this new formatted data into new_date.txt.*/
void find_day(int day,int month,int year){
	FILE *write;/*File is opening to write*/
	write=fopen("new_date.txt","a");/*File is opening to write*/
	int symbol_day=01,symbol_month=01,symbol_year=1800;/*date we will benchmark is 01/01/1800 and it is wednesday.*/
	days symbol_date=wednesday,your_day;
	int i,difference,plus,keep=0,keep2=0,keep3,keep4,normal,count=0,find,find_last;
	for(i=symbol_year;i<year;i++){/*Leap years is found between 1800 and diven year*/
		if(find_leap_year(i)==1){
			count++;
		}
	}
	
	difference=year-symbol_year;/*Differnce is found year is given and 1800*/
	plus=count*366;/*year that is leap year cross 366 day.*/
	normal=(difference-count)*365;/*Year that is not leap year and between 1800 and given year cross 365 day.*/
	for(i=1;i<month;i++){/*In the year that is given is collected the days in  all months up to the given month.*/
		if(i==1 || i==3 ||i==5 ||i==7 ||i==8 ||i==10){
			keep+=31;
		}
		else if(i==4 || i==6 || i==9 || i==11){
			keep2+=30;
		}
		else if(i==2){
			if(find_leap_year(i)==1){
				keep3=29;
			}
			else if(find_leap_year(i)==0){
				keep3=28;
			}
		}
	}
	find=((normal+plus+keep+keep2+keep3+(day-1))%7);/*The values that is found is collected and the mode is set to 7.*/
	your_day=(symbol_date+find)%7;/*Day is found by adding the mode to  wednesday that is symbol day .*/
	
	/*Known days are written to the file as desired.*/
	if(your_day==monday){
		if(month==1){
			printf("Monday,January %d,%d\n",day,year);
			fprintf(write,"Monday,January %d,%d\n",day,year);
		}
		else if(month==2){
			printf("Monday,February %d,%d\n",day,year);
			fprintf(write,"Monday,February %d,%d\n",day,year);
		}
		else if(month==3){
			printf("Monday,March %d,%d\n",day,year);
			fprintf(write,"Monday,March %d,%d\n",day,year);
		}
		else if(month==4){
			printf("Monday,April %d,%d\n",day,year);
			fprintf(write,"Monday,April %d,%d\n",day,year);
		}
		else if(month==5){
			printf("Monday,May %d,%d\n",day,year);
			fprintf(write,"Monday,May %d,%d\n",day,year);
		}
		else if(month==6){
			printf("Monday,June %d,%d\n",day,year);
			fprintf(write,"Monday,June %d,%d\n",day,year);
		}
		else if(month==7){
			printf("Monday,July %d,%d\n",day,year);
			fprintf(write,"Monday,July %d,%d\n",day,year);
		}
		else if(month==8){
			printf("Monday,August %d,%d\n",day,year);
			fprintf(write,"Monday,August %d,%d\n",day,year);
		}
		else if(month==9){
			printf("Monday,September %d,%d\n",day,year);
			fprintf(write,"Monday,September %d,%d\n",day,year);
		}
		else if(month==10){
			printf("Monday,October %d,%d\n",day,year);
			fprintf(write,"Monday,October %d,%d\n",day,year);
		}
		else if(month==11){
			printf("Monday,November %d,%d\n",day,year);
			fprintf(write,"Monday,November %d,%d\n",day,year);
		}
		else if(month==12){
			printf("Monday,December %d,%d\n",day,year);
			fprintf(write,"Monday,December %d,%d\n",day,year);
		}
	}
	else if(your_day==tuesday){
		if(month==1){
			printf("Tuesday,January %d,%d\n",day,year);
			fprintf(write,"Tuesday,January %d,%d\n",day,year);
		}
		else if(month==2){
			printf("Tuesday,February %d,%d\n",day,year);
			fprintf(write,"Tuesday,February %d,%d\n",day,year);
		}
		else if(month==3){
			printf("Tuesday,March %d,%d\n",day,year);
			fprintf(write,"Tuesday,March %d,%d\n",day,year);
		}
		else if(month==4){
			printf("Tuesday,April %d,%d\n",day,year);
			fprintf(write,"Tuesday,April %d,%d\n",day,year);
		}
		else if(month==5){
			printf("Tuesday,May %d,%d\n",day,year);
			fprintf(write,"Tuesday,May %d,%d\n",day,year);
		}
		else if(month==6){
			printf("Tuesday,June %d,%d\n",day,year);
			fprintf(write,"Tuesday,June %d,%d\n",day,year);
		}
		else if(month==7){
			printf("Tuesday,July %d,%d\n",day,year);
			fprintf(write,"Tuesday,July %d,%d\n",day,year);
		}
		else if(month==8){
			printf("Tuesday,August %d,%d\n",day,year);
			fprintf(write,"Tuesday,August %d,%d\n",day,year);
		}
		else if(month==9){
			printf("Tuesday,September %d,%d\n",day,year);
			fprintf(write,"Tuesday,September %d,%d\n",day,year);
		}
		else if(month==10){
			printf("Tuesday,October %d,%d\n",day,year);
			fprintf(write,"Tuesday,October %d,%d\n",day,year);
		}
		else if(month==11){
			printf("Tuesday,November %d,%d\n",day,year);
			fprintf(write,"Tuesday,November %d,%d\n",day,year);
		}
		else if(month==12){
			printf("Tuesday,December %d,%d\n",day,year);
			fprintf(write,"Tuesday,December %d,%d\n",day,year);
		}
	}
	else if(your_day==wednesday){
		if(month==1){
			printf("Wednesday,January %d,%d\n",day,year);
			fprintf(write,"Wednesday,January %d,%d\n",day,year);
		}
		else if(month==2){
			printf("Wednesday,February %d,%d\n",day,year);
			fprintf(write,"Wednesday,February %d,%d\n",day,year);
		}
		else if(month==3){
			printf("Wednesday,March %d,%d\n",day,year);
			fprintf(write,"Wednesday,March %d,%d\n",day,year);
		}
		else if(month==4){
			printf("Wednesday,April %d,%d\n",day,year);
			fprintf(write,"Wednesday,April %d,%d\n",day,year);
		}
		else if(month==5){
			printf("Wednesday,May %d,%d\n",day,year);
			fprintf(write,"Wednesday,May %d,%d\n",day,year);
		}
		else if(month==6){
			printf("Wednesday,June %d,%d\n",day,year);
			fprintf(write,"Wednesday,June %d,%d\n",day,year);
		}
		else if(month==7){
			printf("Wednesday,July %d,%d\n",day,year);
			fprintf(write,"Wednesday,July %d,%d\n",day,year);
		}
		else if(month==8){
			printf("Wednesday,August %d,%d\n",day,year);
			fprintf(write,"Wednesday,August %d,%d\n",day,year);
		}
		else if(month==9){
			printf("Wednesday,September %d,%d\n",day,year);
			fprintf(write,"Wednesday,September %d,%d\n",day,year);
		}
		else if(month==10){
			printf("Wednesday,October %d,%d\n",day,year);
			fprintf(write,"Wednesday,October %d,%d\n",day,year);
		}
		else if(month==11){
			printf("Wednesday,November %d,%d\n",day,year);
			fprintf(write,"Wednesday,November %d,%d\n",day,year);
		}
		else if(month==12){
			printf("Wednesday,December %d,%d\n",day,year);
			fprintf(write,"Wednesday,December %d,%d\n",day,year);
		}
	}
	else if(your_day==thursday){
		if(month==1){
			printf("Thursday,January %d,%d\n",day,year);
			fprintf(write,"Thursday,January %d,%d\n",day,year);
		}
		else if(month==2){
			printf("Thursday,February %d,%d\n",day,year);
			fprintf(write,"Thursday,February %d,%d\n",day,year);
		}
		else if(month==3){
			printf("Thursday,March %d,%d\n",day,year);
			fprintf(write,"Thursday,March %d,%d\n",day,year);
		}
		else if(month==4){
			printf("Thursday,April %d,%d\n",day,year);
			fprintf(write,"Thursday,April %d,%d\n",day,year);
		}
		else if(month==5){
			printf("Thursday,May %d,%d\n",day,year);
			fprintf(write,"Thursday,May %d,%d\n",day,year);
		}
		else if(month==6){
			printf("Thursday,June %d,%d\n",day,year);
			fprintf(write,"Thursday,June %d,%d\n",day,year);
		}
		else if(month==7){
			printf("Thursday,July %d,%d\n",day,year);
			fprintf(write,"Thursday,July %d,%d\n",day,year);
		}
		else if(month==8){
			printf("Thursday,August %d,%d\n",day,year);
			fprintf(write,"Thursday,August %d,%d\n",day,year);
		}
		else if(month==9){
			printf("Thursday,September %d,%d\n",day,year);
			fprintf(write,"Thursday,September %d,%d\n",day,year);
		}
		else if(month==10){
			printf("Thursday,October %d,%d\n",day,year);
			fprintf(write,"Thursday,October %d,%d\n",day,year);
		}
		else if(month==11){
			printf("Thursday,November %d,%d\n",day,year);
			fprintf(write,"Thursday,November %d,%d\n",day,year);
		}
		else if(month==12){
			printf("Thursday,December %d,%d\n",day,year);
			fprintf(write,"Thursday,December %d,%d\n",day,year);
		}
	}
	else if(your_day==friday){
		if(month==1){
			printf("Friday,January %d,%d\n",day,year);
			fprintf(write,"Friday,January %d,%d\n",day,year);
		}
		else if(month==2){
			printf("Friday,February %d,%d\n",day,year);
			fprintf(write,"Friday,February %d,%d\n",day,year);
		}
		else if(month==3){
			printf("Friday,March %d,%d\n",day,year);
			fprintf(write,"Friday,March %d,%d\n",day,year);
		}
		else if(month==4){
			printf("Friday,April %d,%d\n",day,year);
			fprintf(write,"Friday,April %d,%d\n",day,year);
		}
		else if(month==5){
			printf("Friday,May %d,%d\n",day,year);
			fprintf(write,"Friday,May %d,%d\n",day,year);
		}
		else if(month==6){
			printf("Friday,June %d,%d\n",day,year);
			fprintf(write,"Friday,June %d,%d\n",day,year);
		}
		else if(month==7){
			printf("Friday,July %d,%d\n",day,year);
			fprintf(write,"Friday,July %d,%d\n",day,year);
		}
		else if(month==8){
			printf("Friday,August %d,%d\n",day,year);
			fprintf(write,"Friday,August %d,%d\n",day,year);
		}
		else if(month==9){
			printf("Friday,September %d,%d\n",day,year);
			fprintf(write,"Friday,September %d,%d\n",day,year);
		}
		else if(month==10){
			printf("Friday,October %d,%d\n",day,year);
			fprintf(write,"Friday,October %d,%d\n",day,year);
		}
		else if(month==11){
			printf("Friday,November %d,%d\n",day,year);
			fprintf(write,"Friday,November %d,%d\n",day,year);
		}
		else if(month==12){
			printf("Friday,December %d,%d\n",day,year);
			fprintf(write,"Friday,December %d,%d\n",day,year);
		}
	}
	else if(your_day==saturday){
		if(month==1){
			printf("Saturday,January %d,%d\n",day,year);
			fprintf(write,"Saturday,January %d,%d\n",day,year);
		}
		else if(month==2){
			printf("Saturday,February %d,%d\n",day,year);
			fprintf(write,"Saturday,February %d,%d\n",day,year);
		}
		else if(month==3){
			printf("Saturday,March %d,%d\n",day,year);
			fprintf(write,"Saturday,March %d,%d\n",day,year);
		}
		else if(month==4){
			printf("Saturday,April %d,%d\n",day,year);
			fprintf(write,"Saturday,April %d,%d\n",day,year);
		}
		else if(month==5){
			printf("Saturday,May %d,%d\n",day,year);
			fprintf(write,"Saturday,May %d,%d\n",day,year);
		}
		else if(month==6){
			printf("Saturday,June %d,%d\n",day,year);
			fprintf(write,"Saturday,June %d,%d\n",day,year);
		}
		else if(month==7){
			printf("Saturday,July %d,%d\n",day,year);
			fprintf(write,"Saturday,July %d,%d\n",day,year);
		}
		else if(month==8){
			printf("Saturday,August %d,%d\n",day,year);
			fprintf(write,"Saturday,August %d,%d\n",day,year);
		}
		else if(month==9){
			printf("Saturday,September %d,%d\n",day,year);
			fprintf(write,"Saturday,September %d,%d\n",day,year);
		}
		else if(month==10){
			printf("Saturday,October %d,%d\n",day,year);
			fprintf(write,"Saturday,October %d,%d\n",day,year);
		}
		else if(month==11){
			printf("Saturday,November %d,%d\n",day,year);
			fprintf(write,"Saturday,November %d,%d\n",day,year);
		}
		else if(month==12){
			printf("Saturday,December %d,%d\n",day,year);
			fprintf(write,"Saturday,December %d,%d\n",day,year);
		}
	}
	else if(your_day==sunday){
		if(month==1){
			printf("Sunday,January %d,%d\n",day,year);
			fprintf(write,"Sunday,January %d,%d\n",day,year);
		}
		else if(month==2){
			printf("Sunday,February %d,%d\n",day,year);
			fprintf(write,"Sunday,February %d,%d\n",day,year);
		}
		else if(month==3){
			printf("Sunday,March %d,%d\n",day,year);
			fprintf(write,"Sunday,March %d,%d\n",day,year);
		}
		else if(month==4){
			printf("Sunday,April %d,%d\n",day,year);
			fprintf(write,"Sunday,April %d,%d\n",day,year);
		}
		else if(month==5){
			printf("Sunday,May %d,%d\n",day,year);
			fprintf(write,"Sunday,May %d,%d\n",day,year);
		}
		else if(month==6){
			printf("Sunday,June %d,%d\n",day,year);
			fprintf(write,"Sunday,June %d,%d\n",day,year);
		}
		else if(month==7){
			printf("Sunday,July %d,%d\n",day,year);
			fprintf(write,"Sunday,July %d,%d\n",day,year);
		}
		else if(month==8){
			printf("Sunday,August %d,%d\n",day,year);
			fprintf(write,"Sunday,August %d,%d\n",day,year);
		}
		else if(month==9){
			printf("Sunday,September %d,%d\n",day,year);
			fprintf(write,"Sunday,September %d,%d\n",day,year);
		}
		else if(month==10){
			printf("Sunday,October %d,%d\n",day,year);
			fprintf(write,"Sunday,October %d,%d\n",day,year);
		}
		else if(month==11){
			printf("Sunday,November %d,%d\n",day,year);
			fprintf(write,"Sunday,November %d,%d\n",day,year);
		}
		else if(month==12){
			printf("Sunday,December %d,%d\n",day,year);
			fprintf(write,"Sunday,December %d,%d\n",day,year);
		}
	}
	fclose(write);
}
/*This function read inpux_dat.txt file and calls find_day function to finds days of dates.*/
void convert_date(){
	FILE *read;
	read=fopen("input_date.txt","r");/*File is opening to read*/
	int day,month,year;
	
	while(!feof(read)){/*File reads up to end of file*/
		fscanf(read,"%d/%d/%d\n",&day,&month,&year);
		find_day(day,month,year);/*Function that is named  find day calls.*/
	}
	fclose(read);
}
/*This function find a year is leap year or not.*/	
int find_leap_year(int year)
{
	/*If year is divided to 4 and  400 so it is a leap year*/
	if(year%4==0){
        if( year%100 == 0){
			if(year%400 == 0){
				return 1;
			}
			else{
				return 0;
			}
		}
      	else{
           		 return 1;
		}
    }
   	else{
       		return 0;
	}
 
}			
