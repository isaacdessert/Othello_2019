//***************************************************
// Filename: othello.c
//
// Author: Nandigam
// Implementations done by Jesse David and Isaac Dessert
//***************************************************

#include "othello.h"

// DisplatempCols the board (as SIZE tempRow SIZE grid) on console
void displayBoard(char board[][SIZE])
{
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf((i == 0 ? "%5d" : "%3d"), i+1);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%2d", i+1);
		for (int j = 0; j < SIZE; j++) {
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(char board[][SIZE])
{
	for (int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++)
			board[i][j] = '_';
	}
	//setting up
	board[3][3]= 'B';
	board[4][3]= 'W';
	board[3][4]= 'W';
	board[4][4]= 'B';

}

// Returns true if moving the disc to location row,col is valid; else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
	//setting up and checking if free space
	if(board[row][col] != '_')
	return false;
	char opponent ='W';
	if(disc== 'W')
	opponent = 'B';
	int flag = 1;
	int rowDir=0;
	int colDir=0;
	int tempRow=0;
	int tempCol=0;

	//loops delta for each direction
	for(rowDir = -1; rowDir <=1; rowDir++){
		for(colDir = -1; colDir <=1; colDir++){
			//checks to see within param
			if((SIZE<row+rowDir || row+rowDir<0) || (SIZE<col+colDir || col+colDir<0))
				{
				rowDir==0;  
				colDir==0;
				}
				//checks to see if at least one position in that direction is opponent
				if(board[row + rowDir][col +colDir]== opponent){
					tempRow = rowDir + row;
					tempCol = colDir + col;
				}
				else
				{
					continue;
				}
				

			//enter interations to search for own piece in direction
			while(1)
			{
				tempRow+=rowDir;
				tempCol+=colDir;

				//posssible problem with this if statement, monitor.(works)
				if(SIZE<tempRow || tempRow<0 || SIZE<tempCol || tempCol<0)
				break;

				if(board[tempRow][tempCol]== '_')
				break;

				//found, move is valid.
				if(board[tempRow][tempCol] == disc){
				return true;
				}
			}
		}
	}
	return false;
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
	//iterates through just like check valid and then turns around and goes back
	board[row][col] = (char)disc;
	char opponent ='W';
	if(disc== 'W')
	opponent = 'B';
	int flag = 1;
	int rowDir=0;
	int colDir=0;
	int tempRow=0;
	int tempCol=0;

	for(rowDir = -1; rowDir <=1; rowDir++){
		for(colDir = -1; colDir <=1; colDir++){
			tempRow = row;
			tempCol = col;
			flag=1;
			if((SIZE<row+rowDir || row+rowDir<0) || (SIZE<col+colDir || col+colDir<0))
				{
					//does nothing but tracks.  incase I need to adjust keeping it here.
				rowDir==0;  
				colDir==0;
				}
			if(board[row + rowDir][col +colDir]== opponent){
					tempRow = rowDir + row;
					tempCol = colDir + col;
			}
			else
			{
				continue;
			}

			while(flag)
			{
				tempRow+=rowDir;
				tempCol+=colDir;

				//posssible problem with this if statement, monitor.(works)
				if(SIZE<tempRow || tempRow<0 || SIZE<tempCol || tempCol<0)
				flag=0;

				if(board[tempRow][tempCol]== '_')
				flag = 0;

				if(board[tempRow][tempCol] == disc){
					//this turns it around
					rowDir= -rowDir;
					colDir= -colDir;
					while(flag)
					{
						tempRow+=rowDir;
						tempCol+=colDir;

						if(board[tempRow][tempCol] == disc){
							//make sure loop is peachy
							rowDir=-rowDir;
							colDir=-colDir;
							flag=0;
						}
						board[tempRow][tempCol] = disc;
					}
				}
			}
		}
	}
	return;
}

// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
	for (int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++)
		if(isValidMove(board, i, j, disc))
		return true;
	}
	return false;
		
}

// Returns true if the board is fulltempCol occupied with discs; else returns false
bool isBoardFull(char board[][SIZE])
{
	for (int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++)
			if(board[i][j] = '_')
				return false;
	}
	return true;	
}

// Returns true if either the board is full or a valid move is not available for either disc
bool isGameOver(char board[][SIZE])
{

	if(!isBoardFull(board) || isValidMoveAvailable(board,'W') || isValidMoveAvailable(board, 'B'))
	return false;
	return true;	
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTtempCol
char checkWinner(char board[][SIZE])
{
	int Bcount = 0;
	int Wcount = 0;

	for (int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++) {
			if(board[i][j] = 'B')
				Bcount += 1;
			if(board[i][j] = 'W')
				Wcount += 1;
	}
	}
	if(Bcount > Wcount)
	return BLACK;
	if(Wcount > Bcount)
	return WHITE;
	return EMPTY;	

}