#include <stdio.h>
/*This program prints day and hours with enum.*/
typedef enum
		{monday,tuesday,wednesday,thursday,friday,saturday,sunday}
day_t;
void print_day(day_t day);
int main()
{
	double week_hours,day_hours;
	day_t today;
	int score;
	score=monday;
	printf("monday:%d\n",score);
	week_hours=0.0;
	for(today=monday;today<=friday;++today)
	{
		printf("enter hours for:");
		print_day(today);
		printf(">");
		scanf("%lf",&day_hours);
		week_hours+=day_hours;	
	}
	printf("\ntotal weekly hours are %lf\n",week_hours);
	return 0;
}
void print_day(day_t day){
	printf("%u",day);
}
