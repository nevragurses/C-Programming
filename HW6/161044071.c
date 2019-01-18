#include <stdio.h>
int find_size_of_line(char line[]);
void reverse_line(char line[], int line_lenght);
void menu();
void encrypt_open_msg();
void decrypt_secret_msg();
int main()
{
	menu();
	return 0;
}
/*Function that shows menü on screen until user choose 0 in menü.*/
void menu()
{
	int choice;
	do{
		printf("\n------MENU---------\n");
		printf("1.Encrypt\n");
		printf("2.Decrypt\n");
		printf("0.Exit\n");
		printf("\nChoice : ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice){
			case 1:
				encrypt_open_msg(); break;

			case 2:
				decrypt_secret_msg();break;

			case 0:
				break;
			default:
				choice==1;break;/*Allows the menu to be shown again on the screen when different selections are entered.*/
		}
	}
	while(choice != 0);/*If user enter 0 then loop stops.*/

}
/*This function finds size of a line.*/
int find_size_of_line(char line[])
{
	int i = 0, count = 0;
	while(line[i] != '\0'){/*counter increases until null character.*/
		count++;
		i++;
	}
	return count-1;
}
/*This function reverses content of line[].*/
void reverse_line(char line[], int line_lenght)
{
	int i,j;
	char temp;
	/*This loop provides to replace the elements of string from the beginning and from the last.*/
	for(i = 0, j = line_lenght; i < line_lenght / 2 , j > line_lenght / 2; ++i, --j){
			temp = line[i];
			line[i] = line[j];
			line[j] = temp;
	}
}
/*This function reads content of open_msg.txt file,encrypts it,shows encrypted message on screen and then writes to secret_msg.txt file.*/
void encrypt_open_msg()
{
	FILE *in;
	FILE * out;
	int i,line_lenght,j,key, keep1, key2;
	char line[1024];/* This is character string that is maximum line buffer is 1024.*/

	in = fopen("open_msg.txt","r");/*File opens to read.*/
	out=fopen("secret_msg.txt","w");/*The file opens to write encrypted message.*/
	

	/*This statement provide that key value is between 1 and 26.*/
	do{
		printf ("\nenter a key value that is a positive integer between 1 and 26:");
		scanf("%d", &key);
	}
	while(key<1 || key>26);
	do{
		fgets(line,1024,in);
		line_lenght = find_size_of_line(line);/*Line lenght is found.*/
		reverse_line(line, line_lenght);
		/*This loop encryptys the each line in file.*/
		for(i = 0; i <=line_lenght; i++){
			if(line[i] == '.'){
				
				line[i]=(char)('*');
			}
			else if(line[i] == ' '){
				
				line[i]=(char)('_');
			}
			else if(line[i]>='a' && line[i]<='z'){
				keep1 = line[i] - key;
				if(keep1 < 97){
					key2 = key - (key - (97 - keep1));
					line[i]=(char)(123-key2);
				}

				else{
					
					line[i]=(char)(keep1);
				}
			}
		}
		printf("%s",line);
		fprintf(out,"%s",line);
			
	}
	while(!feof(in));
	fclose(out);/*The writing file closes.*/
	fclose(in);/*The reading file closes.*/
}
/*This function reads each line of the message contained in secret_msg.txt, decrypts the secret line, shows the open line on screen and then writes the open line to open_msg.txt file.*/
void decrypt_secret_msg()
{
	
	FILE *in;
	FILE * out;
	
	int i,line_lenght,j,key, keep1, key2;;
	char line[1024];
	in= fopen("secret_msg.txt","r");/*The file opens to read secret message.*/
	out=fopen("open_msg.txt","w");/*The file opens to write decrypted message.*/
	

	/*This statement provide that key value is between 1 and 26.*/
	do{
		printf ("\nenter a key value that is a positive integer between 1 and 26:");
		scanf("%d", &key);
	}
	while(key<1 || key>26);
	/*This loop processes until end of file.*/
	do{
		fgets(line,1024,in);/*A line is read.*/
		printf("\n");
		line_lenght = find_size_of_line(line);/* Line lenght is found.*/
		
		/*This loop decrypts the secret line.*/
		for(i = 0; i <=line_lenght ; i++){
			if(line[i]=='_'){
				line[i]=(char)(' ');
			}
			else if(line[i]=='*'){
				line[i]=(char)('.');
			
			}
			else if(line[i]>='a' && line[i]<='z'){
				keep1=line[i]+key;
				if(keep1>122){
					key2=key-(key-(keep1-122));
					line[i]=(char)(96+key2);
				}
				else{
				line[i]=(char)(keep1);
				}
			}
		}
		reverse_line(line, line_lenght);
		printf("%s",line);
		fprintf(out,"%s",line);/*decrypted message is wrote in open_msg.txt file.*/
	}
	while(!feof(in));
	fclose(out);
	fclose(in);
}

	




	



















