
/*Finding friend number.*/
#include <stdio.h>
int main()
{
	int num,i,j,sum=0,sum2=0;
	printf("Give a number that we find its friend number:");
	scanf("%d",&num);
	for(i=1;i<num;++i){
		if(num%i==0){
			sum=i;
		}
	}
	for(j=1;j<sum;++j)
	{
		if(sum%j==0){
		sum2+=j;}
	}
	if(sum2==num)
	{
		printf("%d's friend number:%d",num,sum);
	}
	else{
		printf("%d has not a friend number.",num);
	}
	return 0;
}
