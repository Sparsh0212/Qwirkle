
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <iostream>

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:

	Tile();
	Tile(Colour color, Shape shape);
	~Tile();

	friend std::ostream& operator << (std::ostream&, const Tile&);
	Colour colour;
	Shape  shape;
};

#endif // ASSIGN2_TILE_H
