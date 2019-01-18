//NEVRA GÜRSES-161044071
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct list {//Defined a struct to be able to perform operations in the linked list.
    int data;
    struct list *next;
} node;
//This function reads lines in data.txt file to be used in other functions.
int read_data(FILE *read){
	int first,second;
	char comma;
	fscanf(read,"%d%c%d\n",&first,&comma,&second);
	return first;
	
}
//This function records all numbers that is in data.txt file into linked list,finds prime numbers and prints them.
void record_linked_list(FILE *read1,FILE *write1)
{
	node *head,*new;
	clock_t time1,time2,time3,time4,time5; //Data type and variables used to make the time account.
	time1=clock(); //The start time of the function is determined.
	float time_diff1,time_diff2,time_diff3,time_diff4;   
	int first,second,flag,j,count=0;
	char comma;
	while(!feof(read1)){//All lines until the end of the file are read with the help of the read_data function.
		first=read_data(read1);
		head = (node *) malloc(sizeof(node));// Dynamic space is allocated for the first node of the linked list.
   	 	head->data = first;
		head->next = NULL;
		flag=0;
		// This is the prime number finding loop.
		for(j=2;j<head->data;++j)
		{
			if(head->data%j==0)
			{
				flag=1;
			}
		}
		if(flag==0 && head->data!=1)// If the number in the node has no divisor, it is printed as prime.
		{
			count++;
			printf("%d.Prime number in linked list= %d,00\n",count,head->data);
			fprintf(write1,"%d.Prime number =%d,00\n",count,head->data);
		}
		// When the number in the node reaches 500.000, the time account is made.
		if(head->data==500000){
			time2=clock();
			time_diff1=(((float)time2-(float)time1)/1000);// Time difference between reaching 500,000 and function start is calculated in milliseconds.
			
		}
		// When the number in the node reaches 750.000, the time account is made.
		else if(head->data==750000){
			time3=clock();
			time_diff2=(((float)time3-(float)time1)/1000);// Time difference between reaching 750,000 and function start is calculated in milliseconds.
			
		}
		// When the number in the node reaches 1.000.000, the time account is made.
		else if(head->data==1000000){
			time4=clock();
			time_diff3=(((float)time4-(float)time1)/1000);// Time difference between reaching 1,000,000 and function start is calculated in milliseconds.
			
		}
   	}
	time5=clock();
	time_diff4=(((float)time5-(float)time1)/1000);// The time difference between the end of the function and the start time is calculated in milliseconds.
	//Calculated times are printed into file.
	fprintf(write1,"Time that is between 1 and 500.000 in linked list= %.0f milliseconds(ms)\n",time_diff1);
	fprintf(write1,"Time that is between 1 and 750.000 in linked list= %.0f milliseconds(ms)\n",time_diff2);
	fprintf(write1,"Time that is between 1 and 1.000.000 in linked list=%.0f milliseconds(ms)\n",time_diff3);
	fprintf(write1,"Time that is running time of record_linked_list function=%.0f milliseconds(ms)\n",time_diff4);
	printf("Time that is between 1 and 500.000 in linked list=%.0f (ms)\nTime that is between 1 and 750.000 in linked list=%.0f (ms)\n",time_diff1,time_diff2);
	printf("Time that is between 1 and 1.000.000 in linked list=%.0f (ms)\nTime that is running time of record_linked_list function=%.0f (ms)\n",time_diff3,time_diff4);
	free(head);
}
//This function records all numbers that is in data.txt file into dynamic array,finds prime numbers and prints them.
void record_array(FILE *read2,FILE *write2){
	int *arr;
	clock_t time1,time2,time3,time4,time5;//Data type and variables used to make the time account.
	time1=clock();//The start time of the function is determined.
	float time_diff1,time_diff2,time_diff3,time_diff4;
	int first;
	int i,j,flag,count=0;
	char comma;
	i=0;
	arr=(int*)malloc(sizeof(int)*1);//Firstly,created a dynamic field for 1 data.
	while(!feof(read2)){//All lines until the end of the file are read with the help of the read_data function.
		first=read_data(read2);
		arr[i]=first;
		flag=0;
		for(j=2;j<arr[i];++j)
		{
			if(arr[i]%j==0)
			{
				flag=1;
			}
		}
		if(flag==0 && arr[i]!=1)// If the number in the array element has no divisor, it is printed as prime.
		{
			count++;
			printf("%d.Prime number in dynamic array=%d,00\n",count,arr[i]);
			fprintf(write2,"%d.Prime number=%d,00\n",count,arr[i]);
		}
		// When the number reaches 500,000 in array,time account is made.
		if(arr[i]==500000){
			time2=clock();
			time_diff1=(((float)time2-(float)time1)/1000);// Time difference between reaching 500,000 and function start is calculated in milliseconds.
			
		}
		// When the number reaches 750,000 in array,time account is made.
		else if(arr[i]==750000){
			time3=clock();
			time_diff2=(((float)time3-(float)time1)/1000);// Time difference between reaching 750,000 and function start is calculated in milliseconds.
		}
		// When the number reaches 1.000,000 in array,time account is made.
		else if(arr[i]==1000000){
			time4=clock();
			time_diff3=(((float)time4-(float)time1)/1000);// Time difference between reaching 1.000,000 and function start is calculated in milliseconds.
		}
		i++;
		arr=realloc(arr,sizeof(int)*(i+1));// The generated dynamic area is expanded during the loop by realloc.
		
	}
	time5=clock();
	time_diff4=(((float)time5-(float)time1)/1000);// The time difference between the end of the function and the start time is calculated in milliseconds.
	//Calculated times are printed into file.
	fprintf(write2,"Time that is between 1 and 500.000 in dynamic array= %.0f milliseconds(ms)\n",time_diff1);
	fprintf(write2,"Time that is between 1 and 750.000 in dynamic array= %.0f milliseconds(ms)\n",time_diff2);
	fprintf(write2,"Time that is between 1 and 1.000.000 in dynamic array= %.0f milliseconds(ms)\n",time_diff3);
	fprintf(write2,"Time that is running time of record_array function= %.0f milliseconds(ms)\n",time_diff4);
	printf("Time that is between 1 and 500.000 in dynamic array=%.0f (ms)\nTime that is between 1 and 750.000 in dynamic array=%.0f (ms)\n",time_diff1,time_diff2);
	printf("Time that is between 1 and 1.000.000 in dynamic array=%.0f (ms)\nTime that is running time of record_array function=%.0f (ms)\n",time_diff3,time_diff4);
	free(arr);
}
	
int main(){
	//A file is opening to read and another file is opening to write in order to linked list prosesses and after closes the files.
	FILE *read1;
	read1=fopen("data.txt","r");
	FILE *write1;
	write1=fopen("output_prime_LiknedList.txt","w");
	record_linked_list(read1,write1);
	fclose(read1);
	fclose(write1);

	//A file is opening to read and another file is opening to write in order to dynamic array prosesses and after closes the files.
	FILE *read2;
	read2=fopen("data.txt","r");
	FILE *write2;
	write2=fopen("output_prime_dynamic_array.txt","w");
	record_array(read2,write2);
	
	fclose(read2);
	fclose(write2);
	
	return 0;
}
