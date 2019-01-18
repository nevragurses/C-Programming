#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Implementing a game. Suppose that a botanist looking
for a quite rare flower by walking randomly in a forest. He/she is sure about that
the rare flower in that forest certainly. He must find the rare flower before his
water runs out. Otherwise, he faints in the forest.*/
typedef struct{
	char **Map;/*Map is a 2D array.*/
	int Width;
	int Height;
	int Flower_X;
	int Flower_Y;
}Forest;
typedef struct{
	int Coord_X;
	int Coord_Y;
	int Water_Bootle_Size;
}Botanist;
/*This function that reads a file named "init.txt" and initiates both the forest and the botanist.*/
void init_game(Forest *forest,Botanist *botanist) {

	FILE * read;
	int r,c,k=0,i;
	char comma;

	char *character;/*This is a 1D array for holding comma.*/

	read = fopen("init.txt", "r");/*File is opening to read.*/
	if (read==NULL) {/*If there is not init.txt file,warning message is given on the screen.*/
		printf("File init.txt cannot open for reading the game...\n");
	}
	else{/*If there is init.txt file this operations are made.*/

		fscanf(read,"%d",&botanist->Water_Bootle_Size);/*First row that is in the init.txt file is read.*/
		fscanf(read,"%d%c%d%c",&forest->Height,&comma,&forest->Width,&comma);/*Second row that is in the init.txt file is read.*/

		/*The dynamic area is created according to the received values.*/
		(forest)->Map=(char**)malloc(sizeof(char*)*(forest->Height));
		for(i=0;i<(forest->Height);i++){
			(forest)->Map[i]=(char*)malloc(sizeof(char)*(forest->Width));
		}
		/*Another dynamic area is created to hold the commas in the file.*/
		character=malloc(sizeof(char)*(forest->Height)*(forest->Width));

		/*The rest of the init.txt file is reading.*/
		for(r=0;r<(forest->Height);r++){
			for(c=0;c<(forest->Width*2);c++){
				if((c+1)%2!=0){/*If data is not comma*/
					fscanf(read,"%c",&forest->Map[r][c/2]);/*It is hold in the map..*/
					/*The positions of botanist and flower is found if and else statements.*/
					if(forest->Map[r][c/2]=='F'){
						forest->Flower_X=r;
						forest->Flower_Y=c/2;
					}
					else if(forest->Map[r][c/2]=='B'){
						botanist->Coord_X=r;
						botanist->Coord_Y=c/2;
					}
            		
					
				}
				else if((c+1)%2==0){/*If data in the init.txt file is comma*/
					fscanf(read,"%c",&character[k]);/*It is hold another field.*/
					k++;
				}
			}
		}	
	}
	fclose(read);
	
}
/*This function shows the forest map on screen.*/
void print_map(Forest *forest)
{
	int r,c,j,i;
	/*Prints all datas on the screen*/
	for (r = 0; r < (forest->Height); r++) {
        	for (c = 0; c < (forest->Width); c++) {
				printf("%c ", forest->Map[r][c]);

			}
			printf("\n");
	}
}
/*This is a recursive function that walks (up, down, left and right) on the forest to find the rare flower.*/
void search(Forest forest,Botanist botanist)
{
	int way;
	/*If water finish,game ends.*/
	if(botanist.Water_Bootle_Size==0){
		printf("\n");
		print_map(&forest);
		printf("Help!I'm on (%d,%d)",botanist.Coord_X,botanist.Coord_Y);
	}
	/*If botanist finds flower,game ends.*/
	else if(botanist.Coord_X==forest.Flower_X && botanist.Coord_Y==forest.Flower_Y){
		printf("\n");
		print_map(&forest);
		printf("I have founded it on (%d,%d)",botanist.Coord_X,botanist.Coord_Y);
	}
	/*If there is water and botanist doesn't find the flower*/
	else{
		way=(rand()%4)+1;/*Random way is determined.*/
		/*If way is 1 and field is empty botanist go a step up.*/
		if(way==1 && (forest.Map[botanist.Coord_X-1][botanist.Coord_Y]==' ')){
			
			forest.Map[botanist.Coord_X-1][botanist.Coord_Y]='B';/*New position of botanist on the map.*/
			forest.Map[botanist.Coord_X][botanist.Coord_Y]=' ';
			botanist.Coord_X=botanist.Coord_X-1;/*New coordinate of botanist*/
			botanist.Water_Bootle_Size=botanist.Water_Bootle_Size-1;
			
		}
		/*If way is 2 and field is empty  botanist go a step down.*/
		else if(way==2 &&(forest.Map[botanist.Coord_X+1][botanist.Coord_Y]==' ')&&botanist.Coord_X!=(forest.Height-2)||(botanist.Coord_X==forest.Flower_X-1 && botanist.Coord_Y==forest.Flower_Y)){
			
			forest.Map[botanist.Coord_X+1][botanist.Coord_Y]='B';/*New position of botanist on the map.*/
			forest.Map[botanist.Coord_X][botanist.Coord_Y]=' ';
			botanist.Coord_X=botanist.Coord_X+1;/*New coordinate of botanist*/
			botanist.Water_Bootle_Size=botanist.Water_Bootle_Size-1;
		}
		/*If way is 3 and field is empty botanist go a step left.*/
		else if(way==3 && (forest.Map[botanist.Coord_X][botanist.Coord_Y-1]==' ')){
		
			forest.Map[botanist.Coord_X][botanist.Coord_Y-1]='B';/*New position of botanist on the map.*/
			forest.Map[botanist.Coord_X][botanist.Coord_Y]=' ';
			botanist.Coord_Y=botanist.Coord_Y-1;/*New coordinate of botanist*/
			botanist.Water_Bootle_Size=botanist.Water_Bootle_Size-1;
		}
		/*If way is 4 and field is empty  botanist go a step right.*/
		else if(way==4 && (forest.Map[botanist.Coord_X][botanist.Coord_Y+1]==' ')){
			
			forest.Map[botanist.Coord_X][botanist.Coord_Y+1]='B';/*New position of botanist on the map.*/
			forest.Map[botanist.Coord_X][botanist.Coord_Y]=' ';
			botanist.Coord_Y=botanist.Coord_Y+1;/*New coordinate of botanist*/
			botanist.Water_Bootle_Size=botanist.Water_Bootle_Size-1;
		}
		search(forest,botanist);
	
	}
}
		
		
int main()
{
	srand(time(NULL));
	Forest forest;
	Botanist botanist;
	init_game(&forest,&botanist);/*Calling init game function.*/
	print_map(&forest);
	printf("\nSearching...\n");
	search(forest,botanist);/*Calling search function.*/
	free(forest.Map);/*Empties the space left in the memory.*/
	return 0;
	
}


