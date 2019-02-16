//***************************************************
// Filename: othello.c
//
// Author: Nandigam
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
	board[3][3]= 'B';
	board[4][3]= 'W';
	board[3][4]= 'W';
	board[4][4]= 'B';

}

// Returns true if moving the disc to location row,col is valid; else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
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
			if((SIZE<row+rowDir<0) || (SIZE<col+colDir<0))
				{
				rowDir==0;  
				colDir==0;
				}
				if(board[row + rowDir][col +colDir]== opponent){
					tempRow = rowDir + row;
					tempCol = colDir + col;
		}


			while(1)
			{
				tempRow+=rowDir;
				tempCol+=colDir;

				//posssible problem with this if statement, monitor.
				if(SIZE<tempRow<0 || SIZE<tempCol<0)
				break;

				if(board[tempRow][tempCol]== '_')
				break;

				if(board[tempRow][tempCol] == disc)
				printf("valid move");
				return true;
			}
		}
		return false;
	}
	return true;	// REPLACE THIS WITH tempColOUR IMPLEMENTATION
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
	
	board[row][col] = (char)disc;

	return;
	// COMPLETE THIS FUNCTION
}

// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
	return true;	// REPLACE THIS WITH tempColOUR IMPLEMENTATION
}

// Returns true if the board is fulltempCol occupied with discs; else returns false
bool isBoardFull(char board[][SIZE])
{
	for (int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++)
			if(board[i][j] = '-')
				return false;
	}
	return true;
		// REPLACE THIS WITH tempColOUR IMPLEMENTATION	
}

// Returns true if either the board is full or a valid move is not available for either disc
bool isGameOver(char board[][SIZE])
{

	return false;	// REPLACE THIS WITH tempColOUR IMPLEMENTATION
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTtempCol
char checkWinner(char board[][SIZE])
{
	return 'B';	// REPLACE THIS WITH tempColOUR IMPLEMENTATION
}