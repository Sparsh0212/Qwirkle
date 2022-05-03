#include "Tile.h"

Tile::Tile(Colour colour, Shape shape)
{
    this->colour = colour;
    this->shape = shape;
}

Tile::Tile() {
    this->colour = ' ';
    this->shape = ' ';
}

Tile::~Tile() {}



std::ostream& operator<<(std::ostream& os, const Tile& tile)
{
    if (tile.shape == 32) os << (char)tile.colour << (char)tile.shape;
    else os << (char)tile.colour << tile.shape;
    return os;
}
