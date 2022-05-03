#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include <vector>
#include <iostream>
#include <string>

typedef unsigned char Row;
typedef unsigned int Col;

class Board {

private:
	std::vector<std::vector<Tile> > board;
public:
	Board();
	Tile GetTile(Row r, Col c);
	void SetTile(Row r, Col c, Tile t);
	void Display();
	void SetTileUI();
};

#endif