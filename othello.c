//***************************************************
// Filename: othello.c
//
// Author: Nandigam
//***************************************************

#include "othello.h"

// Displays the board (as SIZE x SIZE grid) on console
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
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = '-';
		}
	}
}

// Returns true if moving the disc to location row,col is valid; else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
	return true;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
	if(isValidMoveAvailable(board, disc) && isValidMove(board,row,col, disc))
	{
		board[row][col] = disc;
	}
}

// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
	return true;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Returns true if the board is fully occupied with discs; else returns false
bool isBoardFull(char board[][SIZE])
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if(board[i][j] == '-')
				return false;
		}
	}
	return true;
}

// Returns true if either the board is full or a valid move is not available for either disc
bool isGameOver(char board[][SIZE])
{
	return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTY
char checkWinner(char board[][SIZE])
{
	return EMPTY;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}