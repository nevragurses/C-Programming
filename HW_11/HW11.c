#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*This library is used for reading the customers.txt file.*/ 
typedef struct customer{
	int room_num;
	char surname[40];
	char name[40];
	char age[5];
	char gender[8];
	struct customer *next;
}customer;
typedef struct room{
	int number;
	int capacity;
	int floor;
	struct room *next;
	struct customer *process;
}room;
/*This function adds a room to the end of the room list.*/
void add_room_to_end(room *headcp,int number,int capacity,int floor)
{
	room *temp2=headcp;
	while(temp2->next!=NULL){ /*This loop allows to come to the last list.*/
		temp2=temp2->next;
	}	
	temp2->next=(room*)malloc(sizeof(room)); /*Space is allocated for the new node.*/
	temp2=temp2->next;
	temp2->number=number;
	temp2->capacity=capacity;
	temp2->floor=floor;
	temp2->next=NULL;
	
}
/*This function adds a room to after the given room number. If the given room does not exists,it is added to the end of the list.*/
void add_room_after_room_number (room *headcp,int which_room,int number,int capacity,int floor)
{
	room* keep=headcp;
	room*insert;
	while(keep->next!=NULL && keep->number!=which_room){ /*This loop allows to the come to the node that has given room number.*/
		keep=keep->next;
	}
	if(keep->next==NULL && keep->number!=which_room){ /* If the given room does not exists,it is added to the end of the list.*/
		keep->next=(room*)malloc(sizeof(room));
		keep=keep->next;
		keep->number=number;
		keep->capacity=capacity;
		keep->floor=floor;
		keep->next=NULL;
	}
	else{ /*If there is given room number,a room is added after given room number.*/
		insert=(room*)malloc(sizeof(room));
		insert->next=keep->next;
		keep->next=insert;
		insert->number=number;
		insert->capacity=capacity;
		insert->floor=floor;
	}
}
/*This function adds a customer to the end of the partial customer list.*/
void add_customer_to_end(customer *headcp,int room_num,char name[],char age[],char gender[])
{
	customer *temp2=headcp;
	while(temp2->next!=NULL){ /*This loop allows to come to the last customer.*/
		temp2=temp2->next;
	}
	temp2->next=(customer*)malloc(sizeof(room));
	temp2=temp2->next;
	temp2->room_num=room_num;
	strcpy(temp2->name,name);
	strcpy(temp2->age,age);
	strcpy(temp2->gender,gender);
	temp2->next=NULL;
	
}
/*This function connects the customers with the rooms that they belong to.*/
room *link_customers(room **head_room,customer *head_customer)
{
	room *temp=*head_room;
	customer *temp2=head_customer;
	customer *keep;
	for(temp=*head_room;temp->next!=NULL;temp=temp->next){ /*This loop provides control all over rooms from start to finish.*/
		temp2=head_customer;
		for(temp2=head_customer;temp2->next!=NULL;temp2=temp2->next){/*This loop provide control  all over customers from start to finish.*/
			if(temp2->room_num==temp->number && temp->process==NULL){ /*This condition provides to  link customer to the room that is belong to if room is empty.*/
				temp->process=(customer*)malloc(sizeof(customer));
				keep=temp->process;
				keep->room_num=temp2->room_num;
				strcpy(keep->name,temp2->name);
				strcpy(keep->age,temp2->age);
				strcpy(keep->gender,temp2->gender);
				keep->next=NULL;
			}
			else if(temp2->room_num==temp->number && temp->process!=NULL){/*This condition provides to link customer to the  room that is belong to if room is not empty.*/ 
				keep=temp->process;	
				while(keep->next!=NULL){/*This loop allows to come to the last customer in the room.*/
					keep=keep->next;
				}
				keep->next=(customer*)malloc(sizeof(customer));
				keep->next->room_num=temp2->room_num;
				strcpy(keep->next->name,temp2->name);
				strcpy(keep->next->age,temp2->age);
				strcpy(keep->next->gender,temp2->gender);
				keep->next->next=NULL;
			}
		}
	}
	return *head_room;
			
}
/*This function adds partial customer list to a room.*/
room *link_customers_to_room(room **headcp,int room_number,char name[],char age[],char gender[]){
	room *control_room=*headcp;
	customer *keep;
	while(control_room!=NULL){ /*This loop provides control over all rooms from start to finish.*/
		if(control_room->number==room_number && control_room->process!=NULL){ /*If room number equal to given room number and this room is not empty customer is linked to this room.*/
			keep=control_room->process;	
			while(keep->next!=NULL){ /*This loop allows to come last customer in the room.*/
				keep=keep->next;
			}
			keep->next=(customer*)malloc(sizeof(customer));
			keep->next->room_num=room_number;
			strcpy(keep->next->name,name);
			strcpy(keep->next->age,age);
			strcpy(keep->next->gender,gender);
			keep->next->next=NULL;
		}
		else if(control_room->number==room_number && control_room->process==NULL){/*If room number equal to given room number and this room is empty customer is  linked to this room.*/
			control_room->process=(customer*)malloc(sizeof(customer));
			keep=control_room->process;
			keep->room_num=room_number;
			strcpy(keep->name,name);
			strcpy(keep->age,age);
			strcpy(keep->gender,gender);
			keep->next=NULL;
		}
		control_room=control_room->next;
	}
	return *headcp;
}
/*This function removes the room indicated by the room number.*/
room *remove_room (room **headcp,int which_room)
{
	room *temp;
	room *delete=*headcp;
	if((*headcp)->number==which_room){ /*If the first room will delete in the room list,this room is deleted and the new root is updated.*/
		temp=*headcp;
		*headcp=(*headcp)->next;
		free(temp);
		return *headcp;
	}
	while(delete->next!=NULL && delete->next->number!=which_room){/*This loop allow to come the room that will deleted.*/
		delete=delete->next;
	}
	if(delete->next==NULL){ /*If given room number is non exists warning message is given.*/
		printf("Room that is number %d is non exist.\n",which_room);
		return *headcp;
	}
	temp=delete->next;     
	delete->next=delete->next->next;
	free(temp); /*Room deletes.*/
	return *headcp;
}
/*This function lists all available rooms that don’t have any customer.*/
void show_vacancy(room *head_room){
	room *cust=head_room;
	while(cust!=NULL){
		if(cust->process==NULL){
			printf("\n%d\n",cust->number);
		}
		cust=cust->next;
	}
}
/*This function lists the rooms with the given floor number.*/
void get_by_floor(room *headcp,int searching_floor){
	room *temp=headcp;
	printf("\n----ROOM LİSTS THAT FLOOR NUMBER ARE GİVEN NUMBER '%d'----\n",searching_floor);
	while(temp!=NULL){
		if(temp->floor == searching_floor){
			printf("Room Number:%d\n",temp->number);
		}
		temp=temp->next;
	}
}
/*This function prints the room list with customers.*/
void print_list (room *headcp,customer *rootcp)
{
	room *control=headcp;
	customer *cust=rootcp;
	customer *keep;
	while(control!=NULL){ /*This loop provides control over all rooms from start to finish.*/
		printf("\nRoom %d (Floor %d – Capacity %dx)\n",control->number,control->floor,control->capacity);
		if(control->process!=NULL){ /*If there are customer in the room ,his/her features printed on the screen.*/ 
			keep=control->process;
			while(keep!=NULL){
				if(control->number==keep->room_num){
					printf("->%s (%s-%s)\n",keep->name,keep->age,keep->gender);
				}
				keep=keep->next;
			}
		}
		else if(control->process==NULL){ /*If there is not any customer in the room,'empty' printed on the screen.*/
			printf("->Empty\n");
		}
		control=control->next;
	}
}
/*This function provides to print linked list that belong to room.*/
void print(room *temp)
{
	while(temp!=NULL){
		printf(" %d,%d,%d\n",temp->number,temp->capacity,temp->floor);
		temp=temp->next;
	}
				
}
/*This function provides to print linked list that belong to customer.*/
void print2(customer *temp)
{
	while(temp!=NULL){
		printf("%d %s %s %s\n",temp->room_num,temp->name,temp->age,temp->gender);
		temp=temp->next;
	}
				
}
		
int main(){
	FILE *read1;
	read1=fopen("rooms.txt","r");
	room *head,*temp;
	head=(room*)malloc(sizeof(room));
	temp=head;
	fscanf(read1,"%d,%d,%d\n",&head->number,&head->capacity,&head->floor);
	while(!feof(read1)){ /*The file that belongs to the room  list is read and that records as linked list.*/
		temp->next=(room*)malloc(sizeof(room));
		temp=temp->next;
		fscanf(read1,"%d,%d,%d\n",&temp->number,&temp->capacity,&temp->floor);
		temp->next=NULL;
		
	}
	temp=head;
	
	
	/*This operations belongs to customers.*/
	FILE *read2;
	read2=fopen("customers.txt","r");
	customer *head2,*temp2;
	head2=(customer*)malloc(sizeof(customer));
	temp2=head2;
	char str[100];
	char *tok;
	int count=1;
	int x;
	/*Customer file is read as string and it records as linked list by using "strtok".*/
	while(!feof(read2)){
		fgets(str,100,read2);
		tok=strtok(str,",");
		while(tok!=NULL){
			if(count==1){ /* The first word in a line is recorded in linked list as a room number.*/
				x=atoi(tok); /*This provide convert string to integer value.*/
				temp2->room_num=x;
				count ++;
			}
			else if(count==2){ /* The second word in a line is recorded in linked list  as a customer's name and surname.*/
				strcpy(temp2->name,tok);
				count ++;
			}
			
			else if(count==3){ /* The third word in a line is recorded in linked list as a customer's age.*/
				strcpy(temp2->age,tok);
				count ++;
			}
			else if(count==4){ /* The fourth word in a line is recorded in linked list  as a customer's gender.*/
				int k=0;
				int counter=0;
				char gender_str[]="Male";
				while(k<4){ /*This loop provide the control that the read word is 4 letters and it is male.*/
					if(gender_str[k]==tok[k]){ 
						counter++;
					}
					k++;
				}
				if(counter==4){ /*If word is "male",4 caharacter is read in the file.*/
					strncpy(temp2->gender,tok,4);
				}
				else{ /*If word is "female",6 caharacter is read in the file.*/
					strncpy(temp2->gender,tok,6);
				}
				count=1;
				
			}
			tok=strtok(NULL,",");
			
		
		}
		temp2->next=(customer*)malloc(sizeof(customer));
		temp2=temp2->next;
		
	
	}
	link_customers(&head,head2); /*This function is called and customers is linked to rooms that are belongs to.*/
	printf("\n---ROOM LİSTS WİTH CUSTOMERS----\n");
	print_list (head,head2);

	while(head->next!=NULL){/*This loop provide the free room list.*/
		free(head);
		head=head->next;
	}
	
	while(head2->next!=NULL){/*This loop provide the free customer list.*/
		free(head2);
		head2=head2->next;
	}
	

	fclose(read1);
	fclose(read2);
}






