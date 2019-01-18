#include <stdio.h>
/*This program a simple calculater.*/
int main()
{
	double num1,num2;
	char operator;
	printf("Enter an opeator:");
	scanf("%c",&operator);
	printf("Enter two operands:\n");
	scanf("%lf %lf",&num1,&num2);
	switch(operator)
	{
	case('+'):printf("Toplam:%.2lf",num1+num2);break;
	case('-'):printf("Fark:%.2lf",num1-num2);break;
	case('*'):printf("Çarpım:%.2lf",num1*num2);break;
	case('/'):if(num2==0)
		  {
			printf("Paydayı 0'dan farklı girin!");
		  }
		  else
		  {
			printf("Bölüm:%.2lf",num1/num2);
		  }
		  break;
	default:printf("Yanlıs operator girdiniz");
	}
	return 0;
}
