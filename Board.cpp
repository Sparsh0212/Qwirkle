#include "Board.h"
#include "Colors.h"

Board::Board()
{
	/*Board defaut constuctor*/
	this->board.resize(26);
	for (int i = 0; i < 26; i++)
	{
		this->board[i].resize(26);
	}
}

Tile Board::GetTile(Row r, Col c)
{
	/*Getter for the Tile*/
	int row = r - 'A';
	int col = c - 1;

	return board[row][col];
}

void Board::SetTile(Row r, Col c, Tile t)
{
	/*Setter for the TIle*/
	int row = r - 'A';
	int col = c - 1;
	
	this->board[row][col] = t;
	
}

void Board::Display()
{

	/*Displays the current state of 
	the board.*/
	setTextColor(MAGENTA_TXT);
	std::cout << "   ";
	for (int i = 1; i < 27; i++)
	{
		if (i < 10)
		{
			std::cout << i << "  ";
		}
		else
		{
			std::cout << i << " ";
		}
	}
	/*Boarder for the board*/
	std::cout << "\n---------------------------------------------------------------------------------\n";
	resetTextColor(RESET_COLOR);

	/*output rows*/

	/*display col header.*/
	setTextColor(CYAN_TXT);
	for (int i = 0; i < 26; i++)
	{
		std::cout << (char)('A' + i) << " ";
		for (int j = 0; j < 26; j++)
		{
			if (this->board[i][j].shape == 32)
				std::cout << "|" << (char)this->board[i][j].colour << (char)this->board[i][j].shape;
			else
				std::cout << "|" << (char)this->board[i][j].colour << this->board[i][j].shape;
		}
		std::cout << "|" << std::endl;
	}
	resetTextColor(RESET_COLOR);
}

void Board::SetTileUI()
{
	/*User interface for setting
	the board*/
	char row;
	int col;
	Shape shape;
	Colour colour;

	std::cout << "Enter Row: " << std::endl;
	std::cin >> row;

	std::cout << "Enter Col: " << std::endl;
	std::cin >> col;

	std::cout << "Tile Shape: " << std::endl;
	std::cin >> shape;

	std::cout << "Tile Colour: " << std::endl;
	std::cin >> colour;
	

	this->SetTile(row, col, Tile(colour, shape));
	
}
