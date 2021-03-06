#include <stdio.h>
/*Implementing Turkish Draughts board game without recursive.*/
typedef enum {white_man, black_man, white_king, black_king, empty} 
piece;
typedef enum {white = 10, black = 20}
player;

/*This function initializes the board.*/
void init_board(piece board[][8])
{
	int r,c;
	for(r=1;r<3;r++){	
		for(c=0;c<8;c++){
			board[r][c]=black_man;
		}
		
	}
	
	for(r=5;r<7;r++){
		for(c=0;c<8;c++){
			board[r][c]=white_man;
			
		}
	}
	
	for(r=3;r<5;r++){
		for(c=0;c<8;c++){
			board[r][c]=empty;
		}
	}
	
	for(c=0;c<8;c++){
		board[0][c]=empty;
	}
	
	for(c=0;c<8;c++){
		board[7][c]=empty;
	}
		
	
}
/*This function checks if the given player p can move a piece belonging to it from location (from_x,from_y) to location (to_x,to_y).*/
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){	
	int i,count=0;
	/*This if/else statements returns some numbers when the state that move is not alowed.*/
	if((p==white && board[from_x][from_y]==black_man) ||( p==black && board[from_x][from_y]==white_man)){
		return -1;
	}
	else if(p==white && board[from_x][from_y]==white_man && to_x-from_x==1 && from_y-to_y==0){
		return -2;
	}
	else if(p==white && board[from_x][from_y]==white_man && board[to_x][to_y]!=empty){
		return -2;
	}
	else if(p==black && board[from_x][from_y]==black_man && from_x-to_x==1 && from_y-to_y==0){
		return -2;
	}
	else if(p==black && board[from_x][from_y]==black_man && board[to_x][to_y]!=empty){
		return -2;
	}
		
	/*This if statement provides the moving and capturing of white_man*/
	if(p==white && board[from_x][from_y]==white_man && board[to_x][to_y]==empty){
		/*This if statement provides the moving of white_man*/
		if((from_x-to_x==1 && to_y-from_y==0)|| (from_x-to_x==0 && from_y-to_y==1)|| (from_x-to_x==0 && to_y-from_y==1)){
			board[to_x][to_y]=white_man;
			board[from_x][from_y]=empty;
			if(to_x==0){
				board[to_x][to_y]=white_king;
			}
		}
		/*This else-if statement provide the capturing to upwards for white_man*/
		else if((board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king)&& board[to_x][to_y]==board[from_x-2][from_y]){
			board[from_x-1][from_y]=empty;
			board[to_x][to_y]=white_man;
			board[from_x][from_y]=empty;
			if(to_x==0){
				board[to_x][to_y]=white_king;
			}

		}
		/*This else-if statement provides the capturing to the left for white_man*/	
		else if((board[from_x][from_y-1]==black_man || board[from_x][from_y-1]==black_king) && board[to_x][to_y]==board[from_x][from_y-2]){
			board[from_x][from_y-1]=empty;
			board[to_x][to_y]=white_man;
			board[from_x][from_y]=empty;

		}
		/*This else-if statement provides the capturing to the right for white_man*/
		else if((board[from_x][from_y+1]==black_man || board[from_x][from_y+1]==black_king) && board[to_x][to_y]==board[from_x][from_y+2]){
			board[from_x][from_y+1]=empty;
			board[to_x][to_y]=white_man;
			board[from_x][from_y]=empty;

		}
		
	}
	/*This else-if statement provides the moving and capturing of black_man*/
	else if(p==black && board[from_x][from_y]==black_man && board[to_x][to_y]==empty){
		/*This if statement provides the moving of black_man*/
		if((to_x-from_x==1 && to_y-from_y==0)|| (from_x-to_x==0 && from_y-to_y==1)|| (from_x-to_x==0 && to_y-from_y==1)){
			board[to_x][to_y]=black_man;
			board[from_x][from_y]=empty;
			if(to_x==7){
				board[to_x][to_y]=black_king;
			}
		}
		
		
		/*This else-if statement provide the capturing to downwards for  black__man*/
		else if((board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king) && board[to_x][to_y]==board[from_x+2][from_y]){
			board[from_x+1][from_y]=empty;
			board[to_x][to_y]=black_man;
			board[from_x][from_y]=empty;
			if(to_x==7){
				board[to_x][to_y]=black_king;
			}
		}
		
		/*This else-if statement provides the capturing to the left for  black__man*/	
		else if((board[from_x][from_y-1]==white_man || board[from_x][from_y-1]==white_king) && board[to_x][to_y]==board[from_x][from_y-2]){
			board[from_x][from_y-1]=empty;
			board[to_x][to_y]=black_man;
			board[from_x][from_y]=empty;
		}
		/*This else-if statement provides the capturing to the right for  black__man*/
		else if((board[from_x][from_y+1]==white_man || board[from_x][from_y+1]==white_king) && board[to_x][to_y]==board[from_x][from_y+2]){
			board[from_x][from_y+1]=empty;
			board[to_x][to_y]=black_man;
			board[from_x][from_y]=empty;
		}
		
		
	}
	/*This if statement provides the moving and capturing of white_king*/
	if(p==white && board[from_x][from_y]==white_king && board[to_x][to_y]==empty){
		/*This if statement regulates movement and capturing of white_king from top to bottom.*/
		if(from_y-to_y==0 && to_x-from_x>=1 && to_x-from_x<=7){
			for(i=from_x+1;i<to_x;i++){
				/*This if statement checks whether there are any piece or not in front of white_king*/
				if(board[i][from_y]!=empty){
					count ++;/*If there are any piece counter increases.*/
				}
			}
			if(count==0){/*If there aren't any piece white_king goes there.*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
			else if(count!=0){
				count =0;
				for(i=from_x+1;i<to_x;i++){
					if(board[i][from_y]==white_man|| board[i][from_y]==white_king){
						count ++;/*If there are white piece counter increases and white king doesn't go and doesn't capture it.*/
					}
				}
				if(count==0){
					for(i=from_x+1;i<to_x;i++){
						/*This if statement provides to capture ıf there are black piece in front of  white king.*/ 
						if(((board[i][from_y]==black_man ||board[i][from_y]==black_king) && board[i+1][from_y]==empty) && (board[i-1][from_y]==empty ||board[i-1][from_y]==board[from_x][from_y])){
							board[i][from_y]=empty;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
						}
					}
				}
			}
		}
		/*This else-if statement regulates movement and capturing of white_king from bottom to top.*/
		else if(from_y-to_y==0 && from_x-to_x>=1 && from_x-to_x<=7){
			for(i=from_x-1;i>to_x;i--){
				/*This if statement checks whether there are any piece or not in front of white_king*/
				if(board[i][from_y]!=empty){
					count ++;
				}
			}
			if(count==0){/*If there aren't any piece white_king goes there.*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
			else if(count!=0){
				count =0;
				for(i=from_x-1;i>to_x;i--){
					if(board[i][from_y]==white_man|| board[i][from_y]==white_king){
						count ++;/*If there are white piece counter increases and white king doesn't go and doesn't capture it.*/
					}
				}
				if(count==0){
					for(i=from_x-1;i>to_x;i--){
						/*This if statement provides to capture ıf there are black piece in front of or behind of white king.*/ 
						if(((board[i][from_y]==black_man ||board[i][from_y]==black_king) &&board[i-1][from_y]==empty) &&( board[i+1][from_y]==empty ||board[i+1][from_y]==board[from_x][from_y])){
							board[i][from_y]=empty;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
						}
					}
				}
			}
		}
		/*This else-if statement regulates movement and capturing of white_king from right to left.*/
		else if(from_x-to_x==0 && from_y-to_y>=1 && from_y-to_y<=7){
			for(i=from_y-1;i>to_y;i--){
				/*This if statement checks whether there are any piece or not in front of white_king*/
				if(board[from_x][i]!=empty){
					count ++;
				}
			}
			if(count==0){/*If there aren't any piece white_king goes there.*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
			else if(count!=0){
				count =0;
				for(i=from_y-1;i>to_y;i--){
					if(board[from_x][i]==white_man|| board[from_x][i]==white_king){
						count ++;/*If there are white piece counter increases and white king doesn't go and doesn't capture it.*/
					}
				}
				if(count==0){
					for(i=from_y-1;i>to_y;i--){
						/*This if statement provides to capture ıf there are black piece in front of or behind of white king.*/
						if(((board[from_x][i]==black_man ||board[i][from_y]==black_king)&&board[from_x][i-1]==empty) &&(board[from_x][i+1]==empty || board[from_x][i+1]==board[from_x][from_y])){
							board[from_x][i]=empty;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
						}
					}
				}
				
			}
		}
		/*This else-if statement regulates movement and capturing of white_king from left to right.*/
		else if(from_x-to_x==0 && to_y-from_y>=1 && to_y-from_y<=7){
			for(i=from_y+1;i<to_y;i++){
				/*This if statement checks whether there are any piece or not in front of white_king*/
				if(board[from_x][i]!=empty){
					count ++;
				}
			}
			if(count==0){/*If there aren't any piece white_king goes there.*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
			else if(count !=0){
				count =0;
				for(i=from_y+1;i<to_y;i++){
					if(board[from_x][i]==white_man|| board[from_x][i]==white_king){
						count ++;/*If there are white piece counter increases and white king doesn't go and doesn't capture it.*/
					}
				}
				if(count==0){
					for(i=from_y+1;i<to_x;i++){
						/*This if statement provides to capture ıf there are black piece in front of or behind of white king.*/
						if(((board[from_x][i]==black_man ||board[i][from_y]==black_king)&&board[from_x][i+1]==empty) &&(board[from_x][i-1]==empty || board[from_x][i-1]==board[from_x][from_y])){
							board[from_x][i]=empty;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
						}
					}
				}
				
			}
		}
	}
	/*This if statement provides the moving and capturing of  black_king*/
	else if(p==black && board[from_x][from_y]==black_king && board[to_x][to_y]==empty){
		/*This if statement regulates movement and capturing of  black_king from top to bottom.*/
		if(from_y-to_y==0 && to_x-from_x>=1 && to_x-from_x<=7){
			for(i=from_x+1;i<to_x;i++){
				/*This if statement checks whether there are any piece or not in front of black__king*/
				if(board[i][from_y]!=empty){
				count ++;/*This if statement checks whether there are any piece or not in front of  black__king*/
				}
			}
			if(count==0){/*If there aren't any piece  black_king goes there.*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
			else if(count!=0){
				count =0;
				for(i=from_x+1;i<to_x;i++){
					if(board[i][from_y]==black_man|| board[i][from_y]==black_king){
						count ++;/*If there are white piece counter increases and  black_king doesn't go and doesn't capture it.*/
					}
				}
				if(count==0){
					for(i=from_x+1;i<to_x;i++){
						/*This if statement provides to capture ıf there are white piece in front of or behind of  black_king.*/ 
						if(((board[i][from_y]==white_man ||board[i][from_y]==white_king) &&board[i+1][from_y]==empty) && (board[i-1][from_y]==empty ||board[i-1][from_y]==board[from_x][from_y])){
							board[i][from_y]=empty;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
						}
					}
				}
	
			}
		}
		/*This else-if statement regulates movement and capturing of  black_king from bottom to top.*/			
		else if(from_y-to_y==0 && from_x-to_x>=1 && from_x-to_x<=7){
			for(i=from_x-1;i>to_x;i--){
				/*This if statement checks whether there are any piece or not in front of  black_king*/
				if(board[i][from_y]!=empty){
					count ++;
				}
			}
			if(count==0){/*If there aren't any piece  black_king goes there.*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
			else if(count!=0){
				count =0;
				for(i=from_x-1;i>to_x;i--){
					if(board[i][from_y]==black_man|| board[i][from_y]==black_king){
						count ++;/*If there are  black piece counter increases and  black_king doesn't go and doesn't capture it.*/
					}
				}
				if(count==0){
					for(i=from_x-1;i>to_x;i--){
						/*This if statement provides to capture ıf there are white piece in front of or behind of  black_king.*/ 
						if(((board[i][from_y]==white_man ||board[i][from_y]==white_king) &&board[i-1][from_y]==empty) &&( board[i+1][from_y]==empty ||board[i+1][from_y]==board[from_x][from_y])){
							board[i][from_y]=empty;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
						}
					}
				}
			}
		}
		/*This else-if statement regulates movement and capturing of  black_king from right to left.*/		
		else if(from_x-to_x==0 && from_y-to_y>=1 && from_y-to_y<=7){
			for(i=from_y-1;i>to_y;i--){
				/*This if statement checks whether there are any piece or not in front of  black_king*/
				if(board[from_x][i]!=empty){
				count ++;
				}
			}
			if(count==0){/*If there aren't any piece  black_king goes there.*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
			else if(count!=0){
				count =0;
				for(i=from_y-1;i>to_y;i--){
					if(board[from_x][i]==black_man|| board[from_x][i]==black_king){/*If there are  black piece counter increases and  black king doesn't go and doesn't capture it.*/
						count ++;
					}
				}
				if(count==0){
					for(i=from_y-1;i>to_y;i--){
						/*This if statement provides to capture ıf there are white piece in front of or behind of  black_king.*/ 
						if(((board[from_x][i]==white_man ||board[i][from_y]==white_king) &&board[from_x][i-1]==empty) &&(board[from_x][i+1]==empty || board[from_x][i+1]==board[from_x][from_y])){
							board[from_x][i]=empty;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
						}
					}
				}
			}
		}
		/*This else-if statement regulates movement and capturing of  black_king from left to right.*/	
		else if(from_x-to_x==0 && to_y-from_y>=1 && to_y-from_y<=7){
			for(i=from_y+1;i<to_y;i++){
				/*This if statement checks whether there are any piece or not in front of  black_king*/
				if(board[from_x][i]!=empty){
					count ++;
				}
			}
			if(count==0){/*If there aren't any piece  black_king goes there.*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
			else if(count!=0){
				count =0;
				for(i=from_y+1;i<to_y;i++){
					if(board[from_x][i]==black_man|| board[from_x][i]==black_king){
						count ++;/*If there are  black piece counter increases and black_king doesn't go and doesn't capture it.*/
					}
				}
				if(count==0){
					for(i=from_y+1;i<to_y;i++){
						/*This if statement provides to capture ıf there are white piece in front of or behind of black_king.*/ 	
						if(((board[from_x][i]==white_man ||board[i][from_y]==white_king) &&board[from_x][i+1]==empty) &&(board[from_x][i-1]==empty || board[from_x][i-1]==board[from_x][from_y])){
							board[from_x][i]=empty;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
						}
					}	
				}
			}
		}
	}	
	return 1;
}
/*This function checks if the game has been completed after the move.*/
int check_end_of_game(piece board[][8]){
	int i,j,counter=0,counter2=0;
	/*This loop checks whether there are white piece or not.*/
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j]==white_man || board[i][j]==white_king){
				counter ++;
			}
		}
	}
	if(counter==0){
		return black;
	}
	/*This loop checks whether there are black piece or not.*/
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j]==black_man || board[i][j]==black_king){
				counter2 ++;
			}
		}
	}
	if(counter2==0){
		return white;
	}
	/*If game continues returns -1*/
		
	return -1;
}
/*This function displays the board in current state.It uses some symbols for printing.*/
void display_board(piece board[][8])
{
	int r,c;
	for(r=0;r<8;r++){
		for(c=0;c<8;c++){
			if(board[r][c]==white_man){
				printf("w");
			}
			else if(board[r][c]==black_man){
				printf("b");
			}
			else if(board[r][c]==white_king){
				printf("W");
			}
			else if(board[r][c]==black_king){
				printf("B");
			}
			else if(board[r][c]==empty){
				printf("-");
			}

		}
		printf("\n");
	}
}
/*This function is a sample game.*/				
void sample_game_1(){
	piece board[8][8];
	init_board(board);
    	display_board(board);
	
	move(board,5,0,4,0,white);
	display_board(board);
	printf("\n");
	move(board,2,0,3,0,black);
	display_board(board);
	printf("\n");
	move(board,4,0,2,0,white);
	display_board(board);
	printf("\n");
	move(board,2,0,0,0,white);
	display_board(board);
	printf("\n");
	move(board,2,1,3,1,black);
	display_board(board);
	printf("\n");
	move(board,5,1,4,1,white);
	display_board(board);
	printf("\n");
	move(board,3,1,5,1,black);
	display_board(board);
	printf("\n");
	move(board,5,1,7,1,black);
	display_board(board);
	printf("\n");
	move(board,5,2,4,2,white);
	display_board(board);
	printf("\n");
	move(board,2,2,3,2,black);
	display_board(board);
	printf("\n");
	move(board,4,2,2,2,white);
	display_board(board);
	printf("\n");
	move(board,2,2,0,2,white);
	display_board(board);
	printf("\n");
	move(board,2,3,3,3,black);
	display_board(board);
	printf("\n");
	move(board,5,3,4,3,white);
	display_board(board);
	printf("\n");
	move(board,3,3,5,3,black);
	display_board(board);
	printf("\n");
	move(board,5,3,7,3,black);
	display_board(board);
	printf("\n");
	move(board,5,4,4,4,white);
	display_board(board);
	printf("\n");
	move(board,2,4,3,4,black);
	display_board(board);
	printf("\n");
	move(board,4,4,2,4,white);
	display_board(board);
	printf("\n");
	move(board,2,4,0,4,white);
	display_board(board);
	printf("\n");
	move(board,2,5,3,5,black);
	display_board(board);
	printf("\n");
	move(board,5,5,4,5,white);
	display_board(board);
	printf("\n");
	move(board,3,5,5,5,black);
	display_board(board);
	printf("\n");
	move(board,5,5,7,5,black);
	display_board(board);
	printf("\n");
	move(board,5,6,4,6,white);
	display_board(board);
	printf("\n");	
	move(board,2,6,3,6,black);
	display_board(board);
	printf("\n");
	move(board,4,6,2,6,white);
	display_board(board);
	printf("\n");
	move(board,2,6,0,6,white);
	display_board(board);
	printf("\n");
	move(board,2,7,3,7,black);
	display_board(board);
	printf("\n");
	move(board,5,7,4,7,white);
	display_board(board);
	printf("\n");
	move(board,3,7,5,7,black);
	display_board(board);
	printf("\n");
	move(board,5,7,7,7,black);
	display_board(board);
	printf("\n");
	move(board,0,6,0,7,white);
	display_board(board);
	printf("\n");
	move(board,1,1,2,1,black);
	display_board(board);
	printf("\n");
	move(board,0,7,3,7,white);
	display_board(board);
	printf("\n");
	move(board,7,7,2,7,black);
	display_board(board);
	printf("\n");
	move(board,0,4,0,5,white);
	display_board(board);
	printf("\n");
	move(board,1,5,2,5,black);
	display_board(board);
	printf("\n");
	move(board,0,5,3,5,white);
	display_board(board);
	printf("\n");
	move(board,7,5,2,5,black);
	display_board(board);
	printf("\n");
	move(board,6,4,5,4,white);
	display_board(board);
	printf("\n");
	move(board,7,3,7,4,black);
	display_board(board);
	printf("\n");
	move(board,0,2,0,3,white);
	display_board(board);
	printf("\n");
	move(board,7,4,2,4,black);
	display_board(board);
	printf("\n");
	move(board,0,3,5,3,white);
	display_board(board);
	printf("\n");
	move(board,7,1,4,1,black);
	display_board(board);
	printf("\n");
	move(board,0,0,0,1,white);
	display_board(board);
	printf("\n");
	move(board,2,4,2,3,black);
	display_board(board);
	printf("\n");
	move(board,5,3,1,3,white);
	display_board(board);
	printf("\n");
	move(board,2,5,2,4,black);
	display_board(board);
	printf("\n");
	move(board,0,1,3,1,white);
	display_board(board);
	printf("\n");
	move(board,3,1,5,1,white);
	display_board(board);
	printf("\n");
	move(board,2,7,2,5,black);
	display_board(board);
	printf("\n");
	move(board,5,1,5,4,white);
	display_board(board);
	printf("\n");
	move(board,2,4,6,4,black);
	display_board(board);
	printf("\n");
	move(board,1,3,1,7,white);
	display_board(board);
	printf("\n");
	move(board,6,4,6,7,black);
	display_board(board);
	printf("\n");
	move(board,6,7,0,7,black);
	display_board(board);
	printf("\n");
	move(board,6,2,6,3,white);
	display_board(board);
	printf("\n");
	move(board,2,5,6,5,black);
	display_board(board);
	printf("\n");
	move(board,6,0,6,1,white);
	display_board(board);
	printf("\n");
	move(board,6,5,6,2,black);
	display_board(board);
	printf("\n");
	move(board,6,2,6,0,black);
	display_board(board);
	printf("\n");
	/*This if else statements determene the winner of game.*/
	if(check_end_of_game(board)==white){
		printf("\nWhite Win\n");
	}
	else if(check_end_of_game(board)==black){
		printf("\nBlack Win\n");
	}
}
/*This function use the above functions to play the game given in the gif animation.*/
void sample_game_2(){
    	piece board[8][8]={
        {empty,empty,empty,empty,empty,empty,empty,empty},
        {empty,empty,black_man,black_man,black_man,black_man,empty,empty},
        {empty,black_man,black_man,black_man,black_man,empty,black_man,black_man},
        {black_man,black_man,black_man,empty,empty,black_man,empty,black_man},
        {empty,empty,white_man,white_man,white_man,black_man,white_man,white_man},
        {white_man,white_man,white_man,white_man,white_man,empty,white_man,white_man},
        {empty,empty,white_man,white_man,white_man,white_man,empty,empty},
        {empty,empty,empty,empty,empty,empty,empty,empty}
    	};
    display_board(board);
	move(board,5,1,4,1,white);
	display_board(board);
	printf("\n");
	move(board,3,1,5,1,black);
	display_board(board);
	printf("\n");
	move(board,4,3,3,3,white);
	display_board(board); 
	printf("\n");
	move(board,4,5,4,3,black);
	display_board(board);
	printf("\n");
	move(board,4,3,4,1,black);
	display_board(board);
	printf("\n");
	move(board,3,3,3,1,white);
	display_board(board);
	printf("\n");
	move(board,3,1,1,1,white);
	display_board(board);
	printf("\n");
	move(board,1,2,1,0,black);
	display_board(board);
	printf("\n");
	move(board,5,3,4,3,white);
	display_board(board);
	printf("\n");
	move(board,5,1,5,3,black);
	display_board(board);
	printf("\n");
	move(board,5,3,5,5,black);
	display_board(board);
	printf("\n");
	move(board,5,5,7,5,black);
	display_board(board);
	printf("\n");
	move(board,4,3,3,3,white);
	display_board(board);
	printf("\n");
	move(board,2,3,4,3,black);
	display_board(board);
	printf("\n");
	move(board,5,6,5,5,white);
	display_board(board);
	printf("\n");
	move(board,7,5,4,5,black);
	display_board(board);
	printf("\n");
	move(board,4,6,4,4,white);
	display_board(board);
	printf("\n");
	move(board,4,4,4,2,white);
	display_board(board);
	printf("\n");
	move(board,4,2,4,0,white);
	display_board(board);
	printf("\n");
	move(board,4,0,2,0,white);
	display_board(board);
	printf("\n");
	move(board,2,0,0,0,white);
	display_board(board);
	printf("\n");
}
int main()
{
	printf("SAMPLE GAME 1\n");
	sample_game_1();
	printf("\nSAMPLE GAME 2\n");
	sample_game_2();
	return 0;
}

