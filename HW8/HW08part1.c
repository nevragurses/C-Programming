#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TEXTSIZE 10
/*The 100 games*/
typedef enum {snakes=300,stairs=301,penalties=302,boosts=303,traps=304}/*Enum types to define block types.*/
	blockTypes;
typedef struct { /*Feature of board blocks.*/
	char text[TEXTSIZE];
	int pos_x, pos_y, jump_x, jump_y;
	int data;
	blockTypes type;
} block;
/*This function initilaze the board.*/
void initilaze_board(block block_board[][10],int row)
{
	int r,c;
	for(r=0;r<row;r++){
		for(c=0;c<10;c++){
			if(r==0 || r== 2 || r==4 || r==6 || r==8){/*Finds the data and positions of the rows that increase from left to right of the numbers.*/
				block_board[r][c].data=((9-r)*10)+c+1;
				block_board[r][c].pos_x=r;
				block_board[r][c].pos_y=c;
			}
			else if(r==1 || r==3 || r==5 || r==7 || r==9){/*Finds the data and positions of the rows that decrease from left to right of the numbers.*/
				block_board[r][c].data=((10-r)*10)-c;
				block_board[r][c].pos_x=r;
				block_board[r][c].pos_y=c;
			}
		}
	}
	/*Assigned types of the blocks,printed texts,determined jump_x and jump_y positions.*/
	block_board[0][7].type=snakes;
	sprintf(block_board[0][7].text,"S{72} ");
	block_board[0][7].jump_x=2;
	block_board[0][7].jump_y=1;
	block_board[0][8].type=snakes;
	sprintf(block_board[0][8].text,"S{56} ");
	block_board[0][8].jump_x=4;
	block_board[0][8].jump_y=5;
	block_board[2][2].type=snakes;
	sprintf(block_board[2][2].text,"S{68} ");
	block_board[2][2].jump_x=3;
	block_board[2][2].jump_y=2;
	block_board[3][7].type=snakes;
	sprintf(block_board[3][7].text,"S{52} ");
	block_board[3][7].jump_x=4;
	block_board[3][7].jump_y=1;
	block_board[4][9].type=snakes;
	sprintf(block_board[4][9].text,"S{44} ");
	block_board[4][9].jump_x=5;
	block_board[4][9].jump_y=6;
	block_board[5][5].type=snakes;
	sprintf(block_board[5][5].text,"S{22} ");
	block_board[5][5].jump_x=7;
	block_board[5][5].jump_y=8;
	block_board[7][5].type=snakes;
	sprintf(block_board[7][5].text,"S{12} ");
	block_board[7][5].jump_x=8;
	block_board[7][5].jump_y=1;
	block_board[9][4].type=snakes;
	sprintf(block_board[9][4].text," S{1} ");
	block_board[9][4].jump_x=9;
	block_board[9][4].jump_y=9;
	
 	block_board[1][1].type=stairs;
	sprintf(block_board[1][1].text,"M{94} ");
	block_board[1][1].jump_x=0;
	block_board[1][1].jump_y=3;
	block_board[2][5].type=stairs;
	sprintf(block_board[2][5].text,"M{83} ");
	block_board[2][5].jump_x=1;
	block_board[2][5].jump_y=7;
	block_board[3][1].type=stairs;
	sprintf(block_board[3][1].text,"M{77} ");
	block_board[3][1].jump_x=2;
	block_board[3][1].jump_y=6;
	block_board[4][6].type=stairs;
	sprintf(block_board[4][6].text,"M{77} ");
	block_board[4][6].jump_x=2;
	block_board[4][6].jump_y=6;
	block_board[6][1].type=stairs;
	sprintf(block_board[6][1].text,"M{52} ");
	block_board[6][1].jump_x=4;
	block_board[6][1].jump_y=1;
	block_board[8][6].type=stairs;
	sprintf(block_board[8][6].text,"M{28} ");
	block_board[8][6].jump_x=7;
	block_board[8][6].jump_y=2;
	block_board[9][3].type=stairs;
	sprintf(block_board[9][3].text,"M{11} ");
	block_board[9][3].jump_x=8;
	block_board[9][3].jump_y=0;

	block_board[1][5].type=penalties;
	sprintf(block_board[1][5].text,"   P  ");
	block_board[5][2].type=penalties;
	sprintf(block_board[5][2].text,"   P  ");
	block_board[8][2].type=penalties;
	sprintf(block_board[8][2].text,"   P  ");

	block_board[1][8].type=boosts;
	sprintf(block_board[1][8].text,"   B  ");
	block_board[3][4].type=boosts;
	sprintf(block_board[3][4].text,"   B  ");
	block_board[5][0].type=boosts;
	sprintf(block_board[5][0].text,"   B  ");
	block_board[6][5].type=boosts;
	sprintf(block_board[6][5].text,"   B  ");
	block_board[7][1].type=boosts;
	sprintf(block_board[7][1].text,"   B  ");

	block_board[0][2].type=traps;
	sprintf(block_board[0][2].text,"   T  ");
	block_board[2][8].type=traps;
	sprintf(block_board[2][8].text,"   T  ");
	block_board[4][3].type=traps;
	sprintf(block_board[4][3].text,"   T  ");
	block_board[6][9].type=traps;
	sprintf(block_board[6][9].text,"   T  ");
}
/*This function prints the board.*/
void print_board(block block_board[][10],int row)
{
	int r,c;
	for(r=0;r<row;r++){
		for(c=0;c<10;c++){
			/*This if statement prints texts on the board.*/
			if(block_board[r][c].type==snakes || block_board[r][c].type==stairs || block_board[r][c].type==penalties || block_board[r][c].type==boosts || block_board[r][c].type==traps){
				printf("%s",block_board[r][c].text);
			}
			/*This else if statement prints data and writing of  finish on the board.*/
			else if(r ==0 && c==9){
				printf(" %d",block_board[r][c].data);
				printf("(finish)");
			}
			/*This else if statement prints data and writing of  start on the board.*/
			else if(r==9 && c==9){
				printf("  %d",block_board[r][c].data);
				printf("(start)");
			}
			/*Thi else if statement prints data that is one digit.*/
			else if(block_board[r][c].data<10){
				printf("   %d  ",block_board[r][c].data);
			}
			/*Thi else if statement prints data that is bigger than one  digit.*/
			else 
				printf("  %d  ",block_board[r][c].data);
		}
		printf("\n\n");
	}
}
/*This function finds random dice number.*/
int find_dice()
{
	int dice;
	dice=(rand()%6)+1;
	return dice;
}
/*This function is playing the game as a single player, recursively.*/	
int play_game_single(block block_board[][10],int temp_data,int row,int counter)
{
	int i,temp,j;
	int dice,start,r,c;
	int temp_pos_x,temp_pos_y;
	int flag=0;
	dice=find_dice(); 
	temp_data=temp_data+dice;/*New data of position is found by adding dice and data of current position.*/
	
	if(temp_data==100){/*After the dice rolling, if the move reaches the block 100, then the game is over.*/
		printf("\ndata:%d\ndice:%d\ncounter:%d\n",temp_data, dice,counter);
		return counter;
	}
	else if(temp_data>100){/*After the dice rolling, if the move overshoots the block 100, then the player does not move.*/
			temp_data=temp_data-dice;/*State of not moving.*/
			int keep1 = play_game_single(block_board,temp_data,row,counter+1);/*I assigned recursive function an integer because to print the moves last to first.*/
			printf("\ndata:%d\ndice:%d\ncounter:%d\n",temp_data, dice, counter);
			
			return keep1;
	}
	else if(temp_data<100){/*After the dice rolling, if the move doesn't reach the block 100,this else if statement prosesses.*/
		while(flag!=1){
			for(r=0;r<10;r++){/*Player's new position is determened by this loop.*/
				for(c=0;c<10;c++){
					if(block_board[r][c].data==temp_data){
						flag=1;
						if(flag==1){/*New positions of player.*/
							temp_pos_x=r;
							temp_pos_y=c;
						}
					}
				}
			}	
		}	
		/*If the player reaches an “S” block, returns the block that is shown in brackets.*/
		if(block_board[temp_pos_x][temp_pos_y].type==snakes){
			temp_data=block_board[block_board[temp_pos_x][temp_pos_y].jump_x][block_board[temp_pos_x][temp_pos_y].jump_y].data;/*New data of new position.*/
			temp_pos_x=block_board[temp_pos_x][temp_pos_y].jump_x;
			temp_pos_y=block_board[temp_pos_x][temp_pos_y].jump_y;
			
		}
		else if(block_board[temp_pos_x][temp_pos_y].type==stairs){
			temp_data=block_board[block_board[temp_pos_x][temp_pos_y].jump_x][block_board[temp_pos_x][temp_pos_y].jump_y].data;/*New data of new position*/
			temp_pos_x=block_board[temp_pos_x][temp_pos_y].jump_x;
			temp_pos_y=block_board[temp_pos_x][temp_pos_y].jump_y;
			
		}
		/*If the player reaches a “B” block, jumps from current block to fifth next block.*/
		else if(block_board[temp_pos_x][temp_pos_y].type==boosts){
			temp_data=temp_data+5;
		}
		/*If the player reaches a “T” block, returns from current block to fifth previous block.*/	
		else if(block_board[temp_pos_x][temp_pos_y].type==traps){
			temp_data=temp_data-5;
			
		}
		/*If a player ends up in a “P” block after dice rolling, then the player does not move.*/
		else if(block_board[temp_pos_x][temp_pos_y].type==penalties)
		{
			temp_data=temp_data-dice;
			
		}
		int keep2 = play_game_single(block_board,temp_data,row,counter+1);/*I assigned recursive function an integer because to print the moves last to first.*/
		printf("\ndata:%d\ndice:%d\ncounter:%d\n",temp_data, dice, counter);
		
		return keep2;
		
	}
	return counter;/*This function returns move counts.*/
	
}
/*This function determines which player is won the game.*/
void who_won(block block_board[][10],int temp_data,int row,int counter)
{
	int player1,player2;
	printf("\n\n***MOVE OF PLAYER ONE(1)***\n");
	player1=play_game_single(block_board,temp_data,row,counter);
	printf("\n\n***MOVE OF PLAYER TWO(2)***\n");	
	player2=play_game_single(block_board,temp_data,row,counter);
	printf("\nMove count of player one is:%d\n",player1);
	printf("Move count of player two is:%d\n",player2);
	if(player1<player2){/*If move counts of player 1 is less than player 2,it win.*/
		printf("\nPLAYER ONE WON!\n");
	}
	else if(player2<player1){/*If move counts of player 2 is less than player 1,it win.*/
		printf("\nPLAYER TWO WON!\n");
	}
}
	
int main()
{
	int start,temp_data,counter=1;
	srand(time(NULL));
	block block_board[10][10];/*game board*/
	int row=10;
	initilaze_board(block_board,row);
	print_board(block_board,row);
	printf("\n-------A SAMPLE MOVE OF THE GAME------\n"); 
	play_game_single(block_board,1,row,counter);/*I assigned the data 1 as a value of function parameter to start game.*/
	printf("\n--------GAME OF TWO PLAYER--------------\n");
	who_won(block_board,1,row,counter);

}
